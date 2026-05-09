karakterler = [
    {"isim": "Aragorn", "sinif": "savasci", "seviye": 15, "hp": 220, "altin": 500},
    {"isim": "Gandalf", "sinif": "buyucu", "seviye": 20, "hp": 140, "altin": 300},
    {"isim": "Legolas", "sinif": "okcu", "seviye": 12, "hp": 160, "altin": 550},
    {"isim": "Gimli", "sinif": "savasci", "seviye": 10, "hp": 200, "altin": 600},
    {"isim": "Thranduil", "sinif": "okcu", "seviye": 14, "hp": 175, "altin": 900},
    {"isim": "Saruman", "sinif": "buyucu", "seviye": 18, "hp": 130, "altin": 800}
] # Karakter listesi, karakterler 

# Lambda ile istenilen fonksiyonlar
okcu_mu = lambda x: x["sinif"] == "okcu"                        # Okcu olup olmadigini kontrol eder.
guclu_mu = lambda x: x["seviye"] > 10 and x["hp"] > 150         # Guclu olup olmadigini kontrol eder.

# List comprehension ile istenen veriler


# 1) # Seviyesi 15'ten buyuk karakter isimleri
highlevel_chars = [y["isim"] for y in karakterler if y["seviye"] > 15]    # 15' level ustu olan karakterleri listeler.

# 2) # Zengin - Fakir etiketleme
tagged_chars = [
    (z["isim"], "zengin" if z["altin"] > 500 else "fakir")          # 500 altindan fazla olan karakterlere zengin veya fakir etiketi verir.
    for z in karakterler
]
print("Yuksek seviye:", highlevel_chars)
print("Etiketler:", tagged_chars)