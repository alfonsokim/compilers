#include "df_base_type.h"


CFGBaseType::CFGBaseType(std::list<Instruction*>* code) : CFGType(code) {
  ;/*nothing to do*/
}

std::list<Instruction*>& CFGBaseType::GetAllNodes() {
    printf("Devolviendo lista con %lu instrucciones\n", instructions->size());
    return *instructions;
}
