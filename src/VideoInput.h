#pragma once

#include "ofMain.h"

class VideoInput 
{
    public:
        VideoInput();
        ~VideoInput();

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

    private:
        ofVideoGrabber cam;
        ofImage img;
        int camWidth;
        int camHeight;
        bool isRunning;
};
