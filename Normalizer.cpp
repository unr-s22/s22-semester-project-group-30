#include "Normalizer.h"

std::vector<float> Nomralizer::processNormalizer(const std::vector<float>& input){
    std::vector<float> output;
    float max = 0.0f;
    for(int i = 0; i < input.size(); i++){
        if(abs(input[i]) > max){
            max = abs(input[i]);
        }
    }
    /*WAV_HEADER variables;
    Get BitsPerSample variable in a different way */
    if(variables.BitsPerSample == 8){
        for(int i = 0; i < input.size(); i++){
            output.push_back(input[i]*(MAX8BIT/max);
        }
    } else if(variables.BitsPerSample == 16){
        for(int i = 0; i < input.size(); i++){
            if(input[i] > 0){
                output.push_back(input[i]*(MAX16BIT/max);
            } else if( input[i] < 0){
                output.push_back(input[i]*(MIN16BIT/max);
            }
        }
    }
    return output;
}
