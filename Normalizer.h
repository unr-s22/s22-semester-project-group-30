#ifndef FP_NORMALIZER_H
#define FP_NORMALIZER_H
#include "SignalProcessor.cpp"
#include <cstdint>
#include <cmath>
#include <vector>
#include "Wav.h"
#define MAX8BIT 255
#define MAX16BIT 32767
#define MIN16BIT 32768
class Normalizer : public SignalProcessor {
public:

    std::vector<float> process(const std::vector<float> input, wav_hdr attributes) override;

};

#endif
