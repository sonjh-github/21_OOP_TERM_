#include "CheckUtil.h"
CheckUtil* CheckUtil::instance_ = NULL;
CheckUtil* CheckUtil::GetInstance() {
  if(instance_ == NULL) {
    instance_ = new CheckUtil();
  }
  return instance_;
}
vector<int> CheckUtil::Candidates(const Node*[][] map, const bool team) const {
  
}
