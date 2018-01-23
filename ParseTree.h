////////////////////////////////////////////////
// G-Device                                   //
//                                            //
// Copyright 2018 Sung-Min Hong               //
//                                            //
// Please see LICENSE for license information //
////////////////////////////////////////////////

// ParseTree.h

#ifndef ParseTreeH
#define ParseTreeH

#include <iostream>
#include <string>
#include "utilities.h"

class ParseTree {
 public:
 ParseTree(bool isArgList=false,bool isStmtList=false) : _isArgList(isArgList), _isStmtList(isStmtList) {}
  virtual void action (ParseTree* caller=NULL) {}
  //virtual void action1(ParseTree* caller=NULL) {}
  void checkArgList() { 
    if (!_isArgList) myReportError("An ArgList is required.");
  }
  void checkStmtList() { 
    if (!_isStmtList) myReportError("An StmtList is required.");
  }
  bool isArgList() { return _isArgList; }
  bool isStmtList() { return _isStmtList; }
  //virtual double getDval() { return 0; };

 protected:
  bool _isArgList, _isStmtList;
};

class Expr : public ParseTree {
 public:
 Expr(double c) : _isStr(false), _isArray(false), _dval(c) {}
 Expr(double c, double c1) : _isStr(false), _isArray(true), _dval(c), _dval1(c1) {}
 Expr(char* s) : _isStr(true), _isArray(false),  _str(s) {}
  bool isArray() { return _isArray; }
  bool isStr() { return _isStr; }
  std::vector<double> getAval() { 
    std::vector<double> aval;
    aval.resize(2);
    aval[0] = _dval;
    aval[1] = _dval1;    
    return aval;
  }
  double getDval() { return _dval; }
  int getIval() { return int(_dval); }
  //std::string getSval() { return _str.c_str(); }
  std::string getSval() { return _str; }
  
 protected:
  bool _isStr;
  bool _isArray;
  double _dval;
  double _dval1;
  std::string _str;  
};

class Arg : public ParseTree {
 public:
 Arg(const char* s, ParseTree* c) : _name(s), _contents((Expr*)c) {}
  const std::string getName() { return _name; }
  int getValue(const int& i) { return _contents->getIval(); } 
  double getValue(const double& i) { return _contents->getDval(); } 
  std::vector<double> getValue(const std::vector<double>& i) { return _contents->getAval(); }
  std::string getValue(const std::string& i) { return _contents->getSval(); } 

  void show() {
    if (_contents->isStr()) std::cout << _name << " = " << _contents->getSval() << "\n";
    else std::cout << _name << " = " << _contents->getDval() << "\n";
  }

 protected:
  std::string _name;
  Expr* _contents;
};

class ArgList : public ParseTree {
 public:
 ArgList(ParseTree* al, ParseTree* a) 
   : ParseTree(true,false), _argList((ArgList*)al), _arg((Arg*)a), _argSize(0)
    { 
      if (_argList) _argSize = _argList->getArgSize();
      if (_arg) _argSize++;
    } 

  bool doesExist(const std::string& keyword) 
  {  
    bool returnValue(false);
    if (_argList) returnValue = _argList->doesExist(keyword);
    if (_arg) {
      if (_arg->getName() == keyword) returnValue = true; 
    }
    return returnValue;
  }
  Arg* getArg(int ii,std::string& argName) { 
    if (_argSize==(ii+1)) {
      argName = _arg->getName();
      return _arg;
    } else return _argList->getArg(ii,argName);
  }
  template<class T>
    Arg* getArg(int ii,std::string& argName,T& argValue) { 
    if (_argSize==(ii+1)) {
      argName = _arg->getName();
      T dummy;
      argValue = _arg->getValue(dummy);
      return _arg;
    } else return _argList->getArg(ii,argName,argValue);
  }
  int getArgSize() { return _argSize; }
  template<class T>
    T lookup(const std::string& keyword,const T defaultValue) {    
    T returnValue(defaultValue);
    if (_argList) returnValue = _argList->lookup(keyword,defaultValue);
    if (_arg) {
      if (_arg->getName() == keyword) returnValue = _arg->getValue(defaultValue); 
    }
    return returnValue;
  }
  
  void show() {
    if (_argList) _argList->show();
    if (_arg) _arg->show();
    std::cout << "_argSize = " << _argSize << "\n";
  }
  
 protected:
  ArgList* _argList;
  Arg* _arg;
  int _argSize;
};

class Stmt : public ParseTree {
 public:
 Stmt(const char* s, ParseTree* spec, ParseTree* body_sl, ParseTree* body_al) 
   : _name(s), _spec(spec), _body_sl(body_sl), _body_al(body_al) 
  { 
    if (_spec   ) _spec   ->checkArgList();
    if (_body_sl) _body_sl->checkStmtList();
    if (_body_al) _body_al->checkArgList(); 
  }

  void action (ParseTree* caller=NULL);
  //void action1(ParseTree* caller=NULL);
  void bodyAction(int i=0) {
    if (_body_sl) {
      if (i==0) _body_sl->action (this);
      //if (i==1) _body_sl->action1(this);
    }
  } 
  bool bodyDoesExist(const std::string& keyword) {
    return ((ArgList*)_body_al)->doesExist(keyword);
  }
  template<class T> 
    T bodyLookup(const std::string& keyword,const T defaultValue) {
    return ((ArgList*)_body_al)->lookup(keyword,defaultValue);
  }
  std::string getName() { return _name; }

  bool specDoesExist(const std::string& keyword) {
    return ((ArgList*)_spec)->doesExist(keyword);
  }

  template<class T> 
    T specLookup(const std::string& keyword,const T defaultValue) {
    return ((ArgList*)_spec)->lookup(keyword,defaultValue);
  }

 protected:
  std::string _name;
  ParseTree* _spec;
  ParseTree* _body_sl;
  ParseTree* _body_al;

  bool hasBodyArgList();
};

class StmtList : public ParseTree {
 public:
 StmtList(ParseTree* sl, ParseTree* s) : ParseTree(false,true), _stmtList(sl), _stmt(s) { }
  
  void action (ParseTree* caller=NULL);
  //void action1(ParseTree* caller=NULL);

 protected:
  ParseTree* _stmtList;
  ParseTree* _stmt;
};

class Program : public ParseTree {
 public:
 Program(ParseTree* sl) : _name("program"), _stmtList(sl) { }

  void action (ParseTree* caller);
  //void action1(ParseTree* caller);
   
 protected:
  std::string _name;
  ParseTree* _stmtList;
};

extern ParseTree* parse_tree;

#endif
