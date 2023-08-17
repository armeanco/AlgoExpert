#include <string>
bool balancedBrackets(std::string str) {
  std::string copy = "";
  for( const auto &c : str ) if(c == '(' || c == ')' || c == '[' || c == ']' || c == '{' || c == '}' ) copy += c; 
  int control = 25;
	while( control --> 0 ) {
	for( std::size_t i = 0; i < copy.size(); ++i ) {
		if( i + 1 < copy.size() && copy[i] == '[' && copy[i + 1] == ']' ) {
			copy.erase(copy.begin() + i + 1);
			copy.erase(copy.begin() + i);
		}
		if( i + 1 < copy.size() && copy[i] == '{' && copy[i + 1] == '}' ) {
			copy.erase(copy.begin() + i + 1);
			copy.erase(copy.begin() + i);
		}
		if( i + 1 < copy.size() && copy[i] == '(' && copy[i + 1] == ')' ) {
			copy.erase(copy.begin() + i + 1);
			copy.erase(copy.begin() + i);
		}
	}
	}
	return copy.size() == 0;
}

//Alternative Solution
#include <stack>
#include <unordered_map>

bool balancedBrackets(std::string str) {
  std::stack<char> st;
  std::string legit = "({[]})";
  std::unordered_map<char, char> umap;
  umap['{'] = '}'; umap['['] = ']'; umap['('] = ')';
  for( auto &c : str ) {
    if( legit.find(c) != legit.npos) {
      if( st.empty() || umap[st.top()] != c ) st.push( c );
      else st.pop();
    }
  }
  return st.empty();
}
