#inclued <vector>

std::vector<int> missingNumbers(std::vector<int> nums) {
  std::vector<int> res;
  int one = 0, two = 0, n = nums.size();

  if( n == 0 ) return { 1, 2 };
  std::sort(nums.begin(), nums.end());
  if( nums[n - 1] == n ) return { n + 1, n + 1 };
  int a = 0, b = 1;
  while( res.size() != 2 ) {
    if( b != nums[a] ) {
      res.push_back(b); b++; conitnue; 
    }
    b++, a++;
  }
  return res;
}
