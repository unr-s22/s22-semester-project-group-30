#ifndef FP_SIGPROC_H
#define FP_SIGPROC_H
#include <vector>
#include <cstdint>
class SignalProcessor {
public:

    virtual std::vector<float> process(const std::vector<float>, wav_hdr) = 0;

};

#endif