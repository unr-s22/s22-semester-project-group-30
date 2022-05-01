#ifndef FP_WAVMODEL_H
#define FP_WAVMODEL_H
#include <fstream>
#include <string>
#include <vector>
#include "IWavModel.h"
#include "WavReader.h"
#include "WavWriter.h"
#include "Wav.h"

class WavModel : public IWavModel {
    wav_hdr header;
    std::vector<float> audio;
public:
    void openRead(const std::string) override;
    void openWrite(const std::string, std::vector<float>) override;
    std::vector<float> getAudio() const override;
    wav_hdr getAttribute() const override;
};

#endif