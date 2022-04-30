#include "WavReader.h"

void WavReader::readHeader(std::ifstream& file, wav_hdr& header) {
    file.read(reinterpret_cast<char*>(&header), sizeof(header));
}