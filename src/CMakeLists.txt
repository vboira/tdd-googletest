#VB Afegeixo aquest directori, aixi des de sample no cal fer include "../sample1.h" include "../sample2.h"
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
add_subdirectory(sample_lib_1)
add_subdirectory(sample_lib_2)
add_executable (sample1 sample1.cpp)
add_executable (sample2 sample2.cpp)
target_link_libraries (sample1 SAMPLE_LIB_1)
target_link_libraries (sample2 SAMPLE_LIB_2)
