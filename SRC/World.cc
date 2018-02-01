/////////////////////////////////////////////////
// G-Device                                    //
//                                             //
// Copyright 2018 Sung-Min Hong                //
//                                             //
// Please see LICENSE for license information. //
/////////////////////////////////////////////////

// World.cc

#include "World.h"

World::World()
{
  _things.clear();
}

Thing* World::addThing(Thing* thing)
{
  _things.push_back(thing);
  _currentThing = thing;
  return _currentThing;
}

Thing* World::getCurrentThing() { return _currentThing; }

Thing* World::getThing(const std::string& thingName) { 
  for (int ii=0; ii<_things.size(); ii++) {
    Thing* selected = _things[ii];
    if (selected->getName() == thingName) {
      return selected;
    }
  }
  std::string message = "The thing " + thingName + " is not found.";
  myReportError(message);
}
