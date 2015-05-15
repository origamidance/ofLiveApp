project(ofApp)
set(APP ofApp)

cmake_minimum_required(VERSION 2.8)

include(../of/openFrameworks.cmake)

#// LIVECODING /////////////////////////////////////////////////////////////////

set(OF_ENABLE_LIVECODING ON CACHE BOOL "")
message("++ OF_ENABLE_LIVECODING: " ${OF_ENABLE_LIVECODING})

if(OF_ENABLE_LIVECODING)
    add_definitions(-DRCCPP)
    set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
    add_subdirectory(RuntimeCompiledCPlusPlus/Aurora)
    include_directories(RuntimeCompiledCPlusPlus/Aurora)
    list(APPEND OPENFRAMEWORKS_LIBRARIES RuntimeCompiler RuntimeObjectSystem)
endif()

#///////////////////////////////////////////////////////////////////////////////

#ofxaddon()

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
