#include "Echo.h"

std::vector<float> Echo::process(const std::vector<float> input, wav_hdr attributes){
    std::vector<float> output;
    float gain = 0.5;
    int delay = 2000;
    auto decay = log(0.001)/log(gain);
    int newsize = int(input.size() + delay*decay);
    std::vector<float> longerInput(newsize, 0.0f);
    longerInput.insert(longerInput.begin() + int(delay*decay), input.begin(), input.end());
    output.reserve(longerInput.size());

    if(attributes.NumChannels == 1){ //Mono
        for(int i = 0; i < newsize; i++){
            if(i < delay*decay){
                output.push_back(input[i]);
            }
            else{
                output.push_back(longerInput[i]*gain + input[i]);
                longerInput[i] += output[i]*decay;
            }
        }
<<<<<<< HEAD
    } else if(attributes.NumChannels == 2){ //Stereo
        for(int i = 0; i < newsize; i++){
            if(i < delay){
                output.push_back(0.0f);
                output.push_back(0.0f);
            }
            else if(output[i-delay] > 0.0f){
                output.push_back(input[i] + gain * input[i - delay]);
                output.push_back(input[i + 1] + gain * input[i - delay + 1]);
            } else {
=======
    } else if(numChan == 2){ //Stereo
        for(int i = 0; i < newsize; i+=2){
            if(i < delay*decay){
>>>>>>> 6481cacb33b6f59c12744a1e7944ca4fbfbdb75c
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
    return output;
}
