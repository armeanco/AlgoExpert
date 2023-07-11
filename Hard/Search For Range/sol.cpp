#include <vector>
std::vector<int> searchForRange(std::vector<int> array, int target) {
  if( array[0] == target && array[1] != target ) return {0, 0};
  if( array[array.size() - 1] == target && array[array.size() - 2] != target) return {static_cast<int>(array.size() -1), static_cast<int>(array.size() -1)};
  auto bs = [&](std::vector<int> &a, int target) -> void {
    int low = 0, high = array.size() - 1;
    while( low <= high ) {
      int middle = ( low + high ) / 2;
      int cnt_l = middle, cnt_r = middle;
      if( array[middle] == target ) {
        while( array[cnt_r + 1] == target ) {
          cnt_r++;
          if( array[cnt_r + 1] != target ) {
            a.push_back(cnt_r);
          }
        }
        while( array[cnt_l - 1] == target ) {
          cnt_l--;
          if( array[cnt_l - 1] != target ) {
            a.push_back(cnt_l);
          }
        }
      }
      if( array[middle] < target )
        low = middle + 1;
      else 
        high = middle - 1;
    }
    return;
  };
  std::vector<int> res;
  bs(res, target);
  if( res.empty() ) return {-1, -1};
  if( res.size() > 2 ) res.erase(res.begin());
  return res;
}
