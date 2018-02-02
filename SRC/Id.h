/////////////////////////////////////////////////
// G-Device                                    //
//                                             //
// Copyright 2018 Sung-Min Hong                //
//                                             //
// Please see LICENSE for license information. //
/////////////////////////////////////////////////

// Id.h

#ifndef IdH
#define IdH

class Id {
 public:
  Id(int id=-1) : _id(id) { }
 private:
  int _id;
};

class ThingId : public Id {
 public:
 ThingId(int id=-1) : Id(id) { }
};

#endif
