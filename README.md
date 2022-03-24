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

-https://www.facebook.com/profile.php?id=100002145048612-
-https://www.instagram.com/farkadadnan/
-https://www.linkedin.com/in/farkad-adnan-499972121/

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
You can download the program here: RadioFM v1.0
Is required Microsoft .NET Framework 3.5 or above.
![screenradio1](https://user-images.githubusercontent.com/35774039/160005490-a35d66d7-be41-4145-9bbd-1620a23f1eca.jpg)
![screenradio2](https://user-images.githubusercontent.com/35774039/160005492-acc3fd84-b7ea-4407-abb3-e57301d57060.jpg)


# Code Arduino
'''

'''

