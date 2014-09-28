//
//  nsUIButton.cpp
//  nsUI_dev2
//
//  Created by 澤野陽介 on 2014/09/25.
//
//

#include "nsUIButton.h"

nsUIButton::nsUIButton(){
	ofRegisterMouseEvents(this,OF_EVENT_ORDER_BEFORE_APP);
}

nsUIButton::~nsUIButton(){
	value.removeListener(this,&nsUIButton::valueChanged);
	ofUnregisterMouseEvents(this,OF_EVENT_ORDER_BEFORE_APP);
}

nsUIButton* nsUIButton::setup(string _button_name, bool &_bVal){
	button_name=_button_name;
	p_lt_local=p_lt;
	p_lt_local.x+=space;
	button_width=panel_width-2.0*space;
	button_height=fontM.stringHeight(button_name)+2.*sub_space;
	updatePos(button_height);
	
	bGuiActive=false;
	value.set(button_name,_bVal);
	value.addListener(this,&nsUIButton::valueChanged);
	generateDraw();
	return this;
}

void nsUIButton::render(){
	border_path.draw();
	inner_path.draw();
	fontM.drawString(button_name, str_pos.x, str_pos.y);
}

void nsUIButton::generateDraw(){
	generateBorderBox();
	if (value) {
		generateInnerBox_active();
	}else{
		generateInnerBox_nomal();
	}
	generateButtonLabel();
}

void nsUIButton::generateBorderBox(){
	border_rect.set(p_lt_local.x, p_lt_local.y, button_width, button_height);
	border_path.clear();
	border_path.setStrokeColor(thisBorderColor);
	border_path.setStrokeWidth(1);
	border_path.setFilled(false);
	border_path.rectangle(border_rect);
}

void nsUIButton::generateInnerBox_nomal(){
	inner_rect.set(p_lt_local.x, p_lt_local.y, button_width, button_height);
	inner_path.clear();
	inner_path.setFillColor(thisFillColor);
	inner_path.rectangle(inner_rect);
}

void nsUIButton::generateInnerBox_active(){
	inner_rect.set(p_lt_local.x, p_lt_local.y, button_width, button_height);
	inner_path.clear();
	inner_path.setFillColor(thisFillColor_Active);
	inner_path.rectangle(inner_rect);
}

void nsUIButton::generateButtonLabel(){
	float str_width=fontM.stringWidth(button_name);
	float str_height=fontM.stringHeight(button_name);
	str_pos.x=p_lt_local.x+button_width/2.-str_width/2.;
	str_pos.y=p_lt_local.y+button_height/2.+str_height/2.;
}

bool nsUIButton::mouseDragged(ofMouseEventArgs &args){
	if(bGuiActive && border_rect.inside(ofPoint(args.x,args.y))){
		return true;
	}else{
		return false;
	}
}

bool nsUIButton::mouseMoved(ofMouseEventArgs &args){
	if(bGuiActive && border_rect.inside(ofPoint(args.x,args.y))){
		return true;
	}else{
		return false;
	}
}

bool nsUIButton::mousePressed(ofMouseEventArgs &args){
	if (setValue(args.x, args.y, true)) {
		return true;
	}
	return false;
}

bool nsUIButton::mouseReleased(ofMouseEventArgs &args){
	bool wasGuiActive = bGuiActive;
	bGuiActive = false;
	if(wasGuiActive && border_rect.inside(ofPoint(args.x,args.y))){
		return true;
	}else{
		return false;
	}
}

bool nsUIButton::setValue(float x, float y, bool b){
	if (b) {
		if (border_rect.inside(x, y)) {
			bGuiActive=true;
		}else{
			bGuiActive=false;
		}
	}
	if (bGuiActive) {
		value=!value;
		return true;
	}
	return false;
}

void nsUIButton::valueChanged(bool & value){
	//CHECK
	ofLog(OF_LOG_NOTICE, "valueChanged..."+ofToString(value));
	//
	generateDraw();
}