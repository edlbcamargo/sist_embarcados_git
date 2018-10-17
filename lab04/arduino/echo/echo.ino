void setup() {
   // Configurando a serial
   // Baud rate de 115200, 8-bit, sem paridade, 1 stop bit
   Serial.begin(115200, SERIAL_8N1);
}

void loop() {
   byte charIn;                  // cria uma variavel para armazenar o caracter recebido
   if(Serial.available()){       // verifica se recebeu algo pela serial
      charIn = Serial.read();    // le o caracter recebido
      Serial.write(charIn);      // envia o caracter recebido
   }
}

