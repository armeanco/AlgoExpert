#include <vector>
#include <stack>

std::vector<int> nextGreaterElement(std::vector<int> array) {
  std::vector<int> out(array.size() - 1);
  std::stack<int> st;
  int n = array.size() - 1;
  for( int i = n; i >= 0; i-- ) st.push(array[i]);
  for( int i = n; i >= 0; i-- ) {
    while( !st.empty() && st.top() <= array[i] ) st.pop();
    if( st.empty() ) {
      st.push(array[i]);
      continue;
    }
    out[i] = st.top();
    st.push(array[i]);
  }
  return out;
}
