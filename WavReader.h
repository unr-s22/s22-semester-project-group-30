#ifndef FP_WAVREADER_H
#define FP_WAVREADER_H
#include <cstdint>
#include <fstream>
#include "Wav.h"

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
            int16_t data[numBytes];
            file.read(reinterpret_cast<char*>(&data), 2*numBytes);
            for(int i = 0; i < numBytes; i++) {
                samples[i] = float(data[i])/INT16_MAX;
            }
        }
    }
    //void convertToFloat(float* samples, size_t numBytes, std::ifstream& file, wav_hdr header);
    void readHeader(std::ifstream& file, wav_hdr& header);
};

#endif