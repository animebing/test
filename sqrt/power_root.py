#!/usr/bin/python3
import sys

# absolute difference between two numbers
def _abs(diff):
    return diff if diff >= 0 else -diff

# only consider n is positive integer, data power to n
def _power(data, n):
    if n == 0: return 1
    if n == 1: return data
    return _power(data * data, n // 2) if n % 2 == 0 else data * _power(data * data, (n - 1) // 2)

# gradient of x power to n when x is data
def _grad(data, n):
    return n * _power(data, n - 1)

data = float(sys.argv[1])
n = int(sys.argv[2])

# I don't figure out the influence of the initial x_0
x_0 = 10.0
y_0 = _power(x_0, n) - data
epsilon = 1e-8

while True:
    x_1 = x_0 - y_0 / _grad(x_0, n)
    abs_diff = _abs(x_0 - x_1)
    if abs_diff < epsilon:
        print("my answer: %.15f, power with python: %.15f" % (x_1, _abs(_power(x_1, n) - data)))
        break

    x_0 = x_1
    y_0 = _power(x_0, n) - data





