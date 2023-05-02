// Importando bibliotecas
#include "WiFi.h"
#include "ESPAsyncWebServer.h"
#include "SPIFFS.h"

// Credenciais da rede
const char* ssid = "ESP32";
const char* password = "12345678";

// Criando objeto de AsyncWebServer na porta 80
AsyncWebServer server(80);
 
void setup(){
  // Porta serial port para debug
  Serial.begin(115200);

  // Iniciando SPIFFS
  if(!SPIFFS.begin(true)){
    Serial.println("An Error has occurred while mounting SPIFFS");
    return;
  }

  // Conectando no  Wi-Fi
  WiFi.softAP(ssid, password); //Criando access point com credenciais
  IPAddress IP = WiFi.softAPIP(); //Pegando IP
  Serial.println("Access point iniciado");
  Serial.print("Endereço de IP (access point): ");
  Serial.println(IP); //mostrando ID no monitor Serial


  // Mostrando endereço de IP local do ESP32
  Serial.println(WiFi.localIP());

  // Rota para web páginas (que carregam arquivos externos .html)
  server.on("/index.html", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/index.html", "text/html");
  });

  server.on("/sobre.html", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/sobre.html", "text/html");
  });

  server.on("/contato.html", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/contato.html", "text/html");
  });
  

  //Rotas que carregam arquivos externos .css
  
  server.on("/index.css", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/index.css", "text/css");
  });

  server.on("/sobre.css", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/sobre.css", "text/css");
  });

  server.on("/contato.css", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/contato.css", "text/css");
  });

  //Rotas que carregam arquivos externos .js
  
  server.on("/index.js", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/index.js", "text/javascript");
});


  // Inicia servidor
  server.begin();
}
 
void loop(){
  
}
