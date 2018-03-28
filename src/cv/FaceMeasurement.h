//
// Created by Tobe on 3/28/18.
//

#ifndef FRKS_FACEMEASUREMENT_H
#define FRKS_FACEMEASUREMENT_H

/**
 * @brief An abstraction over measurements of different facial features.
 */
class FaceMeasurement {
private:
    double center_x;
    double left_pupil_location, right_pupil_location;
    double upper_lip_location, lower_lip_location;
    double mouth_left, mouth_right;

public:
    FaceMeasurement(double center_x, double left_pupil, double right_pupil, double upper_lip, double lower_lip, double mouth_left,
                    double mouth_right);

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
};

#endif //FRKS_FACEMEASUREMENT_H
