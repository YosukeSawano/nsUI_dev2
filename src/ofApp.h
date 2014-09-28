#pragma once

#include "ofMain.h"
#include "nsUIBase.h"
#include "nsUIPanel.h"
#include "nsUISpacer.h"
#include "nsUIButton.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
	
	
private:
	void guiSetting();
	
	nsUIPanel gui;
	nsUISpacer spacer1;
	nsUIButton button;
	
	nsUIPanel gui_popup1;
	nsUISpacer spacer1__popup1;
	nsUIButton button__popup1;
	bool b_button;
	
	
};
