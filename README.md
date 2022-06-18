# Radio-FM-TEA5767
The TEA5767 is a cheap FM receiver that is controlled through the I2C bus.  

Chapter 3 code_Project_74 The second part 2 of "The Arduino World Book" code_Project_74
 
- code_Project_74
-  By:Farkad Adnan فرقد عدنان - 
 -E-mail: farkad.hpfa95@gmail.com 
-inst : farkadadnan 
- #farkadadnan , #farkad_adnan , فرقد عدنان# 
- FaceBook: كتاب عالم الاردوينو 
- inst : arduinobook
1. #كتاب_عالم_الاردوينو
2. #كتاب_عالم_الآردوينو

* facebook : https://www.facebook.com/profile.php?id=100002145048612
* instagram:  https://www.instagram.com/farkadadnan/
* linkedin : https://www.linkedin.com/in/farkad-adnan-499972121/

 <p>
 <a href='https://mobile.twitter.com/farkadadnan'>
        <img alt="Twitter Follow" src="https://img.shields.io/twitter/follow/farkadadnan?label=%40farkadadnan&style=social" alt='Twitter' align="center"/>
    </a>
</p>

# Introduction

The TEA5767 is a cheap FM receiver that is controlled through the I2C bus

# Required Components

* mbed
* module TEA5767
* audio 3.5mm plug jack

![1](https://user-images.githubusercontent.com/35774039/160004013-f579c02d-607e-4abc-9def-23e16b8562c8.JPG)

# Product Specifications

* Input Voltage 3.3V
* I2C (required 10k pull-up resistrors)
* 32.768 kHz clock crystal

# Pin Description
Name	TEA5767 pin	MBED pin
SDA	1	P28
SCL	2	P27
BUSMODE	3	GND
W/R	4	NC
VCC	5	VOUT
GND	6	GND
R-OUT	7	--
L-OUT	8	--
MPXO	9	NC
ANT	10	--

# How it works
*  يعمل مستقبل المتغاير الفائق في هذا الوضع: يتم ترشيح الإشارة من الهوائي وتضخيمها ، ثم يتم خلط الإشارة بموجة جيبية ناتجة عن مذبذب محلي (LO) والتي تحولها إلى تردد وسيط محدد (IF). يتم ترشيح إشارة IF نفسها وتضخيمها وربما معالجتها بطرق إضافية. يستخدم مزيل التشكيل إشارة IF بدلاً من تردد الراديو الأصلي لإعادة إنشاء نسخة من المعلومات الأصلية.
* The superheterodyne receiver works in this mode: the signal from the antenna is filtered and amplified, then the signal is mixed with a sine wave pruduced from a local oscillator (LO) that shift it to a specific intermediate frequency (IF). The IF signal is itself filtered and amplified and possibly processed in additional ways. The demodulator uses the IF signal rather than the original radio frequency to recreate a copy of the original information.
 * The Frequency is calculated by the following formula that return a 14bits word:
![formula](https://user-images.githubusercontent.com/35774039/160005369-b63acc61-af8b-45ba-8cca-8689ee7b4657.jpg)

# C# Program
Contact me for the next program: RadioFM v1.0
Is required Microsoft .NET Framework 3.5 or above.
![screenradio1](https://user-images.githubusercontent.com/35774039/160005490-a35d66d7-be41-4145-9bbd-1620a23f1eca.jpg)
![screenradio2](https://user-images.githubusercontent.com/35774039/160005492-acc3fd84-b7ea-4407-abb3-e57301d57060.jpg)


# Code Arduino
```
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
```
# Results
![2](https://user-images.githubusercontent.com/35774039/160007438-f7db580f-5834-4f8d-b00b-b9379b22f7bc.JPG)

