// Mux control pins,
// outputs to select Mux input channel
int s0 = 26;
int s1 = 27;
int s2 = 28;
int s3 = 29;

// Mux in "SIG" pin
int SIG_pin = 30;
// Sets mux control pins
int controlPin[] = {s0, s1, s2, s3};

// Sets Mux pin modes: one input - SIG_pin,
// 4 outputs to control multiplexor channel
void resetMux() {
  pinMode(s0, OUTPUT);
  pinMode(s1, OUTPUT);
  pinMode(s2, OUTPUT);
  pinMode(s3, OUTPUT);
  pinMode(SIG_pin, INPUT);
  digitalWrite(s0, LOW);
  digitalWrite(s1, LOW);
  digitalWrite(s2, LOW);
  digitalWrite(s3, LOW);
}

// Sets Mux pin channel
void setMuxPin(int channel) {
  // Encodes mux control bits,
  // from 0 to 15
  int muxChannel[16][4] = {
    {0, 0, 0, 0}, // 0
    {1, 0, 0, 0}, // 1
    {0, 1, 0, 0}, // 2
    {1, 1, 0, 0}, // 3
    {0, 0, 1, 0}, // 4
    {1, 0, 1, 0}, // 5
    {0, 1, 1, 0}, // 6
    {1, 1, 1, 0}, // 7
    {0, 0, 0, 1}, // 8
    {1, 0, 0, 1}, // 9
    {0, 1, 0, 1}, // 10
    {1, 1, 0, 1}, // 11
    {0, 0, 1, 1}, // 12
    {1, 0, 1, 1}, // 13
    {0, 1, 1, 1}, // 14
    {1, 1, 1, 1}  // 15
  };
  // Loop through the 4 sig
  for (int i = 0; i < 4; i ++) {
    digitalWrite(controlPin[i], muxChannel[channel][i]);
  }
}
