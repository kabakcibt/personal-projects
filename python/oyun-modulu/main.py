import oyun_modulu as om


def menu():
    print("\n===== ŞANS OYUNLARI =====")
    print("1 - Sayi Tahmin")
    print("2 - Yazi Tura")
    print("3 - Skorlari Göster")
    print("4 - Cikis")


def main():
    print("Oyun Basladi")

    oyuncu = input("Oyuncu adi: ")

    while True:
        menu()
        secim = input("Secim: ")

        if secim == "1":
            om.sayi_tahmin(oyuncu)

        elif secim == "2":
            om.yazi_tura(oyuncu)

        elif secim == "3":
            om.skor_goster()

        elif secim == "4":
            print("Cikis yapiliyor...")
            break
        
        else:
            print("Gecersiz secim!")

if __name__ == "__main__":
    main()