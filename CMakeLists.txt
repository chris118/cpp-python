cmake_minimum_required (VERSION 2.8)

project (demo)

aux_source_directory(. PROJECT_SOURCE_DIR)

#$ CMake -DCMAKE_BUILD_TYPE=Debug .
#SET(CMAKE_CXX_FLAGS_DEBUG"$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
#SET(CMAKE_CXX_FLAGS_RELEASE"$ENV{CXXFLAGS} -O3 -Wall")

LINK_DIRECTORIES(
 /home/hhit/anaconda2/lib
  )

include_directories (
 /home/hhit/anaconda2/include/python2.7
)

add_executable(demo ${PROJECT_SOURCE_DIR})

target_link_libraries(demo
 libpython2.7.so
)
