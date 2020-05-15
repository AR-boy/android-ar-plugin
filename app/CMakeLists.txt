cmake_minimum_required(VERSION 3.0.0)

# add_library(OpenCVUnity SHARED src/cpp/openCVTest.cpp)

add_library(OpenCVUnity SHARED
        src/cpp/calibrate_camera.cpp
        src/cpp/detect_markers.cpp
        src/cpp/estimate_pose.cpp
        src/cpp/marshalling_API.cpp
        src/cpp/utilities.cpp
        )

include_directories(src/main/cpp/include/)

add_library(open-cv SHARED IMPORTED )

set_target_properties(open-cv PROPERTIES IMPORTED_LOCATION
        ${CMAKE_SOURCE_DIR}/src/cpp/opencv-native/abi/${ANDROID_ABI}/libopencv_java4.so)

include_directories(src/cpp/opencv-native/include/)

find_library( # Defines the name of the path variable that stores the
        # location of the NDK library.
        log-lib

        # Specifies the name of the NDK library that
        # CMake needs to locate.
        log )

target_link_libraries(
        OpenCVUnity
        open-cv
        ${log-lib})
