#include "Normalizer.h"
#include <iostream>
std::vector<float> Normalizer::processNormalizer(const std::vector<float>& input, uint16_t bps){
    std::vector<float> output;
    float max = 0.0f;
    
    for(int i = 0; i < input.size(); i++){
        if(input[i] > max){
            max = input[i];
        }
    }

    if(bps == 8){
        for(int i = 0; i < input.size(); i++){
            output.push_back(input[i]*(MAX8BIT/max));
        }
    } else if(bps == 16){
        for(int i = 0; i < input.size(); i++){
            output.push_back(input[i]/max);
        }
    }
    
    return output;
}
