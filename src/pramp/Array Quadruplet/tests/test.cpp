//
// Copyright (C) 2020 Ruslan Manaev (manavrion@gmail.com)
// This file is part of https://github.com/manavrion/algorun repository
//

#include <gtest/gtest.h>

#include "test_generator.h"

using namespace pramp_array_quadruplet_test;

TEST(Pramp, ArrayQuadrupletTestNaiveVsCubic) {
  TestGenerator generator;
  generator.CompareSolutions(solution_naive::findArrayQuadruplet,
                             solution_cubic_and_log::findArrayQuadruplet,
                             10'000);
}

TEST(Pramp, ArrayQuadrupletTestCubicAndLogVsCubic) {
  TestGenerator generator;
  generator.CompareSolutions(solution_cubic_and_log::findArrayQuadruplet,
                             solution_cubic::findArrayQuadruplet, 100'000);
}

TEST(Pramp, ArrayQuadrupletTestCubicVsQuadratic) {
  TestGenerator generator;
  generator.CompareSolutions(solution_cubic::findArrayQuadruplet,
                             solution_quadratic::findArrayQuadruplet, 1'000);
}
