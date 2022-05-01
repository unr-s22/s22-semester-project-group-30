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
};

#endif