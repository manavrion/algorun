//
// Copyright (C) 2020 Ruslan Manaev (manavrion@gmail.com)
// This file is part of https://github.com/manavrion/algorun repository
//

#include <gtest/gtest.h>

#include "test_generator.h"

using namespace pramp_sentence_reverse_test;

TEST(Pramp, SentenceReverseTestIndexesVsIterators) {
  TestGenerator generator;
  generator.CompareSolutions(solution_indexes::reverseWords,
                             solution_iterators::reverseWords, 100'000);
}
