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
    std::cout << "\nFilename: "        << iFilename << std::endl;
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

void Console::setAudio(const std::vector<float>& input, uint32_t subChunk1Size, uint16_t audioFormat, uint16_t numChannels, uint32_t sampleRate, uint16_t bitsPerSample, uint32_t subChunk2Size){
    std::vector<float> audioOut;
    audioOut = input;
    uint32_t chunkSize = (4 + (8 + subChunk1Size) + (8 + (subChunk2Size)));
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
        uint8_t chunkID[4] = {'R','I','F','F'};
        
        outFile << chunkID;
        std::cout << outFile.tellp() << std::endl;
        /*
        outFile << 52; // "R" chunkID
        outFile << 49; // "I" chunkID
        outFile << 46; // "F" chunkID
        outFile << 46; // "F" chunkID
        */
        //outFile << chunkSize; //chunkSize
        outFile.write(reinterpret_cast<char*>(&chunkSize), sizeof(uint32_t));
        std::cout << outFile.tellp() << std::endl;
        outFile << "WAVE"; //format
        std::cout << outFile.tellp() << std::endl;
        /*
        outFile << 57; // "W" format
        outFile << 41; // "A" format
        outFile << 56; // "V" format
        outFile << 45; // "E" format
        */
        /* Format Subchunk */
        outFile << "fmt "; //subchunk1ID
        /*
        outFile << 66; // "f" subchunk1ID
        outFile << 109; // "m" subchunk1ID
        outFile << 74; // "t" subchunk1ID
        outFile << 20; // " " subchunk1ID
        */

        outFile << subChunk1Size; //subchunk1Size
        outFile << audioFormat; //audioFormat
        outFile << numChannels; //numChannels
        std::cout << outFile.tellp() << std::endl;
        outFile << sampleRate; //sampleRate
        outFile << byteRate; //byteRate
        outFile << blockAlign; //blockAlign
        outFile << bitsPerSample; //bitsPerSample
        
        /* Data Subchunk */
        outFile << "data"; //subchunk2ID
        /*
        outFile << 64; // "d" subchunk2ID
        outFile << 61; // "a" subchunk2ID
        outFile << 74; // "t" subchunk2ID
        outFile << 61; // "a" subchunk2ID
        */

        outFile << subChunk2Size; //subchunk2Size
        for(auto i: audioOut){
            outFile << i;
        }

        outFile.close();


    }
    /*Write Out to Wav File*/
}