//Implementation of live variable analysis

#include <stdio.h>
#include <algorithm>
#include "df_live_var.h"

CFDLiveVariable::CFDLiveVariable(std::list<Instruction*>* code) : CFGBaseType(code) {
    PrintDebug("optim", "Iniciando CFD Live Var con %i instrucciones", code->size());
    std::list<Instruction*> currentBlock;
    std::list<int> currentInEdges;
    std::list<int> currentOutEdges;
    int id = 0;
    bool inBlock = false;

    std::list<Instruction*>::iterator instructionIt = code->begin(); 
    for (; instructionIt != code->end(); instructionIt++) {
        Instruction *instruction = *instructionIt;
        if (!inBlock && instruction->IsStartBlock()) { // Buscar inicio de bloque
            if (instruction != NULL) {
                PrintDebug("optim", "Inicio de bloque (%s)", instruction->Command().c_str());
                currentBlock.push_back(instruction);
                inBlock = true;
            }
        }

        if(inBlock && instruction->IsEndBlock()) {
            PrintDebug("optim", "Fin de bloque (%s)", instruction->Command().c_str());
            // cfg.add_basic_block(id, current_block);
            while(!currentBlock.empty()) {
                currentBlock.pop_front();
            }
            inBlock = false;
            id += 1;
        }
    } // for de iteracion de instrucciones
}

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

void CFDLiveVariable::InitInSet(Instruction* node) {}

void CFDLiveVariable::InitOutSet(Instruction* node) { 
    // PrintDebug("optim", "iniciando init_out_set Inicio?(%i) Fin?(%i)", node->IsStartBlock(), node->IsEndBlock());
}

bool CFDLiveVariable::ApplyMeetOperator(Instruction* node) { 
    return false; 
}

bool CFDLiveVariable::ApplyTransferFunction(Instruction* node) { 
    return false; 
}
  
void CFDLiveVariable::Status(Instruction* node, DF_STATUS_TYPE status) {}

DF_STATUS_TYPE CFDLiveVariable::Status(Instruction* node) { 
    return DF_NOT_INITIALIZED; 
}

void CFDLiveVariable::ApplyDFInfo() {}

void CFDLiveVariable::get_live_locations(std::list<Instruction*> stmt, int id) {
    std::string str_tmp ("=");
    size_t found;
    std::map<std::string, std::pair<int,int> > current_live_vars;
    std::vector<std::string> fails;
    std::string what_temp = "";
    std::list<Instruction*>::iterator it;
    
    for(it=stmt.begin(); it != stmt.end(); it++) {
        found = (*it)->Command().find(str_tmp);
        if(found!=std::string::npos) {
            std::string str_varName ("tmp");
            found = (*it)->Command().find(str_varName);
            int beg = (*it)->Command().find_first_of("tmp");
            int end = (*it)->Command().find_last_of("tmp");
            what_temp = (*it)->Command().substr(beg,end+1);
            fails.push_back( what_temp );   
        }
    }
    
    // remove duplicates
    fails.erase(unique(fails.begin(), fails.end()), fails.end());
    
    /*for(int i=0; i < fails.size(); i++) {
        std::cout << fails[i] << std::endl; 
    }*/

    // handle one at a time
    while(!fails.empty()){   
        int line = 1;
        int start;
        int end;
        bool got_one = false;
        bool got_end = false;
        std::string what_temp = "";
        std::list<Instruction*>::iterator it; 

        for(it=stmt.begin(); it != stmt.end(); it++) {
            if(got_one){
                got_end = true;
            }

            found = (*it)->Command().find( fails.at( fails.size()-1 ) );
            if (!got_one && !got_end && found!=std::string::npos) {
                start = line;
                //std::cout << "start: " << start << std::endl;
                //std::cout << "variable: " << (*it)->command() << std::endl;
                got_one = true;
            }
        
            found = (*it)->Command().find( fails.at( fails.size()-1 ) );
            if(got_one && got_end && found!=std::string::npos) {
                end = line;
                //std::cout << "end: " << end << std::endl;
                //std::cout << "variable: " << (*it)->command() << std::endl;
                break;
            }
        
            line += 1;
        }
        
        current_live_vars.insert( std::pair<std::string, std::pair<int,int> >(
            fails.at(fails.size()-1), std::pair<int,int>(start,end) )
        );
        fails.pop_back();
    }
    variable_timeline.insert( std::pair<int, std::map<std::string, std::pair<int,int> > > (id,current_live_vars) );
}

