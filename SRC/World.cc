////////////////////////////////////////////////
// G-Device                                   //
//                                            //
// Copyright 2018 Sung-Min Hong               //
//                                            //
// Please see LICENSE for license information //
////////////////////////////////////////////////

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
