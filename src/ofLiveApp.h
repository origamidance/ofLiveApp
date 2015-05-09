#pragma once

#ifndef NO_LIVECODE
#include <RuntimeObjectSystem/ObjectInterfacePerModule.h>
#include <RuntimeObjectSystem/IObjectFactorySystem.h>
#include <RuntimeObjectSystem/RuntimeObjectSystem.h>
#include <RuntimeObjectSystem/IObject.h>
#endif

#include <ofMain.h>

struct ofGlobals
{
};

class ofLiveApp
#ifndef NO_LIVECODE
:public TInterface<IID_IOBJECT,IObject>
#endif
{
  public:
    virtual void setup  (ofGlobals&);
    virtual void update (ofGlobals&);
    virtual void draw   (ofGlobals&);
    virtual void exit   (ofGlobals&);

    virtual void keyPressed    (ofGlobals&, ofKeyEventArgs&);
    virtual void keyReleased   (ofGlobals&, ofKeyEventArgs&);
    virtual void mouseMoved    (ofGlobals&, ofMouseEventArgs&);
    virtual void mouseDragged  (ofGlobals&, ofMouseEventArgs&);
    virtual void mousePressed  (ofGlobals&, ofMouseEventArgs&);
    virtual void mouseReleased (ofGlobals&, ofMouseEventArgs&);
    virtual void windowResized (ofGlobals&, ofResizeEventArgs&);
    virtual void gotMessage    (ofGlobals&, ofMessage);
    virtual void dragEvent     (ofGlobals&, ofDragInfo);
};

#ifndef NO_LIVECODE

struct RCPPLogger : ICompilerLogger
{
  void LogError(const char *format, ...)
  {
    fprintf(stderr, "RCPP Error: %s", format);
  }

  void LogWarning(const char *format, ...)
  {
    printf("RCPP Warning: %s", format);
  }

  void LogInfo(const char *format, ...)
  {
    printf("RCPP Info: %s", format);
  }
};

#ifdef TARGET_LINUX
RUNTIME_COMPILER_LINKLIBRARY(
#ifdef __clang__
"-Wno-deprecated-register "
#endif
"-std=c++11 "
"-lPocoFoundation "
"-lassimp "
"-lfreeimage "
"-lglew "
"-lglfw3 "
"-lhalf "
"-liex "
"-lilmimf "
"-lilmthread "
"-limath "
"-ljpeg "
"-lkiss "
"-lopenFrameworks "
"-lopenjpeg "
"-lpng "
"-lPocoCrypto "
"-lPocoData "
"-lPocoDataSQLite "
"-lPocoJSON "
"-lPocoMongoDB "
"-lPocoNet "
"-lPocoNetSSL "
"-lPocoUtil "
"-lPocoXML "
"-lPocoZip "
"-lrawlite "
"-lrtaudio "
"-ltess2 "
"-ltiff "
"-lwebp "
"-lrt "
"-ldl "
"-lXi "
"-lSM "
"-lICE "
"-lX11 "
"-lXext "
"-lXrandr "
"-lXcursor "
"-lXxf86vm "
"-lXinerama "
"-ludev "
"-lgtk-3 "
"-lgdk-3 "
"-latk-1.0 "
"-lgio-2.0 "
"-lpangocairo-1.0 "
"-lgdk_pixbuf-2.0 "
"-lcairo-gobject "
"-lpango-1.0 "
"-lcairo "
"-lgobject-2.0 "
"-lglib-2.0 "
"-lglib-2.0 "
"-lgthread-2.0 "
"-lgmodule-2.0 "
"-lz "
"-lasound "
"-lopenal "
"-lcairo "
"-lGLU "
"-lGL "
"-lSM "
"-lICE "
"-lX11 "
"-lXext "
"-lssl "
"-lcrypto "
"-lsndfile "
"-lfreetype "
"-lgstreamer-1.0 "
"-lfontconfig "
"-lpthread "
"-lgstapp-1.0 "
"-lgstbase-1.0 "
"-lgstvideo-1.0 "
"-lXrandr "
"-lXcursor "
"-lXxf86vm "
"-lXinerama "
"-ludev "
"-lgtk-3 "
"-lgdk-3 "
"-latk-1.0 "
"-lgio-2.0 "
"-lpangocairo-1.0 "
"-lgdk_pixbuf-2.0 "
"-lcairo-gobject "
"-lpango-1.0 "
"-lcairo "
"-lgobject-2.0 "
"-lglib-2.0 "
"-lglib-2.0 "
"-lgthread-2.0 "
"-lgmodule-2.0 "
"-lz "
"-lasound "
"-lopenal "
"-lcairo "
"-lGLU "
"-lGL "
"-lssl "
"-lcrypto "
"-lsndfile "
"-lfreetype "
"-lgstreamer-1.0 "
"-lfontconfig "
"-lpthread "
"-lgstapp-1.0 "
"-lgstbase-1.0 "
"-lgstvideo-1.0 "
)
#endif // #ifdef TARGET_LINUX

#endif // #ifndef NO_LIVECODE
