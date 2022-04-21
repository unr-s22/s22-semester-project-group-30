#ifndef FP_SIGPROC_H
#define FP_SIGPROC_H
#include "WavModel.h"
class SignalProcessor {
private:
    std::vector<float> audioStart;
    WavModel wavData;
public:
    SignalProcessor();

    std::vector<float> getAudioStart(){
        audioStart = wavData.getAudio();        
        return audioStart;
    }

    virtual ~SignalProcessor();
};

#endif