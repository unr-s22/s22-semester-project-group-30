#include "WavReader.h"

void WavReader::convertToFloat(float* samples, size_t numBytes, std::ifstream& file, wav_hdr header) {
    if(header.BitsPerSample == 8) {
        uint8_t data[numBytes];
        readSamples(data, numBytes, file);
        for(int i = 0; i < header.NumChannels*numBytes; i++) {
            samples[i] = float(data[i])/255;
        }
    }
    else if(header.BitsPerSample == 16) {
        int16_t data[numBytes];
        readSamples(data, 2*numBytes, file);
        for(int i = 0; i < numBytes; i++) {
            samples[i] = float(data[i])/32767;
        }
    }
}

void WavReader::readHeader(std::ifstream& file, wav_hdr& header) {
    file.read(reinterpret_cast<char*>(&header), sizeof(header));
    
}