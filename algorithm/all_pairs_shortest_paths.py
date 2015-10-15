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
    L = [None] * n
    L[0] = np.empty((n, n))
    for i in range(0, n):
        for j in range(0, n):
            if i == j:
                L[0][i, j] = 0
            else:
                L[0][i, j] = float("Inf")
    L[1] = W
    for m in range(2, n):
        L[m] = extend_shortest_paths(L[m - 1], W)
    return L

def extend_shortest_paths_with_predecessor_subgraph(L, P, W):
    n = W.shape[0]
    LW = np.empty((n, n))
    PP = np.empty((n, n))
    for i in range(0, n):
        for j in range(0, n):
            LW[i, j] = float("Inf")
            PP[i, j] = None
            for k in range(0, n):
                if LW[i, j] > L[i, k] + W[k, j]:
                    LW[i, j] = L[i, k] + W[k, j]
                    PP[i, j] = k + 1
            if LW[i, j] == L[i, j]:
                PP[i, j] = P[i, j]
#                    if j == i:
#                        PP[i, j] = None
#                    elif j != k:
#                        PP[i, j] = k + 1
#                    else:
#                        PP[i, j] = P[i, j]
    return LW, PP

def slow_all_pairs_shortest_paths_with_predecessor_subgraph(W):
    n = W.shape[0]
    L = np.empty((n, n))
    P = np.empty((n, n))
    for i in range(0, n):
        for j in range(0, n):
            if j == i:
                L[i, j] = 0
            else:
                L[i, j] = float("Inf")
            P[i, j] = None
    for m in range(1, n):
        L, P = extend_shortest_paths_with_predecessor_subgraph(L, P, W)
        print L
        print P
    return L, P

def predecessor(W, L):
    n = W.shape[0]
    P = np.empty((n, n))
    COMPLETED = np.empty((n, n), dtype = bool)
    DEPTH = np.empty((n, n))
    for i in range(0, n):
        for j in range(0, n):
            COMPLETED[i, j] = False
            DEPTH[i, j] = None
            P[i, j] = None
    for i in range(0, n):
        P[i, i] = None
        COMPLETED[i, i] = True
        DEPTH[i, i] = 0
    for m in range(1, n):
        for i in range(0, n):
            for j in range(0, n):
                if i == 0:
                    print m
                    print COMPLETED[i, j]
                    print L[m][i]
                    print L[n - 1][j]
                if COMPLETED[i, j] == False and L[m][i, j] == L[n - 1][i, j]:
                    for k in range(0, n):
                        if DEPTH[i, k] == m - 1 and L[m][i, j] == L[m -1][i, k] + W[k, j]:
                            DEPTH[i, j] = m
                            P[i, j] = k + 1
                            COMPLETED[i, j] = True
                            break
    return P
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
