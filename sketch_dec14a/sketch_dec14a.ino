#include <Stepper.h>

#define motor_steps 200   // Stepper motorun adım sayısı
#define motor_pin_1 8     // Motor sürücüsünün bağlı olduğu pinler
#define motor_pin_2 9
#define motor_pin_3 10
#define motor_pin_4 11

Stepper myStepper(motor_steps, motor_pin_1, motor_pin_2, motor_pin_3, motor_pin_4);

char command; // Bluetooth üzerinden alınacak komut

void setup() {
  Serial.begin(9600); // Seri haberleşme başlatılıyor
  myStepper.setSpeed(120); // Motor hızı (rpm cinsinden)
}

void loop() {
  if (Serial.available() > 0) {
    command = Serial.read(); // Seri bağlantı üzerinden komut okunuyor

    // Gelen komuta göre motor hareketi kontrol ediliyor
    if (command == 'F') {
      myStepper.step(50); // Motoru 100 adım ileri hareket ettir
    } else if (command == 'B') {
      myStepper.step(-50); // Motoru 100 adım geri hareket ettir
    }
  }
}
