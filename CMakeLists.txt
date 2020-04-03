cmake_minimum_required(VERSION 3.14)
project(VectorHoriVert)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1z -fopenmp")

add_executable(VectorHoriVert
        main.cpp
        Vector.h
        VectorHori.h
        VectorVert.h
        VectorFactory.h 
        Rational.cpp Rational.h 
        UnitTests.cpp UnitTests.h 
        TestRunner.cpp TestRunner.h)
