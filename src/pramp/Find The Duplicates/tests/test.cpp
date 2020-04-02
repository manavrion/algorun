//
// Copyright (C) 2020 Ruslan Manaev (manavrion@gmail.com)
// This file is part of https://github.com/manavrion/algorun repository
//

#include <gtest/gtest.h>

#include "test_generator.h"

using namespace pramp_find_the_duplicates_test;

TEST(Pramp, FindTheDuplicatesTestLinearVsLinearithmic) {
  TestGenerator generator;
  generator.CompareSolutions(solution_linear::solve,
                             solution_linearithmic::solve, 10'000);
}
