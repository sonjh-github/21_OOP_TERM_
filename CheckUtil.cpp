#include "CheckUtil.h"
CheckUtil* CheckUtil::instance_ = NULL;
CheckUtil* CheckUtil::GetInstance() {
  if(instance_ == NULL) {
    instance_ = new CheckUtil();
  }
  return instance_;
}
vector<int> CheckUtil::Candidates(const Node*[][] map, const bool team) const {
  // 상하좌우 대각 가능
  for(int row_idx = 0; row_idx < height_ ; row_idx++) {
    for(int col_idx =0 ; col_idx < width_ ; col_idx++) {
        // 수직 조사
      if(map[row_idx][col_idx] -> team() == team) {
	bool found = false;
	for(int offset = 0; (row_idx + offset < height_) ; offset++){
          check4target(row_idx, col_idx, offset, 0);
	}
	found = false;
        for(int offset = 0; (row_idx - offset >= 0) ; offset++){
          check4target(row_idx, col_idx, -offset, 0);
        }

	// 수평 조사
	found = false;
	for(int offset = 0; (col_idx + offset < width_) ; offset++){
          check4target(row_idx, col_idx, 0, offset);
        }
	found = false;
        for(int offset = 0; (col_idx - offset >= 0) ; offset++){
          check4target(row_idx, col_idx, 0, -offset);
        }
	// 대각 조사- 우상향
	found = false;
        for(int offset = 0; (row_idx + offset < height_) && (col_idx + offset < width_) ; offset++){
          check4target(row_idx, col_idx, offset, offset);
        }
        found = false;
        for(int offset = 0; (row_idx - offset >= 0) && (col_idx - offset >= 0); offset++){
          check4target(row_idx, col_idx, -offset, -offset);
        }
	// 대각 조사 - 우하향
        found = false;
        for(int offset = 0; (row_idx + offset < height_) && (col_idx - offset >= 0) ; offset++){
          check4target(row_idx, col_idx, offset, -offset); 
        }
        found = false;
        for(int offset = 0; (row_idx - offset >= 0) && (col_idx + offset < width_) ; offset++){
	  check4target(row_idx, col_idx, -offset, offset);
        }
    }
  }
  candidates.erase(unique(candidates.begin(),candidates.end()),candidates.end());
  return candidates;
}
CheckUtil::check4target(const int pos_x, const int pos_y, const int offset_x, const int offset_y){
  if(found) {
    candidates_.push_back(pos_x*(width_+height_) + pos_y);
    if(map[pos_x + offset_x][pos_y + offset_y] != nullptr && (map[pos_x + offset_x][pos_y + offset_y] -> team()) != team){
      continue;
    } else {
      break;
    }
  }
  if(map[pos_x + offset_x][pos_y + offset_y] != nullptr && (map[pos_x + offset_x][pos_y + offset_y] -> team()) != team){
    found = true;
  }
} 
