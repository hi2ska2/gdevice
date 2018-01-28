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

#include "Field.h"
#include "Id.h"

#include "utilities.h"

namespace ThingType {
  enum Type { LUMPED };
};

class Thing {
 public:
  Thing(const std::string& name,ThingType::Type type);
  
 protected:
  std::string _name;
  ThingType::Type _type;
  Field* _field;
  Id _thingId;
};

#include "Lumped.h"

#endif
