// https://codeforces.com/group/gA8A93jony/contest/270592/problem/I
#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

int64_t dfs(int64_t idx, const vector<int64_t> &A) {
  if(idx == 0) {
    return 1;
  }
  int64_t maxima = 1;
  for(int i = 0; i < idx; ++i) {
    if(A[i] < A[idx]) {
      maxima = max(maxima, 1 + dfs(i, A));
    }
  }
  return maxima;
}

int main() {
  size_t N;
  cin >> N;
  vector<int64_t> A(N);
  for(size_t i = 0; i < N; ++i) {
    cin >> A[i];
  }
  int64_t ans = 0;
  for(size_t i = 0; i < N; ++i) {
    ans = max(ans, dfs(i, A));
  }
  cout << ans << endl;
  return 0;
}
