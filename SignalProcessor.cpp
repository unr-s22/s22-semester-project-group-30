#ifndef FP_SIGPROC_H
#define FP_SIGPROC_H
class SignalProcessor {
public:
    SignalProcessor();

    virtual std::vector<float> processEcho();
    virtual std::vector<float> processNormalizer();
    virtual std::vector<float> processReverser();

    virtual ~SignalProcessor();
};

#endif