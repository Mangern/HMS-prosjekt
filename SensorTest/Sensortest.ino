#define MQ4 SENSOR[0]
#define MQ5 SENSOR[1]
#define MQ6 SENSOR[2]
#define MQ7 SENSOR[3]
#define MQ8 SENSOR[4]
#define MQ135 SENSOR[5]

const int SENSOR[] = {
  A0,
  A1,
  A2,
  A3,
  A4,
  A5
};
const int NUM_SENSORS = 6;

void setup() {
  Serial.begin(9600);
  
  // put your setup code here, to run once:
  for(int i = 0; i < NUM_SENSORS; i++){
    pinMode(SENSOR[i], INPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i = 0; i < NUM_SENSORS; i++) {
    int val = analogRead(SENSOR[i]);
    Serial.print("Sensor ");
    Serial.print(i+1);
    Serial.print(": ");
    Serial.println(val);
  }
  
  delay(700);
}
