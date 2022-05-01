#ifndef FP_WAVREADER_H
#define FP_WAVREADER_H
#include <cstdint>
#include <fstream>
#include "Wav.h"
#include <iostream>

class WavReader {
public:
    template<typename T>
    void readSamples(T* samples, size_t numBytes, std::ifstream& file, wav_hdr &header) {
        
        if(header.BitsPerSample == 8) {
            uint8_t data[numBytes];
            file.read(reinterpret_cast<char*>(&data), numBytes);
            for(int i = 0; i < header.NumChannels*numBytes; i++) {
                samples[i] = float(data[i])/UINT8_MAX;
            }
        }
        if(header.BitsPerSample == 16) {
            int16_t* data = new int16_t[numBytes];
            std::cout << '1' << std::endl;
            file.read(reinterpret_cast<char*>(data), 2*numBytes);
            std::cout << '1' << std::endl;
            for(int i = 0; i < header.NumChannels*numBytes; i++) {
                samples[i] = float(data[i])/INT16_MAX;
            }
            std::cout << '2' << std::endl;
            delete [] data;
        }
    }
    void readHeader(std::ifstream& file, wav_hdr& header);
};

#endif