//-------------------Bibliotecas utilizadas-------------------

#include "SPIFFS.h"
#include <WebServer.h>

//------------------------DAC-----------------------
/* Definição do canal DAC0 (GPIO 25) */
/*
#define CANAL_DAC0 25

//variáveis utilizadas para gerar uma onda triângular
bool turn = 0;
uint16_t sinal = 0;
uint32_t time_old = 0;
*/

//----------------------WebServer------------------------

// Credenciais do Access Point
const char *ssid = "ESP32";
const char *password = "12345678";

// Porta do Web Server
WebServer server(80);


//--------------------Leitura Analógica----------------------

// pino do ESP32 correspondente a leitura analógica
const int pinoAnalogico = 34;

// quantidade de valores capturados de uma vez
const int quantValoresCapturados = 1000;
// vetor com valores capturados por vez
int valoresAnalog_capturados[quantValoresCapturados];
// valores serão inseridos dentro de uma string
String valores = "";
String voltagem = "";
float tempoCapturaValores = 10; //delayMicroseconds
float novo_tempoCapturaValores = 0;


//--------------------------------------------------------

// Função que captura valores e formata como uma string
String juntarValores()
{

  if (novo_tempoCapturaValores==0){
      tempoCapturaValores = 10;   //delayMicroseconds
  } else { 
      tempoCapturaValores = novo_tempoCapturaValores;                     
  }   
    //Serial.println(tempoCapturaValores);

  valores = "{";

  for (int i = 0; i < quantValoresCapturados; i++)
  {
    valores += '"';
    valores += "valor";
    valores += i;
    valores += '"';
    valores += ':';
    valoresAnalog_capturados[i] = analogRead(pinoAnalogico);

    delayMicroseconds(tempoCapturaValores);
    
    valores += valoresAnalog_capturados[i];

    if (i < quantValoresCapturados - 1)
    {
      valores += ',';
    }
  }
  valores += "}";
  return valores;
}

//---------------------Definição do conteudo de cada página---------------------

void pag_index()
{                                                   // Sub-rotina para caso o servidor fique online
  server.send(200, "text/html", html_index(juntarValores(),tempoCapturaValores)); // Envia ao servidor, em formato HTML, o script, com os parâmetros de pressão e temperatura
}

void pag_sobre()
{                                                   // Sub-rotina para caso o servidor fique online
  server.send(200, "text/html", html_sobre()); // Envia ao servidor, em formato HTML, o script, com os parâmetros de pressão e temperatura
}

void pag_contato()
{                                                   // Sub-rotina para caso o servidor fique online
  server.send(200, "text/html", html_contato()); // Envia ao servidor, em formato HTML, o script, com os parâmetros de pressão e temperatura
}

void valores_Debug()
{                                                      // Sub-rotina para caso o servidor fique online
  server.send(200, "text/plain", juntarValores().c_str()); // Envia ao servidor, em formato HTML, o script, com os parâmetros de pressão e temperatura
}

void nao_encontrado()
{                                               // Sub-rotina para caso seja retornado um erro
  server.send(404, "text/plain", "Não encontrado"); // Retorna a mensagem de erro em caso de um retorno 404
}

//----------------------------------------------------------------------------


//Tempo/DIV
void capturaTempo (){ //define novo valor de delay na captura de valores
  String tempo = server.arg("tempoNovo"); //captura variavel do html_index
  novo_tempoCapturaValores = tempo.toFloat();
  //Serial.println(tempoNovo);
  server.sendHeader("Location","/"); //redirecina para página default
  server.send(302, "text/plain", "redirecionado");
}


//----------------------------------------------------------------------------

void setup()
{
  Serial.begin(115200);
  analogReadResolution(12); // resolução de 12 bits do ADC

  // ---------------Iniciando SPIFFS---------------
  if (!SPIFFS.begin(true))
  {
    Serial.println("Ocorreu um erro na criação do SPIFFS");
    return;
  }

  // ---------------Connectando WI-FI---------------
  WiFi.softAP(ssid, password);
  IPAddress IP = WiFi.softAPIP();
  Serial.print("Endereço IP - Access Point: ");
  Serial.println(IP);
  Serial.println(WiFi.localIP());

  // ---------------Rota das páginas---------------
  server.on("/", pag_index);
  server.on("/sobre", pag_sobre);
  server.on("/contato", pag_contato);
  server.on("/texto", valores_Debug);

  server.on("/frequencia", capturaTempo);  
  
  server.onNotFound(nao_encontrado);
  server.begin(); // Inicia o servidor
  Serial.println("Servidor Online");
}

void loop()
{
  //para teste:
  /*
  if (micros() - time_old >= 10)
  {
    // Atualiza a variável para a próxima iteração
    time_old = micros();

    //************************************************
    // Gera uma onda triangular de 1KHz no pino 25
    if (turn == 0)
    {
      sinal += 5;
      if (sinal >= 255)
      {
        turn = 1;
      }
    }

    else if (turn == 1)
    {
      sinal -= 5;
      if (sinal == 0)
      {
        turn = 0;
      }
    }
    // Escreve o valor no DAC (0 - 255)
    dacWrite(CANAL_DAC0, sinal);
    //***********************************************
  }
  */

  server.handleClient();
}
