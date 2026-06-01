#include <esp_now.h>
#include <WiFi.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

#define LED 2

// PCA9685 setup
#define I2C_SDA 32
#define I2C_SCL 33
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x40, Wire);

// Same pulse range for all servos
#define SERVO_MIN  150   // adjust for your servo
#define SERVO_MAX  600   // adjust for your servo

typedef struct {
  int flex1;
  int flex2;
  int flex3;
  int flex4;
} Data;

Data data;

void onReceive(const esp_now_recv_info *info, const uint8_t *incomingData, int len) {
  memcpy(&data, incomingData, sizeof(data));

  // Print all 4 flex sensor values
  Serial.print("Flex1: "); Serial.print(data.flex1);
  Serial.print(" | Flex2: "); Serial.print(data.flex2);
  Serial.print(" | Flex3: "); Serial.print(data.flex3);
  Serial.print(" | Flex4: "); Serial.println(data.flex4);

  // Blink LED
  digitalWrite(LED, HIGH);
  delay(100);
  digitalWrite(LED, LOW);

  // Flex1 → Servo channel 0
  int angle1 = map(data.flex1, 3000, 4085, 0, 180);
  int pulse1 = map(angle1, 0, 180, SERVO_MIN, SERVO_MAX);
  pwm.setPWM(0, 0, pulse1);
  Serial.print("Servo1 Angle: "); Serial.println(angle1);

  // Flex2 → Servo channel 1
  int angle2 = map(data.flex2, 3000, 3650, 0, 180);
  int pulse2 = map(angle2, 0, 180, SERVO_MIN, SERVO_MAX);
  pwm.setPWM(1, 0, pulse2);
  Serial.print("Servo2 Angle: "); Serial.println(angle2);

  // Flex3 → Servo channel 2
  int angle3 = map(data.flex3, 3000, 3880, 0, 180);
  int pulse3 = map(angle3, 0, 180, SERVO_MIN, SERVO_MAX);
  pwm.setPWM(2, 0, pulse3);
  Serial.print("Servo3 Angle: "); Serial.println(angle3);

  // Flex4 → Servo channel 3 (threshold-based snap)
  int angle4;
  if (data.flex4 > 3000) {
    angle4 = 180;   // lock at 180° if flex > 3000
  } else {
    angle4 = 0;     // lock at 0° otherwise
  }

  int pulse4 = map(angle4, 0, 180, SERVO_MIN, SERVO_MAX);
  pwm.setPWM(3, 0, pulse4);
  Serial.print("Servo4 Angle: "); Serial.println(angle4);
}

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);

  pinMode(LED, OUTPUT);

  if (esp_now_init() != ESP_OK) {
    Serial.println("ESP-NOW Init Failed");
    return;
  }

  esp_now_register_recv_cb(onReceive);

  // Initialize PCA9685
  Wire.begin(I2C_SDA, I2C_SCL);
  pwm.begin();
  pwm.setPWMFreq(50);  // typical servo frequency
  delay(10);

  Serial.println("PCA9685 ready on 0x40");
}

void loop() {
 
}
