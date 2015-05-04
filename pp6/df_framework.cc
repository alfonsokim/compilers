#include <stdio.h>

#include <vector>

#include "df_framework.h"



//////////////////////////////////////////////////////////////////
//                   PRIVATE METHODS                            //
//////////////////////////////////////////////////////////////////


void DFFrameworkType::InitFramework(std::list<Instruction*>& todo) {
    // the todo list will include all the instructions in the cfg
    std::list<Instruction*>& instructions = controlFlowGraph->GetAllNodes();
    std::list<Instruction*>::iterator todoIterator = instructions.begin();
    for (; todoIterator != instructions.end(); ++todoIterator) {
        controlFlowGraph->ComputeGenSet((*todoIterator));
        controlFlowGraph->ComputeKillSet((*todoIterator));
        controlFlowGraph->InitInSet((*todoIterator));
        controlFlowGraph->InitOutSet((*todoIterator));
        todo.push_back((*todoIterator));
    }
}


//////////////////////////////////////////////////////////////////
//                      CONSTRUCTORS                            //
//////////////////////////////////////////////////////////////////

DFFrameworkType::DFFrameworkType(CFGBaseType* cfg, DF_DIRECTION_TYPE dir) {
    controlFlowGraph = cfg;
    direction = dir;
}
    

//////////////////////////////////////////////////////////////////
//                    PUBLIC METHODS                            //
//////////////////////////////////////////////////////////////////



void DFFrameworkType::RunFramework() {
    // if backward we need to reverse the cfg
    if (direction == DF_BACKWARD) {
        controlFlowGraph->ReverseCFG();
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
        controlFlowGraph->Status(node,DF_NOT_IN_TODO);
        // first apply the meet operator
        controlFlowGraph->ApplyMeetOperator(node);
        // next apply the transfer function
        bool changed = controlFlowGraph->ApplyTransferFunction(node);
        // if applying the transfer function changed the data sets
        // the out edges of this node need to be added to the todo
        // list since they might also change.
        if (changed) {
            std::vector<Instruction*>& next_nodes = controlFlowGraph->GetOutEdges(node);
            for (int cnt=0; cnt < next_nodes.size(); ++cnt) {
               Instruction* next_node = next_nodes[cnt];
               // only need to add to todo list if not there already
               if (controlFlowGraph->Status(next_node) != DF_IN_TODO) {
                    controlFlowGraph->Status(next_node, DF_IN_TODO);
                    todo.push_back(next_node);
                }
            }
        }
    }
}

