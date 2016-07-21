cmake_minimum_required(VERSION 3.2)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_program(CCACHE_FOUND ccache)
if(CCACHE_FOUND)
    message(STATUS "find ccache")
    set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE ccache)
    set_property(GLOBAL PROPERTY RULE_LAUNCH_LINK ccache)
endif(CCACHE_FOUND)

project(ofApp)
set(APP ofApp)

include(cotire)
set(COTIRE_MINIMUM_NUMBER_OF_TARGET_SOURCES 1)
set_directory_properties(PROPERTIES COTIRE_ADD_UNITY_BUILD FALSE)
set(CMAKE_SUPPRESS_DEVELOPER_WARNINGS 1 CACHE INTERNAL "")

set(OF_PLATFORM x86 CACHE STRING "Platform architecture. No need to be modified by default.")
if(CMAKE_SIZEOF_VOID_P EQUAL 8 AND NOT OF_32BIT)
   set(ARCH_BIT 64)
else()
   set(ARCH_BIT 32)
endif()

# include(../of/openFrameworks.cmake)
set(OF_ROOT_DIR ../of)
if(CMAKE_BUILD_TYPE MATCHES Release)
  set(OF_LIB_DIR "${OF_ROOT_DIR}/lib-linux/release-${OF_PLATFORM}-${ARCH_BIT}")
elseif(CMAKE_BUILD_TYPE MATCHES Debug)
  set(OF_LIB_DIR "${OF_ROOT_DIR}/lib-linux/debug-${OF_PLATFORM}-${ARCH_BIT}")
endif()

set(OF_AUDIO ON CACHE BOOL "Compile audio features of openFrameworks")
set(OF_VIDEO ON CACHE BOOL "Compile video features of openFrameworks")

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE "${CMAKE_CURRENT_SOURCE_DIR}/bin")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_CURRENT_SOURCE_DIR}/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG   "${CMAKE_CURRENT_SOURCE_DIR}/bin")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG   "${CMAKE_CURRENT_SOURCE_DIR}/bin")

find_package(PkgConfig REQUIRED)
pkg_check_modules(CAIRO REQUIRED cairo)
pkg_check_modules(FONTCONFIG REQUIRED fontconfig)

find_package(OpenGL REQUIRED)
find_package(X11 REQUIRED)
find_package(ZLIB REQUIRED)
find_package(Pixman REQUIRED)
find_package(OpenSSL REQUIRED)
find_package(Threads REQUIRED)
find_package(Freetype REQUIRED)
find_package(GLEW REQUIRED)
find_package(Boost COMPONENTS filesystem system REQUIRED)
find_package(ALSA REQUIRED)
find_package(OpenAL REQUIRED)
find_package(MPG123 REQUIRED)
find_package(Sndfile REQUIRED)
find_package(UDev REQUIRED)
find_package(Glib REQUIRED)
find_package(GStreamer REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)
set(OPENFRAMEWORKS_INCLUDE_DIRS
    "${OF_ROOT_DIR}/src/openframeworks"
    "${OF_ROOT_DIR}/src/openframeworks/3d"
    "${OF_ROOT_DIR}/src/openframeworks/app"
    "${OF_ROOT_DIR}/src/openframeworks/communication"
    "${OF_ROOT_DIR}/src/openframeworks/events"
    "${OF_ROOT_DIR}/src/openframeworks/gl"
    "${OF_ROOT_DIR}/src/openframeworks/graphics"
    "${OF_ROOT_DIR}/src/openframeworks/math"
    "${OF_ROOT_DIR}/src/openframeworks/sound"
    "${OF_ROOT_DIR}/src/openframeworks/types"
    "${OF_ROOT_DIR}/src/openframeworks/utils"
    "${OF_ROOT_DIR}/src/openframeworks/video"

    "${OF_ROOT_DIR}/src/freeimage"
    "${OF_ROOT_DIR}/src/freeimage/OpenEXR"
    "${OF_ROOT_DIR}/src/freeimage/OpenEXR/Half"
    "${OF_ROOT_DIR}/src/freeimage/OpenEXR/Iex"
    "${OF_ROOT_DIR}/src/freeimage/OpenEXR/IlmImf"
    "${OF_ROOT_DIR}/src/freeimage/OpenEXR/IlmThread"
    "${OF_ROOT_DIR}/src/freeimage/OpenEXR/Imath"

    "${OF_ROOT_DIR}/src/glew"
    "${OF_ROOT_DIR}/src/glew/include"

    "${OF_ROOT_DIR}/src/glfw"
    "${OF_ROOT_DIR}/src/glfw/include"
    "${OF_ROOT_DIR}/src/glfw/include/GLFW"

    "${OF_ROOT_DIR}/src/kissfft"
    "${OF_ROOT_DIR}/src/kissfft/tools"

    "${OF_ROOT_DIR}/src/libtess2"
    "${OF_ROOT_DIR}/src/libtess2/Include"
    "${OF_ROOT_DIR}/src/libtess2/Source"

    "${OF_ROOT_DIR}/src/poco"
    "${OF_ROOT_DIR}/src/poco/Crypto/include"
    "${OF_ROOT_DIR}/src/poco/Foundation/include"
    "${OF_ROOT_DIR}/src/poco/Net/include"
    "${OF_ROOT_DIR}/src/poco/NetSSL_OpenSSL/include"
    "${OF_ROOT_DIR}/src/poco/Util/include"
    "${OF_ROOT_DIR}/src/poco/XML/include"
    "${OF_ROOT_DIR}/src/poco/Zip/include"

    "${OF_ROOT_DIR}/src/rtaudio"
    "${OF_ROOT_DIR}/src/rtaudio/include"

    "${OF_ROOT_DIR}/src/utf8cpp"
    "${OF_ROOT_DIR}/src/utf8cpp/include"
        #    ${X11_INCLUDE_DIR}
        ${ZLIB_INCLUDE_DIRS}
        ${PIXMAN_INCLUDE_DIRS}
        ${CAIRO_INCLUDE_DIRS}
        ${Boost_INCLUDE_DIRS}
        ${OPENGL_INCLUDE_DIR}
        ${OPENSSL_INCLUDE_DIR}
        ${FREETYPE_INCLUDE_DIRS}
        ${FONTCONFIG_INCLUDE_DIRS}
        ${GLEW_INCLUDE_DIRS}
        #    ${ALSA_INCLUDE_DIRS}
        #    ${OPENAL_INCLUDE_DIR}
        #    ${MPG123_INCLUDE_DIRS}
        #    ${SNDFILE_INCLUDE_DIR}
        ${UDEV_INCLUDE_DIR}
        ${GLIB_INCLUDE_DIRS}
        ${GTK3_INCLUDE_DIRS}
        ${GSTREAMER_INCLUDE_DIRS}
)
file(GLOB_RECURSE OPENFRAMEWORKS_LIBS "${OF_LIB_DIR}/*.so")
if(NOT OPENFRAMEWORKS_LIBS)
  message(FATAL_ERROR "No shared openFrameworks libraries found in ${OF_LIB_DIR} folder.")
endif()

set(OPENFRAMEWORKS_LIBRARIES
  ${OPENFRAMEWORKS_LIBS}
        #  ${X11_Xi_LIB}
        #  ${X11_LIBRARIES}
        #  ${X11_Xrandr_LIB}
        #  ${X11_Xcursor_LIB}
        #  ${X11_Xxf86vm_LIB}
        #  ${X11_Xinerama_LIB}
  ${ZLIB_LIBRARIES}
  ${CAIRO_LIBRARIES}
  ${PIXMAN_LIBRARIES}
  ${OPENGL_LIBRARIES}
  ${OPENSSL_LIBRARIES}
  ${FREETYPE_LIBRARIES}
  ${FONTCONFIG_LIBRARIES}
  ${FREEIMAGE_LIBRARIES}
  ${Boost_SYSTEM_LIBRARY}
  ${Boost_FILESYSTEM_LIBRARY}
  ${GLEW_LIBRARIES}
  ${CMAKE_THREAD_LIBS_INIT}
        #${ALSA_LIBRARIES}
        #${OPENAL_LIBRARY}
        #${MPG123_LIBRARIES}
        #${SNDFILE_LIBRARIES}
        ${UDEV_LIBRARIES}
        ${GLIB_LIBRARIES}
        ${GTK3_LIBRARIES}
        ${GSTREAMER_LIBRARIES}
        ${GSTREAMER_APP_LIBRARIES}
        ${GSTREAMER_BASE_LIBRARIES}
        ${GSTREAMER_VIDEO_LIBRARIES}
  )

#if(NOT OF_AUDIO)
#  list(APPEND OPENFRAMEWORKS_DEFINITIONS -DTARGET_NO_SOUND)
#else()
#  find_package(ALSA REQUIRED)
#  find_package(OpenAL REQUIRED)
#  find_package(MPG123 REQUIRED)
#  find_package(Sndfile REQUIRED)
#
#  list(APPEND OPENFRAMEWORKS_INCLUDE_DIRS
#    ${ALSA_INCLUDE_DIRS}
#    ${OPENAL_INCLUDE_DIR}
#    ${MPG123_INCLUDE_DIRS}
#    ${SNDFILE_INCLUDE_DIR}
#    )
#
#  list(APPEND OPENFRAMEWORKS_LIBRARIES
#    ${ALSA_LIBRARIES}
#    ${OPENAL_LIBRARY}
#    ${MPG123_LIBRARIES}
#    ${SNDFILE_LIBRARIES}
#    )
#endif()
#
#if(NOT OF_VIDEO)
#  list(APPEND OPENFRAMEWORKS_DEFINITIONS -DTARGET_NO_VIDEO)
#else()
#  list(APPEND OPENFRAMEWORKS_DEFINITIONS -DOF_USING_GTK)
#
#  find_package(UDev REQUIRED)
#  find_package(Glib REQUIRED)
#  find_package(GStreamer REQUIRED)
#  pkg_check_modules(GTK3 REQUIRED gtk+-3.0)
#
#  list(APPEND OPENFRAMEWORKS_INCLUDE_DIRS
#    ${UDEV_INCLUDE_DIR}
#    ${GLIB_INCLUDE_DIRS}
#    ${GTK3_INCLUDE_DIRS}
#    ${GSTREAMER_INCLUDE_DIRS}
#    )
#
#  list(APPEND OPENFRAMEWORKS_LIBRARIES
#    ${UDEV_LIBRARIES}
#    ${GLIB_LIBRARIES}
#    ${GTK3_LIBRARIES}
#    ${GSTREAMER_LIBRARIES}
#    ${GSTREAMER_APP_LIBRARIES}
#    ${GSTREAMER_BASE_LIBRARIES}
#    ${GSTREAMER_VIDEO_LIBRARIES}
#    )
#endif()
#message(STATUS ${OPENFRAMEWORKS_INCLUDE_DIRS})
message(STATUS "openframeworks libraries:${OPENFRAMEWORKS_LIBRARIES}")
include_directories(${OPENFRAMEWORKS_INCLUDE_DIRS})
#
#if(CMAKE_C_COMPILER_ID STREQUAL Clang)
#
#  set(RELEASE_C_FLAGS_CLANG "
#    ${RELEASE_C_FLAGS_CLANG}
#    -Wno-switch
#    -Wno-c++11-narrowing
#    -Wno-ignored-attributes
#    -Wno-deprecated-register
#  ")
#
#  set(DEBUG_C_FLAGS_CLANG "
#    ${DEBUG_C_FLAGS_CLANG}
#    -Wno-switch
#    -Wno-c++11-narrowing
#    -Wno-ignored-attributes
#    -Wno-deprecated-register
#  ")
#
#endif()

#if(CMAKE_CXX_COMPILER_ID STREQUAL Clang)
#
#  set(CXX_FLAGS_CLANG "
#    ${RELEASE_CXX_FLAGS_CLANG}
#    -Wno-switch
#    -Wno-c++11-narrowing
#    -Wno-ignored-attributes
#    -Wno-deprecated-register
#  ")
#
#  set(CXX_COLORIZATION "-fcolor-diagnostics")
#  set(O_C_FLAG -O0)
#  set(O_CXX_FLAG -O0)
#  set(PIC_FLAG -fPIC)
#  set(CPP11_FLAG -std=gnu++14)
#  set(RELEASE_FLAGS "
#  ${RELEASE_FLAGS}
#  -g1
#")
#endif()
set(CMAKE_CXX_FLAGS
        "-std=c++11 -fPIC -Wno-switch -Wno-c++11-narrowing -Wno-ignored-attributes -Wno-deprecated-register"
  )

#// LIVECODING /////////////////////////////////////////////////////////////////

set(OF_ENABLE_LIVECODING ON CACHE BOOL "")
message("++ OF_ENABLE_LIVECODING: " ${OF_ENABLE_LIVECODING})

if(OF_ENABLE_LIVECODING)
    add_definitions(-DRCCPP)
    set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
    add_subdirectory(RuntimeCompiledCPlusPlus/Aurora)
    include_directories(RuntimeCompiledCPlusPlus/Aurora)
    #    list(APPEND OPENFRAMEWORKS_LIBRARIES RuntimeCompiler RuntimeObjectSystem)
    set(OPENFRAMEWORKS_LIBRARIES ${OPENFRAMEWORKS_LIBRARIES} RuntimeCompiler RuntimeObjectSystem)
endif()

#///////////////////////////////////////////////////////////////////////////////

# ofxaddon(addons/ofxImGui)
set(OFXADDON_DIR ${CMAKE_CURRENT_LIST_DIR}/addons/ofxImGui)
include_directories("${CMAKE_CURRENT_LIST_DIR}/addons/ofxImGui/src")
include_directories("${CMAKE_CURRENT_LIST_DIR}/addons/ofxImGui/libs")
include_directories("${CMAKE_CURRENT_LIST_DIR}/addons/ofxImGui/libs/imgui/src")

file(GLOB_RECURSE OFXHEADERS
  "${OFXADDON_DIR}/src/*.h"
  "${OFXADDON_DIR}/src/*.hh"
  "${OFXADDON_DIR}/src/*.hpp"
  "${OFXADDON_DIR}/libs/*.h"
  "${OFXADDON_DIR}/libs/*.hh"
  "${OFXADDON_DIR}/libs/*.hpp"
  )

file(GLOB_RECURSE OFXSOURCES
  "${OFXADDON_DIR}/src/*.c"
  "${OFXADDON_DIR}/src/*.cc"
  "${OFXADDON_DIR}/src/*.cpp"
  "${OFXADDON_DIR}/libs/*.c"
  "${OFXADDON_DIR}/libs/*.cc"
  "${OFXADDON_DIR}/libs/*.cpp"
  )
if(OFXSOURCES)
  set(OFXADDONS_SOURCES ${OFXADDONS_SOURCES} ${OFXSOURCES})
endif()

set(SOURCES
        src/main.cpp
        src/ofApp.cpp
        src/ofLive.cpp
)

add_executable(
    ${APP}
    ${SOURCES}
    ${OFXADDONS_SOURCES}
)

target_link_libraries(
    ${APP}
    ${OPENFRAMEWORKS_LIBRARIES}
)

cotire(${APP})
