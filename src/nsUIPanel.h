//
//  nsUIPanel.h
//  nsUI_dev2
//
//  Created by 澤野陽介 on 2014/09/25.
//
//

#ifndef __nsUI_dev2__nsUIPanel__
#define __nsUI_dev2__nsUIPanel__

#include <iostream>
#include "nsUIBase.h"
#include "nsUIButton.h"
#include "nsUISpacer.h"

class nsUIPanel : public nsUIBase{
public:
	nsUIPanel();
	~nsUIPanel();
	void setup(string _panelname);
	void setup(string _panelname,ofVec2f _p_lt);
	void add(nsUIButton* button);
	void add(nsUISpacer* spacer);
	
protected:
	void render();
	void generateDraw();

private:
	void addToCollection(nsUIBase* element);
	void generatePanelLabel();
	void generatePanel();

	vector<nsUIBase*>collection;
	float label_width;
	float label_height;
	ofVec2f p_lt_local;
	string panelname;
};

#endif /* defined(__nsUI_dev2__nsUIPanel__) */
