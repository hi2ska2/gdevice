////////////////////////////////////////////////
// G-Device                                   //
//                                            //
// Copyright 2018 Sung-Min Hong               //
//                                            //
// Please see LICENSE for license information //
////////////////////////////////////////////////

// utilities.cc

#include "utilities.h"

#include <cstdlib>
#include <iostream>

void myReport(const std::string& message) {
  std::cout << message << "\n";
  std::cout.flush();
}

void myReportError(const std::string& message) {
  std::cout << "Error: " << message << "\n";
  std::cout.flush();
  exit(1);
}
