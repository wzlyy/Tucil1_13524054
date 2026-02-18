# Tucil1_13524054
# 📘 Qt 6 Application – Build & Run Guide

Project ini dibuat menggunakan:

- Qt 6
- Qt Creator
- CMake
- C++17
- Windows (MinGW / MSVC)

---

# 🧰 Requirements

Pastikan sudah terinstall:

- Qt 6 (Desktop version)
- Qt Creator
- Compiler:
  - MinGW 64-bit (recommended)
  - atau MSVC

Saat install Qt, pastikan mencentang:

Qt 6.x.x → MinGW 64-bit

---

# 🚀 Cara Compile & Run (Qt Creator)

## 1️⃣ Buka Project

1. Buka **Qt Creator**
2. Klik **Open Project**
3. Pilih file:
4. Klik **Configure Project**
5. Masuk ke:
Projects → Build
7. Build project:
Build → Build Project
8. Jalankan aplikasi:
## Build via Command Line (Opsional)

```bash
mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
cmake --build .