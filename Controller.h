#ifndef FP_CONTROLLER_H
#define FP_CONTROLLER_H
#include "Console.h"
#include "WavModel.h"
#include "Echo.h"
#include "Normalizer.h"
#include "Reverser.h"
class Controller {
    Console UI;
public:
    void setUI(Console);
    void run();
};

#endif