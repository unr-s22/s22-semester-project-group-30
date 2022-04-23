#include "Controller.h"

void Controller::setUI(Console console) {
    UI = console;
}

void Controller::run() {
    WavModel model;
    SignalProcessor processor;
    model.openRead(UI.getIFile());
    /*for(auto i: model.getAudio()) {
        std::cout << i << ',';
    }*/

    UI.displayAttributes(
        model.getAttribute().SampleRate,
        model.getAttribute().BitsPerSample,
        model.getAttribute().NumChannels,
        model.getAttribute().Subchunk2Size/model.getAttribute().ByteRate
    );
    /*UI.displayProcesses();
    int selection = UI.getSelection();*/

    int processChoice = UI.getProcess();
    if(processChoice == 1){ 
        std::vector<float> const in = model.getAudio();
        UI.setAudio((processor.processEcho(in, UI.getGain(), UI.getDelay(), model.getAttribute().NumChannels())), model.getAttribute().Subchunk1Size(), model.getAttribute().AudioFormat(), model.getAttribute().NumChannels(), model.getAttribute().SampleRate(), model.getAttribute().BitsPerSample(), model.getAttribute().Subchunk2Size());
    } else if(processChoice == 2){
        UI.setAudio(processor.processNormalizer(model.getAudio(), model.getAttribute().BitsPerSample()));
    } else if(processChoice == 3){
        UI.setAudio(processor.processReverser(model.getAudio(), model.getAttribute().BitsPerSample()));
    }

}