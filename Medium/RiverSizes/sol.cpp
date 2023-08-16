#include <vector>
void dfs(std::size_t x, std::size_t y, std::vector<std::vector<int>>& map, int &cnt) {
  if(!( x >= 0 && x < map.size() && y >= 0 && 
       y < map[0].size() && map[x][y] == 1 )) return;
  map[x][y] = 0;
  dfs( x - 1, y, map, cnt ); //up
  dfs( x, y - 1, map, cnt ); //left
  dfs( x + 1, y, map, cnt ); //down
  dfs( x, y + 1, map, cnt ); //right
  cnt++;
}

std::vector<int> riverSizes(std::vector<std::vector<int>> matrix) {
   std::vector<int> sizes;
   for( std::size_t i = 0; i < matrix.size(); ++i ) {
     int cnt = 0;
     for( std::size_t j = 0; j < matrix[i].size(); ++j ) {
       if( matrix[i][j] == 0 ) cnt = 0;
       if( matrix[i][j] == 1 ) {
         dfs(i, j, matrix, cnt);
         sizes.push_back(cnt);
       }
     }
   }
   return sizes;
}
