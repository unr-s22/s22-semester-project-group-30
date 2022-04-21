#include "Echo.h"

std::vector<float> Echo::processEcho(const std::vector<float>& input, float gain, int delay){
    std::vector<float> output;
    auto decay = log(0.001)/log(gain);
    int newsize = int(input.size() + delay*decay);
    std::vector<float> longerInput(newsize, 0.0f);
    longerInput.insert(longerInput.begin(), input.begin(), input.end());
    output.reserve(longerInput.size());
    for(int i = 0; i < newsize; i++){
        output.push_back(longerInput[i] + gain * output[i - delay]);
    } else {
        output.push_back(longerInput[i]);
    }
    return output;
}