#include <esp_now.h>
#include <WiFi.h>

// Replace with your RECEIVER MAC
uint8_t receiverMac[] = {0x7B, 0x1C, 0x3C, 0xB7, 0x7A, 0x28};

// Flex sensor pins
const int flexPin1 = 34;
const int flexPin2 = 35;  // choose the correct ADC pin on ESP32
const int flexPin3 = 32;
const int flexPin4 = 33;

typedef struct {
  int flex1;
  int flex2;
  int flex3;
  int flex4;
} Data;

Data data;

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);

  if (esp_now_init() != ESP_OK) {
    Serial.println("ESP-NOW Init Failed");
    return;
  }

  esp_now_peer_info_t peerInfo = {};
  memcpy(peerInfo.peer_addr, receiverMac, 6);
  peerInfo.channel = 0;
  peerInfo.encrypt = false;

  if (esp_now_add_peer(&peerInfo) != ESP_OK) {
    Serial.println("Failed to add peer");
    return;
  }
}

void loop() {
  // Read flex sensor values
  int flexValue1 = analogRead(flexPin1);
  int flexValue2 = analogRead(flexPin2);
  int flexValue3 = analogRead(flexPin3);
  int flexValue4 = analogRead(flexPin4);

  // Assign all values to struct
  data.flex1 = flexValue1;
  data.flex2 = flexValue2;
  data.flex3 = flexValue3;
  data.flex4 = flexValue4;

  // Send via ESP-NOW
  esp_err_t result = esp_now_send(receiverMac, (uint8_t *)&data, sizeof(data));

  if (result == ESP_OK) {
    Serial.print("Flex1: ");
    Serial.print(flexValue1);
    Serial.print(" | Flex2: ");
    Serial.print(flexValue2);
    Serial.print(" | Flex3: ");
    Serial.print(flexValue3);
    Serial.print(" | Flex4: ");
    Serial.println(flexValue4);
  } else {
    Serial.println("Error sending");
  }

  delay(200);
}
