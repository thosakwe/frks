//
// Created by Tobe on 3/28/18.
//

#ifndef FRKS_FACEMEASUREMENT_H
#define FRKS_FACEMEASUREMENT_H

/**
 * @brief An abstraction over measurements of different facial features.
 */
class FaceMeasurement {

public:
    FaceMeasurement(double pCenterX, double pLeftPupil, double pRightPupil, double pUpperLip, double pLowerLip,
                    double pMouthLeft, double pMouthRight);

    // Getters
    double get_center_x() const;

    double get_left_pupil() const;

    double get_right_pupil() const;

    double get_upper_lip() const;

    double get_lower_lip() const;

    double get_mouth_left() const;

    double get_mouth_right() const;

    // Computations
    double mouth_width() const;

    double mouth_height() const;


private:
    double mCenterX, mLeftPupil, mRightPupil, mUpperLip, mLowerLip, mMouthLeft, mMouthRight;
};

#endif //FRKS_FACEMEASUREMENT_H
