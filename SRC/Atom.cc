/////////////////////////////////////////////////
// G-Device                                    //
//                                             //
// Copyright 2018 Sung-Min Hong                //
//                                             //
// Please see LICENSE for license information. //
/////////////////////////////////////////////////

// Atom.cc

#include "Atom.h"

#include "utilities.h"

Atom::Atom(const std::string& name)
        : Thing(name,ThingType::LUMPED)
{
    // Nothing to do
}