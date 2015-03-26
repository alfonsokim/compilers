#include "cfg_type.h"

edge_type cfg_type::empty_edges;

cfg_type::cfg_type(std::list<Instruction*>* code) {
  _instructions = code;
  _first_instruction = 0;
  _last_instruction = 0;
}
  
void cfg_type::first_instruction(Instruction* instruction) {
  _first_instruction = instruction;
}

Instruction* cfg_type::first_instruction() {
  return _first_instruction;
}

void cfg_type::last_instruction(Instruction* instruction) {
  _last_instruction = instruction;
}

Instruction* cfg_type::last_instruction() {
  return _last_instruction;
}


void cfg_type::reverse_cfg() {
  // This method needs to be implemented. Reversing means that the cfg
  // should go from the end of the program to the beginning. Simply put
  // all the edges need to be flipped. Reversing the cfg is usefull when
  // you want to solve a backward dataflow analysis problem
  return;
}

edge_type& cfg_type::in_edges(Instruction* instruction) {
  // first check if this node is actually has any in_edges
  edge_type& in_nodes = empty_edges;
  if (_in_edges.find(instruction) != _in_edges.end()) {
    in_nodes = (*_in_edges.find(instruction)).second;
  }
  return in_nodes;
}


edge_type& cfg_type::out_edges(Instruction* instruction) {
  // first check if this node is actually has any in_edges
  edge_type& out_nodes = empty_edges;
  if (_out_edges.find(instruction) != _out_edges.end()) {
    out_nodes = (*_out_edges.find(instruction)).second;
  }
  return out_nodes;
}

void cfg_type::add_in_edge(Instruction* from, Instruction* to) {
  _in_edges[to].push_back(from);
}

void cfg_type::add_out_edge(Instruction* from, Instruction* to) {
  _out_edges[from].push_back(to);
}
