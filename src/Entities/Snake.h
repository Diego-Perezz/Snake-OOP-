#pragma once
#include <vector>
#include "ofMain.h"

enum Direction {
        LEFT,
        RIGHT,
        UP,
        DOWN,
        NONE
    };

class Snake {

private:
    std::vector<std::vector<int>> body;
    Direction direction;
    int boardSizeWidth, boardSizeHeight;
    int segmentSize;
    bool crashed;
    string ActivePowerUp = "none";

public:
    Snake(int segmentSize, int boardSizeW, int boardSizeH);
    ~Snake();

    void update();
    void draw();
    void changeDirection(Direction d);
    void checkSelfCrash();
    void grow();
    void undo();
    bool isCrashed() {
        return this->crashed;
    }
    std::vector<int> getHead() {
        return this->body[0];
    }
    std::vector<int> getTail() {
        return this->body[this->body.size() - 1];
    }
    std::vector<std::vector<int>> getBody() {
        return this->body;
    }
    void setCrashed(bool crashed){
        this->crashed = crashed;
    }
    
    ofRectangle getBounds();


    bool SpeedBoost = false;
    bool BetterApple = false;
    bool Godmode = false;

    bool UsePowerUp = false;


    void setActivePowerUp(string PowerUp){
        this->ActivePowerUp = PowerUp;
    }
    string getActivePowerUp(){
        return this->ActivePowerUp;
    }
    

};
