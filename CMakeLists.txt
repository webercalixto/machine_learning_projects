cmake_minimum_required (VERSION 2.6)
project (machine_learning)
set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_CXX_FLAGS_RELEASE "-O3")
set(CMAKE_CXX_FLAGS "-g -Wall -Wextra -Werror")
file(GLOB ocr_simple_SRCS
        "${PROJECT_SOURCE_DIR}/tesseract/01-ocr_simple/*"
        )

find_package( OpenCV REQUIRED )
        
add_executable(ocr_simple ${ocr_simple_SRCS})

target_link_libraries(ocr_simple ${OpenCV_LIBS} tesseract )
