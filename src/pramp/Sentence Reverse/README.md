# Sentence Reverse

Source: https://www.pramp.com/challenge/VKdqbrq6B1S5XAyGAOn4

## Solution with indexes

Time complexity: O(n)

Space complexity: O(1) but inplace

## Solution with iterators

Time complexity: O(n)

Space complexity: O(1) but inplace

## Benchmark
```
------------------------------------------------------------------------------------
Benchmark                                          Time             CPU   Iterations
------------------------------------------------------------------------------------
BM_SentenceReverseBenchmark_Indexes             7068 ns         7047 ns        96165
BM_SentenceReverseBenchmark_Iterators           6836 ns         6821 ns       101583
BM_SentenceReverseBenchmark_Indexes_Big       694118 ns       692370 ns         1029
BM_SentenceReverseBenchmark_Iterators_Big     674573 ns       672912 ns         1045
```
