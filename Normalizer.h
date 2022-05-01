#ifndef FP_NORMALIZER_H
#define FP_NORMALIZER_H
#include "SignalProcessor.cpp"
#include <cstdint>
#include <cmath>
#include <vector>
#define MAX8BIT 255
#define MAX16BIT 32767
#define MIN16BIT 32768
class Normalizer : public SignalProcessor {
public:

    std::vector<float> process(const std::vector<float>& input, uint16_t numChan, uint16_t bps);

};

#endif
