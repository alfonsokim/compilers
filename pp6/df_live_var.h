#ifndef _H_DF_LIVE_VAR
#define _H_DF_LIVE_VAR

#include "df_framework.h"
#include <map>
#include <string>

class CFDLiveVariable : public CFGBaseType {

public:

  CFDLiveVariable(std::list<Instruction*>* code);

  void GetLiveLocations(Instruction* instruction);

/* =================================================
   =   Implementacion de metodos en CFGBaseType   =
   ------------------------------------------------- */

  bool ComputeGenSet(Instruction* node);

  bool ComputeKillSet(Instruction* node);

  void InitInSet(Instruction* node);

  void InitOutSet(Instruction* node);

  bool ApplyMeetOperator(Instruction* node);

  bool ApplyTransferFunction(Instruction* node);
  
  void Status(Instruction* node, DF_STATUS_TYPE status);

  DF_STATUS_TYPE Status(Instruction* node);

  void ApplyDFInfo();

/* =================================================
   =      Prueba de simplificacion de codigo       =
   ------------------------------------------------- */

  std::map<int, std::map<std::string, std::pair<int,int> > > variable_timeline;
  
  void get_live_locations(std::list<Instruction*>, int);

};

#endif
