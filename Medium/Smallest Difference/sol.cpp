#include <vector>

std::vector<int> smallestDifference(std::vector<int> arrayOne, std::vector<int> arrayTwo) {
  int sz = arrayOne.size(), zs = arrayTwo.size(), st = 0, ts = 0, diff = 1e9;
  std::sort(arrayOne.begin(), arrayOne.end());
  std::sort(arrayTwo.begin(), arrayTwo.end());
  std::vector<int> res(2, 0);

  while( st < sz && ts < zs ) {
    int cur = std::abs(arrayOne[st] - arrayTwo[ts]);
    if( cur < diff ) {
      diff = cur;
      res[0] = arrayOne[st];
      res[1] = arrayTwo[ts];
    }
    if( arrayOne[st] < arrayTwo[ts] ) {
      st++;
    } else {
      ts++;
    }
  }
  return res;
}
