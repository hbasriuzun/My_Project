#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_COLS 30
#define MAX_COL_LEN 40

// Veriyi okuma işlemi
char *** veri_oku_c(const char * dosya_ismi) {
    FILE * dosya = fopen(dosya_ismi, "r");
    if (!dosya) {
        perror("Dosya açılırken hata oluştu");
        exit(1);
    }

    // Satır sayısını başlangıçta sıfır olarak ayarla
    int satirSayisi = 0;
    char satir[MAX_COLS * MAX_COL_LEN];

    // Maksimum sütun sayısını başlangıçta sıfır olarak ayarla
    int maksimumSutunSayisi = 0;

    // Dosyadan veriyi oku ve satır/sütun sayılarını belirle
    while (fgets(satir, sizeof(satir), dosya)) {
        satirSayisi++;

        // Virgülle ayrılmış özellikleri sayarak maksimum sütun sayısını güncelle
        char * token = strtok(satir, ";");
        int col = 0;
        while (token != NULL) {
            token = strtok(NULL, ";");
            col++;
        }
        if (col > maksimumSutunSayisi) {
            maksimumSutunSayisi = col;
        }
    }

    // Dosyayı yeniden aç ve verileri matrise yerleştir
    fseek(dosya, 0, SEEK_SET);  // Dosyayı başa al

    // Veriyi saklamak için bellek tahsisi yap
    char *** matrix = (char ***) malloc(satirSayisi * sizeof(char **));
    if (!matrix) {
        perror("Matris için bellek tahsis edilemedi");
        exit(1);
    }

    // Dosyadan veriyi oku ve matrise yerleştir
    for (int i = 0; i < satirSayisi; i++) {
        fgets(satir, sizeof(satir), dosya);

        // Satır sonundaki '\n' karakterini kaldır
        char * newline = strchr(satir, '\n');
        if (newline) {
            *newline = '\0';
        }

        // Bellek tahsis et ve veriyi matrise yerleştir
        matrix[i] = (char **) malloc((maksimumSutunSayisi + 1) * sizeof(char *));
        if (!matrix[i]) {
            perror("Satır için bellek tahsis edilemedi");
            fclose(dosya);
            exit(1);
        }

        // Virgülle ayrılmış özellikleri parçala ve matrise yerleştir
        char * token = strtok(satir, ";");
        int col = 0;
        while (token != NULL) {
            matrix[i][col] = (char *) malloc(MAX_COL_LEN * sizeof(char));
            if (!matrix[i][col]) {
                perror("Sütun için bellek tahsis edilemedi");
                fclose(dosya);
                exit(1);
            }

            strcpy(matrix[i][col], token);
            token = strtok(NULL, ";");
            col++;
        }
        matrix[i][col] = NULL;
    }

    fclose(dosya);

    // Satır ve sütun sayılarını döndür

    return matrix;
}

// Veriyi yazma işlemi
void veri_yaz(char *** veri_matrisi, int satir_sayisi, int sutun_sayisi, const char* dosya_ismi) {
    FILE* dosya = fopen(dosya_ismi, "w");
    if (!dosya) {
        perror("Dosyayı açarken hata oluştu");
        exit(1);
    }

    // Veriyi CSV dosyasına yaz
    for (int i = 0; i < satir_sayisi; i++) {
        for (int j = 0; j < sutun_sayisi; j++) {
            fprintf(dosya, "%s", veri_matrisi[i][j]);

            // Her sütunu virgülle ayır, son sütunda virgül olmasın
            if (j < sutun_sayisi - 1) {
                fprintf(dosya, ";");
            }
        }
        fprintf(dosya, "\n");
    }

    fclose(dosya);
}

int main() {

    int satir_sayisi, sutun_sayisi;
    // Veriyi okuduktan sonra işlemler burada yapılabilir
    // Örnek olarak veriyi tekrar yazalım

    char *** veri = veri_oku_c("bank.csv");
    
    // Belleği temizle
    for (int i = 0; i < satir_sayisi; i++) {
        for (int j = 0; veri[i][j] != NULL; j++) {
            free(veri[i][j]);
        }
        free(veri[i]);
    }
    free(veri);

    return 0;
}




void veri_yaz2(char** veri, const char* dosya_ismi) {
    FILE* dosya = fopen(dosya_ismi, "w");
    if (!dosya) {
        perror("Dosyayı açarken hata oluştu");
        exit(1);
    }

    // Her bir veri satırını virgülle ayrılmış sütunlar olarak düzenli bir şekilde yaz
    for (size_t i = 0; veri[i] != NULL; i++) {
        char* satir = veri[i];
        size_t satirUzunlugu = strlen(satir);
        
        // Satırın sonundaki boşlukları temizle
        while (satirUzunlugu > 0 && isspace(satir[satirUzunlugu - 1])) {
            satirUzunlugu--;
        }
        
        // Satırı yaz
        fprintf(dosya, "%.*s\n", (int)satirUzunlugu, satir);
    }

    fclose(dosya);
}



void sadece_ilk_sutunu_yazdir(char** veri) {
    // Her bir veri satırının ilk sütununu yaz
    for (size_t i = 0; veri[i] != NULL; i++) {
        printf("%zu,%s\n", i + 1, strtok(veri[i], ","));
    }
}

// PyObject* veri_oku2(const char* dosya_ismi) {
//     FILE *dosya = fopen(dosya_ismi, "r");
//     if (!dosya) {
//         PyErr_SetString(PyExc_RuntimeError, "Dosyayı açarken hata oluştu");
//         return NULL;
//     }

//     char satir[256];
//     PyObject* pyList = PyList_New(0); // Boş bir Python liste oluştur

//     if (!pyList) {
//         PyErr_SetString(PyExc_RuntimeError, "Python liste oluştururken hata oluştu");
//         fclose(dosya);
//         return NULL;
//     }

//     while (fgets(satir, sizeof(satir), dosya)) {
//         // Veriyi uygun şekilde işleyip Python listesine eklemek için kod ekleyin
//         // Örneğin, virgülle ayrılmış sütunları ayırın ve uygun veri türlerine dönüştürün
//         // Sonuçları PyList_Append ile pyList'e ekleyin
//     }

//     fclose(dosya);

//     return pyList;
// }

// char* veri_oku3(){
//     return  "veri";
// }

// PyObject* charArrayToPythonList(char** charArray, int length) {
//     PyObject* pyList = PyList_New(length);

//     if (!pyList) {
//         PyErr_SetString(PyExc_RuntimeError, "Failed to create Python list");
//         return NULL;
//     }

//     for (int i = 0; i < length; i++) {
//         PyObject* pyString = PyUnicode_DecodeUTF8(charArray[i], strlen(charArray[i]), NULL);
        
//         if (!pyString) {
//             PyErr_SetString(PyExc_RuntimeError, "Failed to decode UTF-8 string");
//             Py_DECREF(pyList);
//             return NULL;
//         }

//         PyList_SetItem(pyList, i, pyString);
//     }

//     return pyList;
// }


