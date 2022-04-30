#include "WavModel.h"

void WavModel::openRead(const std::string filename) {
    WavReader reader;
    std::ifstream wav(filename, std::ios::binary);
    reader.readHeader(wav, header);
    int size;
    switch(header.BitsPerSample) {
        case 8:
            size = header.Subchunk2Size;
            break;
        case 16:
            size = header.Subchunk2Size/2;
    }
    float audio[size];
    reader.readSamples(audio,size,wav, header);
    for(auto i: audio) {
        this->audio.push_back(i);
    }
    wav.close();
}