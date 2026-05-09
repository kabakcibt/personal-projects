#MARKET STOK TAKIBI
print("==========  MARKET STOK TAKIBI  ==========")

market_urunleri = []
# Listeye urun ekleme ve fiyat belirleme
market_urunleri.append({"ad": "\n  Sut", "fiyat": 20.0, "stok": 4})
market_urunleri.append({"ad": "\n  Et", "fiyat": 30.0, "stok": 7})
market_urunleri.append({"ad": "\n  Yumurta", "fiyat": 15.0, "stok": 9})
market_urunleri.append({"ad":"\n  Cikolata", "fiyat":15.0, "stok": 6})
market_urunleri.append({"ad":"\n  Peynir", "fiyat":15.0, "stok": 3})
market_urunleri.append({"ad":"\n  Makarna", "fiyat":15.0, "stok": 2})
market_urunleri.append({"ad":"\n  Yogurt", "fiyat":15.0, "stok": 5})

print("Market Urunleri: \n")
toplam_stok = 0

for urun in market_urunleri:
    print(f"Urun: {urun['ad']}, Fiyat: {urun['fiyat']} TL, Stok: {urun['stok']}")
    
    if urun['stok'] < 5:
        print(f"Stok Uyarisi: {urun['ad']} urunu stokta az kaldi ({urun['stok']})\n")
    
    toplam_stok += urun['fiyat'] * urun['stok'] # Market urunlerinde ki toplam stok degeri

print(f"\n Toplam Stok Degeri: {toplam_stok} TL")
