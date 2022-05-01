#include "Normalizer.h"
#include <iostream>

std::vector<float> Normalizer::process(const std::vector<float>& input, uint16_t numChan, uint16_t bps){
    std::vector<float> output;
    float max = 0.0f;
    
    for(int i = 0; i < input.size(); i++){
        if(input[i] > max){
            max = input[i];
        }
    }
    for(int i = 0; i < input.size(); i++){
        output.push_back(input[i]/max);
    }
    
    return output;
}
