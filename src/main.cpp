#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){
	/* ofSetupOpenGL(1024,768,OF_WINDOW);			// <-------- setup the GL context */
	/* ofSetupOpenGL(1024,768,OF_FULLSCREEN);			// <-------- setup the GL context */
	ofSetupOpenGL(1280,720,OF_WINDOW);			// HD
	/* ofSetupOpenGL(1920,1080,OF_WINDOW);	    // Full HD */

    ofSetLogLevel(OF_LOG_VERBOSE);

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new ofApp());

}
