String morseString;

void setup() {
  // put your setup code here, to run once:
  
Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  if(Serial.available()) {
  Serial.println("Enter a string: ");
  morseString = Serial.readString();
  convertToMorse(morseString);
  }
}

void dot() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(250);
  digitalWrite(LED_BUILTIN, LOW);
  delay(250);
}

void dash() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(750);
  digitalWrite(LED_BUILTIN, LOW);
  delay(250);
}

void convertToMorse(String morseString) {
  for(int i = 0; i < morseString.length(); i++) {
    switch(morseString[i]) {
      case 'A': case 'a':
        dot(); dash();
        break;
      case 'B': case 'b':
        dash(); dot(); dot(); dot();
        break;
      case 'C': case 'c':
        dash(); dot(); dash(); dot();
        break;
      case 'D': case 'd':
        dash(); dot(); dot();
        break;
      case 'E': case 'e':
        dot();
        break;
      case 'G': case 'g':
        dash(); dash(); dot();
        break;
      case 'H': case 'h':
        for(int j = 0; j < 4; j++) { dot(); }
        break;
      case 'I': case 'i':
        for(int j = 0; j < 2; j++) { dot(); dot(); }
        break;
      case 'J': case 'j':
        dot(); dash(); dash(); dash();
        break;
      case 'K': case 'k':
        dash(); dot(); dash();
        break;
      case 'L': case 'l':
        dot(); dash(); dot(); dot();
        break;
      case 'M': case 'm':
        dash(); dash();
        break;
      case 'N': case 'n':
        dash(); dot();
        break;
      case 'O': case 'o':
        dash(); dash(); dash();
        break;
      case 'P': case 'p':
        dot(); dash(); dash(); dot();
        break;
      case 'Q': case 'q':
        dash(); dash(); dot(); dash();
        break;
      case 'R': case 'r':
        dot(); dash(); dot();
      case 'S': case 's':
        for(int j = 0; j < 3; j++) { dot(); }
        break;
      case 'T': case 't':
        dash();
        break;
      case 'U': case 'u':
        dot(); dot(); dash();
        break;
      case 'V': case 'v':
        dot(); dot(); dot(); dash();
        break;
      case 'W': case 'w':
        dot(); dash(); dash();
        break;
      case 'X': case 'x':
        dash(); dot(); dot(); dash();
        break;
      case 'Y': case 'y':
        dash(); dot(); dash(); dash();
        break;
      case 'Z': case 'z':
        dash(); dash(); dot(); dot();
        break;
      case '1':
        dot(); dash(); dash(); dash(); dash();
        break;
      case '2':
        dot(); dot(); dash(); dash(); dash();
        break;
      case '3':
        dot(); dot(); dot(); dash(); dash();
        break;
      case '4':
        dot(); dot(); dot(); dot(); dash();
        break;
      case '5':
        dot(); dot(); dot(); dot(); dot();
        break;
      case '6':
        dash(); dot(); dot(); dot(); dot();
        break;
      case '7':
        dash(); dash(); dot(); dot(); dot();
        break;
      case '8':
        dash(); dash(); dash(); dot(); dot();
        break;
      case '9':
        dash(); dash(); dash(); dash(); dot();
        break;
      case '0':
        dash(); dash(); dash(); dash(); dash();
        break;
      case ' ':
        delay(1500);
    }
  }
}
