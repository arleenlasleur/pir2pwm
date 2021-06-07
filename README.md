# pir2pwm
PWM LED strip control from HC-SR04 PIR sensor

Parts used:
* Basic Arduino NG (atmega8a, 2x 22pF, 0.1 uF, 10k, 16 MHz crystal)
* any DCDC 12V to 5V converter
* more caps (ceramic+electrolyte)
* IRFZ48N, no matter fake or not
* wires for jumpers

Stay on time: defined in MAX_NO_MOTION (ms)  
Turnon time: STEP_LEVEL * 64 (ms)
