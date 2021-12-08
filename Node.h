#ifndef _Node_
#define _Node_
class Node{
 public:
  Node(bool team, int pos_x, int pos_y){}
  bool team();
  const int pos_x();
  const int pos_y();
 private:
  bool team_;
  const int pos_x_;
  const int pos_y_;
};
