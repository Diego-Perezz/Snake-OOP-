#pragma once

#include "State.h"
#include "Snake.h"
#include "ofMain.h"
#include "StaticEntity.h"


class GameState : public State {
    public:
        GameState();
        ~GameState();
        void reset();
        void update();
        void draw();
        void keyPressed(int key);
        void foodSpawner();
        void drawFood();
        void drawStartScreen();
        void drawLostScreen();
        void drawBoardGrid();

        Snake* snake;
        ofImage treeimage;
        ofImage rockimage;
        ofImage wallimage;
        ofImage waterimage;
        ofImage fireimage;
        

        StaticEntity* tree;
        StaticEntity* rock;
        StaticEntity* wall;
        StaticEntity* water;
        StaticEntity* fire;

        StaticEntity* tree2;
        StaticEntity* rock2;
        StaticEntity* wall2;
        StaticEntity* water2;
        StaticEntity* fire2;
        
        bool foodSpawned = false;
        int timer = 0;


        int currentFoodX;
        int currentFoodY;

        int boardSizeWidth, boardSizeHeight;
        int cellSize; // Pixels

        
        std::vector<StaticEntity*> obstacles;
        void addEntity(StaticEntity *e);
};