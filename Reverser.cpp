#include "Reverser.h"

std::vector<float> Reverser::processReverser(const std::vector<float>& input){
    std::vector<float> output;
    /*WAV_HEADER variables;
    Get NumChannels variable in a different way */
    if(variables.NumChannels == 1){ //Mono
        for(int i = input.size()-1; i >= 0; i--){
            output.push_back(input[i]);
        }
    } else if(variables.NumChannels == 2){ //Stereo
        for(int i = input.size()-1; i >= 0; i--){
            output.push_back(input[i]);
            output.push_back(input[i - 1]);
        }
    }
    return output;
}
