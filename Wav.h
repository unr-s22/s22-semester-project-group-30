#ifndef WAV_H
#define WAV_H
#include <cstdint>

typedef struct WAV_HEADER {
    uint8_t ChunkID[4];
    uint32_t ChunkSize;
    uint8_t Format[4];
    uint8_t Subchunk1ID[4];
    uint32_t Subchunk1Size;
    uint16_t AudioFormat;
    uint16_t NumChannels;
    uint32_t SampleRate;
    uint32_t ByteRate;
    uint16_t BlockAlign;
    uint16_t BitsPerSample;
    uint8_t Subchunk2ID[4];
    uint32_t Subchunk2Size;
}wav_hdr;


#endif