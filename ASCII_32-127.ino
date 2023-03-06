
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
for (byte i = 32; i < 128; i++){
    Serial.print(i);
    Serial.print(" ");
    Serial.print(i, HEX);
    Serial.print(" -> ");
    Serial.println((char)i);
  }
  }

void loop() {
  // put your main code here, to run repeatedly:

}
