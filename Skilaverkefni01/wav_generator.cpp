#include <iostream>
#include <fstream>
using namespace std;


int makeWaveHeader(int sampleRate, int noChannels, int bitsSample){
    float duration = 0.5;
    int noSamples = duration * sampleRate;
    int byteRate = sampleRate * noChannels * bitsSample/8;
    int blockAlign = noChannels * bitsSample/8;

    int int_field = 0;

    // TODO make wave header

    return 0;
}

int main(){
    int sampleRate = 44100;   // Sample rate in Hz. (CD quality)
    int freq = 440;           // A above middle C
    float duration = 0.5;     // Length of tone - seconds
    int noChannels = 1;       // Mono

    int noSamples = duration * sampleRate;   // Total number of samples for file
    
    int wave = makeWaveHeader(sampleRate, noChannels, 16);
}