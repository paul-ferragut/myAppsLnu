#pragma once

#include "ofMain.h"


#include "ofxCsv.h"

#include "ofxGui.h"

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
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		ofxCsv csv;
		

		string studentName[18];
		int boltThread[18];
		//int modernMeadow[18];
		//int bayer[18];
		//int monsanto[18];

		ofxPanel gui;

		ofxFloatSlider xPos;
		ofxFloatSlider yPos;
		ofxFloatSlider scale;

		float increasingValue;
};
