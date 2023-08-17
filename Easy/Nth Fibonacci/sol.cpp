int getNthFib(int n) {
  std::vector<int> fib = {0, 1, 1, 2, 3, 5};
  if(n <= 6 ) return fib[n - 1];
  for( int i = fib.size(); i <= n; ++i )
    fib.push_back(fib[i - 1] + fib[i - 2]);
  return fib[n - 1];
}
