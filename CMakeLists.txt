cmake_minimum_required (VERSION 2.6)
project (machine_learning)
find_package( OpenCV REQUIRED )
set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_CXX_FLAGS_RELEASE "-O3")
#set(CMAKE_CXX_FLAGS "-g -Wall -Wextra -Werror")
set(BIBLIOTECAS ${OpenCV_LIBS} tesseract)
file(GLOB ocr_simple_SRCS
        "${PROJECT_SOURCE_DIR}/tesseract/01-ocr_simple/*"
        )
file(GLOB threshold_simple_SRCS
        "${PROJECT_SOURCE_DIR}/opencv/01-threshold_simple/*"
        )
        
add_executable(ocr_simple ${ocr_simple_SRCS})
add_executable(threshold_simple ${threshold_simple_SRCS})

target_link_libraries(ocr_simple ${BIBLIOTECAS})
target_link_libraries(threshold_simple ${BIBLIOTECAS})
