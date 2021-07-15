#include <ESP8266httpUpdate.h>
#include "secret.h"

const char *ssid = WIFI_SSID;         // Set your router SSID
const char *password = WIFI_PASSWORD; // Set your router password

void setup() {
  delay(5000);
  Serial.begin(115200);
  Serial.print("aloha");
  WiFi.begin(ssid, password);
  /*connection to WiFi*/
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(1000);
  }

  Serial.println("Update Start");
  /* warning - the update is done after each reboot now */
  t_httpUpdate_return ret = ESPhttpUpdate.update(
      "http://192.168.2.166:3000/.pio/build/esp_wroom_02/firmware.bin");
  // Location of your binary file
  // t_httpUpdate_return  ret = ESPhttpUpdate.update("https://server/file.bin");
  /*upload information only */
  switch (ret) {
  case HTTP_UPDATE_FAILED:
    Serial.printf("HTTP_UPDATE_FAILD Error (%d): %s",
                  ESPhttpUpdate.getLastError(),
                  ESPhttpUpdate.getLastErrorString().c_str());
    break;
  case HTTP_UPDATE_NO_UPDATES:
    Serial.println("HTTP_UPDATE_NO_UPDATES");
    break;
  case HTTP_UPDATE_OK:
    Serial.println("HTTP_UPDATE_OK");
    break;
  }
}
void loop() {
  // ...
}