#include "ofMain.h"

class MovieExporter: public ofThread
{
    public:
    MovieExporter();
    ~MovieExporter();

    void exportSequence(vector<ofImage> & exportSequence, int framerate=12);
    void start();
    void stop();
    void threadedFunction();
    /// \brief  Asks for saving location.
    ofFileDialogResult promptPath();
    /// \brief  Saves images temporarily
    void saveTmpImages(vector<ofImage> & saveSequence, string path);
    private:
    vector<ofImage> sequence;
};
