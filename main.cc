////////////////////////////////////////////////
// G-Device                                   //
//                                            //
// Copyright 2018 Sung-Min Hong               //
//                                            //
// Please see LICENSE for license information //
////////////////////////////////////////////////

// main.cc

#include <fstream>
#include <iostream>
#include <ctime>

#include "Stopwatch.h"
Stopwatch overallTime;
Stopwatch jacobianTime;
Stopwatch solveTime;

#include "World.h"

int main(int argc, char* argv[])
{
  std::cout << "***********************************************\n";
  std::cout << "***                G-Device                 ***\n";
  std::cout << "***                                         ***\n";   
  std::cout << "***      Copyright 2018 Sung-Min Hong       ***\n";
  std::cout << "*** https://sites.google.com/view/gist-sdsl ***\n";
  std::cout << "***********************************************\n";

  time_t startRawTime, endRawTime;
  struct tm* timeinfo;
  char buffer[80];

  time(&startRawTime);
  timeinfo = localtime(&startRawTime);
  strftime(buffer,80,"%Y-%m-%d %H:%M:%S",timeinfo);
  std::string str_start(buffer); 
  std::cout << "Started at " << str_start << "\n";

  overallTime.start();

  // Something to do

  // As a test, create a Lumped object.
  Lumped* lumped = new Lumped("Resistor");

  // Finished

  overallTime.stop();

  time(&endRawTime);
  timeinfo = localtime(&endRawTime);
  strftime(buffer,80,"%Y-%m-%d %H:%M:%S",timeinfo);
  std::string str_end(buffer);
  
  std::cout << "Ended at " << str_end << "\n";
  std::cout << "Elapsed time: " << difftime(endRawTime,startRawTime) << " [sec].\n";

  std::cout << "***********************************************\n";
  std::cout << "Stopwatch results\n";
  std::cout << "Overall time: " << overallTime.elapse() << " [sec]\n";
  std::cout << "Jacobian time: " << jacobianTime.getAccumulatedTimeInSec() << " [sec]\n";
  std::cout << "Matrix solver time: " << solveTime.getAccumulatedTimeInSec() << " [sec]\n";
  std::cout << "***********************************************\n";
  
  return 0;
}
