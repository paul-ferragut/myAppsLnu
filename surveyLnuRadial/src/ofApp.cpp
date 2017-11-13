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

	//
	ofSetCircleResolution(50);

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

	//set the background color
	ofBackground(0, 0, 0);

	//
	int barSpacing = 6;
	int barWidth = 40;

	ofSetLineWidth(4);

	ofPushMatrix();
	ofTranslate(500, 500);
	//draw concentric circles
	ofNoFill();
	ofSetLineWidth(0.5);
	for (int i = 0; i < 10; i++) {
		ofDrawCircle(0, 0, 50 * i);
	}

	//radial data visualisation
	ofFill();
	ofSetLineWidth(2);
	for (int i = 0; i < 18; i++) {

		//ofPoint pt= convertPt(boltThread[i] * 50,ofMap(i,0,18,0,360));

		float xPos = cos(ofDegToRad(ofMap(i, 0, 18, 0, 360)))*(boltThread[i] * 50);
		float yPos = sin(ofDegToRad(ofMap(i, 0, 18, 0, 360)))*(boltThread[i] * 50);

		ofDrawLine(0, 0, xPos, yPos);
		ofDrawCircle(xPos, yPos, 10);
		ofDrawBitmapStringHighlight(studentName[i], 15+ xPos, 15+ yPos);
	}

	ofPopMatrix();

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

/*
ofPoint ofApp::convertPt(float radius, float angle) {

	ofPoint pt(0,0);

	pt.x = cos(ofDegToRad(angle))*radius;
	pt.y = sin(ofDegToRad(angle))*radius;

	return pt;
}
*/