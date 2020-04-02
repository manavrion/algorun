//
// Copyright (C) 2020 Ruslan Manaev (manavrion@gmail.com)
// This file is part of https://github.com/manavrion/algorun repository
//

// Time complexity: O(n^3)
// Space complexity: O(1) but inplace

vector<int> findArrayQuadruplet(vector<int> a, int target) {
  sort(a.begin(), a.end());

  const size_t n = a.size();
  for (size_t i = 0; i < n; ++i) {
    for (size_t j = i + 1; j < n; ++j) {
      auto new_target = int64_t(target) - a[i] - a[j];
      size_t k = j + 1;
      size_t l = n - 1;
      while (k < l) {
        auto sum = int64_t(a[k]) + a[l];
        if (new_target < sum) {
          --l;
          continue;
        }
        if (new_target > sum) {
          ++k;
          continue;
        }
        return {a[i], a[j], a[k], a[l]};
      }
    }
  }
  return {};
}
