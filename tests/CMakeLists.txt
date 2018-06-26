find_package(Threads REQUIRED)

include(ExternalProject)

ExternalProject_Add(
	gtest
	URL https://github.com/google/googletest/archive/master.zip
	PREFIX ${CMAKE_CURRENT_BINARY_DIR}/gtest
	INSTALL_COMMAND ""
	)

ExternalProject_Get_Property(gtest source_dir binary_dir)

add_library(libgtest IMPORTED STATIC GLOBAL)
add_library(libgtest_main IMPORTED STATIC GLOBAL)
add_dependencies(libgtest libgtest_main gtest)

set_target_properties(libgtest PROPERTIES
	"IMPORTED_LOCATION" "${binary_dir}/googlemock/gtest/libgtest.a"
	"IMPORTED_LINK_INTERFACE_LIBRARIES" "${CMAKE_THREAD_LIBS_INIT}"
	)

set_target_properties(libgtest_main PROPERTIES
	"IMPORTED_LOCATION" "${binary_dir}/googlemock/gtest/libgtest_main.a"
	"IMPORTED_LINK_INTERFACE_LIBRARIES" "${CMAKE_THREAD_LIBS_INIT}"
	)

add_library(libgmock IMPORTED STATIC GLOBAL)
add_dependencies(libgmock gtest)

set_target_properties(libgmock PROPERTIES
	"IMPORTED_LOCATION" "${binary_dir}/googlemock/libgmock.a"
	"IMPORTED_LINK_INTERFACE_LIBRARIES" "${CMAKE_THREAD_LIBS_INIT}"
	)

include_directories("${source_dir}/googletest/include"
	"${source_dir}/googlemock/include")

#VB Afegeixo aquest directori, aixi des del test de sample no cal fer include "../../src/sample1.h" include "../../src/sample2.h"
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../src)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../src/Soundex)

# Per poder tenir els mateixos noms de tests i programes de tests, quan estan en diferents directoris!!!. Encara que estiguin en diferents directoris, sense la seguent linia no seria possible!.
#set(ALLOW_DUPLICATE_CUSTOM_TARGETS TRUE)

add_subdirectory(testSampleLib1)
add_subdirectory(testSampleLib2)

set(ALLOW_DUPLICATE_CUSTOM_TARGETS TRUE)

add_executable(1/SoundexTest 1/SoundexTest.cpp)
TARGET_LINK_LIBRARIES(
	1/SoundexTest	
	libgtest
	libgmock
	libgtest_main
	)

add_test(NAME 1/SoundexTest 
	COMMAND 1/SoundexTest)

add_executable(3/SoundexTest 3/SoundexTest.cpp)
TARGET_LINK_LIBRARIES(
	3/SoundexTest	
	libgtest
	libgmock
	libgtest_main
	)

add_test(NAME 3/SoundexTest 
	COMMAND 3/SoundexTest)

add_executable(5/SoundexTest 5/SoundexTest.cpp)
TARGET_LINK_LIBRARIES(
	5/SoundexTest	
	libgtest
	libgmock
	libgtest_main
	)

add_test(NAME 5/SoundexTest 
	COMMAND 5/SoundexTest)

#Si faig add_subdirectory amb un CMakeLists.txt interior amb:
####add_executable(SoundexTest SoundexTest.cpp)
#### +++
#### +++    TARGET_LINK_LIBRARIES(
#### +++    	SoundexTest	
#### +++    	libgtest
#### +++    	libgmock
#### +++    	libgtest_main
#### +++    	)
#### +++    add_test(NAME SoundexTest 
#### +++    	COMMAND SoundexTest)
#### +++
#aleshores, em diu que Soundex ja existeix,... 

add_subdirectory(1)
add_subdirectory(3)
add_subdirectory(5)

