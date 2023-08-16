#include <vector>
#include <algorithm>

std::vector<std::vector<int>> mergeOverlappingIntervals(std::vector<std::vector<int>> intervals) {
  std::sort(intervals.begin(), intervals.end());
  for(int i = 0; i < (int) intervals.size(); ++i) {
    if(i + 1 < intervals.size() && intervals[i][0] <= intervals[i + 1][0] && 
       intervals[i][1] >= intervals[i + 1][0] && 
       intervals[i][1] <= intervals[i + 1][1]) {
       intervals[i + 1][0] = intervals[i][0];
    }
    else if(i + 1 < intervals.size() && intervals[i][0] <= intervals[i + 1][0] && intervals[i][1] >= intervals[i + 1][0]
            && intervals[i][1] >= intervals[i + 1][1]) {
      intervals[i + 1][0] = intervals[i][0], intervals[i + 1][1] = intervals[i][1];
       }
    }
    std::vector<std::vector<int>> ans;
    for( std::size_t i = 0; i < intervals.size(); ++i ) {
        if( i + 1 < intervals.size() && intervals[i][0] != intervals[i + 1][0] ) {
            ans.push_back({intervals[i][0], intervals[i][1]});
        }
    }
    ans.push_back({intervals[intervals.size() - 1][0], intervals[intervals.size() - 1][1]});
    return ans;
}
