#include <vector>
#include <string>
#include <map>

std::string tournamentWinner(std::vector<std::vector<std::string>> competitions, std::vector<int> results) {
  std::string winner = "";
  std::map<std::string, int> score;
  for( std::size_t i = 0; i < results.size(); ++i ) {
    std::string tmp = competitions[i][!(results[i])];
    score[tmp] += 3;
    winner = ( score[tmp] > score[winner] ? tmp : winner );
  }
  return winner;
}
