/* Encoder-related functions and variables. */

int encoded;
int encoderPin1 = 21;
int encoderPin2 = 24;
volatile int lastEncoded = 0;
volatile long encoderValue = 0;
int scaledEncVal;
int prevScaledEncVal;

extern bool seqRunning;
extern bool seqEditMode;

void updateEncoder() {
  // MSB = most significant bit
  int MSB = digitalRead(encoderPin1);
  // LSB = least significant bit
  int LSB = digitalRead(encoderPin2);
  // converting the 2 pin value to single number
  encoded = (MSB << 1) | LSB;
  // adding it to the previous encoded value
  int sum  = (lastEncoded << 2) | encoded;
  if (sum == 0b1101 || sum == 0b0100 || sum == 0b0010 || sum == 0b1011) encoderValue ++;
  if (sum == 0b1110 || sum == 0b0111 || sum == 0b0001 || sum == 0b1000) encoderValue --;
  if (encoderValue < 0) {
    encoderValue = 0;
  }
  if (seqEditMode) {
    if (encoderValue > 124) {
      encoderValue = 124;
    }
  } else if (seqRunning) {
    if (encoderValue > 2000) {
      encoderValue = 2000;
    }
  }
  scaledEncVal = encoderValue / 4;
  // store this value for next time
  lastEncoded = encoded;
}

void setupEncoder() {
  pinMode(encoderPin1, INPUT);
  pinMode(encoderPin2, INPUT);
  digitalWrite(encoderPin1, HIGH);
  digitalWrite(encoderPin2, HIGH);
  attachInterrupt(21, updateEncoder, CHANGE);
  attachInterrupt(24, updateEncoder, CHANGE);
}

void setupEncoderBtn() {
  pinMode(20, INPUT_PULLUP);
}
