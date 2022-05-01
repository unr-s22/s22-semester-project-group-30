#include "Controller.h"
using namespace std;

void Controller::setUI(Console console) {
    UI = console;
}

void Controller::run() {
    WavModel model;
    Echo echo;
    Normalizer normalizer;

    model.openRead(UI.getIFile());
    for(auto i: model.getAudio()) {
        cout << i << ',';
    }

    UI.displayAttributes(
        model.getAttribute().SampleRate,
        model.getAttribute().BitsPerSample,
        model.getAttribute().NumChannels,
        model.getAttribute().Subchunk2Size/model.getAttribute().ByteRate
    );
    
    int processChoice = UI.getProcess();
    vector<float> const &inputAudio = model.getAudio();

    if(processChoice == 1){ 
        vector<float> const &outputAudioEcho = echo.process(inputAudio, model.getAttribute().NumChannels, model.getAttribute().BitsPerSample);
        UI.setAudio(outputAudioEcho, model.getAttribute().Subchunk1Size, model.getAttribute().AudioFormat, model.getAttribute().NumChannels, model.getAttribute().SampleRate, model.getAttribute().BitsPerSample, model.getAttribute().Subchunk2Size);
    } else if(processChoice == 2){
        vector<float> const &outputAudioNormalizer = normalizer.process(inputAudio, model.getAttribute().NumChannels, model.getAttribute().BitsPerSample);
        UI.setAudio(outputAudioNormalizer, model.getAttribute().Subchunk1Size, model.getAttribute().AudioFormat, model.getAttribute().NumChannels, model.getAttribute().SampleRate, model.getAttribute().BitsPerSample, model.getAttribute().Subchunk2Size);
    }

}
