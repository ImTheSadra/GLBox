cmake_minimum_required(VERSION 3.16)
project(gboxl LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(GLBOX_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Source)
set(GLBOX_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Source)

file(GLOB_RECURSE SOURCES 
    ${GLBOX_SOURCE_DIR}/*.cpp 
    ${GLBOX_SOURCE_DIR}/*.inl 
    ${GLBOX_SOURCE_DIR}/*.c
)
file(GLOB_RECURSE HEADERS 
    ${GLBOX_SOURCE_DIR}/*.h 
    ${GLBOX_SOURCE_DIR}/*.hpp
)

add_library(GLBox STATIC ${SOURCES} ${HEADERS})

if(WIN32)
    message(STATUS "Configuring for Windows")
    
    target_compile_definitions(GLBox PUBLIC 
        _WIN32
        _MBCS 
        _CRT_SECURE_NO_WARNINGS
    )
    
    target_link_libraries(GLBox PUBLIC
        opengl32
        gdi32
        user32
        kernel32
    )
    
elseif(APPLE)
    message(STATUS "Configuring for macOS")
    
    target_compile_definitions(GLBox PUBLIC
        __APPLE__
    )
    
    find_package(OpenGL REQUIRED)
    target_link_libraries(GLBox PUBLIC
        ${OPENGL_LIBRARIES}
        "-framework Cocoa"
        "-framework OpenGL"
    )
    
else() # Linux/Unix
    message(STATUS "Configuring for Linux/Unix")
    
    find_package(OpenGL REQUIRED)
    find_package(X11 REQUIRED)
    
    target_compile_definitions(GLBox PUBLIC
        _X11
        GLX_GLXEXT_PROTOTYPES
    )
    
    target_link_libraries(GLBox PUBLIC
        ${X11_LIBRARIES}
        ${OPENGL_LIBRARIES}
        OpenGL::GL
        dl
        pthread
    )
endif()

target_include_directories(GLBox
    PUBLIC 
        $<BUILD_INTERFACE:${GLBOX_INCLUDE_DIR}>
        $<INSTALL_INTERFACE:include>
    PRIVATE
        ${GLBOX_SOURCE_DIR}
)

install(
    DIRECTORY ${GLBOX_HEADERS_DIR}/
    DESTINATION include/${PROJECT_NAME}
    FILES_MATCHING 
        PATTERN "*.h" 
        PATTERN "*.hpp"
)

set_target_properties(GLBox PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)