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
	gui.add(heightScale.setup("Height Bar Chart", 10, 0.1, 50));

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

	//
	int barSpacing = 6;
	int barWidth = 40;

	//Draw 18 rectangles for the 'bolt thread' answers
	for (int i = 0; i < 18; i++) {
		ofDrawRectangle(100 + (i * (barWidth+ barSpacing)), 100, barWidth, boltThread[i]*heightScale);
	}

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
