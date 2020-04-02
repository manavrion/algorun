//
// Copyright (C) 2020 Ruslan Manaev (manavrion@gmail.com)
// This file is part of https://github.com/manavrion/algorun repository
//

// Time complexity: O(n^3 log n)
// Space complexity: O(1) but inplace

vector<int> findArrayQuadruplet(vector<int> a, int target) {
  sort(a.begin(), a.end());

  const size_t n = a.size();
  for (size_t i = 0; i < n; ++i) {
    for (size_t j = i + 1; j < n; ++j) {
      for (size_t k = j + 1; k < n; ++k) {
        auto new_target = int64_t(target) - a[i] - a[j] - a[k];
        auto it = lower_bound(next(a.begin(), k + 1), a.end(), new_target);
        if (it != a.end() && *it == new_target) {
          size_t l = distance(a.begin(), it);
          return {a[i], a[j], a[k], a[l]};
        }
      }
    }
  }
  return {};
}
