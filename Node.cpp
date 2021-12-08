#include "Node.h"
Node::Node(bool team, int pos_x, int pos_y):team_(team), pos_x_(pos_x), pos_y_(pos_y) {} 
bool Node::team(){
  return team_;
}
int Node::pos_x(){
  return pos_x_;
}
int Node::pos_y(){
  return pos_y_;
}
