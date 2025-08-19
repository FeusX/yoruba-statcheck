#include <LiquidCrystal_I2C.h>
#include <DHT.h>

#define AO_PIN A0
#define DHT_SENSOR_PIN D7
#define DHT_SENSOR_TYPE DHT22


LiquidCrystal_I2C lcd(0x27, 16, 2);
DHT dht_sensor(DHT_SENSOR_PIN, DHT_SENSOR_TYPE);

void setup() {
  Serial.begin(115200);
  lcd.init();
  lcd.backlight();
  lcd.clear();
  dht_sensor.begin();
  pinMode(AO_PIN, INPUT);
  for(unsigned int i = 20; i >= 1; i--)
  {
    lcd.setCursor(0,0);
    lcd.print("MQ2 IS HEATING");
    lcd.setCursor(1,1);
    lcd.print(i);
    lcd.print(" SECONDS LEFT");
    delay(1000);
    lcd.clear();
  }
}

void loop() {
  int gas_val = analogRead(AO_PIN);
  int humi = dht_sensor.readHumidity();
  int temp = dht_sensor.readTemperature();
  lcd.clear();
  lcd.setCursor(3,0);
  lcd.print("GAS: ");
  lcd.print(gas_val);
  lcd.setCursor(0,1);
  lcd.print("HUM: ");
  lcd.print(humi);
  lcd.setCursor(8,1);
  lcd.print("TEMP: ");
  lcd.print(temp);

  delay(2000);
}
