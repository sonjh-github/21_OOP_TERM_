#ifndef _CheckUtil_
#define _CkeckUtil_
#include <vector>
class CheckUtil {
 public:
  CheckUtil* GetInstance();
  void check(const Node* node);
 private:
  CheckUtil();
  static CheckUtil* instance_; 
};
