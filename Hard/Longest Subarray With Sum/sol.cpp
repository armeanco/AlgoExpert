#include <vector>
std::vector<int> longestSubarrayWithSum(std::vector<int> array, int targetSum) {
    std::vector<std::vector<int>> sequence;
    if( array.size() == 1 && targetSum == array[0] ) return { 0, 0 };
    int mx = 0;
    for( std::size_t i = 0; i < array.size(); ++i ) {
        int cnt = 0, res = array[i];
        std::vector<int> t;
        for( std::size_t j = i + 1; j < array.size(); ++j ) {
            cnt++;
            res += array[j];
            if( res == targetSum ) { t.push_back(i); t.push_back(j); if( j - i > mx ) mx = j - i; }
        }
        sequence.push_back(t);
    }
    for( std::size_t i = 0; i < sequence.size(); ++i ) {
        for( std::size_t j = 0; j < sequence[i].size(); ++j ) {
            if( sequence[i][j + 1] - sequence[i][j] == mx ) return {sequence[i][j], sequence[i][j + 1]};
        }
    }
  return {};
}
