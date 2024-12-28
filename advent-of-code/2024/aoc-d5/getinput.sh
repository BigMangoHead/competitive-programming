#!/bin/bash

cd /home/bigma/coding/comp/advent-of-code/2024/aoc-d5
cd A
curl https://adventofcode.com/2024/day/5/input --cookie "session=53616c7465645f5ffc77fb06b313b44143ef1dca5d83ff11308bea339a264950432b82cfc404323d17cb47af1460f66405ae51bba3c5644bb4f1535cdf4e53db" -o 1.in
touch 1.out
cd ../B
cp ../A/1.in .
touch 1.out