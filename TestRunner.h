//
// Created by Osip on 2020-02-26.
//

#ifndef UNITTESTRUNNER_TESTRUNNER_H
#define UNITTESTRUNNER_TESTRUNNER_H

#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <map>

template <typename T>
std::ostream& operator<<(std::ostream& stream, const std::vector<T>& v) {
    bool isFirst = true;

    stream << "[";

    for (const auto& item : v) {
        if (!isFirst) {
            stream << ", ";
        }

        isFirst = false;
        stream << item;
    }

    return stream << "]";
}

template <typename T>
std::ostream& operator<<(std::ostream& stream, const std::set<T>& s) {
    bool isFirst = true;

    stream << "{";

    for (const auto& item : s) {
        if (!isFirst) {
            stream << ", ";
        }

        isFirst = false;
        stream << item;
    }

    return stream << "}";
}

template <typename K, typename V>
std::ostream& operator<<(std::ostream& stream, const std::map<K, V>& m) {
    bool isFirst = true;

    stream << "{";

    for (const auto& pair : m) {
        if (!isFirst) {
            stream << ", ";
        }

        isFirst = false;
        stream << "(" << pair.first << " ; ";
        stream << pair.second << ")";
    }

    return stream << "}";
}

template<class T, class U>
void AssertEqual(const T t, const U u, const std::string& hint = "") {
    if (t != u) {
        std::ostringstream os;
        os << "Assertion failed: " << t << " != " << u
           << ". Hint: " << hint;
        throw std::runtime_error(os.str());
    }
}

inline void Assert(bool b, const std::string& hint) {
    AssertEqual(b, true, hint);
}

class TestRunner {
public:
    template <typename TestFunction>
    void RunTest(TestFunction function, const std::string& testName) {
        try {
            function();

            std::cerr << "Test " << testName << " passed" << std::endl;
        } catch (const std::exception& e) {
            ++nFails;
            std::cerr << "Test " << testName << " failed" << std::endl;
        }
    }

    ~TestRunner();

private:
    int nFails = 0;

};



#endif //UNITTESTRUNNER_TESTRUNNER_H
