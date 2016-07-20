#ifdef RCCPP

#include "ofLive.h"

void ofLive::setup()
{
  rCPP.Initialise(&rLOG, NULL);

# ifdef TARGET_LINUX
# ifdef NDEBUG
  rCPP.AddLibraryDir("../../of/lib-linux/release-x86-64");
# else
  rCPP.AddLibraryDir("../../of/lib-linux/release-x86-64");
  // rCPP.AddLibraryDir("../../of/lib-linux/debug");
# endif
# endif

# ifdef TARGET_LINUX
  rCPP.AddIncludeDir("/usr/include/AL");
  rCPP.AddIncludeDir("/usr/include/cairo");
  rCPP.AddIncludeDir("/usr/include/gtk-3.0");
  rCPP.AddIncludeDir("/usr/include/atk-1.0");
  rCPP.AddIncludeDir("/usr/include/glib-2.0");
  rCPP.AddIncludeDir("/usr/lib/glib-2.0/include/");
  rCPP.AddIncludeDir("/usr/include/harfbuzz");
  rCPP.AddIncludeDir("/usr/include/pixman-1");
  rCPP.AddIncludeDir("/usr/include/libpng12");
  rCPP.AddIncludeDir("/usr/include/pango-1.0");
  rCPP.AddIncludeDir("/usr/include/freetype2");
  rCPP.AddIncludeDir("/usr/include/gio-unix-2.0");
  rCPP.AddIncludeDir("/usr/include/gstreamer-1.0");
  rCPP.AddIncludeDir("/usr/lib/gstreamer-1.0/include");
  rCPP.AddIncludeDir("/usr/lib/gstreamer-1.0/include/gst");
  rCPP.AddIncludeDir("/usr/include/gdk-pixbuf-2.0");
  rCPP.AddIncludeDir("/usr/include/at-spi2-atk/2.0");
  rCPP.AddIncludeDir("/usr/lib/x86_64-linux-gnu/glib-2.0/include");
# endif

  rCPP.AddIncludeDir("../../of/src/freeimage");
  rCPP.AddIncludeDir("../../of/src/freeimage/OpenEXR");
  rCPP.AddIncludeDir("../../of/src/freeimage/OpenEXR/Half");
  rCPP.AddIncludeDir("../../of/src/freeimage/OpenEXR/Iex");
  rCPP.AddIncludeDir("../../of/src/freeimage/OpenEXR/IlmImf");
  rCPP.AddIncludeDir("../../of/src/freeimage/OpenEXR/IlmThread");
  rCPP.AddIncludeDir("../../of/src/freeimage/OpenEXR/Imath");
  rCPP.AddIncludeDir("../../of/src/rtaudio");
  rCPP.AddIncludeDir("../../of/src/rtaudio/include");
  rCPP.AddIncludeDir("../../of/src/utf8cpp");
  rCPP.AddIncludeDir("../../of/src/utf8cpp/include");
  rCPP.AddIncludeDir("../../of/src/utf8cpp/include/utf8");
  rCPP.AddIncludeDir("../../of/src/glew");
  rCPP.AddIncludeDir("../../of/src/glew/include");
  rCPP.AddIncludeDir("../../of/src/glfw");
  rCPP.AddIncludeDir("../../of/src/glfw/include");
  rCPP.AddIncludeDir("../../of/src/glfw/include/GLFW");
  rCPP.AddIncludeDir("../../of/src/kissfft");
  rCPP.AddIncludeDir("../../of/src/kissfft/tools");
  rCPP.AddIncludeDir("../../of/src/poco");
  rCPP.AddIncludeDir("../../of/src/poco/Crypto/include");
  rCPP.AddIncludeDir("../../of/src/poco/Foundation/include");
  rCPP.AddIncludeDir("../../of/src/poco/Net/include");
  rCPP.AddIncludeDir("../../of/src/poco/NetSSL_OpenSSL/include");
  rCPP.AddIncludeDir("../../of/src/poco/Util/include");
  rCPP.AddIncludeDir("../../of/src/poco/XML/include");
  rCPP.AddIncludeDir("../../of/src/poco/Zip/include");
  rCPP.AddIncludeDir("../../of/src/rtaudio");
  rCPP.AddIncludeDir("../../of/src/rtaudio/include");
  rCPP.AddIncludeDir("../../of/src/libtess2");
  rCPP.AddIncludeDir("../../of/src/libtess2/Include");
  rCPP.AddIncludeDir("../../of/src/libtess2/Sources");
  rCPP.AddIncludeDir("../../of/src/openframeworks");
  rCPP.AddIncludeDir("../../of/src/openframeworks/3d");
  rCPP.AddIncludeDir("../../of/src/openframeworks/app");
  rCPP.AddIncludeDir("../../of/src/openframeworks/communication");
  rCPP.AddIncludeDir("../../of/src/openframeworks/events");
  rCPP.AddIncludeDir("../../of/src/openframeworks/gl");
  rCPP.AddIncludeDir("../../of/src/openframeworks/graphics");
  rCPP.AddIncludeDir("../../of/src/openframeworks/math");
  rCPP.AddIncludeDir("../../of/src/openframeworks/sound");
  rCPP.AddIncludeDir("../../of/src/openframeworks/types");
  rCPP.AddIncludeDir("../../of/src/openframeworks/utils");
  rCPP.AddIncludeDir("../../of/src/openframeworks/video");

  rCPP.AddIncludeDir("../RuntimeCompiledCPlusPlus/Aurora");
  rCPP.AddIncludeDir("..");

  {
    ofDirectory dir(ofFilePath::getCurrentExeDir() + "..");
    dir.listDir();
    vector<ofFile> files = dir.getFiles();
    for (ofFile& file : files)
    {
      if (file.isDirectory() &&
          file.getBaseName().substr(0,3) == "ofx")
      {
        rCPP.AddIncludeDir(&(file.path())[0]);
        rCPP.AddIncludeDir(&(file.path() + "/src")[0]);
      }
    }
  }

  rCPP.GetObjectFactorySystem()->AddListener(this);

  {
    IObject* rObject = rCPP.GetObjectFactorySystem()->GetConstructor("ofApp")->Construct();
    rObject->GetInterface(&rAPP);
    rOID = rObject->GetObjectId();
  }

  rAPP->setup();
}

void ofLive::update()
{
  if (rCPP.GetIsCompiledComplete()) rCPP.LoadCompiledModule();
  rCPP.GetFileChangeNotifier()->Update(0.1f);

  rAPP->update();
}

void ofLive::draw()
{
  rAPP->draw();
}

void ofLive::exit()
{
  rAPP->exit();
}

void ofLive::keyPressed(ofKeyEventArgs& key)
{
  rAPP->keyPressed(key);
}

void ofLive::keyReleased(ofKeyEventArgs& key)
{
  rAPP->keyReleased(key);
}

void ofLive::mouseMoved(ofMouseEventArgs& mouse)
{
  rAPP->mouseMoved(mouse);
}

void ofLive::mouseDragged(ofMouseEventArgs& mouse)
{
  rAPP->mouseDragged(mouse);
}

void ofLive::mousePressed(ofMouseEventArgs& mouse)
{
  rAPP->mousePressed(mouse);
}

void ofLive::mouseReleased(ofMouseEventArgs& mouse)
{
  rAPP->mouseReleased(mouse);
}

void ofLive::mouseScrolled(ofMouseEventArgs& mouse)
{
  rAPP->mouseScrolled(mouse);
}

void ofLive::mouseEntered(ofMouseEventArgs& mouse)
{
  rAPP->mouseEntered(mouse);
}

void ofLive::mouseExited(ofMouseEventArgs& mouse)
{
  rAPP->mouseExited(mouse);
}

void ofLive::touchDown(ofTouchEventArgs& touch)
{
  rAPP->touchDown(touch);
}

void ofLive::touchMoved(ofTouchEventArgs& touch)
{
  rAPP->touchMoved(touch);
}

void ofLive::touchUp(ofTouchEventArgs& touch)
{
  rAPP->touchUp(touch);
}

void ofLive::touchDoubleTap(ofTouchEventArgs& touch)
{
  rAPP->touchDoubleTap(touch);
}

void ofLive::touchCancelled(ofTouchEventArgs& touch)
{
  rAPP->touchCancelled(touch);
}

void ofLive::windowResized(ofResizeEventArgs& window)
{
  rAPP->windowResized(window);
}

void ofLive::dragged(ofDragInfo& dragged)
{
  rAPP->dragged(dragged);
}

void ofLive::messageReceived(ofMessage& message)
{
  rAPP->messageReceived(message);
}

void ofLive::OnConstructorsAdded()
{
  if (rAPP) rCPP.GetObjectFactorySystem()->GetObject(rOID)->GetInterface(&rAPP);
}

#endif // #ifdef RCCPP
