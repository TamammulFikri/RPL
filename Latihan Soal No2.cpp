# Meminta input usia dari pengguna
usia = int(input("Masukkan usia Anda: "))

# Menentukan kategori berdasarkan rentang usia
if usia < 12:
    print("Kategori: Anak-anak")
elif 12 <= usia <= 17:
    print("Kategori: Remaja")
elif 18 <= usia <= 60:
    print("Kategori: Dewasa")
else:
    print("Kategori: Lansia")
