#include "ofApp.h"

REGISTERCLASS(ofApp)

void ofApp::setup() {
    ofSetLogLevel(OF_LOG_VERBOSE);

    gui.setup();
    ImGui::GetIO().MouseDrawCursor = false;
    backgroundColor = ofColor(114, 144, 154);
    show_test_window = true;
    show_another_window = false;
    floatValue = 0.0f;
    intValue = 3;
    ofSetCircleResolution(120);

    ofLogVerbose() << "textureSourceID:" << textureSourceID;
}

bool doSetTheme = false;

void ofApp::update() {
    if (doSetTheme) {
        doSetTheme = false;
        gui.setTheme(new ThemeTest());
    }
    if (cam.getMouseInputEnabled())
    {
        if (ImGui::IsMouseHoveringAnyWindow())
        {
            cam.disableMouseInput();
        }
    }
    else if (!ImGui::IsMouseHoveringAnyWindow())
    {
        cam.enableMouseInput();
    }
}

bool doThemeColorsWindow = false;

void ofApp::draw() {

    cam.begin();
    ofRotateX(ofRadToDeg(.5));
    ofRotateY(ofRadToDeg(-.5));

    ofBackground(0);

    ofSetColor(255,0,0);
    ofFill();
    ofDrawBox(30);
    ofNoFill();
    ofSetColor(0);
    ofDrawBox(30);

    ofPushMatrix();
    ofTranslate(0,0,20);
    ofSetColor(0,0,255);
    ofFill();
    ofDrawBox(5);
    ofNoFill();
    ofSetColor(0);
    ofDrawBox(5);
    ofPopMatrix();
    cam.end();
    ofFill();
    drawInteractionArea();
    ofSetColor(255);
    string msg = string("Using mouse inputs to navigate (press 'c' to toggle): ") + (cam.getMouseInputEnabled() ? "YES" : "NO");
    msg += string("\nShowing help (press 'h' to toggle): ")+ (bShowHelp ? "YES" : "NO");
    if (bShowHelp) {
        msg += "\n\nLEFT MOUSE BUTTON DRAG:\nStart dragging INSIDE the yellow circle -> camera XY rotation .\nStart dragging OUTSIDE the yellow circle -> camera Z rotation (roll).\n\n";
        msg += "LEFT MOUSE BUTTON DRAG + TRANSLATION KEY (" + ofToString(cam.getTranslationKey()) + ") PRESSED\n";
        msg += "OR MIDDLE MOUSE BUTTON (if available):\n";
        msg += "move over XY axes (truck and boom).\n\n";
        msg += "RIGHT MOUSE BUTTON:\n";
        msg += "move over Z axis (dolly)";
    }
    msg += "\n\nfps: " + ofToString(ofGetFrameRate(), 2);
    ofDrawBitmapStringHighlight(msg, 10, 20);

    //backgroundColor is stored as an ImVec4 type but is converted to ofColor automatically
    backgroundColor = ofColor(114, 144, 154);
    ofSetBackgroundColor(backgroundColor);
    ofDrawCircle(200, 300,intValue);
    ofDrawCircle(300, 400, 100);
    ofSetColor(0, 255, 255);
    ofDrawCircle(100, 200, 20);
    //required to call this at beginning
    gui.begin();
    //In between gui.begin() and gui.end() you can use ImGui as you would anywhere else

    // 1. Show a simple window
    {
        ImGui::Text("hahaha!");
        ImGui::SliderFloat("Float", &floatValue, 0.0f, 1.0f);
        ImGui::SliderInt("int", &intValue, 0, 200);

        //this will change the app background color
        ImGui::ColorEdit3("Background Color", (float *) &backgroundColor);
        if (ImGui::Button("Test Window")) {
            show_test_window = !show_test_window;
        }

        if (ImGui::Button("Another Window")) {
            //bitwise OR
            show_another_window ^= 1;

        }
        ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate,
                    ImGui::GetIO().Framerate);
    }
//     2. Show another window, this time using an explicit ImGui::Begin and ImGui::End
    if (show_another_window) {
        //note: ofVec2f and ImVec2f are interchangeable
        ImGui::SetNextWindowSize(ofVec2f(200, 100), ImGuiSetCond_FirstUseEver);
        ImGui::Begin("Another Window", &show_another_window);
        ImGui::Text("nihao");
        ImGui::End();
    }

    // // 3. Show the ImGui test window. Most of the sample code is in ImGui::ShowTestWindow()
    // if (show_test_window) {
    //     ImGui::SetNextWindowPos(ofVec2f(650, 20), ImGuiSetCond_FirstUseEver);
    //     ImGui::ShowTestWindow(&show_test_window);
    // }


//    bool pressed = ImGui::ImageButton((ImTextureID) (uintptr_t) imageButtonID, ImVec2(200, 200));
//    pressed = ImGui::ImageButton((ImTextureID) (uintptr_t) pixelsButtonID, ImVec2(200, 200));
//    pressed = ImGui::ImageButton((ImTextureID) (uintptr_t) textureSourceID, ImVec2(200, 200));


    if (doThemeColorsWindow) {
        gui.openThemeColorWindow();

    }

    //required to call this at end
    gui.end();

    if (textureSource.isAllocated()) {
        //textureSource.draw(ofRandom(200), ofRandom(200));
    }

}

void ofApp::drawInteractionArea(){
    ofRectangle vp = ofGetCurrentViewport();
    float r = MIN(vp.width, vp.height) * 0.5f;
    float x = vp.width * 0.5f;
    float y = vp.height * 0.5f;

    ofPushStyle();
    ofSetLineWidth(3);
    ofSetColor(255, 255, 0);
    ofNoFill();
    glDepthMask(false);
    ofDrawCircle(x, y, r);
    glDepthMask(true);
    ofPopStyle();
}


void ofApp::exit() {
}

void ofApp::keyPressed(ofKeyEventArgs &key) {
    ofLogVerbose(__FUNCTION__) << key.key;
    switch (key.key) {
        case 'c':
            if(cam.getMouseInputEnabled()) cam.disableMouseInput();
            else cam.enableMouseInput();
            break;

        case 'f':
            ofToggleFullscreen();
            break;

        case 'h':
            bShowHelp ^=true;
            break;

        case 't' : {
            doThemeColorsWindow = !doThemeColorsWindow;
            break;
        }
        case 's': {
            break;
        }
    }
}

void ofApp::keyReleased(ofKeyEventArgs &key) {
    ofLogVerbose(__FUNCTION__) << key.key;
}

void ofApp::mouseMoved(ofMouseEventArgs &mouse) {

}

void ofApp::mouseDragged(ofMouseEventArgs &mouse) {
}

void ofApp::mousePressed(ofMouseEventArgs &mouse) {
}

void ofApp::mouseReleased(ofMouseEventArgs &mouse) {
}

void ofApp::mouseScrolled(ofMouseEventArgs &mouse) {
    ofLogVerbose(__FUNCTION__) << "x: " << mouse.x << " y: " << mouse.y;
}

void ofApp::mouseEntered(ofMouseEventArgs &mouse) {
}

void ofApp::mouseExited(ofMouseEventArgs &mouse) {
}

void ofApp::touchDown(ofTouchEventArgs &touch) {
}

void ofApp::touchMoved(ofTouchEventArgs &touch) {
}

void ofApp::touchUp(ofTouchEventArgs &touch) {
}

void ofApp::touchDoubleTap(ofTouchEventArgs &touch) {
}

void ofApp::touchCancelled(ofTouchEventArgs &touch) {
}

void ofApp::windowResized(ofResizeEventArgs &window) {
}

void ofApp::dragged(ofDragInfo &dragged) {
}

void ofApp::messageReceived(ofMessage &message) {
}
