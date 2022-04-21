#ifndef FP_NORMALIZER_H
#define FP_NORMALIZER_H
#include "SignalProcessor.h"
#define MAX8BIT 255
class Normalizer : public SignalProcessor {
public:
    Normalizer();

    std::vector<float> processNormalizer(const std::vector<float>& input);

    virtual ~Normalizer();
};

#endif