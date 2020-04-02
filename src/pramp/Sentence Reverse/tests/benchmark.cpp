//
// Copyright (C) 2020 Ruslan Manaev (manavrion@gmail.com)
// This file is part of https://github.com/manavrion/algorun repository
//

#include <benchmark/benchmark.h>

#include "test_generator.h"

using namespace pramp_sentence_reverse_test;

static void BM_SentenceReverseBenchmark_Indexes(benchmark::State& state) {
  TestGenerator generator;
  for (auto _ : state) {
    generator.RunSolution(solution_indexes::reverseWords);
  }
}

BENCHMARK(BM_SentenceReverseBenchmark_Indexes);

static void BM_SentenceReverseBenchmark_Iterators(benchmark::State& state) {
  TestGenerator generator;
  for (auto _ : state) {
    generator.RunSolution(solution_iterators::reverseWords);
  }
}

BENCHMARK(BM_SentenceReverseBenchmark_Iterators);

static const TestGenerator::Dist kBigDist = {
    .space_size = TestGenerator::dist_t<size_t>{1, 100},
    .word_size = TestGenerator::dist_t<size_t>{1, 100},
    .total_size = TestGenerator::dist_t<size_t>{0, 100000},
    .chars = TestGenerator::dist_t<char>{'a', 'z'}};

static void BM_SentenceReverseBenchmark_Indexes_Big(benchmark::State& state) {
  TestGenerator generator;
  generator.dist = kBigDist;
  for (auto _ : state) {
    generator.RunSolution(solution_indexes::reverseWords);
  }
}

BENCHMARK(BM_SentenceReverseBenchmark_Indexes_Big);

static void BM_SentenceReverseBenchmark_Iterators_Big(benchmark::State& state) {
  TestGenerator generator;
  generator.dist = kBigDist;
  for (auto _ : state) {
    generator.RunSolution(solution_iterators::reverseWords);
  }
}

BENCHMARK(BM_SentenceReverseBenchmark_Iterators_Big);
