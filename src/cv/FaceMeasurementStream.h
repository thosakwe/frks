//
// Created by Tobe on 3/28/18.
//

#ifndef FRKS_FACEMEASUREMENTSTREAM_H
#define FRKS_FACEMEASUREMENTSTREAM_H

#include "FaceMeasurement.h"

/**
 * @brief A continuous stream of face data.
 */
class FaceMeasurementStream {
public:
    virtual bool is_done() = 0;

    virtual FaceMeasurement *next() = 0;
};


#endif //FRKS_FACEMEASUREMENTSTREAM_H
