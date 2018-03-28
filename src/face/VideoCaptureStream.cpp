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

    // Detect eyes first.
    std::vector<cv::Rect> eyes;

    pEyeCascade->detectMultiScale(gray, eyes, 1.3, 5);

    if (eyes.size() < 2)
        return nullptr;

    cv::Rect leftEye, rightEye;

    // Find the leftmost eye
    int x = eyes.at(0).x;

    for (auto eye : eyes) {
        if (eye.x > x) {
            x = (leftEye = eye).x;
        }
    }

    // Then, find the rightmost
    for (auto eye : eyes) {
        if (eye.x < x) {
            x = (rightEye = eye).x;
        }
    }

    cv::rectangle(mat, rightEye, cv::Scalar(255, 0, 0), 10);
    cv::rectangle(mat, leftEye, cv::Scalar(0, 255, 0), 10);

    //cv::imshow("w", mat);
    //cv::waitKey(1);

    //cv::destroyAllWindows();
    return nullptr;
}
