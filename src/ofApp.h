#pragma once

#include "ofLiveMain.h"

class ofApp : public ofLiveApp
{
  public:
    virtual void setup  ();
    virtual void update ();
    virtual void draw   ();
    virtual void exit   ();

    virtual void keyPressed    (ofKeyEventArgs&);
    virtual void keyReleased   (ofKeyEventArgs&);
    virtual void mouseMoved    (ofMouseEventArgs&);
    virtual void mouseDragged  (ofMouseEventArgs&);
    virtual void mousePressed  (ofMouseEventArgs&);
    virtual void mouseReleased (ofMouseEventArgs&);
    virtual void windowResized (ofResizeEventArgs&);
    virtual void gotMessage    (ofMessage);
    virtual void dragEvent     (ofDragInfo);

    SERIALIZE_BEGIN
    //SERIALIZE()
    SERIALIZE_END
};
