#ifndef FP_REVERSER_H
#define FP_REVERSER_H
#include "SignalProcessor.h"

class Reverser : public SignalProcessor {
public:
    Reverser();

    std::vector<float> processReverser(const std::vector<float>& input);

    virtual ~Reverser();
};

#endif