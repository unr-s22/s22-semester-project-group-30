#ifndef FP_NORMALIZER_H
#define FP_NORMALIZER_H
#include "SignalProcessor.h"
#define MAX8BIT 255
#define MAX16BIT 32767
#define MIN16BIT -32768
class Normalizer : public SignalProcessor {
public:
    Normalizer();

    std::vector<float> processNormalizer(const std::vector<float>& input);

    virtual ~Normalizer();
};

#endif