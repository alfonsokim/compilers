#include "df_base_type.h"


CFGBaseType::CFGBaseType(std::list<Instruction*>* code) : CFGType(code) {
  ;/*nothing to do*/
}

std::list<Instruction*>& CFGBaseType::GetAllNodes() {
  return *_instructions;
}
