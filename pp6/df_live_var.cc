//Implementation of live variable analysis

#include <stdio.h>
#include "df_live_var.h"

df_live_var::df_live_var(std::list<Instruction*>* code) : CFGBaseType(code) { }

void df_live_var::get_live_locations(Instruction* instruction) {}

/* =================================================
   =   Implementacion de metodos en df_base_type   =
   ------------------------------------------------- */

bool df_live_var::compute_gen_set(Instruction* node) { 
    return false; 
}

bool df_live_var::compute_kill_set(Instruction* node) { 
    return false; 
}

void df_live_var::init_in_set(Instruction* node) { 
}

void df_live_var::init_out_set(Instruction* node) { 
    printf("iniciando init_out_set con ");
    node->Print();
}

bool df_live_var::apply_meet_operator(Instruction* node) { 
    return false; 
}

bool df_live_var::apply_transfer_function(Instruction* node) { 
    return false; 
}
  
void df_live_var::status(Instruction* node, DF_STATUS_TYPE status) {

}

DF_STATUS_TYPE df_live_var::status(Instruction* node) { 
    return DF_NOT_INITIALIZED; 
}

void df_live_var::apply_df_info() {

}
