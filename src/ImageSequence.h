#pragma once

#include "ofMain.h"

class ImageSequence : public ofThread
{
    public:
        ImageSequence();
        ~ImageSequence();

        void threadedFunction();
        void update();
        ofPixels getPixels();
        ofImage getImage();
        /// \brief  Toggles playing video.
        void play();
        /// \brief  Start playing video. 
        void start();
        /// \brief  Pause playing video.
        void pause();
        /// \brief  Stop playing video.
        void stop();
        void reset();

        void addFrame(ofImage & img);
        void insertFrame(ofImage & img);
        void removeFrame();
        void read();
        void write(string savepath="");
        void togglePlay();
        void nextFrame();
        void previousFrame();
        void setFramerate(int fps);
        void increaseFramerate();
        void decreaseFramerate();
        /// \brief  Checks if it's time for a new frame.
        bool isTimeForNewFrame();
        int getNumFrames();

    private:
        vector<ofImage> sequence;
        int currentFrame;
        ofImage img;
        ofImage defaultImg;
        int width;
        int height;
        bool isRunning;
        int frameRate;
};
