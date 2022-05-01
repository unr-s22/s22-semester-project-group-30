#ifndef FP_WAVWRITER_H
#define FP_WAVWRITER_H
#include <fstream>
#include <vector>
#include <iostream>
#include "Wav.h"

class WavWriter {
    public:
        void writeWav(std::ofstream& file, std::vector<float> input, wav_hdr header);
};

#endif