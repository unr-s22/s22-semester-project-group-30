#include "WavWriter.h"

void WavWriter::writeWav(std::ofstream& file, std::vector<float> input, wav_hdr header) {
    /* Header */
    uint8_t chunkID[4] = {'R','I','F','F'};
    uint8_t format[4] = {'W','A','V','E'};
    uint8_t subchunk1ID[4] = {'f','m','t',' '};
    uint8_t subchunk2ID[4] = {'d','a','t','a'};
    uint32_t chunkSize = (4 + (8 + header.Subchunk1Size) + (8 + (header.Subchunk2Size)));
    uint32_t byteRate = (header.SampleRate * header.NumChannels * (header.BitsPerSample/8));
    uint16_t blockAlign = (header.NumChannels * (header.BitsPerSample/8));
    
    file.write(reinterpret_cast<char*>(&chunkID), sizeof(uint32_t));
    file.write(reinterpret_cast<char*>(&chunkSize), sizeof(uint32_t));
    file.write(reinterpret_cast<char*>(&format), sizeof(uint32_t));

    /* Format Subchunk */
    file.write(reinterpret_cast<char*>(&subchunk1ID), sizeof(uint32_t));

    file.write(reinterpret_cast<char*>(&header.Subchunk1Size), sizeof(uint32_t));
    file.write(reinterpret_cast<char*>(&header.AudioFormat), sizeof(uint16_t));
    file.write(reinterpret_cast<char*>(&header.NumChannels), sizeof(uint16_t));
    file.write(reinterpret_cast<char*>(&header.SampleRate), sizeof(uint32_t));
    file.write(reinterpret_cast<char*>(&byteRate), sizeof(uint32_t));
    file.write(reinterpret_cast<char*>(&blockAlign), sizeof(uint16_t));
    file.write(reinterpret_cast<char*>(&header.BitsPerSample), sizeof(uint16_t));
    
    /* Data Subchunk */
    file.write(reinterpret_cast<char*>(&subchunk2ID), sizeof(uint32_t));
    
    
    if(header.BitsPerSample == 8) {
        uint32_t subchunk2size = input.size();
        uint8_t buffer[input.size()];
        std::cout << input.size() << std::endl;
        file.write(reinterpret_cast<char*>(&subchunk2size), sizeof(uint32_t));
        for(int i = 0; i < input.size(); i++) {
            buffer[i] = (input.at(i)+1)*UINT8_MAX/2;
        }
        file.write(reinterpret_cast<char*>(&buffer), sizeof(buffer));
    }
    else if(header.BitsPerSample == 16) {
        uint32_t subchunk2size = input.size()*2;
        int16_t buffer[input.size()];
        file.write(reinterpret_cast<char*>(&subchunk2size), sizeof(uint32_t));
        for(int i = 0; i < input.size(); i++) {
            buffer[i] = input.at(i)*INT16_MAX;
        }
        file.write(reinterpret_cast<char*>(&buffer), sizeof(buffer));
    }
}