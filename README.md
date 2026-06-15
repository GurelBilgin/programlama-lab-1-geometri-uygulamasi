# Programlama Lab 1 - Geometri Uygulaması

Bu proje, Programlama Lab 1 dersi Ödev 3 kapsamında C++ ile geliştirilmiş nesne yönelimli bir geometri uygulamasıdır. Projede nokta, doğru parçası, daire ve üçgen sınıfları ayrı modüller hâlinde düzenlenmiştir.

## Özellikler

- `Nokta` sınıfı ile koordinat tutma, güncelleme ve iki nokta arası uzaklık hesaplama
- `DogruParcasi` sınıfı ile uzunluk ve orta nokta hesaplama
- `Daire` sınıfı ile alan, çevre ve daireler arası kesişim durumunu bulma
- `Ucgen` sınıfı ile alan, çevre ve açı hesaplama
- CMake tabanlı derleme yapısı
- Basit test programı ile temel sınıf davranışlarının kontrol edilmesi

## Proje Yapısı

```text
.
├── CMakeLists.txt
├── README.md
├── docs/
│   └── README.md
├── include/
│   └── geometri/
│       ├── Daire.hpp
│       ├── DogruParcasi.hpp
│       ├── Nokta.hpp
│       └── Ucgen.hpp
├── src/
│   ├── Daire.cpp
│   ├── DogruParcasi.cpp
│   ├── Nokta.cpp
│   ├── Ucgen.cpp
│   └── main.cpp
└── tests/
    └── test_geometri.cpp
```

## Gereksinimler

- C++17 destekleyen bir derleyici
- CMake 3.16 veya üzeri

## Derleme

```bash
cmake -S . -B build
cmake --build build
```

## Çalıştırma

Windows için:

```bash
.\build\Debug\geometri_uygulamasi.exe
```

Linux/macOS için:

```bash
./build/geometri_uygulamasi
```

Bazı CMake yapılandırmalarında çalıştırılabilir dosya `build/` yerine `build/Debug/` veya `build/Release/` içinde oluşabilir.

## Testleri Çalıştırma

```bash
cmake --build build --target geometri_testleri
ctest --test-dir build --output-on-failure
```

Alternatif olarak test programı doğrudan çalıştırılabilir:

```bash
.\build\Debug\geometri_testleri.exe
```

## Sınıflar

### Nokta

İki boyutlu düzlemde bir noktayı temsil eder. `x` ve `y` koordinatları üzerinde getter, setter, uzaklık ve metne dönüştürme işlemleri sağlar.

### DogruParcasi

İki nokta arasında kalan doğru parçasını temsil eder. Başlangıç ve bitiş noktaları üzerinden uzunluk ve orta nokta hesaplar. Ayrıca başlangıç noktası, uzunluk ve eğim açısı ile doğru parçası oluşturulabilir.

### Daire

Merkez noktası ve yarıçap bilgisiyle daireyi temsil eder. Alan, çevre ve başka bir daireyle kesişim durumu hesaplanabilir.

### Ucgen

Üç nokta ile oluşturulan üçgeni temsil eder. Alan, çevre ve iç açı değerlerini hesaplar. Doğrusal veya alanı sıfır olan noktalardan üçgen oluşturulmasına izin verilmez.

## Hazırlayanlar

- Gürel Bilgin
- Berkay Aras

Bu proje, Kocaeli Sağlık ve Teknoloji Üniversitesi Yazılım Mühendisliği Bölümü Programlama Lab 1 dersi kapsamında geliştirilmiştir.
