from itertools import combinations
import numpy as np
import sys

def solve1(k): return [
    '_' if x1 is '_' else 
    '1' if x1=='0' else '0' 
    for x1 in k
]

class Quantum():
    def __init__(self, y):
        self.k = ['_'] * y
        self.st = list(range(y))
        self.read(10)
        self.run()

    def read(self, n):
        for _ in range(n):
            i = self.st.pop()
            self.k[i] = self.solvebi(i+1)
            self.st = self.st[::-1]
        self.update_states()

    def solvebi(self, i):
        print(i, flush=True)
        return input()

    def update_states(self):
        self.n1  = solve1(self.k)
        self.n2 = self.n1[::-1]
        self.n3  = solve1(self.n2)
        self.n4 = [self.k, self.n1, self.n2, self.n3]

    def calculate(self):
        a = list(set(range(y)) - set(self.st))
        b = len(set(map(tuple, self.n4)))
        for c1 in combinations(a, 2):
            c = len(set(
                tuple(np.take(y1, c1))
                for y1 in self.n4
            ))
            if c == b: return c1

    def cash(self):        
        p = self.calculate()
        q = [self.solvebi(i+1) for i in p]
        
        self.k = next(y1
            for y1 in self.n4
            if q == list(np.take(y1, p))
        )

    def run(self):
        while True:
            self.cash()
            try: self.read(8)
            except IndexError: break
    

x, y = map(int, input().split())
print('y:', y, file=sys.stderr)
for _ in range(x): 
    arr = Quantum(y)
    print('guess:', ''.join(arr.k), file=sys.stderr)
    print(''.join(arr.k), flush=True)
    if input() == 'N': sys.exit()
