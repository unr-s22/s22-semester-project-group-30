#ifndef FP_WAVMODEL_H
#define FP_WAVMODEL_H
#include <fstream>
#include <string>
#include <vector>
#include "IWavModel.h"
#include "WavReader.h"
#include "Wav.h"

class WavModel : public IWavModel {
    wav_hdr header;
    std::vector<float> audio;
public:
    void openRead(const std::string);
    std::vector<float> getAudio() const {return audio;}
    wav_hdr getAttribute() {return header;}
};

#endif