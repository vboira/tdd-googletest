set(SAMPLE_LIB_2_SRCS
	../sample2.h
	sample_lib_2.hpp
	sample_lib_2.cpp
	)

add_library(SAMPLE_LIB_2 STATIC
	${SAMPLE_LIB_2_SRCS}
	)

target_link_libraries(SAMPLE_LIB_2
	)

target_include_directories(SAMPLE_LIB_2 PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}
	)

