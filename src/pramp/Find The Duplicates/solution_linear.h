//
// Copyright (C) 2020 Ruslan Manaev (manavrion@gmail.com)
// This file is part of https://github.com/manavrion/algorun repository
//

// Time complexity: O(n + m)
// Space complexity: O(1) but O(min(n, m)) for answer

auto solve(const vector<int>& a, const vector<int>& b) {
  vector<int> result;

  size_t i = 0;
  size_t j = 0;
  while (i < a.size() && j < b.size()) {
    if (a[i] < b[j]) {
      ++i;
    } else if (a[i] > b[j]) {
      ++j;
    } else {
      result.emplace_back(a[i]);
      ++i, ++j;
    }
  }

  return result;
}
