import Data.Time

quicksort :: Ord a => [a] -> [a]
quicksort [] = []
quicksort (p:xs) = (quicksort lesser) ++ [p] ++ (quicksort greater)
    where
        lesser  = filter (< p) xs
        greater = filter (>= p) xs

wordtolist string = map read $ words string :: [Int]

main = do
          start <- getCurrentTime
          vet <- readFile "permutation_n7.txt"                            
          let a = lines vet
          let b = map(wordtolist) a
          let c = map(quicksort) b
          stop <- getCurrentTime
          print $ diffUTCTime stop start