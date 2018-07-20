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