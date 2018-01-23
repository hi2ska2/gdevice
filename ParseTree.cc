////////////////////////////////////////////////
// G-Device                                   //
//                                            //
// Copyright 2018 Sung-Min Hong               //
//                                            //
// Please see LICENSE for license information //
////////////////////////////////////////////////

// ParseTree.cc

#include "ParseTree.h"

ParseTree* parse_tree;

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
    bodyAction();
  } else {
    bodyAction();
  }
}

