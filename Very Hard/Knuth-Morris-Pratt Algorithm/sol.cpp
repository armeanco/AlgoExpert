#include <vector>
#include <string>
std::vector<int> compute_pi(std::string pat) {
  int n = pat.size();
  std::vector<int> pi(n);
  pi[0] = 0;
  for (int i = 1; i < n; i++) {
    pi[i] = 0;
    int j = pi[i - 1]; 
    while (j > 0 && pat[j] != pat[i]) {
      j = pi[j - 1];
    }
    if (pat[j] == pat[i]) {
      pi[i] = j + 1;
    }
  }
  return pi;
}
bool knuthMorrisPrattAlgorithm(string str, string substr) {
    int n = substr.size(), m = str.size();
    std::string s = substr + "$" + str;
    std::vector<int> pi = compute_pi(s), ans;
    for (int i = n + 1; i <= n + m; i++) {
    if (pi[i] == n) {
      ans.push_back(i - 2 * n);
    }
  }
  return ans.empty() ? 0 : 1;
}
