ofLiveApp
=========

ofLiveApp is Linux-only for now. Tested under Ubuntu 14.04.

Write your code in `ofApp.cpp` file. Once the code is compiled you can just save the source file and see your changes in your application after ~5 seconds.

If you need an object which should not be resetted on each code update, add it to [`SERIALIZE` macro](https://github.com/ofnode/ofLiveApp/blob/18974f5/src/ofApp.h#L24). You can make as many serializable objects as you want.

You can also compile application without RCC++ by passing `-DOF_ENABLE_LIVECODING=OFF` to `cmake` command on project generation step.

Giant thanks to [@kritzikratzi](https://github.com/kritzikratzi) for making his code and notes about integrating RCC++ and openFrameworks available to anyone! Check them here:

https://github.com/kritzikratzi/runtimeCPPDraw

And, of course, big thanks to [@dougbinks](https://github.com/dougbinks) for making [RCC++](https://github.com/RuntimeCompiledCPlusPlus/RuntimeCompiledCPlusPlus) happen and helping me out with serialization!

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

