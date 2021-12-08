#ifndef _CheckUtil_
#define _CkeckUtil_
#include <vector>
class CheckUtil {
 public:
  CheckUtil* GetInstance();
  vector<int> Candidates(const Node*[][] map, const bool team) const;
  void init(const int width, const int height);
 private:
  CheckUtil();
  void check4target();
  vector<int> candidates_;
  static CheckUtil* instance_; 
  const int width_;
  const int height_;
};
