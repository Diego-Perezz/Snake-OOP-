#pragma once

#include "State.h"
#include "ofMain.h"

class PauseState : public State {

public:
    PauseState();
    ~PauseState();
    void reset();
    void update();
    void draw();
    void keyPressed(int key);

};