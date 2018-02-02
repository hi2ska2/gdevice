;/////////////////////////////////////////////////
// G-Device                                    //
//                                             //
// Copyright 2018 Sung-Min Hong                //
//                                             //
// Please see LICENSE for license information. //
/////////////////////////////////////////////////

// Thing.h

#ifndef ThingH
#define ThingH

#include "ParseTree.h"
#include "Field.h"
#include "Id.h"

#include "utilities.h"

namespace ThingType {
  enum Type { CIRCUIT, LUMPED };
};

class Thing {
 public:
  Thing(const std::string& name,ThingType::Type type);

  std::string getName();
  
 protected:
  std::string _name;
  ThingType::Type _type;
  Field* _field;
  Id _thingId;
};

#include "Circuit.h"
#include "Lumped.h"

#endif
