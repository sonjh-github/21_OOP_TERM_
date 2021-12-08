#ifndef _CheckUtil_
#define _CkeckUtil_
#include <vector>
class CheckUtil {
 public:
  CheckUtil* GetInstance();
  void check(const Node*[][] map, const bool team) const;
 private:
  CheckUtil();
  static CheckUtil* instance_; 
};
