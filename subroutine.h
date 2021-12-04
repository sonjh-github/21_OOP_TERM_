#include "Node.h"
#include <vector>
std::vector<const Node*> available_pos(const Node*[][] map, bool home_team);
void choose_pos(const Node*[][] map, const Node* new_node);