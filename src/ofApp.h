#pragma once

#include "ofMain.h"
#include "VideoInput.h"
#include "ImageSequence.h"
#include "MovieExporter.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
        void exit(); 

        void addFrame();
        void showCam();
        void showAnimation();
        /// \brief  Save image sequence to file
        void save();

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
            
    private:
        VideoInput videoInput;
        ImageSequence imageSequence;
        ofImage outputImg;
        int output;
};
