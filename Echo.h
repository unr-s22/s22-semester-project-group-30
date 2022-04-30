#ifndef FP_ECHO_H
#define FP_ECHO_H
#include "SignalProcessor.cpp"
#include <cmath>
#include <cstdint>
#include <vector>
class Echo : public SignalProcessor {
public:

    std::vector<float> process(const std::vector<float>& input, uint16_t numChan, uint16_t bps);

};

#endif
