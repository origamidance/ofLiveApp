#pragma once

#include "ofLiveApp.h"

class ofApp : public ofBaseApp
#ifndef NO_LIVECODE
,public IObjectFactoryListener
#endif
{
  public:
    void setup  ();
    void update ();
    void draw   ();
    void exit   ();

    void keyPressed    (ofKeyEventArgs&);
    void keyReleased   (ofKeyEventArgs&);
    void mouseMoved    (ofMouseEventArgs&);
    void mouseDragged  (ofMouseEventArgs&);
    void mousePressed  (ofMouseEventArgs&);
    void mouseReleased (ofMouseEventArgs&);
    void windowResized (ofResizeEventArgs&);
    void gotMessage    (ofMessage);
    void dragEvent     (ofDragInfo);

#   ifndef NO_LIVECODE
    void OnConstructorsAdded();

    RCPPLogger          log;
    RuntimeObjectSystem rcpp;
    ObjectId            liveId;
#   endif

    ofLiveApp          *liveApp;
    ofGlobals           globals;
};
