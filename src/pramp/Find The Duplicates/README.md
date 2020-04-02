# Find The Duplicates

Source: https://www.pramp.com/challenge/15oxrQx6LjtQj9JK9XlA

## Linear solution

Time complexity: O(n + m)

Space complexity: O(1) but O(min(n, m)) for answer

## Linearithmic solution

Time complexity: O(n log m) where n << m

Space complexity:  O(1) but O(min(n, m)) for answer

## Benchmark
```
-----------------------------------------------------------------------------
Benchmark                                   Time             CPU   Iterations
-----------------------------------------------------------------------------
BM_FindTheDuplicates_Linear                    39706 ns        39687 ns        17810
BM_FindTheDuplicates_Linearithmic              40883 ns        40862 ns        17125
BM_FindTheDuplicates_Linear_Special           577594 ns       577199 ns         1213
BM_FindTheDuplicates_Linearithmic_Special     565318 ns       564920 ns         1243
```
