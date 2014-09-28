//
//  nsUIButton.h
//  nsUI_dev2
//
//  Created by 澤野陽介 on 2014/09/25.
//
//

#ifndef __nsUI_dev2__nsUIButton__
#define __nsUI_dev2__nsUIButton__

#include <iostream>
#include "nsUIBase.h"

class nsUIButton : public nsUIBase{
public:
	nsUIButton();
	~nsUIButton();
	nsUIButton* setup(string _button_name, bool &_bVal);
	
	bool mouseReleased(ofMouseEventArgs & args);
	bool mouseMoved(ofMouseEventArgs & args);
	bool mousePressed(ofMouseEventArgs & args);
	bool mouseDragged(ofMouseEventArgs & args);
protected:
	void render();
	
private:
	void generateDraw();
	void generateBorderBox();
	void generateInnerBox_nomal();
	void generateInnerBox_active();
	void generateButtonLabel();
	void valueChanged(bool & value);
	bool setValue(float x,float y,bool b);
	float button_height;
	float button_width;
	ofParameter<bool> value;
	ofVec2f p_lt_local;
	ofVec2f str_pos;
	string button_name;
	bool bGuiActive;
};

#endif /* defined(__nsUI_dev2__nsUIButton__) */
