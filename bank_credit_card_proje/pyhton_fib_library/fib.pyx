# fib_cython.pyx

cdef long fib_cython(int n):
    cdef long a = 0
    cdef long b = 1
    cdef long temp
    cdef int i

    if n <= 0:
        return 0

    for i in range(2, n + 1):
        temp = a + b
        a = b
        b = temp

    return b
