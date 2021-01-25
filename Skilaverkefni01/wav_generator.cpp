#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

// void write_int(int integer, ofstream* wavfs){
//     char data[4];
//     for (int i = 0; i < 4; i++)
//         data[i] = (integer & (0xff << (i*8))) >> (i*8);
//     wavfs->write(data,4);
// }

// void write_short(short s, ofstream* wavfs){
//     char data[2];
//     for (int i = 0; i < 2; i++)
//         data[i] = (s & (0xff << (i*8))) >> (i*8);
//     wavfs->write(data,2);
// }

int makeWaveHeader(int sampleRate, int noChannels, int bitsSample){
    float duration = 0.5;
    int noSamples = duration * sampleRate;
    int byteRate = sampleRate * noChannels * bitsSample/8;
    int blockAlign = noChannels * bitsSample/8;
    int subChunk2Size = noSamples*noChannels*bitsSample/8;
    int int_field = 0;
    ofstream wavfs;
    wavfs.open("poop.wav", ios::binary);
    wavfs.write("RIFF",4);
    wavfs.write("\0\0\0\0",4);
    wavfs.write("WAVE", 4);
    wavfs.write("fmt ",4);
    char Subchunk1Size[4];
    for (int i = 0; i < 4; i++){
        Subchunk1Size[i] = (16 & (0xff << (i*8))) >> (i*8);
    }
    wavfs.write(Subchunk1Size,4);
    char AudioFormat[2];
    for (int i = 0; i < 2; i++){
        AudioFormat[i] = (1 & (0xff << (i*8))) >> (i*8);
    }
    wavfs.write(AudioFormat,2);
    char NumChannels[2];
    for (int i = 0; i < 2; i++){
        NumChannels[i] = (1 & (0xff << (i*8))) >> (i*8);
    }
    wavfs.write(NumChannels,2);
    char sample_rate[4];
    for (int i = 0; i < 4; i++){
        sample_rate[i] = (sampleRate & (0xff << (i*8))) >> (i*8);
    }
    wavfs.write(sample_rate,4);
    char byte_rate[4];
    for (int i = 0; i < 4; i++){
        byte_rate[i] = (byteRate & (0xff << (i*8))) >> (i*8);
    }
    wavfs.write(byte_rate,4);
    char block_align[2];
    for (int i = 0; i < 2; i++){
        block_align[i] = (blockAlign & (0xff << (i*8))) >> (i*8);
    }
    wavfs.write(block_align,2);
    char bits_sample[2];
    for (int i = 0; i < 2; i++){
        bits_sample[i] = (bitsSample & (0xff << (i*8))) >> (i*8);
    }
    wavfs.write(bits_sample,2);
    wavfs.write("data",4);
    char Subchunk2_Size[4];
    for (int i = 0; i < 4; i++){
        Subchunk2_Size[i] = (subChunk2Size & (0xff << (i*8))) >> (i*8);
    }
    wavfs.write(Subchunk2_Size,4);


    for(int i=0; i<noSamples; i++){
        short sample = cos(440 * i * 3.142/sampleRate) * 32767;
        char shortSample[2];
        for (int i = 0; i < 2; i++){
            shortSample[i] = (sample & (0xff << (i*8))) >> (i*8);
        }
        wavfs.write(shortSample,2);
    }
    
    size_t filesize = wavfs.tellp();
    wavfs.seekp(4);
    char file_size[4];
    for (int i = 0; i < 4; i++){
        file_size[i] = (filesize & (0xff << (i*8))) >> (i*8);
    }
    wavfs.write(file_size,4);
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