#include <NewPing.h>

#define TRIG_PIN1 2
#define ECHO_PIN1 3
#define MAX_DISTANCE 400 

NewPing sonar1(TRIG_PIN1, ECHO_PIN1, MAX_DISTANCE);

void setup() {
  Serial.begin(9600);
}

void loop() {
  delay(50);
  unsigned int distance1 = sonar1.ping_cm();

  Serial.print("Distance: ");
  Serial.print(distance1);
  Serial.println(" cm");
}
