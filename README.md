#

![simplinnovation](https://4.bp.blogspot.com/-f7YxPyqHAzY/WJ6VnkvE0SI/AAAAAAAADTQ/0tDQPTrVrtMAFT-q-1-3ktUQT5Il9FGdQCLcB/s350/simpLINnovation1a.png)

# Arduino MKR1000 & Thinger

### A simple IoT (Internet of Things) experiment using __Arduino/Genuino MKR1000__ and __Thinger__ IoT platform. Watch the video below ([click here](https://www.youtube.com/watch?v=7Keu0omKs7U)) to see its action, then follow the instructions to build your own!

#

[![Video MKR1000 Thinger](https://img.youtube.com/vi/7Keu0omKs7U/0.jpg)](https://www.youtube.com/watch?v=7Keu0omKs7U)

#

### **1. What You Need** :gift:

To build this project, you need the following items:
- 1 Arduino/Genuino MKR1000 board
- 2 LEDs
- 1 Potentiometer
- 1 breadboard
- some jumper wires
- Arduino IDE ([download here](https://www.arduino.cc/en/Main/Software))
- WiFi101 library ([download here](https://www.arduino.cc/en/Reference/WiFi101))
- Thinger library ([download here](https://github.com/thinger-io/Arduino-Library))

#

### **2. Setup Virtual Device on Thinger** :iphone:

- First, you have to sign up or login to [Thinger.io](https://thinger.io/). Then create a virtual device: click __Devices__ menu, and click __+Add Device__ button. Fill out the forms: __Device Id, Device description__ & __Device credentials__, then click __Add Device__.
  
  ![Setup_Thinger_Device](https://raw.githubusercontent.com/LintangWisesa/Arduino_MKR1000_Thinger/master/img/1_Setup_Thinger_Device.png)

#

### **3. Schematics** :wrench::hammer:

- Connect your parts to Arduino MKR1000 as the following picture:

  ![schematics](https://raw.githubusercontent.com/LintangWisesa/Arduino_MKR1000_Thinger/master/img/Schematics.png)

#

### **4. Sketch** :clipboard:
 
- Make sure the __WiFi101__ & **Thinger** library are installed. Open Arduino IDE then copy the sketch below. Insert your __Thinger username, Device ID, Device Credentials, WiFi name__ & __WiFi password__. Make sure you have chosen the right option for **_Board_** and **_Port_** under **_Tools_** menu. Upload it!

    ```c++
    #define _DISABLE_TLS_
    #include <WiFi101.h>
    #include <ThingerWifi101.h>

    #define USERNAME "your_thinger_username"    // Thinger username
    #define DEV_ID "your_device_id"             // Thinger device ID
    #define DEV_CRED "your_device_credential"   // Thinger device credential

    #define SSID "your_wifi_name"               // wifi SSID
    #define SSID_PASSWORD "your_wifi_password"  // wifi password

    ThingerWifi101 thing(USERNAME, DEV_ID, DEV_CRED);

    void setup() {
        pinMode(0, OUTPUT);
        thing.add_wifi(SSID, SSID_PASSWORD);
        thing["led"] << digitalPin(0);
        thing["led2"] << analogPin(1);
        thing["pot"] >> outputValue(analogRead(A0));
    }

    void loop() {
        thing.handle();
    }
    ```

#

### **5. Setup Dashboard on Thinger** :iphone:

- Go to __Dashboards__ menu & click __+Add Dashboard__ button. Then fill out the forms: __Dashboard Id, Dashboard name__ & __Dashboard description__, then click **Add Dashboard** button.
  
  ![Setup_Thinger_Dashboard](https://raw.githubusercontent.com/LintangWisesa/Arduino_MKR1000_Thinger/master/img/2_Setup_Thinger_Dashboard.png)

- Go to your dashboard, then create widgets to control and/or monitor your device. On your dashboard click __+Add Widget__ & feel free to use any Thinger's widgets. On this project, I use:
  - __On/Off State__ (_to control my LED on/off_),
  - __Slider__ (_to control the brightness of my LED_),
  - __Donut Chart__ (_show my potentiometer value as a gauge_), and
  - __Time Series Chart__ (_show my potentiometer value as a bar graph_). 

  ![Setup_Thinger_Dashboard](https://raw.githubusercontent.com/LintangWisesa/Arduino_MKR1000_Thinger/master/img/3_Setup_Thinger_Widget.png)

#

### **6. Have Fun!** :sunglasses:

- After everything is done, make sure your Arduino MKR1000 has a good internet connection. On your Thinger's dashboard you can control your LEDs & monitor your potentiometer value! Have fun! 

#

#### Lintang Wisesa :love_letter: _lintangwisesa@ymail.com_

[Facebook](https://www.facebook.com/lintangbagus) |
[Twitter](https://twitter.com/Lintang_Wisesa) |
[Google+](https://plus.google.com/u/0/+LintangWisesa1) |
[Youtube](https://www.youtube.com/user/lintangbagus) | 
:octocat: [GitHub](https://github.com/LintangWisesa) |
[Hackster](https://www.hackster.io/lintangwisesa)

