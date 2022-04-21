#include "Reverser.h"

std::vector<float> Reverser::processReverser(const std::vector<float>& input){
    std::vector<float> output;
    for(int i = input.size()-1; i >= 0; i--){
        output.push_back(input[i]);
    }
    return output;
}
