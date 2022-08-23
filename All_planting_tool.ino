

//Button
const int buttonPin = 9;     // the number of the pushbutton pin
int buttonState = 0;         // variable for reading the pushbutton status

//Leds 
const int ledpin_R = 4;      // LED RED connected to digital pin 4
const int ledpin_G = 5;      // LED RED connected to digital pin 5
const int ledpin_B = 6;      // LED RED connected to digital pin 6
const int delayt = 200;     // Miliseconds to wait for next color

//Humidity
const int sensorPin = A0;   // select input pin for the Humidity sensor.
int sensorValue = 0;  // variable to store the value coming from the sensor.
float a=-0.129;       // constant a to convert value into percentaje.
float b=131.97;       // constant a to convert value into percentaje.
float porcentaje;     // percentaje for Humidity.
const int low_hum=10;
const int normal_hum=80;


void setup() {
  // initialize digital Led pins as outputs.
  pinMode(ledpin_R, OUTPUT);
  pinMode(ledpin_G, OUTPUT);
  pinMode(ledpin_B, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
}

void loop() {

  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {

    sensorValue = analogRead(sensorPin);
    porcentaje=a*sensorValue+b;
    Serial.println(porcentaje);
    
    if (porcentaje<low_hum){
      digitalWrite(ledpin_R, HIGH);
      } 
    else {
      if (porcentaje>normal_hum){
         digitalWrite(ledpin_G, HIGH);        
        }
      else {                     
        digitalWrite(ledpin_B, HIGH);  }
      }
    
    delay(delayt);
  } else {
    // turn LED off:
    digitalWrite(ledpin_R, LOW);
    digitalWrite(ledpin_G, LOW);
    digitalWrite(ledpin_B, LOW);
  }


  

}
