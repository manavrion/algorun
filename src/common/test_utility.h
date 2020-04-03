//
// Copyright (C) 2020 Ruslan Manaev (manavrion@gmail.com)
// This file is part of https://github.com/manavrion/algorun repository
//

#pragma once
#include <gtest/gtest.h>

#include <limits>
#include <random>

namespace common_test_utility {

template <typename T>
class TestMaker {
 public:
  template <typename I>
  using dist_t = std::uniform_int_distribution<I>;

  TestMaker() : int_dist_(kMinInt, kMaxInt), bool_dist_(0, 1), rng_(1337) {}

  template <typename S1, typename S2>
  void CompareSolutions(S1&& s1, S2&& s2, size_t limit) {
    auto print = [](const auto& arg) {
      std::stringstream ss;
      testing::internal::PrintTo(arg, &ss);
      return ss.str();
    };

    auto testCases = GenerateTestCases(limit);

    for (const auto& testCase : testCases) {
      auto s1_answer = std::apply(std::forward<S1>(s1), testCase.input);
      auto s2_answer = std::apply(std::forward<S2>(s2), testCase.input);

      if (auto& expectation = *testCase.expectation; testCase.expectation) {
        {
          auto solution = std::move(s1_answer);
          ASSERT_EQ(expectation, solution) << print(testCase.input);
        }
        {
          auto solution = std::move(s2_answer);
          ASSERT_EQ(expectation, solution) << print(testCase.input);
        }
      } else {
        auto canonical = std::move(s1_answer);
        auto solution = std::move(s2_answer);
        ASSERT_EQ(canonical, solution) << print(testCase.input);
      }
    }
  }

  template <typename S>
  void RunSolution(S&& s) {
    auto testCase = static_cast<T*>(this)->GenerateTestCase();
    auto s_answer = std::apply(std::forward<S>(s), std::move(testCase.input));
    (void)s_answer;
  }

 protected:
  auto GenerateTestCases(size_t limit) {
    auto* this_ = static_cast<T*>(this);
    auto result = this_->DefaultTestCases();
    while (result.size() < limit) {
      result.emplace_back(this_->GenerateTestCase());
    }
    return result;
  }

  static constexpr auto kMaxInt = std::numeric_limits<int>::max();
  static constexpr auto kMinInt = std::numeric_limits<int>::min();

  template <typename R>
  R rand(dist_t<R>& dist) {
    return dist(rng_);
  }

  int int_dist() { return int_dist_(rng_); }

  int bool_dist() { return bool_dist_(rng_); }

 private:
  std::mt19937 rng_;
  dist_t<int> int_dist_;
  dist_t<int> bool_dist_;
};

}  // namespace common_test_utility
