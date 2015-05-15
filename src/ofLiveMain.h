#pragma once

#include <ofMain.h>

#ifdef RCCPP
#include <RuntimeObjectSystem/ObjectInterfacePerModule.h>
#include <RuntimeObjectSystem/IObjectFactorySystem.h>
#include <RuntimeObjectSystem/RuntimeObjectSystem.h>
#include <RuntimeObjectSystem/ISimpleSerializer.h>
#include <RuntimeObjectSystem/IObject.h>
#endif

#ifdef RCCPP
#define ofLiveApp TInterface<IID_IOBJECT,IObject>
#else
#define ofLiveApp ofBaseApp
#endif

#ifdef RCCPP
#define SERIALIZE_BEGIN virtual void Serialize(ISimpleSerializer* pSerializer) {
#define SERIALIZE_END }
#else
#define SERIALIZE_BEGIN
#define SERIALIZE(x)
#define SERIALIZE_END
#define REGISTERCLASS(x)
#endif

#ifdef RCCPP
struct RCPPLogger : ICompilerLogger
{
  void LogError(const char *format, ...)
  {
    va_list args;
    va_start(args, format);
    vprintf(format, args);
    va_end(args);
  }

  void LogWarning(const char *format, ...)
  {
    va_list args;
    va_start(args, format);
    vprintf(format, args);
    va_end(args);
  }

  void LogInfo(const char *format, ...)
  {
    va_list args;
    va_start(args, format);
    vprintf(format, args);
    va_end(args);
  }
};

#ifdef TARGET_LINUX
RUNTIME_COMPILER_LINKLIBRARY(
"-DRCCPP "
"-DOF_USING_GTK "
"-DOF_SOUND_PLAYER_OPENAL "
"-DOF_SOUNDSTREAM_RTAUDIO "
"-DOF_VIDEO_PLAYER_GSTREAMER "
"-DOF_VIDEO_CAPTURE_GSTREAMER "
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
#endif // #ifdef RCCPP
