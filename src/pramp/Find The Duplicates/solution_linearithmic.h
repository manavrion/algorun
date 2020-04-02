//
// Copyright (C) 2020 Ruslan Manaev (manavrion@gmail.com)
// This file is part of https://github.com/manavrion/algorun repository
//

// Time complexity: O(n log m) where n << m
// Space complexity: O(1) but O(min(n, m)) for answer

auto solve_impl(const vector<int>& a, const vector<int>& b) {
  vector<int> result;

  auto it = b.begin();
  for (auto v : a) {
    if (auto jt = lower_bound(it, b.end(), v); it != b.end()) {
      if (*jt == v) {
        result.emplace_back(v);
        it = next(jt);
      } else {
        it = jt;
      }
    } else {
      break;
    }
  }

  return result;
}

auto solve(const vector<int>& a, const vector<int>& b) {
  if (a.size() > b.size()) {
    return solve_impl(b, a);
  }
  return solve_impl(a, b);
}
