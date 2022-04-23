#include "Controller.h"

int main() {
    Controller session;
    Console display;
    session.setUI(display);
    session.run();
    return 0;
}
