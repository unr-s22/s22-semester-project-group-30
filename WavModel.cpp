#include "WavModel.h"

void WavModel::openRead(const std::string filename) {
    WavReader reader;
    std::ifstream wav(filename, std::ios::binary);
    if(wav.is_open()) {
        reader.readHeader(wav, header);
        int size;
        switch(header.BitsPerSample) {
            case 8:
                size = header.Subchunk2Size;
                break;
            case 16:
                size = header.Subchunk2Size/2;
        }
        float* audio = new float[size];
        reader.readSamples(audio,size,wav, header);
        for(int i = 0; i < size; i++) {
            this->audio.push_back(audio[i]);
        }
        wav.close();
        delete [] audio;
    }
    else {
        std::cout << "Error: Could not open file." << std::endl;
        exit(1);
    }
}

void WavModel::openWrite(const std::string filename, std::vector<float> input) {
    WavWriter writer;
    std::ofstream wav(filename, std::ios::binary);
    if(wav.is_open()){
        writer.writeWav(wav, input, header);
        wav.close();
    }
    else {
        std::cout << "Error: Could not open file" << std::endl;
        exit(1);
    }
}

std::vector<float> WavModel::getAudio() const {
    return audio;
}

wav_hdr WavModel::getAttribute() const {
    return header;
}