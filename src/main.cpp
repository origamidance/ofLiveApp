#include "ofLive.h"

int main()
{
  ofGLFWWindowSettings settings;
  auto window = ofCreateWindow(settings);
  #ifdef RCCPP
  auto app = make_shared<ofLive>();
  #else
  auto app = make_shared<ofApp>();
  #endif
  ofRunApp(window, app);

  return ofRunMainLoop();

}
