#ifndef FP_ECHO_H
#define FP_ECHO_H
#include "SignalProcessor.cpp"
#include <cmath>
#include <cstdint>
#include <vector>
class Echo : public SignalProcessor {
public:
    //Echo();
    
    std::vector<float> processEcho(const std::vector<float>& input, float gain, int delay, uint16_t numChan);

    //virtual ~Echo();
};

#endif