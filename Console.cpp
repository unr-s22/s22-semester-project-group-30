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
        uint8_t format[4] = {'W','A','V','E'};
        uint8_t subchunk1ID[4] = {'f','m','t',' '};
        uint8_t subchunk2ID[4] = {'d','a','t','a'};
        
        outFile.write(reinterpret_cast<char*>(&chunkID), sizeof(uint32_t));
        /*
        outFile << 52; // "R" chunkID
        outFile << 49; // "I" chunkID
        outFile << 46; // "F" chunkID
        outFile << 46; // "F" chunkID
        */
        outFile.write(reinterpret_cast<char*>(&chunkSize), sizeof(uint32_t));
        outFile.write(reinterpret_cast<char*>(&format), sizeof(uint32_t));
        /*
        outFile << 57; // "W" format
        outFile << 41; // "A" format
        outFile << 56; // "V" format
        outFile << 45; // "E" format
        */
        /* Format Subchunk */
        outFile.write(reinterpret_cast<char*>(&subchunk1ID), sizeof(uint32_t));
        /*
        outFile << 66; // "f" subchunk1ID
        outFile << 109; // "m" subchunk1ID
        outFile << 74; // "t" subchunk1ID
        outFile << 20; // " " subchunk1ID
        */

        outFile.write(reinterpret_cast<char*>(&subChunk1Size), sizeof(uint32_t));
        outFile.write(reinterpret_cast<char*>(&audioFormat), sizeof(uint16_t));
        outFile.write(reinterpret_cast<char*>(&numChannels), sizeof(uint16_t));
        outFile.write(reinterpret_cast<char*>(&sampleRate), sizeof(uint32_t));
        outFile.write(reinterpret_cast<char*>(&byteRate), sizeof(uint32_t));
        outFile.write(reinterpret_cast<char*>(&blockAlign), sizeof(uint16_t));
        outFile.write(reinterpret_cast<char*>(&bitsPerSample), sizeof(uint16_t));
        
        /* Data Subchunk */
        outFile.write(reinterpret_cast<char*>(&subchunk2ID), sizeof(uint32_t));
        /*
        outFile << 64; // "d" subchunk2ID
        outFile << 61; // "a" subchunk2ID
        outFile << 74; // "t" subchunk2ID
        outFile << 61; // "a" subchunk2ID
        */

        outFile.write(reinterpret_cast<char*>(&subChunk2Size), sizeof(uint32_t));
        
        if(bitsPerSample == 8) {
            uint8_t buffer[subChunk2Size];
        }
        else if(bitsPerSample == 16) {
            int16_t buffer[input.size()];
            for(int i = 0; i < input.size(); i++) {
                buffer[i] = input.at(i)*INT16_MAX;
            }
            outFile.write(reinterpret_cast<char*>(&buffer), sizeof(buffer));
        }

        outFile.close();


    }
    /*Write Out to Wav File*/
}