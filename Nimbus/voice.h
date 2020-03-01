float ampArray[4];
float VoiceFreq[4];
float VoiceVel[4];
int voiceNum;
float voices[4];

int lowestAmp() {
  int index = 0;
  for (int i = 0; i < 4; i++) {
    if (ampArray[i] < ampArray[index]) {
      index = i;
    }
  }
  return index;
}

void startVoice(float frequency, float velocity) {
  voiceNum = lowestAmp();
  // If voice is already in use scan to next voice
  for (int i = 0; i < 4; ++i) {
    if (voices[voiceNum]) {
      voiceNum++;
      if (voiceNum > 3) {
        voiceNum = 0;
      }
    }
  }
  // Assign (unused voice || lowest voice)
  voices[voiceNum] = frequency;
  VoiceFreq[voiceNum] = voices[voiceNum];
  VoiceVel[voiceNum] = velocity;
}

void endVoice(float frequency) {
  for (int i = 0; i < 4; ++i) {
    if (VoiceFreq[i] == frequency) {
      voices[i] = 0;
    }
  }
}
