// Smoke/Gas Detection using Arduino UNO + MQ-4 + LED + Buzzer

const int gasSensor = A0;    // MQ-4 AO pin
const int led = 8;           // LED pin
const int buzzer = 9;        // Buzzer pin

int gasValue = 0;
int threshold = 280;         // Adjust if needed

void setup() {
  pinMode(led, OUTPUT);
  pinMode(buzzer, OUTPUT);

  digitalWrite(led, LOW);
  digitalWrite(buzzer, LOW);

  Serial.begin(9600);
}

void loop() {

  gasValue = analogRead(gasSensor);

  Serial.print("Gas Value: ");
  Serial.println(gasValue);

  if (gasValue > threshold) {

    digitalWrite(led, HIGH);
    digitalWrite(buzzer, HIGH);

    Serial.println("smoke Detected!");

  } else {

    digitalWrite(led, LOW);
    digitalWrite(buzzer, LOW);

    Serial.println("Safe");
  }

  delay(500);
}