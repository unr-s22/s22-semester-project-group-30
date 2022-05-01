#ifndef FP_ECHO_H
#define FP_ECHO_H
#include "SignalProcessor.cpp"
#include <cmath>
#include <cstdint>
#include <vector>
#include "Wav.h"
class Echo : public SignalProcessor {
public:

    std::vector<float> process(const std::vector<float> input, wav_hdr attributes) override;

};

#endif
