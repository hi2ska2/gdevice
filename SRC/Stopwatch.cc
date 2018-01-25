////////////////////////////////////////////////
// G-Device                                   //
//                                            //
// Copyright 2018 Sung-Min Hong               //
//                                            //
// Please see LICENSE for license information //
////////////////////////////////////////////////

// Stopwatch.cc

#include "Stopwatch.h"

#include "utilities.h"

Stopwatch::Stopwatch()
  : _started(false),
    _stopped(false),
    _accumulatedTimeInSec(0.0)
{
  //std::cout << "Stopwatch::Stopwatch()\n";
}

Stopwatch::~Stopwatch()
{
  //std::cout << "Stopwatch::~Stopwatch()\n";
}

void Stopwatch::accumulate()
{
  if (_started && _stopped)  _accumulatedTimeInSec += difftime(_endTime,_startTime);    
  else myReportError("Stopwatch::accumulate()");
}

double Stopwatch::elapse()
{
  if (_started && _stopped) return difftime(_endTime,_startTime);    
  else myReportError("Stopwatch::elapse()");
}
