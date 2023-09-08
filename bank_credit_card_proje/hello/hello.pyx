cimport libc.stdlib
from libc.stdlib cimport malloc, free
from cv2 import cv2

def fib_Ologn(n):
    return _fib_Ologn(n)


def say_hello_to(name):
    print("Hello %s!" % name)

def one_to_ten():
    cdef int a = 0
    for i in range(10):
        a += i
    print(a)
    print(fib_cython(10))


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


cdef long _fib_Ologn(long n):
    cdef long[:, :] F = <long[:2, :2]> malloc(2 * sizeof(long) * 2 * sizeof(long))
    if n == 0:
        result = 0
    else:
        F[0][0] = 1
        F[0][1] = 1
        F[1][0] = 1
        F[1][1] = 0
        power(F, n - 1)
        result = F[0][0]

    return result

cdef void multiply(long[:, :] F, long[:, :] M):
    cdef long x = F[0][0] * M[0][0] + F[0][1] * M[1][0]
    cdef long y = F[0][0] * M[0][1] + F[0][1] * M[1][1]
    cdef long z = F[1][0] * M[0][0] + F[1][1] * M[1][0]
    cdef long w = F[1][0] * M[0][1] + F[1][1] * M[1][1]

    F[0][0] = x
    F[0][1] = y
    F[1][0] = z
    F[1][1] = w

cdef void power(long[:, :] F, long n):
    cdef long[:, :] M = <long[:2, :2]> malloc(2 * sizeof(long) * 2 * sizeof(long))
    M[0][0] = 1
    M[0][1] = 1
    M[1][0] = 1
    M[1][1] = 0
    if n == 0 or n == 1:
        return
    power(F, n // 2)
    multiply(F, F)
    if n % 2 != 0:
        multiply(F, M)



cdef void matrix_multiply(int[:, ::1] A, int[:, ::1] B, int[:, ::1] result):
    cdef int m = A.shape[0]  # İlk matrisin satır sayısı
    cdef int n = A.shape[1]  # İlk matrisin sütun sayısı
    cdef int p = B.shape[1]  # İkinci matrisin sütun sayısı

    cdef int i, j, k

    # Matris çarpımını hesapla
    for i in range(m):
        for j in range(p):
            result[i, j] = 0
            for k in range(n):
                result[i, j] += A[i, k] * B[k, j]

def matrix_multiply_cython(A, B, result):
    matrix_multiply(A, B, result)
