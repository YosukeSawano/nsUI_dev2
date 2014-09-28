//
//  nsUISpacer.h
//  nsUI_dev2
//
//  Created by 澤野陽介 on 2014/09/26.
//
//

#ifndef __nsUI_dev2__nsUISpacer__
#define __nsUI_dev2__nsUISpacer__

#include <iostream>
#include "nsUIBase.h"

class nsUISpacer : public nsUIBase{
public:
	nsUISpacer();
	~nsUISpacer();
	nsUISpacer* setup();
	
protected:
	void render();
	
private:
	void generateDraw();
	static const float spacer_width;
	static const float stroke_width;
	ofVec2f p_lt_local;
	ofPath stroke;
	
};
#endif /* defined(__nsUI_dev2__nsUISpacer__) */
