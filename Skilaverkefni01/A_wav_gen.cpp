#include <iostream>
#include <fstream>
#include <math.h>

/* Configuration macros */
#define SAMPLERATE 44100                          // In Hz. (CD quality)
#define FREQ 440                                  // Middle A.
#define SAMPLESIZE 2                              // Size of each sample in bytes
#define DURATION 0.5                              // Duration in seconds.
#define CHANNELS 1                                // Nr. of channels. (Mono)
#define SAMPLES DURATION * SAMPLERATE             // Nr. of samples
#define BLOCKSIZE SAMPLESIZE * CHANNELS * SAMPLES // Block size
#define FNAME "test.wav"                          // Filename to write to.

/* Wave file format macros */
#define RIFFID "RIFF"      // Riff Chunk ID
#define WAVEID "WAVE"      // Wave Identifier
#define FMTID "fmt "       // 'fmt' chunk ID
#define DATAID "data"      // Data chunk ID
#define WAVE_FORMAT_PCM 1  // PCM Data format

using namespace std;

char* itoca(int n) {
    // Convert integer to char array of size 4
    static char carr[4];

    for (int i = 0; i < 4; i++)
        carr[i] = (n & (0xff << (i*8))) >> (i*8);

    return carr;
};

int main(int argc, char* argv[]) {
    ofstream wavfs; // Wav file stream
    wavfs.open(FNAME, ios::trunc | ios::binary); // Truncate and binary
    if (!wavfs.is_open()) {
        cerr << "Error opening \"" << FNAME << "\"!\nExiting...\n";
        return 1;
    }
    
    // Main header begin
    wavfs.write(RIFFID, 4); // RIFF header
    wavfs.write(itoca(4 + 24 + 8 * BLOCKSIZE), 4); // chunk size
    wavfs.write(WAVEID, 4); // RIFF header WAVE identifier
    // Main header end
    
    // PCM chunk begin
    wavfs.write(FMTID, 4); // PCM chunk ID
    wavfs.write(itoca(16), 4); // PCM chunk size
    wavfs.write(itoca(WAVE_FORMAT_PCM), 2); // Format tag
    wavfs.write(itoca(CHANNELS), 2); // Nr. of channels
    wavfs.write(itoca(SAMPLERATE), 4); // Nr. of samples per sec
    wavfs.write(itoca(SAMPLERATE * SAMPLESIZE * CHANNELS), 4); // Blocks per sec
    wavfs.write(itoca(SAMPLESIZE * CHANNELS), 2); // Block alignment
    wavfs.write(itoca(8 * SAMPLESIZE), 2); // Bits per sample
    // PCM chunk end
    
    // Data chunk begin
    wavfs.write(DATAID, 4); // Data chunk ID
    wavfs.write(itoca(BLOCKSIZE), 4); // Data chunk size
    for (int i = 0; i < SAMPLES; i++) {
        // sounds better with sin, less clipping
        int sample = sin(FREQ * i * 3.142/SAMPLERATE) * 32767;
        wavfs.write(itoca(sample), 2);
    }

    wavfs.close();
    return 0;
};

