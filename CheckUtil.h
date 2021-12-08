#ifndef _CheckUtil_
#define _CkeckUtil_
#include <vector>
class CheckUtil {
 public:
  CheckUtil* GetInstance();
  vector<int> Candidates(const Node*[][] map, const bool team) const;
 private:
  CheckUtil();
  vector<int> candidates_;
  static CheckUtil* instance_; 
};
