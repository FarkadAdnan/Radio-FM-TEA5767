/*
 By:Farkad Adnan
 E-mail: farkad.hpfa95@gmail.com
 inst : farkadadnan
 #farkadadnan , #farkad_adnan , فرقد عدنان#
 FaceBook: كتاب عالم الاردوينو
 inst : arduinobook
 #كتاب_عالم_الاردوينو  #كتاب_عالم_الآردوينو 
 */
#include <TEA5767.h>
#include <Wire.h>
TEA5767 Radio; 
double old_frequency;
double frequency;
int search_mode = 0;
int search_direction;
unsigned long last_pressed;
unsigned char buf[5];
int stereo;
int signal_level;
double current_freq;
unsigned long current_millis = millis();
int inByte;
int flag=0;
void setup () {
  Serial.begin(9600);
  Radio.init();
  Radio.set_frequency(95.2); 
}
void loop () {
  if (Serial.available()>0) {
    inByte = Serial.read();
    if (inByte == '+' || inByte == '-'){  //accept only + and - from keyboard
      flag=0;
    }}
  if (Radio.read_status(buf) == 1) {
     current_freq =  floor (Radio.frequency_available (buf) / 100000 + .5) / 10;
     stereo = Radio.stereo(buf);
     signal_level = Radio.signal_level(buf);
     if(flag == 0){
      Serial.print("Current freq: ");
      Serial.print(current_freq);
      Serial.print("MHz Signal: ");
      //Strereo or mono ?
      if (stereo){
        Serial.print("STEREO "); 
      } 
    else{
      Serial.print("MONO ");
    } 
      Serial.print(signal_level);
      Serial.println("/15");
      flag=1;
     }
  }
   
  if (search_mode == 1) {
      if (Radio.process_search (buf, search_direction) == 1) {
          search_mode = 0;
      } }
  if (inByte == '+') {
    last_pressed = current_millis;
    search_mode = 1;
    search_direction = TEA5767_SEARCH_DIR_UP;
    Radio.search_up(buf);
  }
  if (inByte == '-') {
    last_pressed = current_millis;
    search_mode = 1;
    search_direction = TEA5767_SEARCH_DIR_DOWN;
    Radio.search_down(buf);
  } 
  delay(500);   
}
