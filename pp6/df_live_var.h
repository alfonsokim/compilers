#ifndef _H_DF_LIVE_VAR
#define _H_DF_LIVE_VAR

#include "df_framework.h"

class df_live_var : public df_base_type {

  df_live_var(std::list<Instruction*>* code);

  void get_live_locations(Instruction* instruction);

};

#endif
