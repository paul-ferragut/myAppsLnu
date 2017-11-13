#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){




	//load the csv file
	csv.load("survey.csv");


	//loop collecting the value from the csv file
	for (int i = 0; i < 18; i++) {
		studentName[i] = csv.getRow(i + 1).getString(1);
		cout << studentName[i] << endl;
		boltThread[i]= ofToInt(csv.getRow(i + 1).getString(2));
		cout << boltThread[i] << endl;
	}




	gui.setup();
	gui.add(lightPosX.setup("Light pos x",0,0,1920));
	gui.add(lightPosY.setup("Light pos y", 0, 0, 1080));
	gui.add(colorR.setup("Red",255,0,255));
	gui.add(colorG.setup("Green", 255, 0, 255));
	gui.add(colorB.setup("Blue", 255, 0, 255));
	gui.add(ortho.setup("ortho/perspective camera", false));

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

	//set the background color
	ofBackground(0, 0, 0);

	//Set bar color
	ofSetColor(179, 195, 221);

	if (ortho==true) {
		cam.enableOrtho();
	}
	else {
		cam.disableOrtho();
	}
	
	//
	int barSpacing = 6;
	int barWidth = 40;

	ofEnableDepthTest();

	ofLight light;
	// set the diffuse color, color reflected from the light source //
	light.setDiffuseColor(ofColor(colorR, colorG, colorB));
	light.setPosition(lightPosX,lightPosY, 100);

	cam.begin();


	ofEnableLighting();

	light.enable();

	//Draw 18 rectangles for the 'bolt thread' answers
	for (int i = 0; i < 18; i++) {
		//ofDrawBox(x,y,z,width,height,depth) Important: ofDrawBox() is drawing from the center of the box
		ofDrawBox(100 + (i * (barWidth + barSpacing)), 0, (boltThread[i] * 10) / 2.0, barWidth, barWidth, boltThread[i] * 10);
	}

	light.disable();

	ofDisableLighting();

	ofDrawAxis(100);

	cam.end();

	ofDisableDepthTest();

	ofSetColor(255, 255, 255);
	gui.draw();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
