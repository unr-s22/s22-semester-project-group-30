#ifndef FP_WAVREADER_H
#define FP_WAVREADER_H
#include <cstdint>
#include <fstream>
#include "Wav.h"

class WavReader {
public:
    template<typename T>
    void readSamples(T* samples, size_t numBytes, std::ifstream& file) {
        file.read(reinterpret_cast<char*>(samples), numBytes);
    }
    void convertToFloat(float* samples, size_t numBytes, std::ifstream& file, wav_hdr header);
    void readHeader(std::ifstream& file, wav_hdr& header);
};

#endif