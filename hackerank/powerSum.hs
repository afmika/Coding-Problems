{-# LANGUAGE DuplicateRecordFields, FlexibleInstances, UndecidableInstances #-}

module Main where

import Control.Monad
import Debug.Trace
import System.Environment
import System.IO
import System.IO.Unsafe

dfs c x n
    | left <= 0 = if left == 0 then 1 else 0
    | otherwise = sum $ map ((flip next) n) [left, x]
        where 
            left = x - c^n
            next = dfs (c + 1)

-- currification goes brrrr
powerSum = dfs 1


main :: IO()
main = do
    stdout <- getEnv "OUTPUT_PATH"
    fptr <- openFile stdout WriteMode

    xtemp <- getLine
    let x = read $ xtemp :: Int
    ntemp <- getLine
    let n = read $ ntemp :: Int

    let result = powerSum x n
    hPutStrLn fptr $ show result

    hFlush fptr
    hClose fptr
