//
// Created by Tobe on 3/28/18.
//

#include "VideoCaptureStream.h"

VideoCaptureStream::VideoCaptureStream() {
    capture = new cv::VideoCapture(0);

    if (!capture->isOpened()) {
        capture = nullptr;
    }
}


bool VideoCaptureStream::is_done() {
    return capture == nullptr;
}

FaceMeasurement *VideoCaptureStream::next() {
    cv::Mat mat;
    *capture >> mat;
    return convert_mat(mat);
}

FaceMeasurement *VideoCaptureStream::convert_mat(cv::Mat mat) {
    return nullptr;
}
