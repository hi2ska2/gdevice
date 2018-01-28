/////////////////////////////////////////////////
// G-Device                                    //
//                                             //
// Copyright 2018 Sung-Min Hong                //
//                                             //
// Please see LICENSE for license information. //
/////////////////////////////////////////////////

// Thing.cc

#include "Thing.h"

#include "utilities.h"

Thing::Thing(const std::string& name,
	     ThingType::Type type)
  : _name(name),
    _type(type)
{
  std::cout << "\n";
  std::cout << "A Thing object is created.\n";
  std::cout << "Its name is " << _name << ".\n";
  std::cout << "Its ThingType::type is " << _type << ".\n";
  std::cout << "\n";
}
