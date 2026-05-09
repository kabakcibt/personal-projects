
def password_length(sifre): #Sifre uzunlugu
    """
    Sifrenin en az 8 karakter olup olmadigini kontrol eder. 
    """
    return len(sifre) >= 8

def capitalization_control(sifre): #Buyuk harf kontrolü
    """
    Sifrede buyuk harf olup olmadigini kontrol eder. True veya False döndürür.
    """
    for harf in sifre:
        if harf.isupper():
            return True
    return False

def lowercase_control(sifre): #Kucuk harf kontrolu
    """
    Sifrede kucuk harf olup olmadigini kontrol eder. True veya False döndürür.
    """
    for harf in sifre:
        if harf.islower():
            return True
    return False

def figure_control(sifre): #Rakam kontrolu
    """
    Sifrede rakam olup olmadigini kontrol eder. True veya False döndürür.
    """
    for harf in sifre:
        if harf.isdigit():
            return True
    return False

def password_control(sifre): #Sifre Kontrolu
    """
    Sifre kurallarini kontrol eder. Eksik kurallari listeler.
    """
    eksikler = []

    if not password_length(sifre):
        eksikler.append("Sifre en az 8 karakter uzulugunda olmalidir.")

    if not capitalization_control(sifre):
        eksikler.append("Sifre en az 1 buyuk harf icermelidir.")

    if not lowercase_control(sifre):
        eksikler.append("Sifre en az 1 kucuk harf icermelidir.")

    if not figure_control(sifre):
        eksikler.append("Sifre en az 1 rakam icermelidir.")

    return eksikler

sifre = input("Sifre giriniz: ") # Kullanıcıdan şifre alma
result = password_control(sifre)

if len(result) == 0:
    print("Sifre Gecerli")
else:
    print("Sifre Gecerli Degil\n")
    print("Gecersiz olma sebepleri:")
    for error in result:
        print("-", error)