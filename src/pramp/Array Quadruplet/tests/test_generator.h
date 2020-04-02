//
// Copyright (C) 2020 Ruslan Manaev (manavrion@gmail.com)
// This file is part of https://github.com/manavrion/algorun repository
//

#pragma once
#include <bits/stdc++.h>
using namespace std;

namespace solution_cubic_and_log {
#include "pramp/Array Quadruplet/solution_cubic_and_log.h"
}
namespace solution_cubic {
#include "pramp/Array Quadruplet/solution_cubic.h"
}
namespace solution_naive {
#include "pramp/Array Quadruplet/solution_naive.h"
}
namespace solution_quadratic {
#include "pramp/Array Quadruplet/solution_quadratic.h"
}

#include <common/test_utility.h>

namespace pramp_array_quadruplet_test {

struct TestGenerator : public common_test_utility::TestMaker<TestGenerator> {
  struct TestCase {
    std::tuple<std::vector<int>, int> input;
    std::optional<std::vector<int>> expectation;
  };

  struct Dist {
    dist_t<int> sum{-100, 100};
    dist_t<int> val{-100, 100};
    dist_t<size_t> size{0, 100};
  } dist;

  auto sum_dist() { return rand(dist.sum); }
  auto val_dist() { return rand(dist.val); }
  auto size_dist() { return rand(dist.size); }

  std::vector<TestCase> DefaultTestCases() {
    std::vector<TestCase> result = {
        // Cases from pramp
        TestCase{{{}, 12}, {{}}},
        TestCase{{{4, 4, 4}, 12}, {{}}},
        TestCase{{{4, 4, 4, 2}, 16}, {{}}},
        TestCase{{{4, 4, 4, 4}, 16}, {{4, 4, 4, 4}}},
        TestCase{{{2, 7, 4, 0, 9, 5, 1, 3}, 20}, {{0, 4, 7, 9}}},
        TestCase{{{2, 7, 4, 0, 9, 5, 1, 3}, 120}, {{}}},
        TestCase{{{1, 2, 3, 4, 5, 9, 19, 12, 12, 19}, 40}, {{4, 5, 12, 19}}},
        // My cases
        TestCase{{{kMaxInt, 0, 1, 0}, kMinInt}, {{}}},
    };
    return result;
  }

  TestCase GenerateTestCase() {
    TestCase result;
    auto& [as, sum] = result.input;
    sum = sum_dist();
    as.resize(size_dist());
    for (auto& a : as) {
      a = val_dist();
    }
    return result;
  }
};

}  // namespace pramp_array_quadruplet_test
