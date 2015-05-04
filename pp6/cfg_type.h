#ifndef _H_CFG_TYPE
#define _H_CFG_TYPE

#include <map>
#include <vector>
#include <list>
#include "tac.h"


typedef std::vector<Instruction*> EdgeType;  

// this class is a wrapper that represents the cfg. There is a mapping 
// for every (Stmt) node to all the nodes that can follow (or precede)
// in the control flow graph. 
class CFGType {

 private:

  static EdgeType emptyEdges;

  std::map<int, std::list<Instruction*> > codeBlocks;
  std::map<Instruction*, EdgeType> inEdges;
  std::map<Instruction*, EdgeType> OutEdges;
  Instruction* firstInstr;
  Instruction* lastInstr;

 protected:

  std::list<Instruction*>* instructions;
  int codeBlockNum;
  
 public:
  
  CFGType(std::list<Instruction*>* code);
  
  void  FirstInstruction(Instruction* first);
  Instruction* FirstInstruction();
  
  void  lastInstruction(Instruction* last);
  Instruction* lastInstruction();

  void ReverseCFG();

  EdgeType& GetInEdges(Instruction* stmt);

  EdgeType& GetOutEdges(Instruction* stmt);

  void AddInEdge(Instruction* from, Instruction* to);

  void AddOutEdge(Instruction* from, Instruction* to);

  void AddCodeBlock(std::list<Instruction*>);

  int NumCodeBlocks();

  void AddInEdge(int, std::list<int>);

  void AddOutEdge(int, std::list<int>);

  std::list<Instruction*> GetCodeBlockAt(int);
  
};

#endif
