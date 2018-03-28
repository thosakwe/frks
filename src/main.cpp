#include <iostream>
#include "face/VideoCaptureStream.h"

int main() {
    auto * stream = new VideoCaptureStream();

    while (!stream->is_done()) {
        stream->next();
    }

    return 0;
}