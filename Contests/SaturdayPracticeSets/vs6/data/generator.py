#!/usr/bin/python3
import sys
import random

random.seed(int(sys.argv[-1]))

typ = sys.argv[1]

if typ == "fix":
    n = eval(sys.argv[2])
    e = eval(sys.argv[3])
    print(n, e)

if typ == "rand":
    min_n = eval(sys.argv[2])
    max_n = eval(sys.argv[3])
    min_e = eval(sys.argv[4])
    max_e = eval(sys.argv[5])
    n = random.randint(min_n, max_n)
    e = random.randint(min_e, max_e)
    print(n, e)
