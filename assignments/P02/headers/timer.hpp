///////////////////////////////////////////////////////////////////////////////
//
// Author:           Terry Griffin
// Email:            terry.griffin@msutexas.edu
// Title:            Timer Class
// Semester:         Spring 2020
// Date:             3 Feb 2020
//
// Description:
//       This is a simple class that wraps the "chrono" data type and allows a user
//       to time code snippets at the granularity of seconds or milliseconds.
//
// Usage:
//      #include "timer.hpp"
//
//
//      Timer T;
//      T.start();
//
//      // do stuff to be timed here
//
//      T.end();
//
//      double s = T.Seconds();
//      long m = T.MilliSeconds();
//
//      cout <<s << " seconds" <<endl;
//      cout <<m << " milli" <<endl;
//
/////////////////////////////////////////////////////////////////////////////////
#include <chrono>
#include <thread>
#include <time.h>

using namespace std;

class Timer {
private:
    std::chrono::time_point<std::chrono::steady_clock> _start;
    std::chrono::time_point<std::chrono::steady_clock> _end;

public:
    Timer() {
    }

    void start() {
        _start = chrono::steady_clock::now();
    }

    void end() {
        _end = chrono::steady_clock::now();
    }

    int NanoSeconds() {
        return chrono::duration_cast<chrono::nanoseconds>(_end - _start).count();
    }

    int Seconds() {
        return chrono::duration_cast<chrono::seconds>(_end - _start).count();
    }

    int MilliSeconds() {
        return chrono::duration_cast<chrono::milliseconds>(_end - _start).count();
    }
};
