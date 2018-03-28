//
// Created by Tobe on 3/28/18.
//

#include "VideoCaptureStream.h"

VideoCaptureStream::VideoCaptureStream() {
    mCapture = new cv::VideoCapture(0);

    if (!mCapture->isOpened())
        mCapture = nullptr;
    else {
        mFaceCascade = new cv::CascadeClassifier("haarcascade_frontalface_default.xml");
        mEyeCascade = new cv::CascadeClassifier("haarcascade_eye.xml");
    }
}


bool VideoCaptureStream::is_done() {
    return mCapture == nullptr;
}

FaceMeasurement *VideoCaptureStream::next() {
    cv::Mat mat;
    *mCapture >> mat;
    return convert_mat(mat, mFaceCascade, mEyeCascade);
}

FaceMeasurement *
VideoCaptureStream::convert_mat(cv::Mat mat, cv::CascadeClassifier *pFaceCascade, cv::CascadeClassifier *pEyeCascade) {

    // Convert to grayscale
    cv::Mat gray;
    cv::cvtColor(mat, gray, cv::COLOR_BGR2GRAY);

    // Detect faces
    std::vector<cv::Rect> faces;
    pFaceCascade->detectMultiScale(gray, faces, 1.3, 5);

    cv::namedWindow("w", cv::WINDOW_AUTOSIZE);
    cv::imshow("w", gray);
    cv::waitKey(0);
    cv::destroyAllWindows();
    return nullptr;
}
