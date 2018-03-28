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
    return nullptr;
}

FaceMeasurement *VideoCaptureStream::convert_mat(cv::Mat mat) {
    return nullptr;
}
