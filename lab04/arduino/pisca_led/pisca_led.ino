// a funcao setup roda apenas uma vez, quando a placa eh alimentada
// ou o botao reset eh pressionado
void setup() {
  Serial.begin(9600, SERIAL_8N1);   // configura a comunicacao serial
  pinMode(LED_BUILTIN, OUTPUT);     // inicializa o pino digital LED_BUILTIN (pino 13) como saida
  Serial.write("Final da configuracao. Saida no pino %d.\n",LED_BUILTIN); // envia uma mensagem pela comunicacao serial
}

// a funcao loop roda sem parar...
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);  // liga o LED
  delay(1000);                      // espera 1000ms
  digitalWrite(LED_BUILTIN, LOW);   // desliga o LED
  delay(300);                       // espera 300ms
  digitalWrite(LED_BUILTIN, HIGH);  // liga o LED
  delay(300);                       // espera 300ms
  digitalWrite(LED_BUILTIN, LOW);   // desliga o LED
  delay(300);                       // espera 300ms
}

