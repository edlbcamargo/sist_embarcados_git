// programa baseado no codigo disponibilizado em:
// Derek Molloy, Exploring Raspberry Pi: Interfacing to the Real World with Embedded Linux,
// Wiley 2016, ISBN 978-1-119-1868-1, http://www.exploringrpi.com/

int ledPin = 11;          // LED com controle de brilho por PWM

void setup() {
   // Configura a serial: baud rate de 115200, 8-bit, sem paridade, 1 stop bit
   Serial.begin(115200, SERIAL_8N1);
   pinMode(ledPin, OUTPUT);                    // configura o pino do LED como saida
}

void loop() {
   String command;
   char buffer[100];                           // buffer para guardar a mensagem de resposta
   if (Serial.available()>0){                 // verifica se recebeu algum comando
      command = Serial.readStringUntil('\0'); // Strings em C terminam com \0
      if(command.substring(0,4) == "LED "){    // comeca com "LED "?
         String intString = command.substring(4, command.length()); // retira "LED " do comando
         int level = intString.toInt();        // converte o restante do comando para inteiro
         if(level>=0 && level<=255){           // verifica se eh um numero valido
            analogWrite(ledPin, level);        // escreve no PWM o valor desejado
            sprintf(buffer, "Brilho do LED ajustado para %d", level);
         }
         else{                                 // nao eh um numero valido
            sprintf(buffer, "Erro: %d esta fora da faixa valida.", level);
         } 
      }                                        // comando nao reconhecido
      else{ sprintf(buffer, "Comando incorreto: %s", command.c_str()); }
      Serial.print(buffer);                   // envia o buffer para a RaspberryPi
   }
}
