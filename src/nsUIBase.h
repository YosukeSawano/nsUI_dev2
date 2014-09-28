//
//  nsUIBase.h
//  nsUI_dev2
//
//  Created by 澤野陽介 on 2014/09/25.
//
//

#ifndef __nsUI_dev2__nsUIBase__
#define __nsUI_dev2__nsUIBase__

#include <iostream>
#include "ofMain.h"

class nsUIBase{
public:
	nsUIBase();
	~nsUIBase();
	
	void draw();

protected:
	virtual void render()=0;
	virtual void generateDraw()=0;
	
	void updatePos(float height);
	
	static ofTrueTypeFont fontL;
	static ofTrueTypeFont fontM;
	static ofTrueTypeFont fontS;

	static ofColor headerBackgroundColor;
	static ofColor backgroundColor;
	static ofColor borderColor;
	static ofColor panelColor;
	static ofColor textColor;
	static ofColor fillColor;
	static ofColor fillColor_Active;
	
	ofColor thisHeaderBackgroundColor;
	ofColor thisBackgroundColor;
	ofColor thisBorderColor;
	ofColor thisPanelColor;
	ofColor thisTextColor;
	ofColor thisFillColor;
	ofColor thisFillColor_Active;
	
	static const float panel_width;
	static const float L_height, M_height, S_height;
	static const float space;
	static const float sub_space;
	static ofVec2f p_lt;
	static ofVec2f p_lb;
	
	ofRectangle border_rect;
	ofRectangle inner_rect;
	ofPath border_path;
	ofPath inner_path;
	
private:
	void setDefaultColor();
	void loadFont();
};

#endif /* defined(__nsUI_dev2__nsUIBase__) */
