////////////////////////////////////////////////
// G-Device                                   //
//                                            //
// Copyright 2018 Sung-Min Hong               //
//                                            //
// Please see LICENSE for license information //
////////////////////////////////////////////////

// Thing.cc

#include "Thing.h"

#include "utilities.h"

Thing::Thing(const std::string& name)
  : _name(name)
{
  std::cout << "\n";
  std::cout << "A Thing object is created.\n";
  std::cout << "Its name is " << _name << ".\n";
  std::cout << "\n";
}
