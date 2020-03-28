//
// Created by Osip on 2020-03-18.
//

#ifndef PROFILE_H
#define PROFILE_H

#include <iostream>
#include <string>
#include <chrono>

class LogDuration {
public:
    explicit LogDuration(const std::string& message = "") :
    message_(message + ": ")
    , start_(std::chrono::steady_clock::now())
    {
    }

    ~LogDuration();


private:
    std::string message_;
    std::chrono::steady_clock::time_point start_;
};

#define UNIQ_ID_IMPL(lineno) _a_local_var_##lineno
#define UNIQ_ID(lineno) UNIQ_ID_IMPL(lineno)

#define LOG_DURATION(message) \
  LogDuration UNIQ_ID(__LINE__){message};

#endif //RED_PROFILE_H
