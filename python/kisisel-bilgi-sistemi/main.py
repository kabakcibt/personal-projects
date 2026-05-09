print("== Kisisel Bilgiler == ")
name = str(input("What is your name?"))
surname = str(input("What is your last name?"))
age = int(input("How old are you?"))
city = str(input("Where do you live?"))
job = str(input("What is your profession?"))

age_in_5_years = age + 5
name_surname = len(name) + len(surname)
print(f"Adiniz:  {name}")
print(f"Soyadiniz: {surname}")
print(f"Yasiniz: {age}")
print(f"Yasadiginiz sehir: {city}")
print(f"Mesleginiz: {job}")

print(f"5 yil sonraki yasiniz: {age_in_5_years}")
print(f"Adinizin harf sayisi: {name_surname}")
