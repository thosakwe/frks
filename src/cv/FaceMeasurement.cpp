//
// Created by Tobe on 3/28/18.
//
#include "FaceMeasurement.h"

FaceMeasurement::FaceMeasurement(double center_x, double left_pupil, double right_pupil, double upper_lip,
                                 double lower_lip, double mouth_left, double mouth_right) {
    this->center_x = center_x;
    this->left_pupil_location = left_pupil;
    this->right_pupil_location = right_pupil;
    this->upper_lip_location = upper_lip;
    this->lower_lip_location = lower_lip;
    this->mouth_left = mouth_left;
    this->mouth_right = mouth_right;
}

double FaceMeasurement::get_center_x() const {
    return center_x;
}

double FaceMeasurement::get_left_pupil() const {
    return left_pupil_location;
}

double FaceMeasurement::get_right_pupil() const {
    return right_pupil_location;
}

double FaceMeasurement::get_upper_lip() const {
    return upper_lip_location;
}

double FaceMeasurement::get_lower_lip() const {
    return lower_lip_location;
}

double FaceMeasurement::get_mouth_left() const {
    return mouth_left;
}

double FaceMeasurement::get_mouth_right() const {
    return mouth_right;
}

double FaceMeasurement::mouth_width() const {
    return  mouth_right - mouth_left;
}


double FaceMeasurement::mouth_height() const {
    return lower_lip_location - upper_lip_location;
}
