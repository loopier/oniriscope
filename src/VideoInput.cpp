#include "VideoInput.h"

VideoInput::VideoInput()
: camWidth(ofGetWidth())
, camHeight(ofGetHeight())
, isRunning(true)
{
    ofLogVerbose() << __PRETTY_FUNCTION__;

    /* ofAddListener(ofEvent().update, this, &VideoInput::update) */

    img.allocate(camWidth, camHeight, OF_IMAGE_COLOR_ALPHA);

    cam.listDevices();

    cam.setDeviceID(0);
    cam.setDesiredFrameRate(60);
    cam.initGrabber(camWidth, camHeight);
}

VideoInput::~VideoInput()
{
    /* ofRemoveListener(ofEvent().update, this, &VideoInput::update) */
}

void VideoInput::update()
{
    if (isRunning == false) return;
    cam.update();
    if (cam.isFrameNew()) {
        img.setFromPixels(cam.getPixels());
    }
}

ofPixels VideoInput::getPixels()
{
    return img.getPixels();
}

ofImage VideoInput::getImage()
{
    return img;
}

void VideoInput::play()
{
    isRunning = !isRunning;
}

void VideoInput::start()
{
    isRunning = true;
}

void VideoInput::pause()
{
    isRunning = false;
}

void VideoInput::stop()
{
    isRunning = false;
}
