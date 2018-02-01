/////////////////////////////////////////////////
// G-Device                                    //
//                                             //
// Copyright 2018 Sung-Min Hong                //
//                                             //
// Please see LICENSE for license information. //
/////////////////////////////////////////////////

// Lumped.cc

#include "Lumped.h"

#include "utilities.h"

Lumped::Lumped(const std::string& name)
  : Thing(name,ThingType::LUMPED),
    _type(LumpedType::U)
{
  _V = 0.0;
  _I = 0.0;
  _R = 0.0;
  _L = 0.0;
  _C = 0.0;

  std::cout << "\n";
  std::cout << "A Lumped object is created.\n";
  std::cout << "Its name is " << _name << ".\n";
  std::cout << "Its LumpedType::Type is " << _type << "\n";
  std::cout << "\n";
}
