#include "WavReader.h"

void WavReader::readSamples(float* samples, size_t numBytes, std::ifstream& file, wav_hdr &header) {
        if(header.BitsPerSample == 8) {
            uint8_t* data = new uint8_t[numBytes];
            file.read(reinterpret_cast<char*>(data), numBytes);
            for(int i = 0; i < numBytes; i++) {
                samples[i] = (2*float(data[i])/UINT8_MAX)-1;
            }
            delete [] data;
        }
        if(header.BitsPerSample == 16) {
            int16_t* data = new int16_t[numBytes];
            file.read(reinterpret_cast<char*>(data), 2*numBytes);
            for(int i = 0; i < numBytes; i++) {
                samples[i] = float(data[i])/INT16_MAX;
            }
            delete [] data;
        }
    }

void WavReader::readHeader(std::ifstream& file, wav_hdr& header) {
    file.read(reinterpret_cast<char*>(&header), sizeof(header));
}