#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofSetWindowTitle("Snake");

    gameState = new GameState();
    menuState = new MenuState();
    loseState = new LoseState();
	pauseState = new PauseState();
    currentState = menuState;

    música.load("música.mp3");
	música.setLoop(true);
	música.play();

}

//--------------------------------------------------------------
void ofApp::update(){
    if(currentState->hasFinished()) {
        if(currentState->getNextState() == "GameState") {
            gameState->reset();
            currentState = gameState;
        } else if(currentState->getNextState() == "LoseState") {
            loseState->setScore(gameState->getScore());
            loseState->reset();
            currentState = loseState;
        }
		 else if(currentState->getNextState() == "PauseState") {
            // loseState->setScore(gameState->getScore());
            pauseState->reset();
            currentState = pauseState;
        }
    }
    currentState->update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    currentState->draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    currentState->keyPressed(key);
}
//--------------------------------------------------------------