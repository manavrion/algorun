//
// Copyright (C) 2020 Ruslan Manaev (manavrion@gmail.com)
// This file is part of https://github.com/manavrion/algorun repository
//

// Time complexity: O(n)
// Space complexity: O(1) but inplace

auto reverseWords(string s) {
  reverse(s.begin(), s.end());

  auto it = s.begin();
  while (it != s.end()) {
    if (*it == ' ') {
      ++it;
      continue;
    }
    auto jt = next(it);
    while (jt != s.end() && *jt != ' ') {
      ++jt;
    }
    reverse(it, jt);
    it = jt;
  }

  return s;
}
