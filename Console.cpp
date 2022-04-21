#include "Console.h"

std::string Console::getIFile() {
    std::string filename;
    std::cout << "Enter input file: ";
    std::cin >> filename;
    iFilename = filename;
    return iFilename;
}

std::string Console::getOFile() {
    std::string filename;
    std::cout << "Enter output file: ";
    std::cin >> filename;
    oFilename = filename;
    return oFilename;
}

void Console::displayAttributes(int sr, int bps, int ch, int duration) {
    std::cout << "Filename: "        << iFilename << std::endl;
    std::cout << "Sample Rate: "     << sr        << std::endl; //samplerate variable needed
    std::cout << "Bits Per Sample: " << bps       << std::endl; //BPS variable
    std::cout << "Channel: "         << ch        << std::endl; //mono or stereo
    std::cout << "Duration: "        << std::setw(2) << std::setfill('0') << duration/60 << ':' << std::setw(2) << std::setfill('0') << duration%60 << std::endl; //size divided by bytes per second
}