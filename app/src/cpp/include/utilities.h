#pragma once
#define _USE_MATH_DEFINES
#include "platform.h"
#include <opencv2\core\matx.hpp>
#include <opencv2\calib3d.hpp>
#include <iostream>
#include <cmath>
#include <string>
// opencv imports


extern "C" {

    void RotationVectorToEulerAngles(
            cv::Vec3d* rvec,
            cv::Mat* eulerRvecs
    );

    cv::Mat ConvertUnityTextureToMat(
            unsigned char* textureData,
            int width,
            int height
    );
}
