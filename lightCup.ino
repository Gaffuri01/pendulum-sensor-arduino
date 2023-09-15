const int switchPinA = 8;     // Entrada do Sensor
int switchStateA = 0;         // Leitura do Sensor
int voltas = 0;         // Leitura do Sensor
int parou = 0;         // Leitura do Sensor

const int IN3 = 7; //Pino IN3 da ponte H deve ser conectado ao pino 7 do Arduino
const int IN4 = 6; //Pino IN4 da ponte H deve ser conectado ao pino 6 do Arduino
const int ENB = 5; //Pino ENB da ponte H deve ser conectado ao pino 5 do Arduino


void setup() {
  // pinMode(motor, OUTPUT);     // Set Motor as output
  pinMode(switchPinA, INPUT); // Set Sensor as input
  Serial.begin(9600);         // Instancia o Serial
  Serial.println("-- CONTROLE DE MOTORES DC COM DRIVER PONTE H L298N --");

  pinMode(IN3, OUTPUT); //Define o pino IN3 como um pino de saída
  pinMode(IN4, OUTPUT); //Define o pino IN4 como um pino de saída
  pinMode(ENB, OUTPUT); //Define o pino ENB como um pino de saída

}

void loop() {
  switchStateA = digitalRead(switchPinA);  // Read switch state
  Serial.println(switchStateA);            // Mostra o valor coletado

  // Caso a bolinha de mercúrio esteja longe do circuito
  if(switchStateA != 0){
    // descer(); // Correto
    sobe();
  // Caso a bolinha de mercúrio esteja ligando o circuito
  } else {
    if(parou == 1){
      parar();

    } else {
      if(voltas < 0){
        sobe();
      }
    }
  }

  delay(250);                         // tempo de repetição do código
}

void descer() {
  parou = 1;
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

  analogWrite(ENB, 100); // velocidade de giro
  voltas = voltas + 1;
}

void sobe() {
  parou = 0;
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  analogWrite(ENB, 100); // velocidade de giro
  
  voltas = voltas - 1;
}

void parar() {
  parou = 0;
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

// Assinador do código
// char ligar;
// Serial.available() //
// ligar = Serial.read()