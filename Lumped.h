////////////////////////////////////////////////
// G-Device                                   //
//                                            //
// Copyright 2018 Sung-Min Hong               //
//                                            //
// Please see LICENSE for license information //
////////////////////////////////////////////////

// Lumped.h

#ifndef LumpedH
#define LumpedH

#include "Thing.h"

namespace LumpedType {
  enum Type { U, V, I, R, L, C };
};

class Lumped : public Thing {
 public:
  Lumped(const std::string& name);

 private:
  LumpedType::Type _type;
  // To be inserted...
  double _V;
  double _I;
  double _R;
  double _L;
  double _C;  
};
  

#endif
