/* Definição do canal DAC0 (GPIO 25) */
#define CANAL_DAC0 25

bool turn = 0;
uint16_t sinal = 0;
uint32_t time_old = 0;

void setup() {
  Serial.begin(115200);
  analogReadResolution ( 12 ); // resolução de 12 bits do ADC
}

void loop() {

  //Executa este if a cada 10us
  if (micros() - time_old >= 10) {

    //Atualiza a variável para a próxima iteração
    time_old = micros();

    //************************************************
    //Gera uma onda triangular de 1KHz no pino 25
    if (turn == 0) {
      sinal += 5;
      if (sinal >= 255) {
        turn = 1;
      }
    }

    else if (turn == 1) {
      sinal -= 5;
      if (sinal == 0) {
        turn = 0;
      }
    }
    //Escreve o valor no DAC (0 - 255)
    dacWrite(CANAL_DAC0, sinal);
    //***********************************************

    //***********************************************
    //Faz a leitura do canal ADC pino 34 e apresenta no monitor serial
    Serial.println(analogRead(34));
    //***********************************************
  }
}
