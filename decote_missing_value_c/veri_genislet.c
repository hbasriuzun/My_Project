#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
    const char *girdiDosyaAdi = "loan.csv"; // Verinin olduğu CSV dosya adı
    const char *ciktiDosyaAdi = "genisletilmis_veri.csv"; // Genişletilmiş veriyi yazacağınız CSV dosya adı

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

    char satir[4096];

    while (fgets(satir, sizeof(satir), girdiDosya)) {
        char *ptr = strtok(satir, "\n"); // Satır sonundaki new line karakterini kaldır
        for (int i = 0; i < 3; i++) { // Her satırı 3 kez aşağı doğru kopyala
            fputs(ptr, ciktiDosya); // İlk olarak satırı olduğu gibi kopyala
            fputs(",", ciktiDosya); // Virgül ekleyerek aynı satırı bir kez daha kopyala
            fputs(ptr, ciktiDosya); // Bir kez daha aynı satırı kopyala
            fputs(",", ciktiDosya); // Virgül ekleyerek bir kez daha aynı satırı kopyala
            fputs(ptr, ciktiDosya); // Ve son kez aynı satırı kopyala
            fputs("\n", ciktiDosya); // Her satırın sonuna yeni satır karakteri ekle
        }
    }

    fclose(girdiDosya);
    fclose(ciktiDosya);

    // Bitiş zamanını kaydet
    bitis_zamani = clock();

    // İşlem süresini hesapla ve yazdır
    double sure = (double)(bitis_zamani - baslangic_zamani) / CLOCKS_PER_SEC;
    printf("Veri hem sağa hem de aşağı doğru genişletildi. İşlem süresi: %.2f saniye\n", sure);

    return 0;
}
