#ifndef _H_DF_LIVE_VAR
#define _H_DF_LIVE_VAR

#include "df_framework.h"

class df_live_var : public df_base_type {

public:

  df_live_var(std::list<Instruction*>* code);

  void get_live_locations(Instruction* instruction);

/* =================================================
   =   Implementacion de metodos en df_base_type   =
   ------------------------------------------------- */

  bool compute_gen_set(Instruction* node);

  bool compute_kill_set(Instruction* node);

  void init_in_set(Instruction* node);

  void init_out_set(Instruction* node);

  bool apply_meet_operator(Instruction* node);

  bool apply_transfer_function(Instruction* node);
  
  void status(Instruction* node, DF_STATUS_TYPE status);

  DF_STATUS_TYPE status(Instruction* node);

  void apply_df_info();

};

#endif
