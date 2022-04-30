#include "Echo.h"

std::vector<float> Echo::process(const std::vector<float>& input, uint16_t numChan, uint16_t bps){
    std::vector<float> output;
    float gain = 0.5;
    int delay = 100;
    auto decay = log(0.001)/log(gain);
    int newsize = int(input.size() + delay*decay);
    std::vector<float> longerInput(newsize, 0.0f);
    longerInput.insert(longerInput.begin(), input.begin(), input.end());
    output.reserve(longerInput.size());

    if(numChan == 1){ //Mono
        for(int i = 0; i < newsize; i++){
            if(i < delay){
                output.push_back(0.0f);
            }
            else if(output[i-delay] > 0.0f){
                output.push_back(longerInput[i] + gain * output[i - delay]);
            } else {
                output.push_back(longerInput[i]);
            }
        }
    } else if(numChan == 2){ //Stereo
        for(int i = 0; i < newsize; i++){
            if(i < delay){
                output.push_back(0.0f);
                output.push_back(0.0f);
            }
            else if(output[i-delay] > 0.0f){
                output.push_back(input[i] + gain * input[i - delay]);
                output.push_back(input[i + 1] + gain * input[i - delay + 1]);
            } else {
                output.push_back(input[i]);
                output.push_back(input[i + 1]);

            }
        }
    }
    return output;
}
