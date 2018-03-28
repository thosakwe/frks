//
// Created by Tobe on 3/28/18.
//
#include "FaceMeasurement.h"

FaceMeasurement::FaceMeasurement(double pCenterX, double pLeftPupil, double pRightPupil, double pUpperLip,
                                 double pLowerLip, double pMouthLeft, double pMouthRight) {
    this->mCenterX = pCenterX;
    this->mLeftPupil = pLeftPupil;
    this->mRightPupil = pRightPupil;
    this->mUpperLip = pUpperLip;
    this->mLowerLip = pLowerLip;
    this->mMouthLeft = pMouthLeft;
    this->mMouthRight = pMouthRight;
}

double FaceMeasurement::get_center_x() const {
    return mCenterX;
}

double FaceMeasurement::get_left_pupil() const {
    return mLeftPupil;
}

double FaceMeasurement::get_right_pupil() const {
    return mRightPupil;
}

double FaceMeasurement::get_upper_lip() const {
    return mUpperLip;
}

double FaceMeasurement::get_lower_lip() const {
    return mLowerLip;
}

double FaceMeasurement::get_mouth_left() const {
    return mMouthLeft;
}

double FaceMeasurement::get_mouth_right() const {
    return mMouthRight;
}

double FaceMeasurement::mouth_width() const {
    return  mMouthRight - mMouthLeft;
}


double FaceMeasurement::mouth_height() const {
    return mLowerLip - mUpperLip;
}
