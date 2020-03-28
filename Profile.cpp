//
// Created by Osip on 2020-03-18.
//

#include "Profile.h"

using namespace std::chrono;
using namespace std;

LogDuration::~LogDuration() {
    auto finish = steady_clock::now();
    auto dur = finish - start_;
    cerr << message_
         << duration_cast<milliseconds>(dur).count()
         << " ms" << endl;
}