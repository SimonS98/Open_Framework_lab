#include "ofMain.h"
#include "testApp.h"

//========================================================================
int main( ){

    ofSetupOpenGL(1600,1600, OF_WINDOW);            // <-------- setup the GL context
    //ofSetupOpenGL(2048,2048, OF_WINDOW);
    // this kicks off the running of my app
    // can be OF_WINDOW or OF_FULLSCREEN
    // pass in width and height too:
    ofRunApp( new testApp());

}
