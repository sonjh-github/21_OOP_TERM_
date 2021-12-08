#include "CheckUtil.h"
CheckUtil* CheckUtil::instance_ = NULL;
CheckUtil* CheckUtil::GetInstance() {
  if(instance_ == NULL) {
    instance_ = new CheckUtil();
  }
  return instance_;
}
CheckUtil::check(const Node* node){
  
}
