int ledPin[7] ={7,8,9,10,11,12,13} ;  // choose the pin for the LED  
int val = 0;      // variable for reading the pin status  
char msg = '  ';   // variable to hold data from serial  
boolean h = true;  
  
void setup() {  
  for (int i = 0; i<7; i++)
  {
  pinMode(ledPin[i], OUTPUT);      // declare LED as output  
  }
  Serial.begin(9600);  
  Serial.print("Program Initiated\n");    
     digitalWrite(ledPin[2],HIGH);
}  
  
void loop(){  
        // While data is sent over serial assign it to the msg  
    while (Serial.available()>0){

        msg=Serial.read();  
    }  
 
  // Turn LED on/off if we recieve 'Y'/'N' over serial   
  if (msg=='M') {

for(int i = 0; i<=7; i++)
{
    pingPong();
}
   Serial.print("LED Activated\n");  
   msg=' ';  
  
}else if( msg == 'N'){
}
}


void pingPong()
{
  int index;
  int delayTime = 1000; // milliseconds to pause between LEDs
                       // make this smaller for faster switching
  
  // step through the LEDs, from 0 to 7
  
  for(index = 0; index <= 7; index++)
  {
    digitalWrite(ledPin[index], HIGH);  // turn LED on
    delay(delayTime);                    // pause to slow down
    digitalWrite(ledPin[index], LOW);   // turn LED off
  }

  // step through the LEDs, from 7 to 0
  
  for(index = 7; index >= 0; index--)
  {
    digitalWrite(ledPin[index], HIGH);  // turn LED on
    delay(delayTime);                    // pause to slow down
    digitalWrite(ledPin[index], LOW);   // turn LED off
  }
}
