# Array Quadruplet

Source: https://www.pramp.com/challenge/gKQ5zA52mySBOA5GALj9

## Naive solution

Time complexity: O(n^4)

Space complexity: O(1) but inplace

## Cubic and log solution

Time complexity: O(n^3 log n)

Space complexity: O(1) but inplace

## Cubic solution

Time complexity: O(n^3)

Space complexity: O(1) but inplace

## Quadratic solution

Time complexity: best case - O(n^2), worst case - O(n^4)

Space complexity: O(n^2)

## Benchmark
```
-----------------------------------------------------------------------------
Benchmark                                   Time             CPU   Iterations
-----------------------------------------------------------------------------
BM_ArrayQuadruplet_Naive                11234 ns        11068 ns        60998
BM_ArrayQuadruplet_CubicAndLog           4376 ns         4326 ns       150849
BM_ArrayQuadruplet_Cubic                 2585 ns         2548 ns       274580
BM_ArrayQuadruplet_Quadratic           731963 ns       722390 ns          914
BM_ArrayQuadruplet_Naive_Big       2149803341 ns   2139712236 ns            1
BM_ArrayQuadruplet_CubicAndLog_Big  511350385 ns    509082012 ns            4
BM_ArrayQuadruplet_Cubic_Big         56448714 ns     56220566 ns           10
BM_ArrayQuadruplet_Quadratic_Big      8298268 ns      8255393 ns           71
```
