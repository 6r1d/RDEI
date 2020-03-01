// Touch Pins
bool noteTouched[8];
int noteTouchPins[8] = {0, 1, 15, 16, 17, 25, 32, 33};
float noteCurrent[8];

int N_readings = 8;

// Takes a smooth reading for a pin.
// Smooth means taking a sum of N readings and dividing these by N.
int smoothRead(int pin) {
  int vals[N_readings]; // array that stores N readings.
  for (int i = 0; i < N_readings; i++) {
    vals[i] = touchRead(pin); // takes N readings.
  }
  float smooth = (vals[0] + vals[1] + vals[2] + vals[3] + vals[4] + vals[5] + vals[6] + vals[7]) / N_readings;
  return smooth;
}
