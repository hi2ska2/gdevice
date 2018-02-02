/////////////////////////////////////////////////
// G-Device                                    //
//                                             //
// Copyright 2018 Sung-Min Hong                //
//                                             //
// Please see LICENSE for license information. //
/////////////////////////////////////////////////

// Circuit.h

#ifndef CircuitH
#define CircuitH

#include "Thing.h"

#include <map>

// Currently, CircuitNode and CircuitContact are using std::string to identify quantities.
// It must be improved later.

class CircuitNode {
 public:
  CircuitNode() 
    : _isGND(false) {
    _things.clear();
    _contactNames.clear();
  }
  void addContact(Thing* thing,std::string contactName) 
  {
    _things.push_back(thing);
    _contactNames.push_back(contactName);
  }
  std::string getContactName(int ii) { return _contactNames[ii]; }
  int getSize() { return _things.size(); }
  Thing* getThing(int ii) { return _things[ii]; }
  bool isGND() { return _isGND; }
  void setGND() { _isGND = true; }
 private:
  bool _isGND;
  std::vector<Thing*> _things;
  std::vector<std::string> _contactNames;
};

class CircuitContact {
 public:
  CircuitContact() {
    _contactNames.clear();
    _nodeNames.clear();
  }
  void addNode(std::string contactName,std::string nodeName) {
    _contactNames.push_back(contactName);
    _nodeNames.push_back(nodeName);
  }
  std::string search(std::string contactName) {
    for (int ii=0; ii<_contactNames.size(); ++ii) {
      if (contactName.compare(_contactNames[ii])==0) return _nodeNames[ii];
    }
    myReportError("CircuitContact::search(contactName)");
  }
 private:
  std::vector<std::string> _contactNames;
  std::vector<std::string> _nodeNames;  
};

class Circuit : public Thing {
 public:
  Circuit(const std::string& name);

  //int get_nNode() { return _nodes.size(); }  
  //virtual Mesh* getMesh() { myReportError("Circuit::getMesh()"); }
  //int getNodeIndex(std::string nodeName);
  //int getNodeIndex(ThingId thingId,std::string contactName);
  //std::map<std::string,CircuitNode*> getNodes() { return _nodes; }
  //virtual bool hasMesh() { return false; }
  //bool isGND(std::string nodeName);
  //bool isGND(ThingId thingId,std::string contactName);
  //virtual bool isInitialized() { return (_nodes.size()>0); }
  //void node(const std::string& nodeName);
  //void node(const std::string& nodeName,Thing* thing,const std::string& contactName);
  //virtual void record(const std::string& fileName) { }
  //virtual void set(ArgList* argList);

 private:
  std::map<std::string,CircuitNode*> _nodes; // From Circuit to Thing
  std::map<ThingId,CircuitContact*> _contacts; // From Thing to Circuit
};
  

#endif
