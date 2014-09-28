#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(0,0,0);
	ofEnableAntiAliasing();
	guiSetting();
}

void ofApp::guiSetting(){
	b_button=false;
	gui.setup("NSSOLVER");
	gui.add(spacer1.setup());
	gui.add(button.setup("SAVE",b_button));
	
	gui_popup1.setup("POP_UP_BOX",ofVec2f(100., 100.));
	gui_popup1.add(spacer1__popup1.setup());
	gui_popup1.add(button__popup1.setup("SAVE",b_button));
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	gui.draw();
	gui_popup1.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
