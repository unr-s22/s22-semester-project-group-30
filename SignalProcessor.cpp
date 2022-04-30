#ifndef FP_SIGPROC_H
#define FP_SIGPROC_H
#include <vector>
#include <cstdint>
class SignalProcessor {
public:

    const std::vector<float>& process(const std::vector<float>& input, uint16_t numChan, uint16_t bps);

};

#endif