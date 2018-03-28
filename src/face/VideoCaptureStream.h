//
// Created by Tobe on 3/28/18.
//

#ifndef FRKS_VIDEOCAPTURESTREAM_H
#define FRKS_VIDEOCAPTURESTREAM_H

#include <opencv2/opencv.hpp>
#include "FaceMeasurementStream.h"

/**
 * @brief Captures face data from an OpenCV `VideoCapture`.
 */
class VideoCaptureStream: public FaceMeasurementStream {
private:
    cv::VideoCapture *capture;

public:
    VideoCaptureStream();

    bool is_done() override;

    FaceMeasurement *next() override;
};


#endif //FRKS_VIDEOCAPTURESTREAM_H
