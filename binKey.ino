const byte inputs[] = {2, 3, 4, 5, 6, 7, 8, 9};
const int SUBMIT = 10;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for (int i = 0; i < sizeof(inputs); i++) {
    pinMode(inputs[i], INPUT);
  }
  pinMode(SUBMIT, INPUT);
}

void loop() {
  int submit_state = digitalRead(SUBMIT);
  if (submit_state == 1) {
    byte data = 0;
    for (int i = 0; i < 8; i++) {
        data |= (digitalRead(inputs[i]) << i);
    }
    char letter = data;
    Serial.print(letter);
  }
}
