#ifndef FP_CONTROLLER_H
#define FP_CONTROLLER_H
#include "Console.h"
#include "WavModel.h"
#include "SignalProcessor.cpp"
class Controller {
    Console UI;
public:
    void setUI(Console);
    void run();
};

#endif