#ifndef _H_DF_BASE_TYPE
#define _H_DF_BASE_TYPE

#include <list>

#include "cfg_type.h"

enum DF_STATUS_TYPE {
  DF_NOT_INITIALIZED,
  DF_NOT_IN_TODO,
  DF_IN_TODO
};



class CFGBaseType : public CFGType {

 public:

  CFGBaseType(std::list<Instruction*>* code);

  std::list<Instruction*>& GetAllNodes();

  virtual bool ComputeGenSet(Instruction* node) = 0;

  virtual bool ComputeKillSet(Instruction* node) = 0;

  virtual void InitInSet(Instruction* node) = 0;

  virtual void InitOutSet(Instruction* node) = 0;

  virtual bool ApplyMeetOperator(Instruction* node) = 0;

  virtual bool ApplyTransferFunction(Instruction* node) = 0;
  
  virtual void Status(Instruction* node, DF_STATUS_TYPE status) = 0;
  virtual DF_STATUS_TYPE Status(Instruction* node) = 0; 

  virtual void ApplyDFInfo() = 0;
  

};


#endif
