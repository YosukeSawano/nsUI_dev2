//
//  nsUIBase.cpp
//  nsUI_dev2
//
//  Created by 澤野陽介 on 2014/09/25.
//
//

#include "nsUIBase.h"


const float nsUIBase::panel_width = 150.0;
const float nsUIBase::L_height = 25.0;
const float nsUIBase::M_height = 20.0;
const float nsUIBase::S_height = 15.0;
const float nsUIBase::space = 10.0;
const float nsUIBase::sub_space = 5.0;
ofColor
nsUIBase::headerBackgroundColor(64),
nsUIBase::backgroundColor(0),
nsUIBase::borderColor(150,100),
nsUIBase::panelColor(128,128,128,50),
nsUIBase::textColor(255),
nsUIBase::fillColor(100),
nsUIBase::fillColor_Active(180);

ofVec2f nsUIBase::p_lt = ofVec2f(space, space);
ofVec2f nsUIBase::p_lb = ofVec2f(space, space);

ofTrueTypeFont nsUIBase::fontL;
ofTrueTypeFont nsUIBase::fontM;
ofTrueTypeFont nsUIBase::fontS;
nsUIBase::nsUIBase(){
	setDefaultColor();
	loadFont();
}

nsUIBase::~nsUIBase(){
	
}

void nsUIBase::setDefaultColor(){
	thisHeaderBackgroundColor=headerBackgroundColor;
	thisBackgroundColor=backgroundColor;
	thisBorderColor=borderColor;
	thisPanelColor=panelColor;
	thisTextColor=textColor;
	thisFillColor=fillColor;
	thisFillColor_Active=fillColor_Active;
}

void nsUIBase::loadFont(){
	fontL.loadFont("HelveticaNeueDeskUI.ttc", 15);
	fontM.loadFont("HelveticaNeueDeskUI.ttc", 11);
	fontS.loadFont("HelveticaNeueDeskUI.ttc", 9);

}

void nsUIBase::draw(){
	render();
}

void nsUIBase::updatePos(float height){
	p_lt.y+=height+space;
}
