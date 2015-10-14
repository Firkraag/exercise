import numpy as np

def extend_shortest_paths(L, W):
    n = L.shape[0]
    LW = np.empty((n, n)) 
    for i in range(0, n):
        for j in range(0, n):
            LW[i, j] = float("Inf")
            for k in range(0, n):
                LW[i, j] = min(LW[i, j], L[i, k] + W[k, j])
    return LW

def slow_all_pairs_shortest_paths(W):
    n = W.shape[0]
    L = W
    for m in range(2, n):
        L = extend_shortest_paths(L, W)
    return L

def faster_all_pairs_shortest_paths(W):
    n = W.shape[0]
    L = W
    m = 1
    while m < n - 1:
        L = extend_shortest_paths(L, L)
        m = 2 * m
        print m
        print L
    return L
