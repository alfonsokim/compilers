//Implementation of live variable analysis

#include <stdio.h>
#include "df_live_var.h"

df_live_var::df_live_var(std::list<Instruction*>* code) : CFGBaseType(code) { }

void df_live_var::get_live_locations(Instruction* instruction) {}

/* =================================================
   =   Implementacion de metodos en df_base_type   =
   ------------------------------------------------- */

bool df_live_var::ComputeGenSet(Instruction* node) { 
    return false; 
}

bool df_live_var::ComputeKillSet(Instruction* node) { 
    return false; 
}

void df_live_var::InitInSet(Instruction* node) { 
}

void df_live_var::InitOutSet(Instruction* node) { 
    printf("iniciando init_out_set con ");
    node->Print();
}

bool df_live_var::ApplyMeetOperator(Instruction* node) { 
    return false; 
}

bool df_live_var::ApplyTransferFunction(Instruction* node) { 
    return false; 
}
  
void df_live_var::Status(Instruction* node, DF_STATUS_TYPE status) {

}

DF_STATUS_TYPE df_live_var::Status(Instruction* node) { 
    return DF_NOT_INITIALIZED; 
}

void df_live_var::ApplyDFInfo() {

}
