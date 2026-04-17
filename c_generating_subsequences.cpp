// https://codeforces.com/group/gA8A93jony/contest/270592/problem/C
#include <algorithm>
#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void dfs(int64_t idx, string &cur, const string &s,
         vector<string> &subsequences) {
  if (idx == s.length()) {
    if (cur != "") {
      subsequences.push_back(cur);
    }
    return;
  }
  cur.push_back(s[idx]);
  dfs(idx + 1, cur, s, subsequences);
  cur.pop_back();
  dfs(idx + 1, cur, s, subsequences);
}

int main() {
  string s;
  cin >> s;
  string t;
  vector<string> subsequences;
  dfs(0, t, s, subsequences);
  sort(subsequences.begin(), subsequences.end());
  for(const auto& subsequence : subsequences) {
    cout << subsequence << endl;
  }
  return 0;
}
