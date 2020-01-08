// LED vars 
const int ledPin = 13;

// LED read vars
String inputString = "";         // a string to hold incoming data
boolean toggleComplete = false;  // whether the string is complete 

int GNDPin=A4; //Set Analog pin 4 as GND
int VccPin=A5; //Set Analog pin 5 as VCC
int Q1=9; //Output pin connected to 10 Encoder IC
int Q2=10; //Output pin connected to 11 Encoder IC
int Q3=11; //Output pin connected to 12 Encoder IC
int Q4=12; //Output pin connected to 13 Encoder IC
void setup() {
  // initialize serial:
  Serial.begin(9600);
  // init LEDS
  pinMode(LED_BUILTIN,OUTPUT);
  digitalWrite(LED_BUILTIN,0);
  pinMode(Q1,OUTPUT);
  pinMode(Q2,OUTPUT);
  pinMode(Q3,OUTPUT);
  pinMode(Q4,OUTPUT);
  pinMode(GNDPin, OUTPUT);
  pinMode(VccPin, OUTPUT);
  digitalWrite(GNDPin, LOW); //Set A4 pin LOW
  digitalWrite(VccPin, HIGH); //Set A5 pin HIGH
}

void loop() {
   // Recieve data from Node and write it to a String
   while (Serial.available() && toggleComplete == false) {
    char inChar = (char)Serial.read();
    if(inChar == 'E'){ // end character for led
     toggleComplete = true;
    }
    else{
      inputString += inChar; 
    }
  }
  if(!Serial.available() && toggleComplete == true)
  {
    // convert String to int. 
    int recievedVal = stringToInt();
    digitalWrite(LED_BUILTIN,1);
    if(recievedVal == 0) //Forward
    {
      digitalWrite(Q1,HIGH); 
      digitalWrite(Q2,LOW);  
      digitalWrite(Q3,HIGH); 
      digitalWrite(Q4,LOW);
    }
    else if(recievedVal == 1) //Left
    {
      digitalWrite(Q1,HIGH); 
      digitalWrite(Q2,LOW);  
      digitalWrite(Q3,LOW);  
      digitalWrite(Q4,LOW);
    }
    else if(recievedVal == 2) //Right
    {
      digitalWrite(Q1,LOW); 
      digitalWrite(Q2,LOW);  
      digitalWrite(Q3,HIGH);  
      digitalWrite(Q4,LOW);
    }
    else if(recievedVal == 3) //Backward
    {
      digitalWrite(Q1,LOW);  
      digitalWrite(Q2,HIGH); 
      digitalWrite(Q3,LOW);  
      digitalWrite(Q4,HIGH);
    }
    else if(recievedVal == 4) //Stop
    {
      digitalWrite(Q1,LOW); 
      digitalWrite(Q2,LOW);  
      digitalWrite(Q3,LOW);  
      digitalWrite(Q4,LOW);
    }    
    toggleComplete = false;
  }
  // Dim LED 3
    
  delay(50); // give the Arduino some breathing room.
  digitalWrite(LED_BUILTIN,0);
}

int stringToInt()
{
    char charHolder[inputString.length()+1];
    inputString.toCharArray(charHolder,inputString.length()+1);
    inputString = "";
    int _recievedVal = atoi(charHolder);
    return _recievedVal;
}