#include <stdio.h>

#include <vector>

#include "df_framework.h"



//////////////////////////////////////////////////////////////////
//                   PRIVATE METHODS                            //
//////////////////////////////////////////////////////////////////


void DFFrameworkType::InitFramework(std::list<Instruction*>& todo) {
  // the todo list will include all the instructions in the cfg
  std::list<Instruction*>& instructions = controlFlowGraph->GetAllNodes();
  std::list<Instruction*>::iterator todo_it = instructions.begin();
  for (; todo_it != instructions.end(); ++todo_it) {
    controlFlowGraph->compute_gen_set((*todo_it));
    controlFlowGraph->compute_kill_set((*todo_it));
    controlFlowGraph->init_in_set((*todo_it));
    controlFlowGraph->init_out_set((*todo_it));
    todo.push_back((*todo_it));
  }

}


//////////////////////////////////////////////////////////////////
//                      CONSTRUCTORS                            //
//////////////////////////////////////////////////////////////////

DFFrameworkType::DFFrameworkType(CFGBaseType* controlFlowGraph, DF_DIRECTION_TYPE direction) {
  controlFlowGraph = controlFlowGraph;
  direction = direction;
}
    

//////////////////////////////////////////////////////////////////
//                    PUBLIC METHODS                            //
//////////////////////////////////////////////////////////////////



void DFFrameworkType::RunFramework() {
  // if backward we need to reverse the cfg
  if (direction == DF_BACKWARD) {
    controlFlowGraph->reverse_cfg();
  }

  std::list<Instruction*> todo;
  // next initialize the nodes
  InitFramework(todo);
  
  // start the iterative data flow. All the nodes
  // will be processed until a fixed point is reached 
  // (i.e. no change)  
  while (todo.size() > 0) {
    Instruction* node = todo.front();
    todo.pop_front();
    controlFlowGraph->status(node,DF_NOT_IN_TODO);
    // first apply the meet operator
    controlFlowGraph->apply_meet_operator(node);
    // next apply the transfer function
    bool changed = controlFlowGraph->apply_transfer_function(node);
    // if applying the transfer function changed the data sets
    // the out edges of this node need to be added to the todo
    // list since they might also change.
    if (changed) {
      std::vector<Instruction*>& next_nodes = controlFlowGraph->out_edges(node);
      for (int cnt=0; cnt < next_nodes.size(); ++cnt) {
	    Instruction* next_node = next_nodes[cnt];
	    // only need to add to todo list if not there already
	    if (controlFlowGraph->status(next_node) != DF_IN_TODO) {
	      controlFlowGraph->status(next_node,DF_IN_TODO);
	      todo.push_back(next_node);
	    }
      }
    }
  }
}

