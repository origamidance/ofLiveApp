ofLiveApp
=========

ofLiveApp is Linux-only for now. Tested under Ubuntu 14.04.

Write your code in `ofApp.cpp` file. Once the code is compiled you can just save the source file and see your changes in your application after ~5 seconds.

If you need an object which should not be resetted on each code update, add it to [`SERIALIZE` macro](https://github.com/ofnode/ofLiveApp/blob/18974f5/src/ofApp.h#L24). You can make as many serializable objects as you want.

You can also compile application without RCC++ by passing `-DOF_ENABLE_LIVECODING=OFF` to `cmake` command on project generation step.

Giant thanks to [@kritzikratzi](https://github.com/kritzikratzi) for making his code and notes about integrating RCC++ and openFrameworks available to anyone! Check them here:

https://github.com/kritzikratzi/runtimeCPPDraw

And, of course, big thanks to [@dougbinks](https://github.com/dougbinks) for making [RCC++](https://github.com/RuntimeCompiledCPlusPlus/RuntimeCompiledCPlusPlus) happen and helping me out with serialization!

Converting ofApp to ofLiveApp
-----------------------------

 * Copy all of your files (except for `main.cpp`) from `ofApp/src` to `ofLiveApp/src` folder.
 * Copy addons folders and `ofxaddon()` commands from `ofApp/CMakeLists.txt` to `ofLiveApp/CMakeLists.txt`.
 * In `ofLiveApp/src/ofApp.h` change:

From:
```cpp
#include "ofMain.h"
```
To:
```cpp
#include "ofLiveMain.h"
```
From:
```cpp
class ofApp : public ofBaseApp
```
To:
```cpp
class ofApp : public ofLiveApp
```
And make standard callbacks look like so:
```cpp
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
```

  * In `ofLiveApp/src/ofApp.cpp` add `REGISTERCLASS(ofApp)` line after `#include "ofApp.h"` and add all callback implementations if some of them are missing in your code:

```cpp
#include "ofApp.h

REGISTERCLASS(ofApp)

void ofApp::setup()
{
}

void ofApp::update()
{
}

void ofApp::draw()
{
}

void ofApp::exit()
{
}

void ofApp::keyPressed(ofKeyEventArgs& key)
{
}

void ofApp::keyReleased(ofKeyEventArgs& key)
{
}

void ofApp::mouseMoved(ofMouseEventArgs& mouse)
{
}

void ofApp::mouseDragged(ofMouseEventArgs& mouse)
{
}

void ofApp::mousePressed(ofMouseEventArgs& mouse)
{
}

void ofApp::mouseReleased(ofMouseEventArgs& mouse)
{
}

void ofApp::windowResized(ofResizeEventArgs& window)
{
}

void ofApp::gotMessage(ofMessage message)
{
}

void ofApp::dragEvent(ofDragInfo dragged)
{
}
```

Known issues
------------

Q: My application doesn't changes after a code change!
A: Check the command line of an application, probably the new code can't be compiled at runtime.

Q: My application crashes after a code change!
A: There can be many reasons why it may happen, I noticed only one so far: don't use raw pointers in your code.

Q: `ofEasyCam` stops working after a code change!
A: Use [`ofxFirstPersonCamera`]() instead, it was rewritten with `ofLiveApp` in mind.

Compiling
---------

Make sure that [of](https://github.com/ofnode/of) and ofApp share the same folder.

![ScreenShot](http://i.imgur.com/xTQQYv4.png)

Change directory to ofApp and perform these steps:

```bash
git submodule update --init --recursive
mkdir build
cd build
cmake .. -G Ninja -DCMAKE_CXX_COMPILER=clang++ -DCMAKE_BUILD_TYPE=Release
ninja
```

### [Compiling ofApp with IDE on Linux](https://github.com/ofnode/of/wiki/Compiling-ofApp-with-IDE-on-Linux)


See also
--------

### [ofTools](https://github.com/ofnode/ofTools)

