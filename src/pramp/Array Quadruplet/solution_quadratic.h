//
// Copyright (C) 2020 Ruslan Manaev (manavrion@gmail.com)
// This file is part of https://github.com/manavrion/algorun repository
//

// Time complexity: best case - O(n^2), worst case - O(n^4)
// Space complexity: O(n^2)

vector<int> findArrayQuadruplet(const vector<int>& a, int64_t target) {
  unordered_map<int64_t, vector<pair<size_t, size_t>>> sum_to_indexes;

  for (size_t i = 0; i < a.size(); ++i) {
    for (size_t j = i + 1; j < a.size(); ++j) {
      auto sum = int64_t(a[i]) + a[j];
      sum_to_indexes[sum].emplace_back(i, j);
    }
  }

  vector<int> result;

  for (const auto& [sum, pairs] : sum_to_indexes) {
    for (const auto& [i, j] : pairs) {
      if (auto it = sum_to_indexes.find(target - sum);
          it != sum_to_indexes.end()) {
        for (const auto& [k, l] : it->second) {
          if (i == k || i == l || j == k || j == l) {
            continue;
          }
          vector<int> tmp = {a[i], a[j], a[k], a[l]};
          sort(tmp.begin(), tmp.end());
          if (tmp < result || result.empty()) {
            result = std::move(tmp);
          }
        }
      }
    }
  }

  return result;
}
