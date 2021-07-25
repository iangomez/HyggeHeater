// digital relay pins
const int insolePin = 10;
const int fleecePin = 11;
const int numChannels = 2;

// user interface
const int insoleButtonPin = 2;  // pin for input of button for insole power
int insolePower = 1;            // current insole power mode
float insolePWM = 1;            //

const int fleeceButtonPin = 6;  // pin for input of button for insole power
int fleecePower = 1;            // current fleece power mode
float fleecePWM = 1;            // 

const int maxPower = 3;         // max number of power modes
const int period = 1000;        // time per power cycle
float insoleRecordTime = 0;     //
float fleeceRecordTime = 0;     // 

// rgb led pins
const bool rgbPower[3][3] = {{LOW, LOW, HIGH}, {HIGH, HIGH, HIGH}, {HIGH, LOW, LOW}};

const int redInsolePin = 3;
const int greenInsolePin = 5;
const int blueInsolePin = 6;

const int redFleecePin = 7;
const int greenFleecePin = 8;
const int blueFleecePin = 9;

// voltage monitoring and protection
int sampleDelay = 50;  // delay between samples (might want to use millis instead)
int numSamples = 15;   // number of samples for to take for voltage monitoring
int powerOn = 5;       // undervoltage protection counter
float vCutoff = 3.5;   // cutoff voltage
int timeOff = 600000;  // 600 seconds or 10 min of off time 

// mosfet test
//const int mosfetPin = 10;

// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(9600);

  // heater logic pins
  pinMode(insolePin, OUTPUT);
  pinMode(fleecePin, OUTPUT);
  
  // buttons to control heater modes
  pinMode(insoleButtonPin, INPUT);
  pinMode(fleeceButtonPin, INPUT);

  // set up rgb pins
  pinMode(redInsolePin, OUTPUT);
  pinMode(greenInsolePin, OUTPUT);
  pinMode(blueInsolePin, OUTPUT);
  pinMode(redFleecePin, OUTPUT);
  pinMode(greenFleecePin, OUTPUT);
  pinMode(blueFleecePin, OUTPUT);
  rgbColor(redFleecePin, greenFleecePin, blueFleecePin, rgbPower[0][0], rgbPower[0][1], rgbPower[0][2]);
  rgbColor(redInsolePin, greenInsolePin, blueInsolePin, rgbPower[0][0], rgbPower[0][1], rgbPower[0][2]);
  
  insoleRecordTime = millis();
  fleeceRecordTime = millis();
}

// the loop function runs over and over again forever
void loop() {
  monitorButton();
  insoleRecordTime = monitorPWM(insolePin, insoleRecordTime, insolePWM);
  fleeceRecordTime = monitorPWM(fleecePin, fleeceRecordTime, fleecePWM);
}
