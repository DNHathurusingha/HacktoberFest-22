#include <SPI.h>

int Relay_Reactor = A0;
int Relay_Washing = A1;
int Relay_Water = A2;
int Relay_4 = A3;
int Relay_5 = A4;
int Relay_pump = A5;
int Relay_stire = 4;

int Heater_Reactor = 7;
int Heater_Washing = 9;
int Heater_Water = 10;
int Heater_4 = 3;
int Heater_5 = 5;

int set_temp_Reactor = 30;
int set_temp_Washing = 30;
int set_temp_Water = 30;
int set_temp_4 = 30;
int set_temp_5 = 30;

int temp_Reactor = 0;
int temp_Washing = 0;
int temp_Water = 0;
int temp_4 = 0;
int temp_5 = 0;

bool pump = false;
bool stire = false;

unsigned long previousMillis = 0;
const long interval = 500;

String inString = "";
String MyMessage = "";
bool newData;

double readCelsius(uint8_t cs) {
  uint16_t v;

  digitalWrite(cs, LOW);
  v = SPI.transfer(0x00);
  v <<= 8;
  v |= SPI.transfer(0x00);
  digitalWrite(cs, HIGH);

  if (v & 0x4) {
    return NAN;
  }

  v >>= 3;

  return v * 0.25;
}

void setup() {

  SPI.begin();
  Serial.begin(115200);

  pinMode(Relay_Reactor, OUTPUT);
  pinMode(Relay_Washing, OUTPUT);
  pinMode(Relay_Water, OUTPUT);
  pinMode(Relay_4, OUTPUT);
  pinMode(Relay_5, OUTPUT);
  pinMode(Relay_pump, OUTPUT);
  pinMode(Relay_stire, OUTPUT);

  pinMode(Heater_Reactor, OUTPUT);
  pinMode(Heater_Washing, OUTPUT);
  pinMode(Heater_Water, OUTPUT);
  pinMode(Heater_4, OUTPUT);
  pinMode(Heater_5, OUTPUT);

  digitalWrite(Heater_Reactor, HIGH);
  digitalWrite(Heater_Washing, HIGH);
  digitalWrite(Heater_Water, HIGH);
  digitalWrite(Heater_4, HIGH);
  digitalWrite(Heater_5, HIGH);

  digitalWrite(Relay_Reactor, LOW);
  digitalWrite(Relay_Washing, LOW);
  digitalWrite(Relay_Water, LOW);
  digitalWrite(Relay_4, LOW);
  digitalWrite(Relay_5, LOW);
  digitalWrite(Relay_pump, LOW);
  digitalWrite(Relay_stire, LOW);
}

void loop() {

  while (Serial.available()) {
    int inChar = Serial.read();
    inString += (char)inChar;
    get_values();
  }

  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
        Serial.print(set_temp_Reactor);
        Serial.print(" , ");
        Serial.print(set_temp_Washing);
        Serial.print(" , ");
        Serial.print(set_temp_Water);
        Serial.print(" , ");
        Serial.print(set_temp_4);
        Serial.print(" , ");
        Serial.print(set_temp_5);
        Serial.print(" , ");
        Serial.print(pump);
        Serial.print(" , ");
        Serial.print(stire);
        Serial.print(" / ");
    read_tem();
    delay(10);
    MyMessage = "";
    MyMessage = MyMessage + String(temp_Reactor) + "," + String(temp_Washing) + "," + String(temp_Water) + "," + String(temp_4) + "," + String(temp_5) + "," + String(pump) + "," + String(stire);
    Serial.println(MyMessage);
  }

  inString = " ";

  control();
}

void get_values() {
  String q = getValue(inString, ',', 0);
  String r = getValue(inString, ',', 1);
  String s = getValue(inString, ',', 2);
  String t = getValue(inString, ',', 3);
  String u = getValue(inString, ',', 4);
  String v = getValue(inString, ',', 5);
  String w = getValue(inString, ',', 6);

  set_temp_Reactor = q.toInt();
  set_temp_Washing = r.toInt();
  set_temp_Water = s.toInt();
  set_temp_4 = t.toInt();
  set_temp_5 = u.toInt();

  if (v == "0") {
    pump = false;
  }
  if (v == "1") {
    pump = true;
  }
  if (w == "0") {
    stire = false;
  }
  if (w == "1") {
    stire = true;
  }
}

void read_tem() {

  temp_Reactor = (int)readCelsius(Heater_Reactor);
  delay(10);
  temp_Washing = (int)readCelsius(Heater_Washing);
  delay(10);
  temp_Water = (int)readCelsius(Heater_Water);
  delay(10);
  temp_4 = (int)readCelsius(Heater_4);
  delay(10);
  temp_5 = (int)readCelsius(Heater_5);
  delay(10);

}


void control() {

  if (set_temp_Reactor + 1 > temp_Reactor) {
    digitalWrite(Relay_Reactor, HIGH);

  }
  if (set_temp_Reactor - 1 < temp_Reactor) {
    digitalWrite(Relay_Reactor, LOW);
  }
  ////////////
  if (set_temp_Washing + 1 > temp_Washing) {
    digitalWrite(Relay_Washing, HIGH);
  }
  if (set_temp_Washing - 1 < temp_Washing) {
    digitalWrite(Relay_Washing, LOW);
  }
  ////////////
  if (set_temp_Water + 1 > temp_Water) {
    digitalWrite(Relay_Water, HIGH);
  }
  if (set_temp_Water - 1 < temp_Water) {
    digitalWrite(Relay_Water, LOW);
  }
  ////////////
  if (set_temp_4 + 1 > temp_Reactor) {
    digitalWrite(Relay_4, HIGH);

  }
  if (set_temp_4 - 1 < temp_Reactor) {
    digitalWrite(Relay_4, LOW);
  }
  ////////////
  if (set_temp_5 + 1 > temp_Reactor) {
    digitalWrite(Relay_5, HIGH);

  }
  if (set_temp_5 - 1 < temp_Reactor) {
    digitalWrite(Relay_5, LOW);
  }
  ////////////
  if (pump == false) {
    digitalWrite(Relay_pump, LOW);
  }
  if (pump == true) {
    digitalWrite(Relay_pump, HIGH);
  }
  if (stire == false) {
    digitalWrite(Relay_stire, LOW);
  }
  if (stire == true) {
    digitalWrite(Relay_stire, HIGH);
  }

}

String getValue(String data, char separator, int index) {

  int found = 0;
  int strIndex[] = { 0, -1 };
  int maxIndex = data.length() - 1;

  for (int i = 0; i <= maxIndex && found <= index; i++) {
    if (data.charAt(i) == separator || i == maxIndex) {
      found++;
      strIndex[0] = strIndex[1] + 1;
      strIndex[1] = (i == maxIndex) ? i + 1 : i;
    }
  }
  return found > index ? data.substring(strIndex[0], strIndex[1]) : "";
}
