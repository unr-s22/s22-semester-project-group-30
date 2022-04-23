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
    void displayProcesses();
    int getProcess();
    float getGain();
    int getDelay();
    void setAudio(const std::vector<float>& input, int subChunk1Size, int audioFormat, int numChannels, uint32_t sampleRate, int bitsPerSample, uint8_t subChunk2Size);

};

#endif