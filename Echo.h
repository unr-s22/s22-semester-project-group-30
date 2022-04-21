#ifndef FP_ECHO_H
#define FP_ECHO_H
#include "SignalProcessor.h"
#include <cmath>
class Echo : public SignalProcessor {
public:
    Echo(): SignalProcessor() {getAudioStart();};
    
    std::vector<float> processEcho(const std::vector<float>& input, float gain, int delay);

    virtual ~Echo();
};

#endif