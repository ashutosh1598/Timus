cmake_minimum_required(VERSION 3.7)
project(Timus)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        1009.cpp
        1012.cpp
        1013.cpp
        1017.cpp
        1029.cpp
        1073.cpp
        1100.cpp
        1119.cpp
        1126.cpp
        1146.cpp
        1152.cpp
        1167.cpp
        1203.cpp
        1225.cpp
        1260.cpp
        1280.cpp
        1290.cpp
        1296.cpp
        1297.cpp
        1306.cpp
        1353.cpp
        1494.cpp
        1613.cpp
        1654.cpp
        1671.cpp
        1837.cpp
        2018.cpp
        2072.cpp
        "Judge ID"
        template.cpp)

add_executable(Timus ${SOURCE_FILES})