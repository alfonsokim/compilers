#include "cfg_type.h"

EdgeType CFGType::emptyEdges;

CFGType::CFGType(std::list<Instruction*>* code) {
    instructions = code;
    firstInstr = 0;
    lastInstr = 0;
    codeBlockNum = 0;
}
  
void CFGType::FirstInstruction(Instruction* instruction) {
  firstInstr = instruction;
}

Instruction* CFGType::FirstInstruction() {
  return firstInstr;
}

void CFGType::lastInstruction(Instruction* instruction) {
  lastInstr = instruction;
}

Instruction* CFGType::lastInstruction() {
  return lastInstr;
}


void CFGType::ReverseCFG() {
  // This method needs to be implemented. Reversing means that the cfg
  // should go from the end of the program to the beginning. Simply put
  // all the edges need to be flipped. Reversing the cfg is usefull when
  // you want to solve a backward dataflow analysis problem
  return;
}

EdgeType& CFGType::GetInEdges(Instruction* instruction) {
  // first check if this node is actually has any in_edges
  EdgeType& inNodes = emptyEdges;
  if (inEdges.find(instruction) != inEdges.end()) {
    inNodes = (*inEdges.find(instruction)).second;
  }
  return inNodes;
}


EdgeType& CFGType::GetOutEdges(Instruction* instruction) {
  // first check if this node is actually has any in_edges
  EdgeType& outNodes = emptyEdges;
  if (OutEdges.find(instruction) != OutEdges.end()) {
    outNodes = (*OutEdges.find(instruction)).second;
  }
  return outNodes;
}

void CFGType::AddInEdge(Instruction* from, Instruction* to) {
  inEdges[to].push_back(from);
}

void CFGType::AddOutEdge(Instruction* from, Instruction* to) {
  OutEdges[from].push_back(to);
}

void CFGType::AddCodeBlock(std::list<Instruction*> codeBlock){
    PrintDebug("optim", "Agregando bloque (%i: %i)", codeBlockNum, codeBlock.size());
    codeBlocks.insert(std::pair<int, std::list<Instruction*> >(codeBlockNum++, codeBlock));
}
