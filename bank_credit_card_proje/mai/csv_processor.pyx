# csv_processor.pyx
cimport libc.stdlib
from cpython.bytes cimport PyBytes_FromString

cdef extern from "loan.c":
    int main()
    char*** veri_oku_c(char* dosya_ismi)

def veri_oku_py(dosya_ismi):
    # C tarafından gelen veriyi al
    cdef char*** data_char = veri_oku_c(dosya_ismi.encode('utf-8'))  # Python stringini bytes'a çevir
        
    # Veriyi saklamak için 2 boyutlu bir liste oluştur
    data_list = []
    
    # Satır ve sütun sayılarını elde et
    cdef int satir_sayisi = 0
    cdef int sutun_sayisi = 0
    
    cdef int i, j
    cdef char* cell
    cdef bytes cell_bytes
    cdef str cell_str

    # C veri yapısını Python veri yapısına dönüştür
    while data_char[satir_sayisi] is not NULL:
        data_list.append([])
        sutun_sayisi = 0
        while data_char[satir_sayisi][sutun_sayisi] is not NULL:
            cell = data_char[satir_sayisi][sutun_sayisi]
            cell_bytes = PyBytes_FromString(cell)
            cell_str = cell_bytes.decode('utf-8')
            data_list[satir_sayisi].append(cell_str)
            sutun_sayisi += 1
        satir_sayisi += 1

    # Dönüştürülmüş veriyi Python tarafına aktar
    return data_list
