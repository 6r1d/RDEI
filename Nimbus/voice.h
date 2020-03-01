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

void setVoceOneShape (bool saw) {
  if (saw) {
    voiceOneA.begin(WAVEFORM_SAWTOOTH);
    voiceOneB.begin(WAVEFORM_SAWTOOTH);
    voiceOneC.begin(WAVEFORM_SAWTOOTH);
    voiceOneD.begin(WAVEFORM_SAWTOOTH);
  } else {
    voiceOneA.begin(WAVEFORM_SQUARE);
    voiceOneB.begin(WAVEFORM_SQUARE);
    voiceOneC.begin(WAVEFORM_SQUARE);
    voiceOneD.begin(WAVEFORM_SQUARE);
  }
}

void setVoceTwoShape (bool saw) {
  if (saw) {
    voiceTwoA.begin(WAVEFORM_SAWTOOTH);
    voiceTwoB.begin(WAVEFORM_SAWTOOTH);
    voiceTwoC.begin(WAVEFORM_SAWTOOTH);
    voiceTwoD.begin(WAVEFORM_SAWTOOTH);
  } else {
    voiceTwoA.begin(WAVEFORM_SQUARE);
    voiceTwoB.begin(WAVEFORM_SQUARE);
    voiceTwoC.begin(WAVEFORM_SQUARE);
    voiceTwoD.begin(WAVEFORM_SQUARE);
  }
}

void setVoceThreeShape (bool saw) {
  if (saw) {
    voiceThreeA.begin(WAVEFORM_TRIANGLE);
    voiceThreeB.begin(WAVEFORM_TRIANGLE);
    voiceThreeC.begin(WAVEFORM_TRIANGLE);
    voiceThreeD.begin(WAVEFORM_TRIANGLE);
  } else {
    voiceThreeA.begin(WAVEFORM_SQUARE);
    voiceThreeB.begin(WAVEFORM_SQUARE);
    voiceThreeC.begin(WAVEFORM_SQUARE);
    voiceThreeD.begin(WAVEFORM_SQUARE);
  }
}

void setLfoShape(bool sine) {
  if (sine) {
    LFO1.begin(WAVEFORM_SINE);
  } else {
    LFO1.begin(WAVEFORM_SAWTOOTH_REVERSE);
  }
}

void endVoice(float frequency) {
  for (int i = 0; i < 4; ++i) {
    if (VoiceFreq[i] == frequency) {
      voices[i] = 0;
    }
  }
}
