#include "LoseState.h"

//--------------------------------------------------------------
LoseState::LoseState() {

}   
//--------------------------------------------------------------
LoseState::~LoseState() {

}
//--------------------------------------------------------------
void LoseState::reset() {
    
}
//--------------------------------------------------------------
void LoseState::update() {
    
}
//--------------------------------------------------------------
void LoseState::draw() {
    ofSetColor(ofColor::black);
    ofDrawRectangle(0,0,ofGetWidth(),ofGetHeight());
    ofSetColor(ofColor::white);
    string text = "Has Perdido :(";
    ofDrawBitmapString(text, ofGetWidth()/2-8*text.length()/2, ofGetHeight()/2-11);
    ofDrawBitmapString("Score: " + to_string(State::getScore()),ofGetWidth()/2, ofGetHeight() - 100);
    return;
}
//--------------------------------------------------------------
void LoseState::keyPressed(int key) {
    
}
