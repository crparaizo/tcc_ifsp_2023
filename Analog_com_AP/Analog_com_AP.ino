//Bibliotecas utilizadas nesse código
#include "ESPAsyncWebServer.h"
#include "SPIFFS.h"

//Credenciais do Access Point
const char* ssid = "ESP32";
const char* password = "12345678";

//Porta do Web Server
AsyncWebServer server(80);


//pino do ESP32 correspondente a leitura analógica
const int pinoAnalogico = 34;

//vetor com valores capturados por vez
int valoresAnalog_capturados[10];
//valores serão inseridos dentro de uma string
String valores = "";


//Função que substitui a variável no HTML pelo vetor de valores analógicos
String processor(const String & var)
{
  Serial.println(var);
  if (var == "PLACEHOLDER") {
    return valores;
  }
  return String();
}

//Função que captura valores e formata como uma string
String juntarValores () {

  valores = "{";

  for (int i = 0; i < 10; i++) {
    valores += '"';
    valores += "valor";
    valores += i;
    valores += '"';
    valores += ':';
    valoresAnalog_capturados[i] = analogRead(pinoAnalogico);
    //voltagem = valorSensor * (3.3/4095.0)
    delayMicroseconds(100);
    valores += valoresAnalog_capturados[i];

    if (i < 9) {
      valores += ',';
    }
  }

  valores += "}";
  return valores;
}

void setup() {
  Serial.begin(115200);

  // Iniciando SPIFFS
  if (!SPIFFS.begin(true)) {
    Serial.println("Ocorreu um erro na criação do SPIFFS");
    return;
  }

  //Connectando WI-FI
  WiFi.softAP(ssid, password);
  IPAddress IP = WiFi.softAPIP();
  Serial.print("Endereço IP - Access Point: ");
  Serial.println(IP);
  Serial.println(WiFi.localIP());

  //1 - SPIFFS - significa que irá gravar na memória flash do ESP32
  //2 - local do arquivo html dentro da pasta "data"
  //3 - informa que irá passar conteudo como String
  //4 - false - desabilita o download do html quando acessado no navegador
  //5 - chama função que enviar dados para html

  //Rota que enviar os valores análogicos para HTML
  server.on("/index.html", HTTP_GET, [](AsyncWebServerRequest * request) {
    request->send(SPIFFS, "/index.html", String(), false, processor);
  });

  //Rota que envia os valores como texto para Javascript tratar
  server.on("/texto", HTTP_GET, [](AsyncWebServerRequest * request) {
    request->send(200, "text/plain", juntarValores().c_str());
  });

  //Rota que grava arquivo js no ESP32
  server.on("/index.js", HTTP_GET, [](AsyncWebServerRequest * request) {
    request->send(SPIFFS, "/index.js", "text/javascript");
  });

  //Iniciando servidor
  server.begin();
}


void loop() {

  juntarValores ();
  delay(100);

}
