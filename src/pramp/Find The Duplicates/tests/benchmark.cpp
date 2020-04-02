//
// Copyright (C) 2020 Ruslan Manaev (manavrion@gmail.com)
// This file is part of https://github.com/manavrion/algorun repository
//

#include <benchmark/benchmark.h>

#include "test_generator.h"

using namespace pramp_find_the_duplicates_test;

static void BM_FindTheDuplicates_Linear(benchmark::State& state) {
  TestGenerator generator;
  for (auto _ : state) {
    generator.RunSolution(solution_linear::solve);
  }
}

BENCHMARK(BM_FindTheDuplicates_Linear);

static void BM_FindTheDuplicates_Linearithmic(benchmark::State& state) {
  TestGenerator generator;
  for (auto _ : state) {
    generator.RunSolution(solution_linearithmic::solve);
  }
}

BENCHMARK(BM_FindTheDuplicates_Linearithmic);

static const TestGenerator::Dist kSpecialDist = {
    .a_size = TestGenerator::dist_t<size_t>{10000, 20000},
    .b_size = TestGenerator::dist_t<size_t>{0, 100},
    .a_val = TestGenerator::dist_t<int>{-10, 10},
    .b_val = TestGenerator::dist_t<int>{-10, 10}};

static void BM_FindTheDuplicates_Linear_Special(benchmark::State& state) {
  TestGenerator generator;
  generator.dist = kSpecialDist;
  for (auto _ : state) {
    generator.RunSolution(solution_linear::solve);
  }
}

BENCHMARK(BM_FindTheDuplicates_Linear_Special);

static void BM_FindTheDuplicates_Linearithmic_Special(benchmark::State& state) {
  TestGenerator generator;
  generator.dist = kSpecialDist;
  for (auto _ : state) {
    generator.RunSolution(solution_linearithmic::solve);
  }
}

BENCHMARK(BM_FindTheDuplicates_Linearithmic_Special);