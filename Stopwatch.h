////////////////////////////////////////////////
// G-Device                                   //
//                                            //
// Copyright 2018 Sung-Min Hong               //
//                                            //
// Please see LICENSE for license information //
////////////////////////////////////////////////

// Stopwatch.h

#ifndef StopwatchH
#define StopwatchH

#include <ctime>

class Stopwatch {
 public:
  Stopwatch();
  ~Stopwatch();

  void accumulate();
  double getAccumulatedTimeInSec()
  {
    return _accumulatedTimeInSec;
  }
  void lap() {
    stop();
    accumulate();
    reset();
  }
  void start() {
    _started = true;
    time(&_startTime);
  }
  void stop() {
    _stopped = true;
    time(&_endTime);
  }
  double elapse();
  void reset() { _started = false; _stopped = false; }
  
 private:
  bool _started, _stopped;
  time_t _startTime, _endTime;
  double _accumulatedTimeInSec;  
};

#endif
