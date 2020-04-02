//
// Copyright (C) 2020 Ruslan Manaev (manavrion@gmail.com)
// This file is part of https://github.com/manavrion/algorun repository
//

#include <benchmark/benchmark.h>

#include "test_generator.h"

using namespace pramp_array_quadruplet_test;

static void BM_ArrayQuadruplet_Naive(benchmark::State& state) {
  TestGenerator generator;
  for (auto _ : state) {
    generator.RunSolution(solution_naive::findArrayQuadruplet);
  }
}

BENCHMARK(BM_ArrayQuadruplet_Naive);

static void BM_ArrayQuadruplet_CubicAndLog(benchmark::State& state) {
  TestGenerator generator;
  for (auto _ : state) {
    generator.RunSolution(solution_cubic_and_log::findArrayQuadruplet);
  }
}

BENCHMARK(BM_ArrayQuadruplet_CubicAndLog);

static void BM_ArrayQuadruplet_Cubic(benchmark::State& state) {
  TestGenerator generator;
  for (auto _ : state) {
    generator.RunSolution(solution_cubic::findArrayQuadruplet);
  }
}

BENCHMARK(BM_ArrayQuadruplet_Cubic);

static void BM_ArrayQuadruplet_Quadratic(benchmark::State& state) {
  TestGenerator generator;
  for (auto _ : state) {
    generator.RunSolution(solution_quadratic::findArrayQuadruplet);
  }
}

BENCHMARK(BM_ArrayQuadruplet_Quadratic);

static const TestGenerator::Dist kBigDist = {
    .sum = TestGenerator::dist_t<int>{20000, 30000},
    .val = TestGenerator::dist_t<int>{-100, 100},
    .size = TestGenerator::dist_t<size_t>{0, 1000}};

static void BM_ArrayQuadruplet_Naive_Big(benchmark::State& state) {
  TestGenerator generator;
  generator.dist = kBigDist;
  for (auto _ : state) {
    generator.RunSolution(solution_naive::findArrayQuadruplet);
  }
}

BENCHMARK(BM_ArrayQuadruplet_Naive_Big);

static void BM_ArrayQuadruplet_CubicAndLog_Big(benchmark::State& state) {
  TestGenerator generator;
  generator.dist = kBigDist;
  for (auto _ : state) {
    generator.RunSolution(solution_cubic_and_log::findArrayQuadruplet);
  }
}

BENCHMARK(BM_ArrayQuadruplet_CubicAndLog_Big);

static void BM_ArrayQuadruplet_Cubic_Big(benchmark::State& state) {
  TestGenerator generator;
  generator.dist = kBigDist;
  for (auto _ : state) {
    generator.RunSolution(solution_cubic::findArrayQuadruplet);
  }
}

BENCHMARK(BM_ArrayQuadruplet_Cubic_Big);

static void BM_ArrayQuadruplet_Quadratic_Big(benchmark::State& state) {
  TestGenerator generator;
  generator.dist = kBigDist;
  for (auto _ : state) {
    generator.RunSolution(solution_quadratic::findArrayQuadruplet);
  }
}

BENCHMARK(BM_ArrayQuadruplet_Quadratic_Big);
