// programa baseado no codigo disponibilizado em:
// Derek Molloy, Exploring Raspberry Pi: Interfacing to the Real World with Embedded Linux,
// Wiley 2016, ISBN 978-1-119-1868-1, http://www.exploringrpi.com/

void setup() {
   // Configurando a serial
   // Baud rate de 115200, 8-bit, sem paridade, 1 stop bit
   Serial.begin(115200, SERIAL_8N1);
}

void loop() {
   byte charIn;                  // cria uma variavel para armazenar o caractere recebido
   if(Serial.available()){       // verifica se recebeu algo pela serial
      charIn = Serial.read();    // le o caractere recebido
      Serial.write(charIn);      // envia o caractere recebido
   }
}

