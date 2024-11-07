// GLOBAL VARIABLE
int led1 = 2;  
int led2 = 3;
int led3 = 4;
int led4 = 5;
int led5 = 6;

int delayperiod=1000;
  
void setup() {              //THIS SETUP CODE RUNS ONCE
 
  pinMode( led1, OUTPUT);   //INTIALIZES THE DIGITAL PINS AS OUTPUT
  pinMode( led2, OUTPUT);   //INTIALIZES THE DIGITAL PINS AS OUTPUT
  pinMode( led3, OUTPUT);   //INTIALIZES THE DIGITAL PINS AS OUTPUT
  pinMode( led4, OUTPUT);   //INTIALIZES THE DIGITAL PINS AS OUTPUT
  pinMode( led5, OUTPUT);   //INTIALIZES THE DIGITAL PINS AS OUTPUT

  Serial.begin(9600);       //FOR DATA TRANSMISSION TO SERIAL MONITOR

}

void loop() {   //THIS MAIN CODE RUNS REPEATEDLY
  
  Serial.println("LED 1 is ON ");    //INDICATES LED 1 IS ON (SERIAL MONITOR)
  
  digitalWrite(led1, HIGH);          //TURNS LED ON
  delay(1000);                       //WAIT 1,0 SECOND
  
  digitalWrite(led1, LOW);           //TURNS LED OFF
  
  Serial.println("LED 2 is ON ");    //INDICATES LED 2 IS ON (SERIAL MONITOR)
  
  digitalWrite(led2, HIGH);          //TURNS LED ON
  delay(1000);                       //WAIT 1.0 SECONDS
  
  digitalWrite(led2, LOW);           //TURNS LED ON
                                  
  Serial.println("LED 3 is ON ");    //INDICATES LED 3 IS ON (SERIAL MONITOR)
  
  digitalWrite(led3, HIGH);          //TURNS LED ON
  delay(1000);                       //WAIT 1.0 SECOND
  
  digitalWrite(led3, LOW);           //TURNS LED OFF
  
  Serial.println("LED 4 is ON ");    //INDICATES LED 4 IS ON (SERIAL MONITOR)
  
  digitalWrite(led4, HIGH);          //TURNS LED ON
  delay(1000);                       //WAIT 1.0 SECONDS
  
  digitalWrite(led4, LOW);           //TURNS LED OFF
  
  Serial.println("LED 5 is ON ");    //INDICATES LED 5 IS ON (SERIAL MONITOR)
  
  digitalWrite(led5, HIGH);          //TURNS LED ON
  delay(1000);                       //WAIT 1.0 SECOND
  
  digitalWrite(led5, LOW);           //TURNS LED OFF
  
}