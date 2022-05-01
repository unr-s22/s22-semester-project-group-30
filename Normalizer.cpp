#include "Normalizer.h"
#include <iostream>

std::vector<float> Normalizer::process(const std::vector<float> input, wav_hdr attributes) {
    std::vector<float> output;
    float max = 0.0f;
    
    for(int i = 0; i < attributes.Subchunk1Size; i++){
        if(input[i] > max){
            max = input[i];
        }
    }
    for(int i = 0; i < attributes.Subchunk1Size; i++){
        output.push_back(input[i]/max);
    }
    
    return output;
}
