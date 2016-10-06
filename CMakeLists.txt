project("Cheap GMP")

list(APPEND CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS} -g -ftest-coverage -fprofile-arcs")

add_executable(cheapgmp 
    src/cheapgmp.cpp 
    src/accessories.cpp 
    src/main.cpp)

add_executable(gmpcmd
    src/cheapgmp.cpp
    src/accessories.cpp
    src/cmd.cpp)

