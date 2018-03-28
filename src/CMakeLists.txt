cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(face)

add_executable(frks main.cpp)

target_link_libraries(frks face)

macro("copy_cascade" name)
    file(
            COPY "${CMAKE_CURRENT_SOURCE_DIR}/cascades/haarcascade_${name}.xml"
            DESTINATION "${CMAKE_BINARY_DIR}/src"
    )
endmacro()

copy_cascade(eye)
copy_cascade(eye_tree_eyeglasses)
copy_cascade(frontalface_default)