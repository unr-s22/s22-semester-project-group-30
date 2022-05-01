#include "Reverser.h"

std::vector<float> Reverser::process(const std::vector<float>& input, uint16_t numChan, uint16_t bps){
    std::vector<float> output;
    if(numChan == 1){ //Mono
        for(int i = input.size()-1; i >= 0; i--){
            output.push_back(input[i]);
        }
    } else if(numChan == 2){ //Stereo
        for(int i = input.size()-1; i >= 0; i--){
            output.push_back(input[i]);
            output.push_back(input[i - 1]);
        }
    }
    return output;
}