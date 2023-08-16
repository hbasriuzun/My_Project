import pandas as pd


    # CSV dosyasını pandas ile okuma
data = pd.read_csv('bank-additional-full.csv',sep=";")

    # Verileri işleme ve çıktı üretme
for index, row in data.iterrows():
        print("Müşteri Adı:", row['job'])
        print("Yaş:", row['age'])
        print("Medeni Durum:", row['marital'])
        # Diğer verileri de benzer şekilde yazdırabilirsiniz
        print("------------------------------")


