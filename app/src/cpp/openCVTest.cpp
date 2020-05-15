//
// Created by Matas on 11/02/2020.
//

#include <opencv2/opencv.hpp>
#include <opencv2/objdetect.hpp>
#include <opencv2/aruco.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <stdio.h>


/*
 * Method to convert Unity given texture from camera
 * capture into usable format for OpenCV
 */

extern "C" {

    // native methods that help managed c# code to marshall - std::vector<int> structure

    std::vector<int> * CreateVectorIntPointer()
    {
        return new std::vector<int>();
    }

    void DeleteVectorIntPointer(std::vector<int> * pointer)
    {
        delete pointer;
    }

    int *  GetVectorIntData(std::vector<int> * pointer)
    {
        return pointer->data();
    }

    int GetVectorIntSize(std::vector<int> * pointer)
    {
        return pointer->size();
    }




    // native methods that help managed c# code to marshall - std::vector<cv::Point2f> structure

     std::vector<cv::Point2f> * CreateVector2PointFPointer()
    {
        return new std::vector<cv::Point2f>();
    }
    void  DeleteVector2PointFPointer(std::vector<cv::Point2f>* pointer)
    {
        delete pointer;
    }

    cv::Point2f * GetVector2PointFPointerData(std::vector<cv::Point2f> * pointer)
    {
        return pointer->data();
    }

     int GetVector2PointFPointerSize(std::vector<cv::Point2f> * pointer)
    {
        return pointer->size();
    }


    // native methods that help managed c# code to marshall - std::vector<std::vector<cv::Point2f>> structure

    std::vector<std::vector<cv::Point2f>> * CreateDoubleVector2PointFPointer()
    {
        return new std::vector<std::vector<cv::Point2f>>();
    }

    void DeleteDoubleVector2PointFPointer(std::vector<std::vector<cv::Point2f>> * pointer)
    {
        delete pointer;
    }

    std::vector<cv::Point2f> *  GetDoubleVector2PointFPointerData(std::vector<std::vector<cv::Point2f>> * pointer)
    {
        return pointer->data();
    }
    std::vector<cv::Point2f> *  GetDoubleVector2PointFPointerDataAt(std::vector<std::vector<cv::Point2f>> * pointer, int offset)
    {
        return pointer->data()+ offset;
    }

    int GetDoubleVector2PointFPointerSize(std::vector<std::vector<cv::Point2f>> * pointer)
    {
        return pointer->size();
    }


    void DetectMarkers(
            unsigned char* textureData,
            int width,
            int height,
            std::vector<int> * markerIds,
            std::vector<std::vector<cv::Point2f>> * markerCorners,
            std::vector<std::vector<cv::Point2f>> * rejectedCandidates)
    {
        // assign pointers
        cv::Ptr<cv::aruco::DetectorParameters> parameters = cv::aruco::DetectorParameters::create();
        cv::Ptr<cv::aruco::Dictionary> dictionary = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_6X6_250);

        cv::Mat texture = cv::Mat(height, width, CV_8UC4, textureData);
        if (texture.empty())
        {
            // return markerCorners;
        }

        // format image for detection
        cv::cvtColor(texture, texture, cv::COLOR_BGRA2RGB);
        cv::flip(texture, texture, 0);

        // detect markers
        cv::aruco::detectMarkers(texture, dictionary, *markerCorners, *markerIds, parameters, *rejectedCandidates);

        if (markerCorners->empty())
        {
            // return markerCorners;
        }
        // return pointer
        // return markerCorners;
        // later return an int for exit code
    }

}