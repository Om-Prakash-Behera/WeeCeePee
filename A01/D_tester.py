from itertools import permutations


def inversion_count(arr):
    n = len(arr)
    inv = 0

    for i in range(n):
        for j in range(i + 1, n):
            if arr[i] > arr[j]:
                inv += 1

    return inv


t = int(input())

for _ in range(t):
    n, k = map(int, input().split())

    # Build array a
    a = list(range(1, k + 1))

    for x in range(k - 1, k - (n - k) - 1, -1):
        a.append(x)

    inv_a = inversion_count(a)

    best_p = None
    best_b = None

    # Try all permutations
    for p in permutations(range(1, k + 1)):

        # permutation mapping:
        # value x -> p[x-1]
        b = [p[x - 1] for x in a]

        inv_b = inversion_count(b)

        # valid condition
        if inv_b <= inv_a:

            # maximize lexicographically
            if best_b is None or b > best_b:
                best_b = b
                best_p = p

    print(*best_p)