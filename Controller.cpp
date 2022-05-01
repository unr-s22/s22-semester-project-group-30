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
    /*
    for(auto i: model.getAudio()) {
        cout << i << ',';
    }
    */

    UI.displayAttributes(
        model.getAttribute().SampleRate,
        model.getAttribute().BitsPerSample,
        model.getAttribute().NumChannels,
        model.getAttribute().Subchunk2Size/model.getAttribute().ByteRate
    );
    
    int processChoice = UI.getProcess();
    vector<float> inputAudio = model.getAudio();

    if(processChoice == 1){ 
        vector<float> outputAudioEcho = echo.process(inputAudio, model.getAttribute());
        model.openWrite(UI.getOFile(), outputAudioEcho);
    } else if(processChoice == 2){
        std::vector<float> const &outputAudioNormalizer = normalizer.process(inputAudio, model.getAttribute());
        model.openWrite(UI.getOFile(), outputAudioNormalizer);
    }
	else {
		cout << "Error: Invalid choice." << endl;
	}
}
