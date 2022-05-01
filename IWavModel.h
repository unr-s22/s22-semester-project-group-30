#ifndef FP_IWAVMODEL_H
#define FP_IWAVMODEL_H
#include <string>
#include <vector>
#include "Wav.h"

class IWavModel {
public:
    virtual void openRead(const std::string) = 0;
    virtual void openWrite(const std::string, std::vector<float>) = 0;
    virtual std::vector<float> getAudio() const = 0;
    virtual wav_hdr getAttribute() const = 0;
};

#endif