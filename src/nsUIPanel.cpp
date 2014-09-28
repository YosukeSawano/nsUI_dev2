//
//  nsUIPanel.cpp
//  nsUI_dev2
//
//  Created by 澤野陽介 on 2014/09/25.
//
//

#include "nsUIPanel.h"

nsUIPanel::nsUIPanel(){
	
}

nsUIPanel::~nsUIPanel(){
	
}

void nsUIPanel::setup(string _panelname){
	panelname=_panelname;
	p_lt_local=p_lt;
	label_height=L_height;
	label_width=panel_width;
	updatePos(label_height);
}

void nsUIPanel::setup(string _panelname, ofVec2f _p_lt){
	panelname=_panelname;
	p_lt=_p_lt;
	p_lt_local=p_lt;
	label_height=L_height;
	label_width=panel_width;
	updatePos(label_height);
}

void nsUIPanel::add(nsUISpacer *spacer){
	addToCollection(spacer);
}

void nsUIPanel::add(nsUIButton * button){
	addToCollection(button);
}

void nsUIPanel::addToCollection(nsUIBase * element){
	collection.push_back(element);
}

void nsUIPanel::render(){
	generateDraw();
	for (int i=0; i<collection.size(); ++i) {
		collection[i]->draw();
	}
}

void nsUIPanel::generateDraw(){
	generatePanel();
	generatePanelLabel();
}

void nsUIPanel::generatePanelLabel(){
	float str_width =fontL.stringWidth(panelname);
	float str_height=fontL.stringHeight(panelname);
	ofVec2f str_pos;
	str_pos.x=p_lt_local.x+label_width/2.-str_width/2.;
	str_pos.y=p_lt_local.y+label_height/2.+str_height/2.;
	ofSetColor(thisTextColor);
	fontL.drawString(panelname, str_pos.x, str_pos.y);
}

void nsUIPanel::generatePanel(){
	inner_path.clear();
	inner_rect.set(p_lt_local.x, p_lt_local.y, panel_width, p_lt.y-p_lt_local.y);
	inner_path.setFillColor(thisPanelColor);
	inner_path.rectangle(inner_rect);
	inner_path.draw();
}
