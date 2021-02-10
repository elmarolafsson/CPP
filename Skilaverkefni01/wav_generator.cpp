#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <math.h>
using namespace std;

int makeWaveHeader(int sampleRate, int noChannels, int bitsSample, char name[], int pmc, float duration, int freq){
    int noSamples = duration * sampleRate;
    int byteRate = sampleRate * noChannels * bitsSample/8;
    int blockAlign = noChannels * bitsSample/8;
    int subChunk2Size = noSamples*noChannels*bitsSample/8;
    ofstream wavfs;
    wavfs.open(name, ios::binary);
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
        NumChannels[i] = (pmc & (0xff << (i*8))) >> (i*8);
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
        short sample = cos(freq * i * 3.142/sampleRate) * 32767;
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

int main(int argc, char* args[]){
    int PMC = 1;
    int sampleRate = 44100;   // Sample rate in Hz. (CD quality)
    int noChannels = 1;       // Mono
    int freq;
    float duration;
    char file[32];
    int size = 0;
    int i = 0;
    if (argc < 4){
        cout << "Insert Filename: ";
        cin >> file;
        while(file[i] != '\0'){
            size++;
            i++;
        }
        cout << "Insert Duration: ";
        cin >> duration;
        cout << "Insert Frequency: ";
        cin >> freq;
    }
    else{
        freq = atoi(args[3]);           // A above middle C
        duration = atof(args[2]);     // Length of tone - seconds
        while(args[1][i] != '\0'){
            file[size] = args[1][i];
            size++;
            i++;
        }
    }
    int noSamples = duration * sampleRate;   // Total number of samples for file
    file[size++] = '.';
    file[size++] = 'w';
    file[size++] = 'a';
    file[size++] = 'v';
    int wave = makeWaveHeader(sampleRate, noChannels, 16, file, PMC, duration, freq);
}