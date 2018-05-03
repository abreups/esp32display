/*
  Exemplo de como escrever no display OLED do ESP32 com LoRa.

  Para que o display funcione, é necessário que o GPIO16 
  vá para 0 por pelo menos 5 ms e depois fique em 1.
  
*/

//biblioteca para comunicação com o display
#include "SSD1306.h"

// construtor do objeto do display
// parametros: address,SDA,SCL
// (Documentação da placa WiFi LoRa 32)
SSD1306 tela(0x3c, 4, 15); 

void setup() {
 //configura GPIO16 como saida
  pinMode(16,OUTPUT);       // GPIO16 como saída
  digitalWrite(16, LOW);    // reseta o OLED
  delay(10);                // aguarda pelo menos 5 ms
  digitalWrite(16, HIGH);   // mantém GPIO16 em 1 durante uso do OLED
  tela.init();           // inicializa o display
  tela.clear();          // limpa a tela do display
  
  tela.drawString(0, 0, "OLED display"); // prepara texto para o display
  tela.drawString(0, 10, "Linha 2");     // prepara texto para o display
  tela.drawString(10, 20, "deslocado");  // prepara texto para o display
  tela.display();                        // mostra o texto no display

  delay(5000);        // aguarda 5 s
  tela.clear();    // apaga texto que vai para o display
  tela.display();  // mostra o texto (vazio) no display
}

void loop() {
}


