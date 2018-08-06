/************************************************************
************************************************************/
#pragma once

/************************************************************
************************************************************/
#include "ofMain.h"
#include "ofxSyphon.h"

/************************************************************
************************************************************/

class ofApp : public ofBaseApp{
private:
	/****************************************
	****************************************/
	enum{
		WIDTH = 800,
		HEIGHT = 600,
	};
	
	/****************************************
	****************************************/
	float counter;
	bool bSmooth;
	
	ofTexture tex;
	
	ofxSyphonServer mainOutputSyphonServer;
	ofxSyphonServer individualTextureSyphonServer;
	ofxSyphonServer fbo_TextureSyphonServer;
	
	ofxSyphonClient mClient;
	
	ofFbo fbo;

public:
	/****************************************
	****************************************/
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
	
};
