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
            uint8_t* data = new uint8_t[numBytes];
            file.read(reinterpret_cast<char*>(data), numBytes);
            for(int i = 0; i < numBytes; i++) {
                samples[i] = (2*float(data[i])/UINT8_MAX)-1;
            }
            delete [] data;
        }
        if(header.BitsPerSample == 16) {
            int16_t* data = new int16_t[numBytes];
            std::cout << '2' << std::endl;
            file.read(reinterpret_cast<char*>(data), 2*numBytes);
            for(int i = 0; i < numBytes; i++) {
                samples[i] = float(data[i])/INT16_MAX;
            }
            delete [] data;
        }
    }
    void readHeader(std::ifstream& file, wav_hdr& header);
};

#endif