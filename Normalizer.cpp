#include "Normalizer.h"

std::vector<float> Nomralizer::processNormalizer(const std::vector<float>& input){
    std::vector<float> output;
    float max = 0.0f;
    for(int i = 0; i < input.size(); i++){
        if(abs(input[i]) > max){
            max = abs(input[i]);
        }
    }
    for(int i = 0; i < input.size(); i++){
        output.push_back(input[i]*(MAX8BIT/max);
    }
    return output;
}
