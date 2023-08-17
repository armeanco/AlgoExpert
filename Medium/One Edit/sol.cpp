#include <vector>
#include <utility>
#include <map>
std::map<std::pair<int, int>> mp;
int edit(std::string stringOne, std::string stringTwo, int i, int j) {
  if( i >= stringOne.size() || j >= stringTwo.size() ) {
    if( i < stringOne.size() ) return stringOne.size() - i;
    if( j < stringTwo.size() ) return stringTwo.size() - j;
    return 0;
  }
  if( mp[{i,j}] ) return mp[{i, j}];
  int cnt = 0;
  if( stringOne[i] == stringTwo[j] ) cnt = edit( stringOne, stringTwo, i + 1, j + 1 );
  else {
    std::vector<int> v = { edit( stringOne, stringTwo, i + 1, j + 1 ) + 1, edit( stringOne, stringTwo, i, j + 1) + 1, edit( stringOne, stringTwo, i + 1, j ) + 1 };
    cnt = *std::min_element(v.begin(), v.end());
  }
  return mp[{i, j}] = cnt;
}

bool oneEdit(std::string stringOne, std::string stringTwo) {
  mp.clear();
  return (edit(stringOne, stringTwo, 0, 0) <= 1 ? 1 : 0);
}
