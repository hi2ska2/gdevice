////////////////////////////////////////////////
// G-Device                                   //
//                                            //
// Copyright 2018 Sung-Min Hong               //
//                                            //
// Please see LICENSE for license information //
////////////////////////////////////////////////

// Thing.h

#ifndef ThingH
#define ThingH

#include "utilities.h"

class Thing {
  public:
  Thing(const std::string& name);

  protected:
  std::string _name;
};

#include "Lumped.h"

#endif
