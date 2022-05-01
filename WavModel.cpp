#include "WavModel.h"

void WavModel::openRead(const std::string filename) {
    WavReader reader;
    std::ifstream wav(filename, std::ios::binary);
    if(wav.is_open()) {
        reader.readHeader(wav, header);
        
        uint8_t FileID[4] = {'R', 'I', 'F', 'F'};
        uint8_t FileType[4] = {'W', 'A', 'V', 'E'};
        uint8_t FmtID[4] = {'f', 'm', 't', ' '};
        uint8_t DataID[4] = {'d', 'a', 't', 'a'};

        if(header.ChunkID[0] == FileID[0] && header.ChunkID[1] == FileID[1] && header.ChunkID[2] == FileID[2] && header.ChunkID[3] == FileID[3] && header.Format[0] == FileType[0] && header.Format[1] == FileType[1] && header.Format[2] == FileType[2] && header.Format[3] == FileType[3] && header.Subchunk1ID[0] == FmtID[0] && header.Subchunk1ID[1] == FmtID[1] && header.Subchunk1ID[2] == FmtID[2] && header.Subchunk1ID[3] == FmtID[3] && header.Subchunk2ID[0] == DataID[0] && header.Subchunk2ID[1] == DataID[1] && header.Subchunk2ID[2] == DataID[2] && header.Subchunk2ID[3] == DataID[3]) { 
            int size;
            switch(header.BitsPerSample) {
                case 8:
                    size = header.Subchunk2Size;
                    break;
                case 16:
                    size = header.Subchunk2Size/2;
            }
            float* audio = new float[size];
            reader.readSamples(audio,size,wav, header);
            for(int i = 0; i < size; i++) {
                this->audio.push_back(audio[i]);
            }
            wav.close();
            delete [] audio;
        } else {
            std::cout << "Error: File is not a wav file." << std::endl;
            exit(1);
        }
    } else{
        std::cout << "Error: File could not be opened." << std::endl;
        exit(1);
    }
}

void WavModel::openWrite(const std::string filename, std::vector<float> input) {
    WavWriter writer;
    std::ofstream wav(filename, std::ios::binary);
    if(wav.is_open()){
        writer.writeWav(wav, input, header);
        wav.close();
    }
    else {
        std::cout << "Error: Could not open file" << std::endl;
        exit(1);
    }
}

std::vector<float> WavModel::getAudio() const {
    return audio;
}

wav_hdr WavModel::getAttribute() const {
    return header;
}