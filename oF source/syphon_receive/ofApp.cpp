/************************************************************
************************************************************/
#include "ofApp.h"

/************************************************************
************************************************************/

//--------------------------------------------------------------
void ofApp::setup(){
	/********************
	********************/
	ofSetWindowTitle("ofxSyphonServerDirectoryExample");
	ofSetWindowShape(WIDTH, HEIGHT);
	ofSetFrameRate(60);

	/********************
	********************/
	dir.setup();
	
	/********************
	********************/
	client.setup();
	
	client_direct.setup();
	// client_direct.set("Screen Output","study__syphon_send"); // void set(string _serverName, string _appName);
	// client_direct.set("Main Camera","Unity"); // void set(string _serverName, string _appName);
	client_direct.set("Main Camera","test_syphon"); // void set(string _serverName, string _appName);

	/********************
	********************/
	//register for our directory's callbacks
	ofAddListener(dir.events.serverAnnounced, this, &ofApp::serverAnnounced);
	// not yet implemented
	//ofAddListener(dir.events.serverUpdated, this, &ofApp::serverUpdated);
	ofAddListener(dir.events.serverRetired, this, &ofApp::serverRetired);

	/********************
	********************/
	dirIdx = -1;
	b_direct = true;
}

/******************************
description
	these are our directory's callbacks

auto
	http://kaworu.jpn.org/cpp/auto
		C++のauto型とは、C++11で追加された型推論です。コンパイル時に型を推測し、適切な型として扱ってくれます。
******************************/
void ofApp::serverAnnounced(ofxSyphonServerDirectoryEventArgs &arg)
{
	for( auto& dir : arg.servers ){
		ofLogNotice("ofxSyphonServerDirectory Server Announced")<<" Server Name: "<<dir.serverName <<" | App Name: "<<dir.appName;
	}
	dirIdx = 0;
}

void ofApp::serverUpdated(ofxSyphonServerDirectoryEventArgs &arg)
{
	for( auto& dir : arg.servers ){
		ofLogNotice("ofxSyphonServerDirectory Server Updated")<<" Server Name: "<<dir.serverName <<" | App Name: "<<dir.appName;
	}
	dirIdx = 0;
}

void ofApp::serverRetired(ofxSyphonServerDirectoryEventArgs &arg)
{
	for( auto& dir : arg.servers ){
		ofLogNotice("ofxSyphonServerDirectory Server Retired")<<" Server Name: "<<dir.serverName <<" | App Name: "<<dir.appName;
	}
	dirIdx = 0;
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(0, 0, 0);
	ofColor(255, 255, 255, 255);
	ofEnableAlphaBlending();

	
	if(b_direct){
		client_direct.draw(0, 0);
	}else if(dir.isValidIndex(dirIdx)){
		client.draw(0, 0);
	}
		

	ofDrawBitmapString("Press 'c' to cycle through all available Syphon servers.", ofPoint(20, 580));
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	switch(key){
		case 'c':
		{
			if (dir.size() > 0){
				dirIdx++;
				if(dirIdx > dir.size() - 1) dirIdx = 0;
				
				client.set(dir.getDescription(dirIdx)); // void set(ofxSyphonServerDescription _server);
				string serverName = client.getServerName();
				string appName = client.getApplicationName();
		
				if(serverName == "")	serverName = "null";
				if(appName == "")		appName = "null";
		
				ofSetWindowTitle(serverName + ":" + appName);
			}else{
				ofSetWindowTitle("No Server");
			}
		}
			break;
			
		case 'd':
			b_direct = !b_direct;
			break;
	}
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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
