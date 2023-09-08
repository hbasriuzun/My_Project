char** veri_oku_c(char dosya_ismi[]) {
    FILE *dosya = fopen(dosya_ismi, "r");
    if (!dosya) {
        perror("Dosyayı açarken hata oluştu");
        exit(1);
    }

    char satir[80];
    char **veri = NULL;
    size_t veriBoyut = 0;

    while (fgets(satir, sizeof(satir), dosya)) {
        veri = (char **)realloc(veri, (veriBoyut + 1) * sizeof(char *));
        if (!veri) {
            perror("Veri vektörünü yeniden boyutlandırırken hata oluştu");
            fclose(dosya);
            exit(1);
        }
        
        // Veriyi virgülle ayır ve boş kısımları NULL olarak işaretle
        char* token = strtok(satir, ",");
        while (token != NULL) {
            // Boş olan kısmı NULL olarak işaretle
            if (strlen(token) == 0 || (strlen(token) == 1 && token[0] == '\n')) {
                veri[veriBoyut] = NULL;
            } else {
                veri[veriBoyut] = strdup(token);
            }
            
            if (!veri[veriBoyut]) {
                perror("Veri kopyalama sırasında hata oluştu");
                fclose(dosya);
                exit(1);
            }
            
            // Bir sonraki virgülle ayrılmış parçayı al
            token = strtok(NULL, ",");
            veriBoyut++;
        }
    }

    fclose(dosya);

    printf("Veri boyutu: %zu\n", veriBoyut);
    
    // Verinin sonunu belirlemek için NULL işareti ekleyin
    veri = (char **)realloc(veri, (veriBoyut + 1) * sizeof(char *));
    if (!veri) {
        perror("Veri vektörünü yeniden boyutlandırırken hata oluştu");
        exit(1);
    }
    veri[veriBoyut] = NULL;

    return veri;
}