#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    outputImg.allocate(ofGetWidth(), ofGetHeight(), OF_IMAGE_COLOR_ALPHA);
    /* outputImg.load("imgs/default.png"); */
    output = 2;
}

//--------------------------------------------------------------
void ofApp::update(){
    /* if (imageSequence.getNumFrames() > 0)   output = 2; */
    if (output == 1) {
        videoInput.update();
        outputImg = videoInput.getImage();
    } else if (output == 2) {
        imageSequence.update();
        outputImg = imageSequence.getImage();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    if (outputImg.getPixels().size() <= 0)  return;
    outputImg.draw(0,0);
}

//--------------------------------------------------------------
void ofApp::exit(){

}

//--------------------------------------------------------------
void ofApp::addFrame(){
    videoInput.update();
    ofImage img = videoInput.getImage();
    imageSequence.addFrame(img);
}

//--------------------------------------------------------------
void ofApp::showCam(){
   output = 1; 
}

//--------------------------------------------------------------
void ofApp::showAnimation(){
   output = 2; 
}

//--------------------------------------------------------------
void ofApp::save()
{
    /* imageSequence.stop(); */
    /* string extension = ".avi"; */
    /* ofFileDialogResult saveFileResult = ofSystemSaveDialog(ofGetTimestampString() + extension, "Save your file"); */
    /* if (saveFileResult.bSuccess) { */
    /*     string moviePath = saveFileResult.filePath; */
    /*     if (!ofIsStringInString(extension, moviePath))  moviePath += extension; */
    /*     ofLogVerbose() << "Saving file to: " <<  moviePath; */
    /*     string dirPath = moviePath.substr(0, moviePath.find(".")); */
    /*     string movieFilename = saveFileResult.fileName; */
    /*     string basename = movieFilename.substr(0, movieFilename.find(".")); */
    /*     // Create a temporary folder to store frames */
    /*     ofDirectory dir(dirPath); */
    /*     if (!dir.exists())  dir.create(true); */
    /*     // Save sequence of images to temporary directory */
    /*     vector<ofImage> images = imageSequence.getSequence(); */
    /*     for (int i = 0; i < images.size(); i++) { */
    /*         string imgFilename = dirPath + "/" + basename + "-" + ofToString(i) + ".png"; */
    /*         images[i].save(imgFilename); */
    /*         ofLogVerbose() << "File name: " << imgFilename; */
    /*     } */
    /*     // Use FFMPEG to save the sequence to movie file */
    /*     : */
    /*     // Delete temporary directory */
    MovieExporter exporter;
    exporter.exportSequence(imageSequence.getSequence(), imageSequence.getFrameRate());
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    char k = char(key);
    if (key == ' ') {
        addFrame();
    } else if (key == OF_KEY_BACKSPACE) {
        imageSequence.removeFrame();
    } else if (key == '1') {
        showCam();
    } else if (key == '2') {
        showAnimation();
    } else if (key == OF_KEY_LEFT) {
        imageSequence.previousFrame();
    } else if (key == OF_KEY_RIGHT) {
        imageSequence.nextFrame();
    } else if (key == OF_KEY_UP) {
        imageSequence.increaseFramerate();
    } else if (key == OF_KEY_DOWN) {
        imageSequence.decreaseFramerate();
    } else if (key == 'p') {
        imageSequence.togglePlay();
    } else if (key == 's') {
        save();
    } else {
        ofLog() << "Key not mapped: " << k;
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
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
