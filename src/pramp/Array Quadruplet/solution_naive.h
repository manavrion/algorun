//
// Copyright (C) 2020 Ruslan Manaev (manavrion@gmail.com)
// This file is part of https://github.com/manavrion/algorun repository
//

// Time complexity: O(n^4)
// Space complexity: O(1) but inplace

vector<int> findArrayQuadruplet(vector<int> a, int target) {
  sort(a.begin(), a.end());

  const size_t n = a.size();
  for (size_t i = 0; i < n; ++i) {
    for (size_t j = i + 1; j < n; ++j) {
      for (size_t k = j + 1; k < n; ++k) {
        for (size_t l = k + 1; l < n; ++l) {
          auto sum = int64_t(a[i]) + a[j] + a[k] + a[l];
          if (sum == target) {
            return {a[i], a[j], a[k], a[l]};
          }
        }
      }
    }
  }
  return {};
}
