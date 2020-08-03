#include <Controllino.h>
int input1 = HIGH;
int input2 = HIGH;
int previous1 = HIGH;
int previous2 = HIGH;
long timepass1 = 0;
long timepass2 = 0;
long debounce1 = 1000;
long debounce2 = 200;

void setup() {
  pinMode(CONTROLLINO_D0, OUTPUT);
  pinMode(CONTROLLINO_D1, OUTPUT);
  pinMode(CONTROLLINO_D2, OUTPUT);
  pinMode(CONTROLLINO_D3, OUTPUT);
  pinMode(CONTROLLINO_D4, OUTPUT);
  pinMode(CONTROLLINO_A0, INPUT);
  pinMode(CONTROLLINO_A1, INPUT);

}
void loop() {
  input1 = digitalRead(CONTROLLINO_A0);
  input2 = digitalRead(CONTROLLINO_A1);
  if (input1 == LOW && previous1 == HIGH && millis() - timepass1 > debounce1) {
    if (digitalRead(CONTROLLINO_D0)==HIGH){
      digitalWrite(CONTROLLINO_D0, LOW);
      digitalWrite(CONTROLLINO_D3, LOW);
    }
    else {
      digitalWrite(CONTROLLINO_D0, HIGH);
      digitalWrite(CONTROLLINO_D3, HIGH);
    }
    timepass1 = millis();
  }
  if (input2 == LOW && previous2 == HIGH && millis() - timepass2 > debounce2 && digitalRead(CONTROLLINO_D0)==LOW) {
    digitalWrite(CONTROLLINO_D4, HIGH);
    digitalWrite(CONTROLLINO_D1, HIGH);
    delay(500);
    digitalWrite(CONTROLLINO_D2, HIGH);
    delay(500);
    digitalWrite(CONTROLLINO_D2, LOW);
    delay(1000);
    digitalWrite(CONTROLLINO_D1, LOW);
    digitalWrite(CONTROLLINO_D4, LOW);
    timepass2 = millis();
  }
  previous1 = input1;
  previous2 = input2;
}
