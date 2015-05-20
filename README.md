ofLiveApp
=========

ofLiveApp is Linux-only for now. Tested under Ubuntu 14.04.

Write your code in `ofApp.cpp` file. Once the code is compiled you can just save the source file and see your changes in your application after ~5 seconds.

If you need an object which should not be resetted on each code update, add it to [`SERIALIZE` macro](https://github.com/ofnode/ofLiveApp/blob/43a5f2a/src/ofApp.h#L35). You can make as many serializable objects as you want.

You can also compile application without RCC++ by passing `-DOF_ENABLE_LIVECODING=OFF` to `cmake` command on project generation step.

Giant thanks to [@kritzikratzi](https://github.com/kritzikratzi) for making his code and notes about integrating RCC++ and openFrameworks available to anyone! Check it here:

https://github.com/kritzikratzi/runtimeCPPDraw

And, of course, big thanks to [@dougbinks](https://github.com/dougbinks) for making [RCC++](https://github.com/RuntimeCompiledCPlusPlus/RuntimeCompiledCPlusPlus) happen and helping me out with serialization!

Known issues
------------

`Q:` My application doesn't change when I save the source file!

`A:` Check the command line of your application, probably the code can't be compiled at runtime.

`Q:` My application crashes after a code change!

`A:` There can be many reasons why it happens, I've noticed only one so far: don't use raw pointers.

`Q:` `ofEasyCam` stops working after first code update!

`A:` Use [`ofxFirstPersonCamera`](https://github.com/ofnode/ofxFirstPersonCamera) instead, it was rewritten with `ofLiveApp` in mind.

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


Converting ofApp to ofLiveApp
-----------------------------

 1. Copy all of your files (except for `main.cpp`) from `ofApp/src` to `ofLiveApp/src` folder.
 2. Copy addons folders and `ofxaddon()` commands from `ofApp/CMakeLists.txt` to `ofLiveApp/CMakeLists.txt`.
 3. In `ofLiveApp/src/ofApp.cpp` add `REGISTERCLASS(ofApp)` line after `#include "ofApp.h"`.
 4. In `ofLiveApp/src/ofApp.h` change:

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
