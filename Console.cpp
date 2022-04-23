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

int Console::getProcess(){
    int selection;
    std::cout << "Select a process: " << std::endl;
    std::cout << "1. Echo" << std::endl;
    std::cout << "2. Normalize" << std::endl;
    std::cout << "3. Reverse" << std::endl;
    std::cin >> selection;
    return selection;
}

float Console::getGain(){
    float gain;
    std::cout << "Enter gain(0.001 to 0.999): ";
    std::cin >> gain;
    return gain;
}

int Console::getDelay(){
    int delay;
    std::cout << "Enter delay: ";
    std::cin >> delay;
    return delay;
}

void Console::setAudio(const std::vector<float>& input, int subChunk1Size, int audioFormat, int numChannels, uint32_t sampleRate, int bitsPerSample, uint8_t subChunk2Size){
    std::vector<float> audioOut;
    audioOut = input;
    int chunkSize = (4 + (8 + subChunk1Size) + (8 + (subChunk2Size)));
    uint32_t byteRate = (sampleRate * numChannels * (bitsPerSample/8));
    uint16_t blockAlign = (numChannels * (bitsPerSample/8));

    Console console;
    std::string outFileName = console.getOFile();

    std::ofstream outFile(outFileName, std::ios::binary);
    if(!outFile){
        std::cout << "Error opening file" << std::endl;
        exit(1);
    } else {
        /* Header */
        outFile << "RIFF"; //chunkID
        outFile << chunkSize; //chunkSize
        outFile << "WAVE"; //format

        /* Format Subchunk */
        outFile << "fmt "; //subchunk1ID
        outFile << subChunk1Size; //subchunk1Size
        outFile << audioFormat; //audioFormat
        outFile << numChannels; //numChannels
        outFile << sampleRate; //sampleRate
        outFile << byteRate; //byteRate
        outFile << blockAlign; //blockAlign
        outFile << bitsPerSample; //bitsPerSample
        
        /* Data Subchunk */
        outFile << "data"; //subchunk2ID
        outFile << subChunk2Size; //subchunk2Size
        for(auto i: audioOut){
            outFile << i;
        }

        outFile.close();
    }
    /*Write Out to Wav File*/
}