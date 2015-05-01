#ifndef _H_DF_FRAMEWORK
#define _H_DF_FRAMEWORK

#include <map>
#include <list>

#include "df_base_type.h"

enum DF_DIRECTION_TYPE {
  DF_FORWARD,
  DF_BACKWARD
};


class DFFrameworkType {

 public:
  
  DFFrameworkType(CFGBaseType* df_cfg, DF_DIRECTION_TYPE direction);
  
  void RunFramework();
  
 private: // private methods
  
  void InitFramework(std::list<Instruction*>& todo);

 private: // private members
  
  DF_DIRECTION_TYPE direction;
  CFGBaseType* controlFlowGraph;

};


#endif
