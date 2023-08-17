#include <vector>

int minimumWaitingTime(std::vector<int> queries) {
  std::sort(queries.begin(), queries.end());
  int min = 0, res = 0;
  for( std::size_t i = 1; i < queries.size(); ++i ) {
    min += queries[i - 1], res += min;
  }
  return res;
}
