#include "ImageSequence.h"

ImageSequence::ImageSequence()
: currentFrame(0)
, img(ofImage())
, defaultImg(ofImage())
, width(1)
, height(1)
, isRunning(true)
, frameRate(12)
{
    ofLogVerbose() << __PRETTY_FUNCTION__;
    img.allocate(ofGetWidth(), ofGetHeight(), OF_IMAGE_COLOR_ALPHA);
    defaultImg.allocate(ofGetWidth(), ofGetHeight(), OF_IMAGE_COLOR_ALPHA);
    /* img.load("imgs/default.jpg"); */
    defaultImg.load("imgs/default.jpg");
    /* img.resize(ofGetWidth(), ofGetHeight()); */
    defaultImg.resize(ofGetWidth(), ofGetHeight());
}

ImageSequence::~ImageSequence()
{
    ofLogVerbose() << __PRETTY_FUNCTION__;
}

void ImageSequence::start()
{
    ofLogVerbose() << __PRETTY_FUNCTION__;
    startThread();
}

void ImageSequence::stop()
{
    ofLogVerbose() << "Stop";
    pause();
    reset();
    std::unique_lock<std::mutex> lck(mutex);
    stopThread();
    // !!! TODO: Stop thread
}

void ImageSequence::reset()
{
    ofLogVerbose() << __PRETTY_FUNCTION__;
    currentFrame = 0;
}

void ImageSequence::threadedFunction()
{
    while(isThreadRunning()) {
        update();
    }
}

void ImageSequence::update()
{
    if (sequence.size() == 0)    return;
    if (isRunning && isTimeForNewFrame())   nextFrame();
    if (sequence.size() == 0)    return;
    if (isRunning && isTimeForNewFrame())   nextFrame();
    img = sequence[currentFrame];
    img = sequence[currentFrame];
}

void ImageSequence::updateImage()
{
    if (sequence.size() == 0)   return;
    if (isRunning == false)     return;
    if (isTimeForNewFrame() == false)   return;
    nextFrame();
}

ofPixels ImageSequence::getPixels()
{
    return img.getPixels();
}

ofImage ImageSequence::getImage()
{
    if (getNumFrames() < 1) return defaultImg;
    else return img;
}

void ImageSequence::play()
{
    ofLogVerbose() << "Play";
    isRunning = true;
}

void ImageSequence::pause()
{
    ofLogVerbose() << "Pause";
    isRunning = false;
}

void ImageSequence::addFrame(ofImage & img)
{
    sequence.push_back(img);
    nextFrame();
    ofLogVerbose() << "Adding frame: " << sequence.size();
}

void ImageSequence::insertFrame(ofImage & img)
{
    ofLogVerbose() << "Inserting frame at postion: " << currentFrame;
}

void ImageSequence::removeFrame()
{
    if (getNumFrames() < 1) return;
    previousFrame();
    sequence.erase(sequence.begin() + currentFrame);
    ofLogVerbose() << "Removing frame: " << sequence.size();
}

void ImageSequence::read()
{
    ofLogVerbose() << __PRETTY_FUNCTION__;
}

void ImageSequence::write(string savepath)
{
    ofLogVerbose() << __PRETTY_FUNCTION__;
}

void ImageSequence::togglePlay()
{
    isRunning = !isRunning;
    ofLogVerbose() << __PRETTY_FUNCTION__ << " " << isRunning;
}

void ImageSequence::nextFrame()
{
    if (sequence.size() <= 0)   return;
    currentFrame = (currentFrame + 1) % sequence.size();
    updateImage();
}

void ImageSequence::previousFrame()
{
    /* ofLogVerbose() << __PRETTY_FUNCTION__ << " " << currentFrame; */
    if (sequence.size() <= 0)   return;
    currentFrame -= 1;
    if (currentFrame < 0)  currentFrame = sequence.size() - 1;
    updateImage();
    /* ofLogVerbose() << __PRETTY_FUNCTION__ << " " << currentFrame; */
}

void ImageSequence::setFramerate(int fps)
{
    ofLogVerbose() << __PRETTY_FUNCTION__;
}

void ImageSequence::increaseFramerate()
{
    frameRate += 1;
    ofLogVerbose() << __PRETTY_FUNCTION__ << " " << frameRate;
}

void ImageSequence::decreaseFramerate()
{
    frameRate -= 1;
    if (frameRate <= 0) frameRate = 1;
    ofLogVerbose() << __PRETTY_FUNCTION__ << " " << frameRate;
}

bool ImageSequence::isTimeForNewFrame()
{
    /* float fps = float(frameRate) / 60.0; */
    float fps = 1.0 / float(frameRate); 

    if (ofGetElapsedTimef() >= fps) {
        ofResetElapsedTimeCounter();
        return true;
    }
}

int ImageSequence::getNumFrames()
{
    return sequence.size();
}

