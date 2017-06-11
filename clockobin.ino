/*clockôbin by kerblock
   Date : 11/06/17
   Description : A clock for your mind. Display time in binary with leds.
*/

byte hour;
byte minute;
byte second;

boolean leds_test = false;

//D2->D6 = leds hours
//D7->D12 = leds minutes
void setup() {
  Serial.begin(9600);
  hour = 17;
  minute = 57;
  second = 30;

  for (byte i = 2; i <= 6; i++){
    pinMode(i, OUTPUT);
    if (leds_test){
    digitalWrite(i, HIGH);
    delay(500);
    digitalWrite(i, LOW);
    }
  }
  for (byte i = 7; i <= 12; i++){
    pinMode(i, OUTPUT);
    if (leds_test){
    digitalWrite(i, HIGH);
    delay(500);
    digitalWrite(i, LOW);
    }
  }
}

void loop() {
  updateTime();
  ledsRouter();
}

void updateTime(){
  delay(1000);
  second++;
  if (second > 59){
    second = 0;
    minute++;
  }
  if (minute > 59){
    minute = 0;
    hour++;
  }
  if (hour > 23){
    hour = 0;
  }
}

void ledsRouter(){
  String strH = String(hour, BIN);
  String strM = String(minute, BIN);

  //hour loop
  for (int i = 0; i < strH.length(); i++){
      if (strH.charAt(i) == '0'){
        digitalWrite(6-i, LOW);
      }
      else{
        digitalWrite(6-i, HIGH);
      }
    }

  //minute loop
  for (int i = 0; i < strM.length(); i++){
     if (strM.charAt(i) == '0'){
        digitalWrite(12-i, LOW);
      }
      else{
        digitalWrite(12-i, HIGH);
      }
  }
}
