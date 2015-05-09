#include "ofApp.h"

void ofApp::setup()
{
# ifndef OF_LIVECODE
  liveApp = new ofLiveApp;
# else

  rcpp.Initialise(&log, NULL);

# ifdef TARGET_LINUX
# ifdef NDEBUG
  rcpp.AddLibraryDir("../../of/lib-linux/release");
# else
  rcpp.AddLibraryDir("../../of/lib-linux/debug");
# endif
# endif

# ifdef TARGET_LINUX
  rcpp.AddIncludeDir("/usr/include/AL");
  rcpp.AddIncludeDir("/usr/include/cairo");
  rcpp.AddIncludeDir("/usr/include/gtk-3.0");
  rcpp.AddIncludeDir("/usr/include/atk-1.0");
  rcpp.AddIncludeDir("/usr/include/glib-2.0");
  rcpp.AddIncludeDir("/usr/include/harfbuzz");
  rcpp.AddIncludeDir("/usr/include/pixman-1");
  rcpp.AddIncludeDir("/usr/include/libpng12");
  rcpp.AddIncludeDir("/usr/include/pango-1.0");
  rcpp.AddIncludeDir("/usr/include/freetype2");
  rcpp.AddIncludeDir("/usr/include/gio-unix-2.0");
  rcpp.AddIncludeDir("/usr/include/gstreamer-1.0");
  rcpp.AddIncludeDir("/usr/include/gdk-pixbuf-2.0");
  rcpp.AddIncludeDir("/usr/include/at-spi2-atk/2.0");
  rcpp.AddIncludeDir("/usr/lib/x86_64-linux-gnu/glib-2.0/include");
# endif

  rcpp.AddIncludeDir("../../of/src/freeimage");
  rcpp.AddIncludeDir("../../of/src/freeimage/OpenEXR");
  rcpp.AddIncludeDir("../../of/src/freeimage/OpenEXR/Half");
  rcpp.AddIncludeDir("../../of/src/freeimage/OpenEXR/Iex");
  rcpp.AddIncludeDir("../../of/src/freeimage/OpenEXR/IlmImf");
  rcpp.AddIncludeDir("../../of/src/freeimage/OpenEXR/IlmThread");
  rcpp.AddIncludeDir("../../of/src/freeimage/OpenEXR/Imath");
  rcpp.AddIncludeDir("../../of/src/glew");
  rcpp.AddIncludeDir("../../of/src/glew/include");
  rcpp.AddIncludeDir("../../of/src/glfw");
  rcpp.AddIncludeDir("../../of/src/glfw/include");
  rcpp.AddIncludeDir("../../of/src/glfw/include/GLFW");
  rcpp.AddIncludeDir("../../of/src/kiss");
  rcpp.AddIncludeDir("../../of/src/kiss/include");
  rcpp.AddIncludeDir("../../of/src/kiss/src");
  rcpp.AddIncludeDir("../../of/src/poco");
  rcpp.AddIncludeDir("../../of/src/poco/Crypto/include");
  rcpp.AddIncludeDir("../../of/src/poco/Foundation/include");
  rcpp.AddIncludeDir("../../of/src/poco/Net/include");
  rcpp.AddIncludeDir("../../of/src/poco/NetSSL_OpenSSL/include");
  rcpp.AddIncludeDir("../../of/src/poco/Util/include");
  rcpp.AddIncludeDir("../../of/src/poco/XML/include");
  rcpp.AddIncludeDir("../../of/src/poco/Zip/include");
  rcpp.AddIncludeDir("../../of/src/rtaudio");
  rcpp.AddIncludeDir("../../of/src/rtaudio/include");
  rcpp.AddIncludeDir("../../of/src/tess2");
  rcpp.AddIncludeDir("../../of/src/tess2/include");
  rcpp.AddIncludeDir("../../of/src/tess2/Sources");
  rcpp.AddIncludeDir("../../of/src/openframeworks");
  rcpp.AddIncludeDir("../../of/src/openframeworks/3d");
  rcpp.AddIncludeDir("../../of/src/openframeworks/app");
  rcpp.AddIncludeDir("../../of/src/openframeworks/communication");
  rcpp.AddIncludeDir("../../of/src/openframeworks/events");
  rcpp.AddIncludeDir("../../of/src/openframeworks/gl");
  rcpp.AddIncludeDir("../../of/src/openframeworks/graphics");
  rcpp.AddIncludeDir("../../of/src/openframeworks/math");
  rcpp.AddIncludeDir("../../of/src/openframeworks/sound");
  rcpp.AddIncludeDir("../../of/src/openframeworks/types");
  rcpp.AddIncludeDir("../../of/src/openframeworks/utils");
  rcpp.AddIncludeDir("../../of/src/openframeworks/video");

  rcpp.AddIncludeDir("../RuntimeCompiledCPlusPlus/Aurora");
  rcpp.AddIncludeDir("..");

  {
    ofDirectory dir(ofFilePath::getCurrentExeDir() + "..");
    dir.listDir();
    vector<ofFile> files = dir.getFiles();
    for (ofFile& file : files)
    {
      if (file.isDirectory() &&
          file.getBaseName().substr(0,3) == "ofx")
      {
        rcpp.AddIncludeDir(&(file.path())[0]);
        rcpp.AddIncludeDir(&(file.path() + "/src")[0]);
      }
    }
  }

  rcpp.GetObjectFactorySystem()->AddListener(this);

  {
    IObject *liveObject = rcpp.GetObjectFactorySystem()->GetConstructor("ofLiveApp")->Construct();
    liveObject->GetInterface(&liveApp);
    liveId = liveObject->GetObjectId();
  }
# endif // ifndef OF_LIVECODE

  liveApp->setup();
}

void ofApp::update()
{
# ifdef OF_LIVECODE
  if (rcpp.GetIsCompiledComplete()) rcpp.LoadCompiledModule();
  rcpp.GetFileChangeNotifier()->Update(0.1f);
# endif

  liveApp->update();
}

void ofApp::draw()
{
  liveApp->draw();
}

void ofApp::exit()
{
  liveApp->exit();

# ifndef OF_LIVECODE
  delete liveApp;
# endif
}

void ofApp::keyPressed(ofKeyEventArgs& key)
{
  liveApp->keyPressed(key);
}

void ofApp::keyReleased(ofKeyEventArgs& key)
{
  liveApp->keyReleased(key);
}

void ofApp::mouseMoved(ofMouseEventArgs& mouse)
{
  liveApp->mouseMoved(mouse);
}

void ofApp::mouseDragged(ofMouseEventArgs& mouse)
{
  liveApp->mouseDragged(mouse);
}

void ofApp::mousePressed(ofMouseEventArgs& mouse)
{
  liveApp->mousePressed(mouse);
}

void ofApp::mouseReleased(ofMouseEventArgs& mouse)
{
  liveApp->mouseReleased(mouse);
}

void ofApp::windowResized(ofResizeEventArgs& window)
{
  liveApp->windowResized(window);
}

void ofApp::gotMessage(ofMessage message)
{
  liveApp->gotMessage(message);
}

void ofApp::dragEvent(ofDragInfo dragged)
{
  liveApp->dragEvent(dragged);
}

#ifdef OF_LIVECODE
void ofApp::OnConstructorsAdded()
{
  if (liveApp) rcpp.GetObjectFactorySystem()->GetObject(liveId)->GetInterface(&liveApp);
}
#endif
