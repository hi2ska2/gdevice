/////////////////////////////////////////////////
// G-Device                                    //
//                                             //
// Copyright 2018 Sung-Min Hong                //
//                                             //
// Please see LICENSE for license information. //
/////////////////////////////////////////////////

// World.h

#ifndef WorldH
#define WorldH

#include <vector>

#include "Thing.h"

class World {
 public:
  World();

  Thing* addThing(Thing* thing);
  Thing* getCurrentThing();
  Thing* getThing(const std::string& thingName);

 private:
  std::vector<Thing*> _things;
  Thing* _currentThing;
};

#endif
