#ifndef FP_WAVREADER_H
#define FP_WAVREADER_H
#include <cstdint>
#include <fstream>
#include "Wav.h"
#include <iostream>

class WavReader {
public:
    void readSamples(float* samples, size_t numBytes, std::ifstream& file, wav_hdr &header);
    void readHeader(std::ifstream& file, wav_hdr& header);
};

#endif