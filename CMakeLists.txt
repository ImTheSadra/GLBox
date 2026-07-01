cmake_minimum_required(VERSION 3.16)
project(gboxl LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(GLBox STATIC)

target_sources(GLBox
    PRIVATE
        Source/glbox.cpp
        Source/glbox.h
        Source/glbox_head.h
        Source/textures.h
        Source/uniforms.h
)

target_include_directories(GLBox
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/Source>
        $<INSTALL_INTERFACE:include/GLBox>
)

if(WIN32)
    target_compile_definitions(GLBox PUBLIC _WIN32 _CRT_SECURE_NO_WARNINGS)
    target_link_libraries(GLBox PUBLIC opengl32 gdi32 user32)
elseif(APPLE)
    target_compile_definitions(GLBox PUBLIC __APPLE__)
    find_package(OpenGL REQUIRED)
    target_link_libraries(GLBox PUBLIC OpenGL::GL "-framework Cocoa")
else()
    find_package(OpenGL REQUIRED)
    find_package(X11 REQUIRED)
    target_compile_definitions(GLBox PUBLIC _X11 GLX_GLXEXT_PROTOTYPES)
    target_link_libraries(GLBox PUBLIC OpenGL::GL X11::X11 ${CMAKE_DL_LIBS} pthread)
endif()

set_target_properties(GLBox PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

install(TARGETS GLBox
    EXPORT GLBoxTargets
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin
)

install(FILES
    Source/glbox.h
    Source/glbox_head.h
    Source/textures.h
    Source/uniforms.h
    DESTINATION include/GLBox
)
