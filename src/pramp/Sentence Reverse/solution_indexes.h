//
// Copyright (C) 2020 Ruslan Manaev (manavrion@gmail.com)
// This file is part of https://github.com/manavrion/algorun repository
//

// Time complexity: O(n)
// Space complexity: O(1) but inplace

auto reverseWords(string s) {
  reverse(s.begin(), s.end());

  size_t i = 0;
  while (i < s.size()) {
    if (s[i] == ' ') {
      ++i;
      continue;
    }
    size_t j = i + 1;
    while (j < s.size() && s[j] != ' ') {
      ++j;
    }
    reverse(next(s.begin(), i), next(s.begin(), j));
    i = j + 1;
  }

  return s;
}
