/*
 * Contains USB-MIDI related code.
 */

void setSynthParams(int number, float value);

float noteToFrequency(byte note) {
  return 440.0 * powf(2.0, (float)(note - 69) * 0.08333333);
}

void OnControlChange(byte channel, byte control, byte value) {
  setSynthParams(control - 1, value * 8.055);
  rawVals[control - 1] = value * 8.055;
  paramLocks[control - 1] = true;
}

// A handler for MIDI NoteOn message
void OnNoteOn(byte channel, byte note, byte velocity) {
  float freq = noteToFrequency(note);
  float vel = (float)velocity / 127;
  startVoice(freq, vel);
}

// A handler for MIDI NoteOff message
void OnNoteOff(byte channel, byte note, byte velocity) {
  float freq = noteToFrequency(note);
  endVoice(freq);
}

// Configures MIDI protocol handlers
void setupMIDIHandlers() {
  usbMIDI.setHandleNoteOff(OnNoteOff);
  usbMIDI.setHandleNoteOn(OnNoteOn);
  usbMIDI.setHandleControlChange(OnControlChange);
}
