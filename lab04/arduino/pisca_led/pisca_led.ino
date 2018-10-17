// a funcao setup roda apenas uma vez, quando a placa eh alimentada
// ou o botao reset eh pressionado
void setup() {
  // inicializa o pino digital LED_BUILTIN como saida
  pinMode(LED_BUILTIN, OUTPUT);
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

