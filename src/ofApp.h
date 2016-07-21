#pragma once

#include "ofLiveMain.h"
#include "ofxImGui.h"
#include "ThemeTest.h"

class ofApp : public ofLiveApp
{
public:
    void setup();

    void update();

    void draw();

    void exit();

    void keyPressed(ofKeyEventArgs &);

    void keyReleased(ofKeyEventArgs &);

    void mouseMoved(ofMouseEventArgs &);

    void mouseDragged(ofMouseEventArgs &);

    void mousePressed(ofMouseEventArgs &);

    void mouseReleased(ofMouseEventArgs &);

    void mouseScrolled(ofMouseEventArgs &);

    void mouseEntered(ofMouseEventArgs &);

    void mouseExited(ofMouseEventArgs &);

    void touchDown(ofTouchEventArgs &);

    void touchMoved(ofTouchEventArgs &);

    void touchUp(ofTouchEventArgs &);

    void touchDoubleTap(ofTouchEventArgs &);

    void touchCancelled(ofTouchEventArgs &);

    void windowResized(ofResizeEventArgs &);

    void dragged(ofDragInfo &);

    void messageReceived(ofMessage &);

    void drawInteractionArea();
    bool bShowHelp;
    ofEasyCam cam; // add mouse controls for camera movement
  ::ofEasyCam testcam;
    ofxImGui gui;

    ImVec4 backgroundColor;
    bool show_test_window;
    bool show_another_window;

    float floatValue;
    int intValue;
    ofImage imageButtonSource;
    GLuint imageButtonID;

    ofPixels pixelsButtonSource;
    GLuint pixelsButtonID;

    ofTexture textureSource;
    GLuint textureSourceID;

    SERIALIZE_BEGIN
        //SERIALIZE()
    SERIALIZE_END

};
