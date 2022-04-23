#ifndef FP_REVERSER_H
#define FP_REVERSER_H
#include "SignalProcessor.cpp"
#include <cstdint>
#include <vector>
class Reverser : public SignalProcessor {
public:
    Reverser();

    std::vector<float> processReverser(const std::vector<float>& input, uint16_t numChan);

    virtual ~Reverser();
};

#endif