#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

void write_int(int integer, ofstream* wavfs){
    char data[4];
    for (int i = 0; i < 4; i++)
        data[i] = (integer & (0xff << (i*8))) >> (i*8);
    wavfs->write(data,4);
}

void write_short(short s, ofstream* wavfs){
    char data[2];
    for (int i = 0; i < 2; i++)
        data[i] = (s & (0xff << (i*8))) >> (i*8);
    wavfs->write(data,2);
}

int makeWaveHeader(int sampleRate, int noChannels, int bitsSample){
    float duration = 0.5;
    int noSamples = duration * sampleRate;
    int byteRate = sampleRate * noChannels * bitsSample/8;
    int blockAlign = noChannels * bitsSample/8;
    int int_field = 0;
    ofstream wavfs;
    wavfs.open("poop.wav");
    // TODO make wave header
    wavfs.write("RIFF",4);
    wavfs.write("\0\0\0\0",4);
    wavfs.write("WAVE", 4);
    wavfs.write("fmt ",4);
    write_int(16, &wavfs);
    write_short(1, &wavfs);
    write_short(1, &wavfs);
    write_int(sampleRate, &wavfs);
    write_int(byteRate, &wavfs);
    write_short(blockAlign, &wavfs);
    write_short(bitsSample, &wavfs);
    wavfs.write("data",4);
    write_int((noSamples*noChannels*bitsSample/8), &wavfs);

    for(int i=0; i<noSamples; i++){
        short sample = cos(440 * i * 3.142/sampleRate) * 32767;
        write_short(sample, &wavfs);
    }
    size_t filesize = wavfs.tellp();
    wavfs.seekp(4);
    write_int(filesize-8, &wavfs);
    wavfs.close();
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