//
// Created by Osip on 2020-02-26.
//

#include "TestRunner.h"

TestRunner::~TestRunner() {
    if (nFails > 0) {
        std::cerr << nFails << " tests failed. Terminating program!" << std::endl;

        exit(-1);
    }
}