#include <vector>
#include <cmath>
#include <list>

void precompute(std::vector<int> &array, int n, int max) {
  int i, j, m, p = 1, index, temp, count = 0;
   std::list<int> pocket[10];
   for(i = 0; i < max; i++) {
      m = std::pow(10, i+1);
      p = std::pow(10, i);
      for(j = 0; j < n; j++) {
         temp = array[j] % m;
         index = temp / p;
         pocket[index].push_back(array[j]);
      }
      count = 0;
      for(j = 0; j < 10; j++) {
         while(!pocket[j].empty()) {
            array[count] = *(pocket[j].begin());
            pocket[j].erase(pocket[j].begin());
            count++;
         }
      }
   }
}

std::vector<int> radixSort(std::vector<int> array) {
  int mx = 0;
  for( const auto &c : array ) if( c > mx ) mx = c;
  int n = array.size(), l = std::to_string(mx).size();
  precompute(array, n, l);
  return array;
}
