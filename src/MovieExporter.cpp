#include "MovieExporter.h"

MovieExporter::MovieExporter()
{

}

MovieExporter::~MovieExporter()
{
    stopThread();
}

void MovieExporter::exportSequence(vector<ofImage> & exportSequence, int framerate)
{
    ofFileDialogResult dialogResult = promptPath();
    string moviefilepath = dialogResult.filePath;
    if (!ofIsStringInString(moviefilepath, ".avi")) moviefilepath += ".avi";
    string dirpath = moviefilepath.substr(0, moviefilepath.find("."));
    ofLogVerbose() << "Exporting as: " << dirpath;
    
    saveTmpImages(exportSequence, dirpath);
    
    string cmd = "ffmpeg -framerate " + ofToString(framerate) + " -i " + dirpath + "/frame-%03d.png " + moviefilepath;
    ofLogVerbose() << cmd;
    ofSystem(cmd);
    ofSystem("rm -r " + dirpath);
    /* sequence = exportSequence; */
    /* start(); */
}

void MovieExporter::start()
{
    startThread();
    ofLogVerbose() << "Stopped exporting thread.";
}

void MovieExporter::stop()
{
    stopThread();
}

void MovieExporter::threadedFunction()
{
    /* ofLogVerbose() << "Started exporting thread."; */
    /* string fullpath = promptPath(); */
    /* ofLogVerbose() << "Saving: " << fullpath; */
    /* for (int i = 0; i < sequence.size(); i++) { */
    /*     ofLogVerbose() << "Image " << ofToString(i); */
    /* } */
}

ofFileDialogResult MovieExporter::promptPath()
{
    string extension = ".avi";
    string defaultFileName = ofGetTimestampString() + extension;
    ofStringReplace(defaultFileName, "-", "");
    ofFileDialogResult saveFileResult = ofSystemSaveDialog(defaultFileName, "Save your file.");
    return saveFileResult;
}

void MovieExporter::saveTmpImages(vector<ofImage> & saveSequence, string path)
{
    if (path == "") {
        ofLogWarning() << "Cannot save to empty path";
    }
    ofLogVerbose() << "Saving images to " << path;
    ofDirectory dir(path);
    if (!dir.exists())  dir.create(true);
    for (int i = 0; i < saveSequence.size(); i++) {
        stringstream ss;
        ss << path << "/frame-" << std::setw(3) << std::setfill('0') << i << ".png";
        string imgfilename = ss.str();
        ofLogVerbose() << imgfilename;
        saveSequence[i].save(imgfilename);
    }
}
