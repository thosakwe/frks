//
// Created by Tobe on 3/28/18.
//

#ifndef FRKS_VIDEOCAPTURESTREAM_H
#define FRKS_VIDEOCAPTURESTREAM_H

#include <cmath>
#include <opencv2/opencv.hpp>
#include <vector>
#include "FaceMeasurementStream.h"

/**
 * @brief Captures face data from an OpenCV `VideoCapture`.
 */
class VideoCaptureStream: public FaceMeasurementStream {
private:
    cv::VideoCapture *mCapture;
    cv::CascadeClassifier *mFaceCascade, *mEyeCascade;

public:
    VideoCaptureStream();

    /**
     * Converts an OpenCV `Matrix` to a `FaceMeasurement`.
     * @param mat
     * @return
     */
    static FaceMeasurement* convert_mat(cv::Mat mat, cv::CascadeClassifier *pFaceCascade, cv::CascadeClassifier *pEyeCascade);

    bool is_done() override;

    FaceMeasurement *next() override;
};


#endif //FRKS_VIDEOCAPTURESTREAM_H
