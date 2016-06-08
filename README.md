# HaskellQuicksort
Comparison between C, Haskell and Prolog implementations of quicksort

# Compiling
gcc -o permutation permutation.c 
gcc -o quick quicksort.c

# Instructions
1.  Define the array size at permutation.c (line 4) and then run the permutation.c (./permutation);
2.  Run:
  1. C: Change input file (line 14) and then run quicksort.c (./quick);
  2. Prolog: Open quicksortN.pl and query the clause "check" (N = Base array size).
  3. Haskell: Change the input file (line 14) and then run function "main".

# Results
![plot](newplot.png)

Analitic result:
Language|5|6|7|8|9|
-----|------|-------|---------|---------|---------|
C	| 0.000000 s	| 0.000000 s	| 0.015000 s	| 0.062000 s |	0.453000 s|
Prolog	| 0.000000 s |	0.015000 s |	0.160000 s |	2.468000 s |	30708* s|
Haskell	| 0.0000000 s	| 0.0157007 s |	0.0243243 s	| 0.0306376 s	| 0.0307905 s|

  
