//
// Copyright (C) 2020 Ruslan Manaev (manavrion@gmail.com)
// This file is part of https://github.com/manavrion/algorun repository
//

#pragma once
#include <bits/stdc++.h>
using namespace std;

namespace solution_indexes {
#include "pramp/Sentence Reverse/solution_indexes.h"
}
namespace solution_iterators {
#include "pramp/Sentence Reverse/solution_iterators.h"
}

#include <common/test_utility.h>

namespace pramp_sentence_reverse_test {

struct TestGenerator : public common_test_utility::TestMaker<TestGenerator> {
  struct TestCase {
    std::tuple<std::string> input;
    std::optional<std::string> expectation;
  };

  struct Dist {
    dist_t<size_t> space_size{1, 100};
    dist_t<size_t> word_size{1, 100};
    dist_t<size_t> total_size{0, 1000};
    dist_t<char> chars{'a', 'z'};
  } dist;

  auto space_size_dist() { return rand(dist.space_size); }
  auto word_size_dist() { return rand(dist.word_size); }
  auto total_size_dist() { return rand(dist.total_size); }
  auto chars_dist() { return rand(dist.chars); }

  std::vector<TestCase> DefaultTestCases() {
    std::vector<TestCase> result = {
        // Cases from pramp.
        TestCase{" ", " "},
        TestCase{"a  b", "b  a"},
        TestCase{"hello", "hello"},
        TestCase{"perfect makes practice", "practice makes perfect"},
        TestCase{"you with be force the may", "may the force be with you"},
        TestCase{"greatest name first ever name last",
                 "last name ever first name greatest"},
        // My cases.
        TestCase{"perfect   makes practice", "practice makes   perfect"},
        TestCase{"perfect   makes  practice", "practice  makes   perfect"},
        TestCase{"    perfect   makes  practice",
                 "practice  makes   perfect    "},
    };
    return result;
  }

  TestCase GenerateTestCase() {
    TestCase result;
    auto& [s] = result.input;
    int gg = total_size_dist();
    s.resize(gg);

    auto it = s.begin();
    bool is_word = bool_dist();
    while (it != s.end()) {
      if (is_word) {
        auto size = word_size_dist();
        while (size-- && it != s.end()) {
          *(it++) = chars_dist();
        }
      } else {
        auto size = space_size_dist();
        while (size-- && it != s.end()) {
          *(it++) = ' ';
        }
      }
      is_word = !is_word;
    }
    return result;
  }
};

}  // namespace pramp_sentence_reverse_test
