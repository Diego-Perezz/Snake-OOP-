#include "GameState.h"
#include "LoseState.h"
#include "StaticEntity.h"


#include "PauseState.h"

//--------------------------------------------------------------
GameState::GameState() {
    foodSpawned = false;
    cellSize = 25;
    boardSizeWidth = 64;
    boardSizeHeight = 36;
    snake = new Snake(cellSize, boardSizeWidth, boardSizeHeight);

    treeimage.load("images/tree.png");
    rockimage.load("images/rock.png");
    wallimage.load("images/wall.png");
    waterimage.load("images/water.png");
    fireimage.load("images/fire.png");

    tree = new StaticEntity(47 * 25 ,6 * 25,25,25,treeimage);
    rock = new StaticEntity(15 * 25,14 * 25,25,25,rockimage);
    wall = new StaticEntity(10 * 25,20 * 25,25,25,wallimage);
    water = new StaticEntity(32 * 25,13 * 25,25,25,waterimage);
    fire = new StaticEntity(25 * 25,2 * 25,25,25,fireimage);

    tree2 = new StaticEntity(6 * 25,21 * 25,25,25,treeimage);
    rock2 = new StaticEntity(39 * 25,25 * 25,25,25,rockimage);
    wall2 = new StaticEntity(28 * 25,1 * 25,25,25,wallimage);
    water2 = new StaticEntity(40 * 25,16 * 25,25,25,waterimage);
    fire2 = new StaticEntity(63 * 25,11 * 25,25,25,fireimage);

    addEntity(tree);
    addEntity(rock);
    addEntity(wall);
    addEntity(water);
    addEntity(fire);


    addEntity(tree2);
    addEntity(rock2);
    addEntity(wall2);
    addEntity(water2);
    addEntity(fire2);
}
//--------------------------------------------------------------
GameState::~GameState() {
    delete snake;
}
//--------------------------------------------------------------
void GameState::reset() {
    // delete snake;
    // snake = new Snake(cellSize, boardSizeWidth, boardSizeHeight);
    // foodSpawned = false;
    setFinished(false);
    setNextState("");
    setScore(getScore()); 
}
//--------------------------------------------------------------
void GameState::update() {

    if(snake->isCrashed()) {
        this->setNextState("LoseState");
        this->setFinished(true);
        State::setScore(getScore());
        return;
    }

    if(snake->getHead()[0] == currentFoodX && snake->getHead()[1] == currentFoodY) {
        snake->grow();
        foodSpawned = false;
        increaseScore();
    }

    foodSpawner();
    if(ofGetFrameNum() % 10 == 0) {
        snake->update();
        for (StaticEntity* obstacle : obstacles){
            if (obstacle->collides(snake)){
                snake->setCrashed(true);
            }
        }
    }

    if (snake->SpeedBoost && getScore() > 50){
        if (ofGetFrameNum() == 8){
            snake->update();
            timer += 1;
            if (timer >= 450){
                snake->SpeedBoost = false;
                snake->Snake::setActivePowerUp("none");
                timer = 0;
            }
        }
    }

    

}
//--------------------------------------------------------------
void GameState::draw() {
    drawBoardGrid();
    snake->draw();
    for (StaticEntity* obstacle : obstacles){
        obstacle->draw();
    }
    drawFood();
    ofSetColor(ofColor::white);
    ofDrawBitmapString("Score: " + to_string(getScore()),ofGetWidth()/2, ofGetHeight() - 100);

    ofDrawBitmapString("Stored Power-Up: " + snake->Snake::getActivePowerUp(), ofGetWidth()-260,45);
    ofDrawBitmapString("Press 'b' to activate Power-Up", ofGetWidth()-260,60);
}
//--------------------------------------------------------------
void GameState::keyPressed(int key) {

    // if(key != OF_KEY_LEFT && key != OF_KEY_RIGHT && key != OF_KEY_UP && key != OF_KEY_DOWN) { return; }

    switch(key) {
        case OF_KEY_LEFT:
            snake->changeDirection(LEFT);
            break;
        case OF_KEY_RIGHT:
            snake->changeDirection(RIGHT);
            break;
        case OF_KEY_UP:
            snake->changeDirection(UP);
            break;
        case OF_KEY_DOWN:
            snake->changeDirection(DOWN);
            break;
        case 'a':
            increaseScore();
            break;
        case 'u':
            if(snake->getBody().size() > 2)
            {
                snake->undo();
            }
            break;
        case 'p':
            this->setNextState("PauseState");
            this->setFinished(true);
            return;
        case 'b':
            if (!snake->BetterApple && !snake->Godmode){
                snake->SpeedBoost = true;
            }
            break;    
    }
}
//--------------------------------------------------------------
void GameState::foodSpawner() {
    if(!foodSpawned) {
        bool isInSnakeBody;
        do {
            isInSnakeBody = false;
            currentFoodX = ofRandom(1, boardSizeWidth-1);
            currentFoodY = ofRandom(1, boardSizeHeight-1);
            for(unsigned int i = 0; i < snake->getBody().size(); i++) {
                if(currentFoodX == snake->getBody()[i][0] and currentFoodY == snake->getBody()[i][1]) {
                    isInSnakeBody = true;
                }
            }
        } while(isInSnakeBody);
        foodSpawned = true;
    }
}
//--------------------------------------------------------------
void GameState::drawFood() {
    ofSetColor(ofColor::red);
    if(foodSpawned) {
        ofDrawRectangle(currentFoodX*cellSize, currentFoodY*cellSize, cellSize, cellSize);
    }
}
//--------------------------------------------------------------
void GameState::drawStartScreen() {
    ofSetColor(ofColor::black);
    ofDrawRectangle(0,0,ofGetWidth(),ofGetHeight());
    ofSetColor(ofColor::white);
    string text = "Press any arrow key to start.";
    ofDrawBitmapString(text, ofGetWidth()/2-8*text.length()/2, ofGetHeight()/2-11);
    return;
}
//--------------------------------------------------------------
void GameState::drawLostScreen() {
    ofSetColor(ofColor::black);
    ofDrawRectangle(0,0,ofGetWidth(),ofGetHeight());
    ofSetColor(ofColor::white);
    string text = "You lost! Press any arrow key to play again";
    string text2 = "or press ESC to exit.";
    ofDrawBitmapString(text, ofGetWidth()/2-8*text.length()/2, ofGetHeight()/2-11);
    ofDrawBitmapString(text2, ofGetWidth()/2-8*text2.length()/2, ofGetHeight()/2+2);
    return;
}
//--------------------------------------------------------------
void GameState::drawBoardGrid() {
    
    ofDrawGrid(25, 64, false, false, false, true);
    
    // ofSetColor(ofColor::white);
    // for(int i = 0; i <= boardSize; i++) {
    //     ofDrawLine(i*cellSize, 0, i*cellSize, ofGetHeight());
    //     ofDrawLine(0, i*cellSize, ofGetWidth(), i*cellSize);
    // }
}
//--------------------------------------------------------------


void GameState::addEntity(StaticEntity *e){
    obstacles.push_back(e);
}