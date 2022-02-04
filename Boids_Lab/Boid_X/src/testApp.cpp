#include "testApp.h"

testApp::~testApp()
{
	for (int i = 0; i < boids.size(); i++)
	{
		delete boids[i];
	}
    for (int i = 0; i < birds.size(); i++)
    {
        delete birds[i];
    }
}

//--------------------------------------------------------------
void testApp::setup(){
	
	
	int screenW = ofGetScreenWidth();
	int screenH = ofGetScreenHeight();

	//ofBackground(255,255,255);
    ofBackground(0,0,0);
	
	// set up the boids
	for (int i = 0; i < 600; i++)
		boids.push_back(new Boid());
    for (int i = 0; i < 400; i++)
        birds.push_back(new Bird());

}


//--------------------------------------------------------------
void testApp::update(){
	
    ofVec3f min(0, 0);
	ofVec3f max(ofGetWidth(), ofGetHeight());
	for (int i = 0; i < boids.size(); i++)
	{
		boids[i]->update(boids,birds, min, max);
	}
    
    for (int i = 0; i < birds.size(); i++)
    {
        birds[i]->update(birds,boids, min, max);
    }
}

//--------------------------------------------------------------
void testApp::draw(){

	for (int i = 0; i < boids.size(); i++)
	{
		boids[i]->draw();
	}
    for (int i = 0; i < birds.size(); i++)
    {
        birds[i]->draw();
    }
}


//--------------------------------------------------------------
void testApp::keyPressed(int key){
 
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
    
}
