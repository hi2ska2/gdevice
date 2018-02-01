////////////////////////////////////////////////
// G-Device                                   //
//                                            //
// Copyright 2018 Sung-Min Hong               //
//                                            //
// Please see LICENSE for license information //
////////////////////////////////////////////////

// ParseTree.cc

#include "ParseTree.h"

#include "World.h"

ParseTree* parse_tree;
World* theWorld = new World();

void Program::action(ParseTree* caller) {
  myReport("Program starts.");
  
  if (_stmtList) _stmtList->action(this);

  //
  //theHistory->epilogue();

  myReport("Program ends.");
}

void StmtList::action(ParseTree* caller) {  
  if (_stmtList) _stmtList->action(caller);
  if (_stmt)     _stmt->action(caller);
}

void Stmt::action(ParseTree* caller) {
  std::string callerName;
  if (caller) {
    callerName = static_cast<Stmt*>(caller)->getName();
    myReport(_name + " was called by " + callerName + ".");
  } else myReport(_name + " was called.");

  if (_name.compare("thing")==0) {
    std::string thingType = specLookup("type",std::string("device"));
    std::string thingName = specLookup("name",std::string("device"));
    Thing* selected = NULL;
    if      (thingType=="circuit") selected = theWorld->addThing( new Circuit(thingName) );
    else if (thingType=="lumped" ) selected = theWorld->addThing( new Lumped (thingName) );
    else myReportError(thingType + " is not a known thing type.");
    
    bodyAction();    
  }

  ////////////////////
  // thing->circuit //
  ////////////////////

  else if (_name=="circuit" && callerName=="thing") {
    Circuit* circuit = static_cast<Circuit*>(theWorld->getCurrentThing());
    //circuit->set((ArgList*)_spec);    
    
    bodyAction();
  }
  else if (_name=="node" && callerName=="circuit") { 
    Circuit* circuit = static_cast<Circuit*>(theWorld->getCurrentThing());
    std::string nodeName = specLookup("name",std::string("noname"));
    std::string thingName = specLookup("thing",std::string("noname"));
       
    if (thingName.compare("gnd")==0) {
      //circuit->node(nodeName);
    } else {
      std::string contactName = specLookup("contact",std::string("noname"));
      Thing* thing(theWorld->getThing(thingName));
      //circuit->node(nodeName,thing,contactName);
      std::cout << "Contact " << contactName << " of Thing " << thingName
		<< " is connected to Node " << nodeName << ".\n";
    }    
  }  

  ///////////////////
  // thing->lumped //
  ///////////////////
  
  else if (_name=="lumped" && callerName=="thing") {
    Lumped* lumped = static_cast<Lumped*>(theWorld->getCurrentThing());
    //lumped->set((ArgList*)_spec);
  }  

  else {
    std::string message = 
      _name + std::string(" is not a valid Stmt name.");
    myReportError(message);
  }
}

