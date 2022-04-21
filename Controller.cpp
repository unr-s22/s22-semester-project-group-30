#include "Controller.h"

void Controller::setUI(Console console) {
    UI = console;
}

void Controller::run() {
    WavModel model;
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
}