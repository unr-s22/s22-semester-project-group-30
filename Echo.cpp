#include "Echo.h"

std::vector<float> Echo::processEcho(const std::vector<float>& input, float gain, int delay){
    std::vector<float> output;
    auto decay = log(0.001)/log(gain);
    int newsize = int(input.size() + delay*decay);
    std::vector<float> longerInput(newsize, 0.0f);
    longerInput.insert(longerInput.begin(), input.begin(), input.end());
    output.reserve(longerInput.size());
    /*WAV_HEADER variables;
    Get NumChannels variable in a different way */
    if(variables.NumChannels == 1){ //Mono
        for(int i = 0; i < newsize; i++){
            output.push_back(longerInput[i] + gain * output[i - delay]);
        } else {
            output.push_back(longerInput[i]);
        }
    } else if(variables.NumChannels == 2){ //Stereo
        for(int i = 0; i < newsize; i++){
            output.push_back(input[i] + gain * input[i - delay]);
            output.push_back(input[i + 1] + gain * input[i - delay + 1]);
        } else {
            output.push_back(input[i]);
            output.push_back(input[i + 1]);
        }
    }
    return output;
}