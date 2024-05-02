
#define sensorPin A0
int timesTosend=1;
int count=0;
char phone_no[] = "xxxxxxx";  //phone number to alert

void setup()
{
//pinMode(sensorPin,INPUT);
Serial.begin(9600);  //Open Serial connection at baud 9600
delay(2000);
Serial.println("AT+CMGF=1"); //set GSM to text mode
delay(200);
}

void loop()
{
  int data = analogRead(sensorPin);
  if (data >= 200)
  {
while(count<timesTosend){
delay(1500);
Serial.print("ATD");; //Dial the phone number using ATD command
Serial.print(phone_no);
Serial.println(";"); // Semicolon is a must at the end
delay(10000);
Serial.println("ATH"); // After a delay of 5 secs Hang the call
delay(1000);

Serial.print("AT+CMGS=\"");
Serial.print(phone_no);
Serial.println("\"");

delay(1000);  // delay is must it waits for > symbol

Serial.print("CAUTION...FIRE ALARM !!!!!!!!!!");  //SMS body
Serial.write(0x1A);  // sends ctrl+z end of message
//Serial.write(0x0D);  // Carriage Return in Hex
//Serial.write(0x0A);  // Line feed in Hex

//The 0D0A pair of characters is the signal for the end of a line and beginning of another.
delay(5000);
count++;
}
}
}

