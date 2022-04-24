#ifndef FP_CONSOLE_H
#define FP_CONSOLE_H
#include <cstdint>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
class Console {
    std::string iFilename;
    std::string oFilename;
public:
    std::string getIFile();
    std::string getOFile();
    void displayAttributes(int, int, int, int);
    int getProcess();
    float getGain();
    int getDelay();
    void setAudio(const std::vector<float>& input, uint32_t subChunk1Size, uint16_t audioFormat, uint16_t numChannels, uint32_t sampleRate, uint16_t bitsPerSample, uint32_t subChunk2Size);

};

#endif