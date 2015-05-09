cmake_minimum_required(VERSION 2.8)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../of")

project(ofLiveApp)
set(APP ofLiveApp)

include(openFrameworks)

set(OF_ENABLE_LIVECODE ON CACHE BOOL "")

if(OF_ENABLE_LIVECODE)
    add_definitions(-DOF_LIVECODE)
    set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
    add_subdirectory(RuntimeCompiledCPlusPlus/Aurora)
    include_directories(RuntimeCompiledCPlusPlus/Aurora)
    list(APPEND OPENFRAMEWORKS_LIBRARIES RuntimeCompiler RuntimeObjectSystem)
endif()

#ofxaddon()

set(SOURCES
    src/main.cpp
    src/ofApp.cpp
    src/ofLiveApp.cpp
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
