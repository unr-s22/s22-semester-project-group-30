#include "Echo.h"
#include <iostream>

std::vector<float> Echo::process(const std::vector<float> input, wav_hdr attributes){
    std::vector<float> output;
    float gain = 0.5;
    int delay = 10000;
    auto decay = log(0.001)/log(gain);
    int newsize = int(input.size() + delay*decay);
    std::vector<float> longerInput(newsize, 0.0f);
    longerInput.insert(longerInput.begin() + int(delay*decay), input.begin(), input.end());

    if(attributes.NumChannels == 1){ //Mono
        for(int i = 0; i < input.size(); i++){
            if(i < delay*decay){
                output.push_back(input[i]);
            }
            else{
                output.push_back(longerInput[i]*gain + input[i]);
                longerInput[i] += output[i]*decay;
            }
        }
    } else if(attributes.NumChannels == 2){ //Stereo
        for(int i = 0; i < input.size(); i+=2){
            if(i < delay*decay){
                output.push_back(input[i]);
                output.push_back(input[i+1]);
            }
            else{
                output.push_back(longerInput[i]*gain + input[i]);
                output.push_back(longerInput[i+1]*gain + input[i+1]);
                longerInput[i] += output[i]*decay;
                longerInput[i+1] += output[i+1]*decay;
            }
        }
    }
	else {
		std::cout << "Error!" << std::endl;
	}
    return output;
}
