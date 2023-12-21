#include "PauseState.h"

//--------------------------------------------------------------
PauseState::PauseState() {

}   
//--------------------------------------------------------------
PauseState::~PauseState() {

}
//--------------------------------------------------------------
void PauseState::reset() {
    setFinished(false);
    setNextState("");
    return;
}
//--------------------------------------------------------------
void PauseState::update() {

}
//--------------------------------------------------------------
void PauseState::draw() {
    ofSetColor(ofColor::black);
    ofDrawRectangle(0,0,ofGetWidth(),ofGetHeight());
    ofSetColor(ofColor::white);
    string texto1 = "Pausa";
    ofDrawBitmapString(texto1, ofGetWidth()/2-8*texto1.length()/2, ofGetHeight()/2-11);
    string texto2 = "Oprime \"c\" para continuar";
    ofDrawBitmapString(texto2, ofGetWidth()/2-8*texto2.length()/2, ofGetHeight()/3-11);
    return;
}
//--------------------------------------------------------------
void PauseState::keyPressed(int key) {
    if(key == 'c')
    {
        setFinished(true);
        setNextState("GameState");
        return;
    }
}
