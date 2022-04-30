#include "Controller.h"

void Controller::setUI(Console console) {
    UI = console;
}

void Controller::run() {
    WavModel model;
    Echo echo;
    Normalizer normalizer;
    Reverser reverser;

    model.openRead(UI.getIFile());
    for(auto i: model.getAudio()) {
        std::cout << i << ',';
    }

    UI.displayAttributes(
        model.getAttribute().SampleRate,
        model.getAttribute().BitsPerSample,
        model.getAttribute().NumChannels,
        model.getAttribute().Subchunk2Size/model.getAttribute().ByteRate
    );
    
    int processChoice = UI.getProcess();
    std::vector<float> const &inputAudio = model.getAudio();

    if(processChoice == 1){ 
        std::vector<float> const &outputAudioEcho = echo.processEcho(inputAudio, UI.getGain(), UI.getDelay(), model.getAttribute().NumChannels);
        UI.setAudio(outputAudioEcho, model.getAttribute().Subchunk1Size, model.getAttribute().AudioFormat, model.getAttribute().NumChannels, model.getAttribute().SampleRate, model.getAttribute().BitsPerSample, model.getAttribute().Subchunk2Size);
    } else if(processChoice == 2){
        
        std::vector<float> const &outputAudioNormalizer = normalizer.processNormalizer(model.getAudio(), model.getAttribute().BitsPerSample);
        UI.setAudio(outputAudioNormalizer, model.getAttribute().Subchunk1Size, model.getAttribute().AudioFormat, model.getAttribute().NumChannels, model.getAttribute().SampleRate, model.getAttribute().BitsPerSample, model.getAttribute().Subchunk2Size);
    } else if(processChoice == 3){
        std::vector<float> const &outputAudioReverser = reverser.processReverser(model.getAudio(), model.getAttribute().BitsPerSample);
        UI.setAudio(outputAudioReverser, model.getAttribute().Subchunk1Size, model.getAttribute().AudioFormat, model.getAttribute().NumChannels, model.getAttribute().SampleRate, model.getAttribute().BitsPerSample, model.getAttribute().Subchunk2Size);
    }

}