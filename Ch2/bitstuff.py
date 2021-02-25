def setbits(x, p, n, y):
    o = x
    m = 0
    for i in range(n):
        m = (m << 1) + 1
    k = m & y
    t = p + n
    x >>= t
    x <<= t
    x |= (k << p)
    for i in range(p): # 0 1 2
        m = 1 << i # 1 10 100
        if o & m > 0: # 010 001 / 010 010 / 010 100
            x |= m
    return x


x = 1234
y = 543
n = 4
p = 3
print(bin(setbits(x, p, n, y)))
