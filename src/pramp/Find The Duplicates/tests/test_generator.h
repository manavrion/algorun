//
// Copyright (C) 2020 Ruslan Manaev (manavrion@gmail.com)
// This file is part of https://github.com/manavrion/algorun repository
//

#pragma once
#include <bits/stdc++.h>
using namespace std;

namespace solution_linear {
#include "pramp/Find The Duplicates/solution_linear.h"
}

namespace solution_linearithmic {
#include "pramp/Find The Duplicates/solution_linearithmic.h"
}

#include <common/test_utility.h>

namespace pramp_find_the_duplicates_test {

struct TestGenerator : public common_test_utility::TestMaker<TestGenerator> {
  struct TestCase {
    std::tuple<std::vector<int>, std::vector<int>> input;
    std::optional<std::vector<int>> expectation;
  };

  struct Dist {
    dist_t<size_t> a_size{0, 1000};
    dist_t<size_t> b_size{0, 1000};
    dist_t<int> a_val{-10, 10};
    dist_t<int> b_val{-10, 10};
  } dist;

  auto a_size_dist() { return rand(dist.a_size); }
  auto b_size_dist() { return rand(dist.b_size); }
  auto a_val_dist() { return rand(dist.a_val); }
  auto b_val_dist() { return rand(dist.b_val); }

  std::vector<TestCase> DefaultTestCases() {
    std::vector<TestCase> result = {
        // Cases from pramp
        TestCase{{{11}, {11}}, {{11}}},
        TestCase{{{1, 3, 5, 9}, {2, 4, 6, 10}}, {{}}},
        TestCase{{{1, 2, 3, 5, 6, 7}, {3, 6, 7, 8, 20}}, {{3, 6, 7}}},
        TestCase{{{1, 2, 3, 5, 6, 7}, {7, 8, 9, 10, 11, 12}}, {{7}}},
        TestCase{{{10, 20, 30, 40, 50, 60, 70, 80}, {10, 20, 30, 40, 50, 60}},
                 {{10, 20, 30, 40, 50, 60}}},
        TestCase{{{10, 20, 30, 40, 50, 60, 70}, {10, 20, 30, 40, 50, 60, 70}},
                 {{10, 20, 30, 40, 50, 60, 70}}},
        // My cases
        TestCase{{{1, 2, 2, 2, 2, 3, 4, 4, 5}, {1, 2, 2, 3, 4, 4, 4, 4, 4}},
                 {{1, 2, 2, 3, 4, 4}}},
    };
    return result;
  }

  TestCase GenerateTestCase() {
    TestCase result;
    auto& [as, bs] = result.input;
    as.resize(a_size_dist());
    for (auto& a : as) {
      a = a_val_dist();
    }
    std::sort(as.begin(), as.end());
    bs.resize(b_size_dist());
    for (auto& b : bs) {
      b = b_val_dist();
    }
    std::sort(bs.begin(), bs.end());
    return result;
  }
};

}  // namespace pramp_find_the_duplicates_test
