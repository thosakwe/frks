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

    // Find angle between eyes
    // Imagine this is a right triangle...
    // side a = l.x - r.x, b = l.y - r.y;
    // Angle = arctan(b/a)
    double angle = -atan2(leftEye.y - rightEye.y, leftEye.x - rightEye.x);

    // Next, rotate gray image by the angle to find the face.
    // get rotation matrix for rotating the image around its center
    cv::Point2f center(gray.cols / 2.0f, gray.rows / 2.0f);
    cv::Mat rot = cv::getRotationMatrix2D(center, angle, 1.0);

    // determine bounding rectangle
    cv::Rect bbox = cv::RotatedRect(center, gray.size(), (float) angle).boundingRect();

    // adjust transformation matrix
    rot.at<double>(0, 2) += bbox.width / 2.0 - center.x;
    rot.at<double>(1, 2) += bbox.height / 2.0 - center.y;

    cv::Mat dst;
    cv::warpAffine(gray, dst, rot, bbox.size());

    // Write back into gray
    dst.copyTo(gray);

    // Now that the gray image has been rotated, detect the face.
    std::vector<cv::Rect> faces;
    pFaceCascade->detectMultiScale(gray, faces, 1.3, 5);

    if (faces.empty())
        return nullptr;

    cv::Rect face = faces.at(0);
    cv::imshow("w", gray);
    cv::waitKey(1);

    //cv::destroyAllWindows();
    return new FaceMeasurement(
            (face.width + face.x) / 2, // centerX
            leftPupil,
            rightPupil,
            upperLip,
            lowerLip,
            mouthLeft,
            mouthRight
    );
}
