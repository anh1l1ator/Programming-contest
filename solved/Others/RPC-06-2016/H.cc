// W.A
#include <bits/stdc++.h>
#define endl '\n'
#define debug(x) cout << #x  " = " << (x) << endl

using namespace std;

pair<int, int> left(vector<int> &a, int s) {
  if (a.size() == 0) return make_pair(0, s);
  if (a.size() <= 5) {
    return make_pair(s - a[0], a[0]);
  }
  int have = 4;
  int total = s - a[0];
  for (int i = 1; i < a.size(); ++i) {
    if (have == 0) {
      total += 2 * (s - a[i]);
      have = 5;
    } else {
      total += a[i] - a[i - 1];
    }
  }
  return make_pair(total, a.back());
}

pair<int, int> right(vector<int> &a, int s) {
  if (a.size() == 0) return make_pair(0, s);
  if (a.size() <= 5) {
    return make_pair(a.back() - s, a.back());
  }

  int have = 4;
  int n = a.size() - 1;
  int total = a[n] - s;
  for (int i = n - 1; i >= 0; --i) {
    if (have == 0) {
      total += 2 * (a[i] - s);
      have = 5;
    } else {
      total += a[i + 1] - a[i];
    }
  }
  return make_pair(total, a[0]);
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  while (cin >> n) {
    vector<int> h(n);
    for (auto &i : h) cin >> i;
    int start; cin >> start;
    sort(h.begin(), h.end());
    vector<int> l, r;
    for (auto &i : h)
      if (i < start)
        l.emplace_back(i);
      else if (i > start)
        r.emplace_back(i);

    pair<int, int> ll = left(l, start);
    pair<int, int> rr = right(r, start);
    int ans = n + ll.first + rr.first;
    int best = start - ll.second;
    best = min(best, rr.second - start);
    cout << ans + best << endl;
  }
  return 0;
}
