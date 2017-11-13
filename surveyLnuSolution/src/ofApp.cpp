#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {


	/*
	This is a series of exercises to get familiar with coding data visualizations. The last 3 will be challenging for beginners. Sometimes there a hint if you are blocked with an exercise. Try first to do the exercise without reading the hint. Each small exercise is increasingly more difficult.

	-change the background and bar chart color.

	-change the spacing of the bar chart and the width of the bars. hint: There are already two variables created in draw function to change those parameters, so you only need to tweak the value.

	-the bar chart is aligned from the top. Make it aligned from the bottom. hint: you will need to subtract the value of the rectangle height to the y position of the rectangle.

	-create the other bar charts for the other brands (bayer, monsanto, modern meadow), place those 4 new bar chart under each other. hint: before you can do the bar chart you will need to assign the value from the .csv file to a corresponding variable array. see how it's done in setup() with boltThread[i]= ofToInt(csv.getRow(i + 1).getString(2));

	-use the function ofDrawBitmapString(string s, int x, int y); to write the name of the brand next to its respective chart.

	-instead of a bar chart try to create an area graph https://datavizcatalogue.com/methods/images/anatomy/area_graph.png using a for loop and the functions ofBeginShape();    ofVertex();        ofEndShape(); http://openframeworks.cc/documentation/graphics/ofGraphics/#show_ofBeginShape

	-try to have different bar colors within a chart, for instance, a small value is a darker bar and high value is a brighter bar.

	-for each bar chart overlay a line representing the average value of the result. hint: to calculate an average, add up all the value and divide the sum by the number of values.

	*/



	//load the csv file
	csv.load("survey.csv");


	//loop collecting the value from the csv file
	for (int i = 0; i < 18; i++) {
		studentName[i] = csv.getRow(i + 1).getString(1);
		cout << studentName[i] << endl;

		boltThread[i] = ofToInt(csv.getRow(i + 1).getString(2));
		bayer[i] = ofToInt(csv.getRow(i + 1).getString(3));
		monsanto[i] = ofToInt(csv.getRow(i + 1).getString(4));
		modernMeadow[i] = ofToInt(csv.getRow(i + 1).getString(5));
		
	}

}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	//set the background color
	ofBackground(20, 0, 40);

	//Set bar color
	ofSetColor(179, 195, 221);

	//
	int barSpacing = 4;
	int barWidth = 50;

	//Draw 18 rectangles for the 'bolt thread' answers
	for (int i = 0; i < 18; i++) {


		ofSetColor(25.5 * boltThread[i]);
		ofDrawRectangle(100 + (i * (barWidth + barSpacing)), 150- (boltThread[i] * 10), barWidth, boltThread[i] * 10);
		
		ofSetColor(25.5 * modernMeadow[i]);
		ofDrawRectangle(100 + (i * (barWidth + barSpacing)), 300 - (modernMeadow[i] * 10), barWidth, modernMeadow[i] * 10);
		
		ofSetColor(25.5 * bayer[i]);
		ofDrawRectangle(100 + (i * (barWidth + barSpacing)), 450 - (bayer[i] * 10), barWidth, bayer[i] * 10);

	//	ofDrawRectangle(100 + (i * (barWidth + barSpacing)), 600 - (monsanto[i] * 10), barWidth, monsanto[i] * 10);
	}






	ofSetColor(255, 255,255);
	ofDrawBitmapString("Bolt Thread", 100, 165);
	ofDrawBitmapString("Modern Meadow", 100, 315);
	ofDrawBitmapString("Bayer", 100, 465);
	ofDrawBitmapString("Monsanto", 100, 615);



	//
	ofSetPolyMode(OF_POLY_WINDING_NONZERO);
	ofBeginShape();
	
	//the first vertex is at the bottom left
	ofVertex(100, 600);

	for (int i = 0; i < 18; i++) {
		
		ofVertex(100 + (i * (barWidth + barSpacing)), 600 - (monsanto[i] * 10));

	}

	//the last vertex is at the bottom right
	ofVertex(100 + 18 * (barSpacing + barWidth), 600);
	ofEndShape();



	//we create variable for the average value
	float averageBoltThread = 0;
	float averageModernMeadow = 0;
	float averageBayer = 0;
	float averageMonsanto = 0;

	//first we add up all the value from the array
	for (int i = 0; i < 18; i++) {
		averageBoltThread += boltThread[i];
		averageModernMeadow += modernMeadow[i];
		averageBayer += bayer[i];
		averageMonsanto += monsanto[i];
	}

	//secondly we divide by the number of students
	averageBoltThread = (averageBoltThread / 18) * 10;
	averageModernMeadow = (averageModernMeadow / 18) * 10;
	averageBayer = (averageBayer / 18) * 10;
	averageMonsanto = (averageMonsanto / 18) * 10;

	//then we draw line using the value
	ofSetColor(255, 20, 20);
	ofDrawLine(100, 150 - averageBoltThread, 100 + 18 * (barSpacing + barWidth), 150 - averageBoltThread);
	ofDrawLine(100, 300 - averageModernMeadow, 100 + 18 * (barSpacing + barWidth), 300 - averageModernMeadow);
	ofDrawLine(100, 450 - averageBayer, 100 + 18 * (barSpacing + barWidth), 450 - averageBayer);
	ofDrawLine(100, 600 - averageMonsanto, 100 + 18 * (barSpacing + barWidth), 600 - averageMonsanto);


}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
