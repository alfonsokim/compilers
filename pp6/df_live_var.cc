//Implementation of live variable analysis

#include <stdio.h>
#include "df_live_var.h"

CFDLiveVariable::CFDLiveVariable(std::list<Instruction*>* code) : CFGBaseType(code) { }

void CFDLiveVariable::GetLiveLocations(Instruction* instruction) {}

/* =================================================
   =   Implementacion de metodos en df_base_type   =
   ------------------------------------------------- */

bool CFDLiveVariable::ComputeGenSet(Instruction* node) { 
    return false; 
}

bool CFDLiveVariable::ComputeKillSet(Instruction* node) { 
    return false; 
}

void CFDLiveVariable::InitInSet(Instruction* node) { 
}

void CFDLiveVariable::InitOutSet(Instruction* node) { 
    PrintDebug("optim", "iniciando init_out_set Inicio?(%i) Fin?(%i)", node->IsStartBlock(), node->IsEndBlock());
}

bool CFDLiveVariable::ApplyMeetOperator(Instruction* node) { 
    return false; 
}

bool CFDLiveVariable::ApplyTransferFunction(Instruction* node) { 
    return false; 
}
  
void CFDLiveVariable::Status(Instruction* node, DF_STATUS_TYPE status) {

}

DF_STATUS_TYPE CFDLiveVariable::Status(Instruction* node) { 
    return DF_NOT_INITIALIZED; 
}

void CFDLiveVariable::ApplyDFInfo() {

}
