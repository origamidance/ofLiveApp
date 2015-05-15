#pragma once

#include "ofApp.h"

#ifdef RCCPP

class ofLive : public ofBaseApp, public IObjectFactoryListener
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

    void OnConstructorsAdded ();

    RuntimeObjectSystem rCPP;
    RCPPLogger          rLOG;
    ObjectId            rOID;
    ofApp*              rAPP;
};

#endif // #ifdef RCCPP
