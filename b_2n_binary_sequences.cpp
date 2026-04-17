// https://codeforces.com/group/gA8A93jony/contest/270592/problem/A
#include <cstdint>
#include <iostream>

using namespace std;

void dfs(string &current, int64_t N) {
  if (current.length() == N) {
    int64_t left, right;
    left = right = 0;
    for (int i = 0; 2*i < N; ++i) {
      if (current[i] == '1') {
        left += 1;
      }
    }
    for (int i = N/2; i <  N; ++i) {
      if (current[i] == '1') {
        right += 1;
      }
    }
    // cout << "left: " << left << " right: " << right << endl;
    if (left == right) {
      cout << current << endl;
    }
    return;
  }
  current.push_back('0');
  dfs(current, N);
  current.pop_back();
  current.push_back('1');
  dfs(current, N);
  current.pop_back();
}

int main() {
  int64_t T;
  cin >> T;
  int64_t N;
  while (T--) {
    cin >> N;
    string s = "";
    dfs(s, 2 * N);
  }
  return 0;
}
