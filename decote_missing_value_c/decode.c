#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
    const char *girdiDosyaAdi = "genisletilmis_veri.csv";
    const char *ciktiDosyaAdi = "cikti.csv";

    // Zamanı kaydetmek için iki değişken
    clock_t baslangic_zamani, bitis_zamani;

    // Başlangıç zamanını kaydet
    baslangic_zamani = clock();

    FILE *girdiDosya = fopen(girdiDosyaAdi, "r");
    if (girdiDosya == NULL) {
        perror("Girdi dosyasını açarken hata oluştu");
        return 1;
    }

    FILE *ciktiDosya = fopen(ciktiDosyaAdi, "w");
    if (ciktiDosya == NULL) {
        perror("Çıktı dosyasını açarken hata oluştu");
        fclose(girdiDosya);
        return 1;
    }

    char satir[2000];

    while (fgets(satir, sizeof(satir), girdiDosya)) {
        char* temp = satir;

        while (*temp) {
            if (*temp == ',' && (temp == satir || *(temp - 1) == ',')) {
                fprintf(ciktiDosya, "-999,");
            } else {
                fprintf(ciktiDosya, "%c", *temp);
            }

            temp++;
        }

        fprintf(ciktiDosya, "\n");
    }

    fclose(girdiDosya);
    fclose(ciktiDosya);

    // Bitiş zamanını kaydet
    bitis_zamani = clock();

    // İşlem süresini hesapla ve yazdır
    double sure = (double)(bitis_zamani - baslangic_zamani) / CLOCKS_PER_SEC;
    printf("Boş özelliklere -999 atandı ve çıktı dosyasına yazıldı. İşlem süresi: %.2f saniye\n", sure);

    return 0;
}
