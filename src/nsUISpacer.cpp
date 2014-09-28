//
//  nsUISpacer.cpp
//  nsUI_dev2
//
//  Created by 澤野陽介 on 2014/09/26.
//
//

#include "nsUISpacer.h"

const float nsUISpacer::spacer_width=panel_width-2.0*space;
const float nsUISpacer::stroke_width=1.0;

nsUISpacer::nsUISpacer(){
	
}

nsUISpacer::~nsUISpacer(){
	
}

nsUISpacer* nsUISpacer::setup(){
	p_lt_local=p_lt;
	p_lt_local.x+=space;
	updatePos(stroke_width);
	generateDraw();
	return this;
}

void nsUISpacer::render(){
	stroke.draw();
}

void nsUISpacer::generateDraw(){
	stroke.clear();
	stroke.moveTo(p_lt_local.x, p_lt_local.y);
	stroke.lineTo(p_lt_local.x+spacer_width,p_lt_local.y);
	stroke.setFilled(false);
	stroke.setStrokeColor(thisBorderColor);
	stroke.setStrokeWidth(stroke_width);
}