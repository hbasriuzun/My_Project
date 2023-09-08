from hello import fib_Ologn
from hello import matrix_multiply_cython

import numpy as np
import time

start_time = time.time()*1000
print(fib_Ologn(13))
end_time = time.time()*1000
elapsed_time = (end_time - start_time)*1000
print(f"fonksiyonu {elapsed_time:.4f} mikrosaniye sürdü.")

# İki matrisi oluştur
A = np.array([[23, 2], [3, 60]], dtype=np.int32)
B = np.array([[13, 6], [58, 8]], dtype=np.int32)

# Sonuç matrisini oluştur
result = np.zeros((2, 2), dtype=np.int32)

start_time = time.time()*1000
# Matris çarpımını hesapla
matrix_multiply_cython(A, B, result)
end_time = time.time()*1000
elapsed_time = (end_time - start_time)*1000

start_time = time.time()*1000
# Matris çarpımını hesapla
np.dot(A, B)
end_time = time.time()*1000
elapsed_time2 = (end_time - start_time)*1000

print("A:")
print(A)
print("B:")
print(B)
print("Çarpım:")
print(result)
print(f"matrix_multiply fonksiyonu {elapsed_time:.4f} mikrosaniye sürdü.")
print(f"np_dot fonksiyonu {elapsed_time2:.4f} mikrosaniye sürdü.")

