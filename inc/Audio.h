#ifndef __AUDIO_H__
#define __AUDIO_H__

#include <stdint.h>
#include <stdbool.h>

typedef void AudioCallbackFunction(void *context,int buffer);

#define Audio8000HzSettings 256,5,12,1
#define Audio16000HzSettings 213,2,13,0
#define Audio32000HzSettings 213,2,6,1
#define Audio48000HzSettings 258,3,3,1
#define Audio96000HzSettings 344,2,3,1
#define Audio22050HzSettings 429,4,9,1
#define Audio44100HzSettings 271,2,6,0
#define AudioVGAHSyncSettings 419,2,13,0 // 31475.3606. Actual VGA timer is 31472.4616.

// Initialize and power up audio hardware. Use the above defines for the parameters.
// Can probably only be called once.
void InitializeAudio(int plln,int pllr,int i2sdiv,int i2sodd);

// Power up and down the audio hardware.
void AudioOn();
void AudioOff();

// Set audio volume in steps of 0.5 dB. 0xff is +12 dB.
void SetAudioVolume(int volume);

// Output one audio sample directly to the hardware without using DMA.
void OutputAudioSample(int16_t sample);
void OutputAudioSampleWithoutBlocking(int16_t sample);

// Start and stop audio playback using DMA.
// Callback is optional, and called whenever a new buffer is needed.
void PlayAudioWithCallback(AudioCallbackFunction *callback,void *context);
void StopAudio();

// Provide a new buffer to the audio DMA. Output is double buffered, so
// at least two buffers must be maintained by the program. It is not allowed
// to overwrite the previously provided buffer until after the next callback
// invocation.
// Buffers must reside in DMA1-accessible memory, that is, the 128k RAM bank,
// or flash.
void ProvideAudioBuffer(void *samples,int numsamples);
bool ProvideAudioBufferWithoutBlocking(void *samples,int numsamples);

#endif
