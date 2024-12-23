#include <MX1508.h>

#define PINA 9
#define PINB 10
#define PINA2 3
#define PINB2 5
#define NUMPWM 2
#define PWM 255


/*
 * MX1508(uint8_t pinIN1, uint8_t pinIN2, DecayMode decayMode, NumOfPwmPins numPWM);
 * DecayMode must be FAST_DECAY or SLOW_DECAY,
 * NumOfPwmPins, either use 1 or 2 pwm. 
 * I recommend using 2 pwm pins per motor so spinning motor forward and backward gives similar response.
 * if using 1 pwm pin, make sure its pinIN1, then set pinIN2 to any digital pin. I dont recommend this setting because 
 * we need to use FAST_DECAY in one direction and SLOW_DECAY for the other direction.  
 */
 
MX1508 motorA(PINA,PINB, FAST_DECAY, NUMPWM);
MX1508 motorB(PINA2,PINB2, FAST_DECAY, NUMPWM);

void setup() {
 Serial.begin(9600); 
}
void loop() {
  if (Serial.available()) {
    String command = Serial.readStringUntil('\n');


    if (command == "UP") {
       motorA.motorGo(PWM);
      motorB.motorGo(PWM);
    } else if (command == "DOWN") {
       motorA.motorGo(-PWM);
       motorB.motorGo(-PWM);
    } else if (command == "STOP") {
       motorA.motorGo(0);
       motorB.motorGo(0);
    } else if (command == "LEFT") {
       motorA.motorGo(PWM);
       motorB.motorGo(-PWM);
    } else if (command == "RIGHT") {
       motorA.motorGo(-PWM);
       motorB.motorGo(PWM);
    }
  }
}
