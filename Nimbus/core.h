#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

//  GUItool: begin automatically generated code
AudioSynthWaveform       voiceOneB;      // xy=387.5,590
AudioSynthWaveform       voiceTwoB;      // xy=387.5,624
AudioSynthWaveform       voiceTwoD;      // xy=389.5,1045
AudioSynthWaveform       voiceOneD;      // xy=390.5,1009
AudioSynthWaveform       voiceThreeB;    // xy=392.5,660
AudioSynthNoiseWhite     noiseVoiceB;    // xy=393.5,694
AudioSynthWaveform       voiceThreeD;    // xy=392.5,1080
AudioSynthNoiseWhite     noiseVoiceD;    // xy=392.5,1114
AudioSynthWaveform       voiceTwoC;      // xy=410.5,845
AudioSynthWaveform       voiceOneC;      // xy=411.5,810
AudioSynthNoiseWhite     noiseVoiceC;    // xy=411.5,917
AudioSynthWaveform       voiceThreeC;    // xy=414.5,881
AudioSynthWaveform       voiceOneA;      // xy=454.5,300
AudioSynthWaveform       voiceTwoA;      // xy=454.5,336
AudioSynthNoiseWhite     noiseVoiceA;    // xy=455.5,411
AudioSynthWaveform       voiceThreeA;    // xy=458.5,373
AudioMixer4              voiceMixerB;    // xy=567.5,655
AudioSynthWaveformDc     envelopeB;      // xy=577.5,600
AudioSynthWaveformDc     envelopeC;      // xy=578.5,817
AudioMixer4              voiceMixerC;    // xy=578.5,877
AudioMixer4              voiceMixerD;    // xy=579.5,1070
AudioSynthWaveformDc     envelopeD;      // xy=588.5,1006
AudioMixer4              voiceMixerA;    // xy=635.5,364
AudioSynthWaveformDc     envelopeA;      // xy=639.5,306
AudioEffectMultiply      multiplyB;      // xy=726.5,627
AudioEffectMultiply      multiplyC;      // xy=738.5,848
AudioEffectMultiply      multiplyD;      // xy=738.5,1035
AudioSynthWaveform       LFO1;           // xy=757.5,770
AudioEffectMultiply      multiplyA;      // xy=796.5,354
AudioSynthWaveformDc     filterEnvD;     // xy=819.5,1113
AudioSynthWaveformDc     filterEnvB;     // xy=849.5,675
AudioSynthWaveformDc     filterEnvA;     // xy=854.5,445
AudioSynthWaveformDc     filterEnvC;     // xy=860.5,892
AudioMixer4              filterModMixerD; // xy=977.5,1176
AudioMixer4              filterModMixerB; // xy=1002.5,727
AudioMixer4              filterModMixerA; // xy=1007.5,475
AudioMixer4              filterModMixerC; // xy=1012.5,950
AudioSynthWaveformDc     lfo2Amt;        // xy=1050.5,185
AudioSynthWaveformSine   LFO2;           // xy=1050.5,232
AudioFilterStateVariable filterA;        // xy=1172.5,434
AudioFilterStateVariable filterD;        // xy=1175.5,1097
AudioFilterStateVariable filterB;        // xy=1183.5,673
AudioAnalyzePeak         peakC;          // xy=1183.5,775
AudioFilterStateVariable filterC;        // xy=1183.5,865
AudioAnalyzePeak         peakD;          // xy=1183.5,1011
AudioAnalyzePeak         peakA;          // xy=1187.5,365
AudioAnalyzePeak         peakB;          // xy=1205.5,557
AudioMixer4              LfoMixer;       // xy=1207.5,235
AudioAnalyzePeak         lfoPeak;        // xy=1364.5,229
AudioMixer4              finalMixer;     // xy=1388.5,692
AudioAnalyzePeak         finalPeak;      // xy=1586.5,779
AudioOutputI2S           i2s1;           // xy=1592.5,691
AudioConnection          patchCord1(voiceOneB, 0, voiceMixerB, 0);
AudioConnection          patchCord2(voiceTwoB, 0, voiceMixerB, 1);
AudioConnection          patchCord3(voiceTwoD, 0, voiceMixerD, 1);
AudioConnection          patchCord4(voiceOneD, 0, voiceMixerD, 0);
AudioConnection          patchCord5(voiceThreeB, 0, voiceMixerB, 2);
AudioConnection          patchCord6(noiseVoiceB, 0, voiceMixerB, 3);
AudioConnection          patchCord7(voiceThreeD, 0, voiceMixerD, 2);
AudioConnection          patchCord8(noiseVoiceD, 0, voiceMixerD, 3);
AudioConnection          patchCord9(voiceTwoC, 0, voiceMixerC, 1);
AudioConnection          patchCord10(voiceOneC, 0, voiceMixerC, 0);
AudioConnection          patchCord11(noiseVoiceC, 0, voiceMixerC, 3);
AudioConnection          patchCord12(voiceThreeC, 0, voiceMixerC, 2);
AudioConnection          patchCord13(voiceOneA, 0, voiceMixerA, 0);
AudioConnection          patchCord14(voiceTwoA, 0, voiceMixerA, 1);
AudioConnection          patchCord15(noiseVoiceA, 0, voiceMixerA, 3);
AudioConnection          patchCord16(voiceThreeA, 0, voiceMixerA, 2);
AudioConnection          patchCord17(voiceMixerB, 0, multiplyB, 1);
AudioConnection          patchCord18(envelopeB, 0, multiplyB, 0);
AudioConnection          patchCord19(envelopeC, 0, multiplyC, 0);
AudioConnection          patchCord20(voiceMixerC, 0, multiplyC, 1);
AudioConnection          patchCord21(voiceMixerD, 0, multiplyD, 1);
AudioConnection          patchCord22(envelopeD, 0, multiplyD, 0);
AudioConnection          patchCord23(voiceMixerA, 0, multiplyA, 1);
AudioConnection          patchCord24(envelopeA, 0, multiplyA, 0);
AudioConnection          patchCord25(multiplyB, 0, filterB, 0);
AudioConnection          patchCord26(multiplyC, 0, filterC, 0);
AudioConnection          patchCord27(multiplyD, 0, filterD, 0);
AudioConnection          patchCord28(LFO1, 0, filterModMixerA, 1);
AudioConnection          patchCord29(LFO1, 0, filterModMixerB, 1);
AudioConnection          patchCord30(LFO1, 0, filterModMixerC, 1);
AudioConnection          patchCord31(LFO1, 0, filterModMixerD, 1);
AudioConnection          patchCord32(multiplyA, 0, filterA, 0);
AudioConnection          patchCord33(filterEnvD, 0, filterModMixerD, 0);
AudioConnection          patchCord34(filterEnvB, 0, filterModMixerB, 0);
AudioConnection          patchCord35(filterEnvA, 0, filterModMixerA, 0);
AudioConnection          patchCord36(filterEnvC, 0, filterModMixerC, 0);
AudioConnection          patchCord37(filterModMixerD, 0, filterD, 1);
AudioConnection          patchCord38(filterModMixerB, 0, filterB, 1);
AudioConnection          patchCord39(filterModMixerA, 0, filterA, 1);
AudioConnection          patchCord40(filterModMixerC, 0, filterC, 1);
AudioConnection          patchCord41(lfo2Amt, 0, LfoMixer, 0);
AudioConnection          patchCord42(LFO2, 0, LfoMixer, 1);
AudioConnection          patchCord43(filterA, 0, finalMixer, 0);
AudioConnection          patchCord44(filterA, 0, peakA, 0);
AudioConnection          patchCord45(filterD, 0, finalMixer, 3);
AudioConnection          patchCord46(filterD, 0, peakD, 0);
AudioConnection          patchCord47(filterB, 0, finalMixer, 1);
AudioConnection          patchCord48(filterB, 0, peakB, 0);
AudioConnection          patchCord49(filterC, 0, finalMixer, 2);
AudioConnection          patchCord50(filterC, 0, peakC, 0);
AudioConnection          patchCord51(LfoMixer, lfoPeak);
AudioConnection          patchCord52(finalMixer, 0, i2s1, 0);
AudioConnection          patchCord53(finalMixer, 0, i2s1, 1);
AudioConnection          patchCord54(finalMixer, finalPeak);
AudioControlSGTL5000     sgtl5000_1;     // xy=1371.5,273
//  GUItool: end automatically generated code

#include <Bounce.h>
#include <Adafruit_NeoPixel.h>
#include <Metro.h>

#include "theory.h"

// Amin, Bmin, Cmin, Dmin, Emin, Fmin, Gmin, Chrom
int scale;
// Frequency in Hz
float frequency;

// Pixels
#include "pixels.h"
// Touch
#include "touch.h"

void setupAudio() {
  AudioMemory(64);
  sgtl5000_1.enable();
  sgtl5000_1.volume(.8);
}

// Switches / EncoderBtn
Bounce btnSwBouncers[5] = {
  Bounce(3, 10),
  Bounce(4, 10),
  Bounce(5, 10),
  Bounce(8, 10),
  Bounce(20, 10),
};
int btnSwPins[5] = {3, 4, 5, 8, 20};

// Knobs
float analogValues[16];
float analogValuesLag[16];

// FirstRunFlag
bool firstRun;

int menuCount;

unsigned long clearTimeStamp;

#include "preset.h"
#include "encoder.h"

const int chipSelect = 10;
int presetNumber = -1;

// sequencer
Metro metronome = Metro(500);
bool seqRunning;
int metroInterval = 300;
int seqStep;
int prevSeqStep;
int seqPage;
bool seqEditMode;
float seqFrequencies[4][8];
float seqFrequenciesTwo[4][8];
bool seqStepClearFlag;
unsigned long seqStepClearTimeStamp;
// float seqVelocities[4][8];
float currentSeqNote;
float currentSeqNoteTwo;
int seqLength;

// Synth Params
float finalAmp;
float voiceAPeak;
float voiceBPeak;
float voiceCPeak;
float voiceDPeak;

int attackTime = 10;
int releaseTime = 10;
float lfoAmt;
float lfoFreq;
int lfoTimeMathArray[5] = {250, 500, 1000, 2000, 4000};
int lfoIndex;
float seqInterval;
float lfoTwoAmt;
float lfoTwoFreq;
float lfoPitchMod;
float octave[4] = {.25, .5, 1, 2};
int midiOctave[4] = {-24, -12, 0, 12};
int octaveKey;
int filterFreq;
float filterRes;
float masterDetune;
float plusDetune;
float minusDetune;
unsigned long filterEnvAttack;
unsigned long filterEnvRelease;

void resetGraph() {
  // lfoMixer
  LfoMixer.gain(0, .5);
  LfoMixer.gain(1, .5);
  // Set LFO amplitudes
  lfo2Amt.amplitude(1);
  LFO2.amplitude(1);
  LFO2.frequency(1);
  // finalMixer
  finalMixer.gain(0, .25);
  finalMixer.gain(1, .25);
  finalMixer.gain(2, .25);
  finalMixer.gain(3, .25);
  // Voice 1
  voiceOneA.amplitude(.25);
  voiceOneB.amplitude(.25);
  voiceOneC.amplitude(.25);
  voiceOneD.amplitude(.25);
  // Voice 2
  voiceTwoA.amplitude(.25);
  voiceTwoB.amplitude(.25);
  voiceTwoC.amplitude(.25);
  voiceTwoD.amplitude(.25);
  // Voice 3
  voiceThreeA.amplitude(.25);
  voiceThreeB.amplitude(.25);
  voiceThreeC.amplitude(.25);
  voiceThreeD.amplitude(.25);
  // Noise
  noiseVoiceA.amplitude(.125);
  noiseVoiceB.amplitude(.125);
  noiseVoiceC.amplitude(.125);
  noiseVoiceD.amplitude(.125);
  // LFO
  LFO1.begin(.7, .5, WAVEFORM_SAWTOOTH_REVERSE);
  // filter
  filterA.octaveControl(2.5);
  filterB.octaveControl(2.5);
  filterC.octaveControl(2.5);
  filterD.octaveControl(2.5);
}

void setupSwitches() {
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
}
