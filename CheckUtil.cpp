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
  vector<int> candidates;
  for(int row_idx = 0; row_idx < height_ ; row_idx++) {
    for(int col_idx =0 ; col_idx < width_ ; col_idx++) {
        // 수직 조사
	bool found = false;
	for(int offset = 0; (row_idx + offset < height_) ; offset++){
          if(found) {
            candidates.push_back(row_idx*size + col_idx);
	    break;
	  }
          if(map[row_idx + offset][col_idx] != nullptr && (map[row_idx + offset][col_idx] -> team()) != team){
            found = true;
	  }
	}
	found = false;
        for(int offset = 0; (row_idx - offset >= 0) ; offset++){
          if(found) {
            candidates.push_back(row_idx*size + col_idx);
            break;
          }
          if(map[row_idx - offset][col_idx] != nullptr && (map[row_idx - offset][col_idx] -> team()) != team){
            found = true;
          }
        }

	// 수평 조사
	found = false;
	for(int offset = 0; (col_idx + offset < width_) ; offset++){
          if(found) {
            candidates.push_back(row_idx*size + col_idx);
	    break;
          }
          if(map[row_idx][col_idx + offset] != nullptr && (map[row_idx][col_idx + offset] -> team()) != team){
            found = true;
          }
        }
	found = false;
        for(int offset = 0; (col_idx - offset >= 0) ; offset++){
          if(found) {
            candidates.push_back(row_idx*size + col_idx);
            break;
          }
          if(map[row_idx][col_idx - offset] != nullptr && (map[row_idx][col_idx - offset] -> team()) != team){
            found = true;
          }
        }
	// 대각 조사- 우상향
	found = false;
        for(int offset = 0; (row_idx + offset < height_) && (col_idx + offset < width_) ; offset++){
          if(found) {
            candidates.push_back(row_idx*size + col_idx);
            break;
          }
          if(map[row_idx + offset][col_idx + offset] != nullptr && (map[row_idx + offset][col_idx + offset] -> team()) != team){
            found = true;
          }
        }
        found = false;
        for(int offset = 0; (row_idx - offset >= 0) && (col_idx - offset >= 0); offset++){
          if(found) {
            candidates.push_back(row_idx*size + col_idx);
            break;
          }
          if(map[row_idx - offset][col_idx - offset] != nullptr && (map[row_idx - offset][col_idx - offset] -> team()) != team){
            found = true;
          }
        }
	// 대각 조사 - 우하향
        found = false;
        for(int offset = 0; (row_idx + offset < height_) && (col_idx - offset >= 0) ; offset++){
          if(found) {
            candidates.push_back(row_idx*size + col_idx);
            break;
          }
          if(map[row_idx + offset][col_idx - offset] != nullptr && (map[row_idx + offset][col_idx - offset] -> team()) != team){
            found = true;
          }
        }
        found = false;
        for(int offset = 0; (row_idx - offset >= 0) && (col_idx + offset < width_) ; offset++){
          if(found) {
            candidates.push_back(row_idx*size + col_idx);
            break;
          }
          if(map[row_idx - offset][col_idx + offset] != nullptr && (map[row_idx - offset][col_idx + offset] -> team()) != team){
            found = true;
          }
        }
    }
  }
  candidates.erase(unique(candidates.begin(),candidates.end()),candidates.end());
  return candidates;
}
