# 🎨 **`libstrui` v1.0.0**

Minimal Unicode‑aware & ANSI‑aware string library (header‑only, class‑less)

[![C++](https://img.shields.io/badge/language-C%2B%2B17-blue)](https://en.cppreference.com/)
[![Type: header‑only](https://img.shields.io/badge/type-header--only-lightgrey)](https://en.wikipedia.org/wiki/Header-only)
[![Platform: Unix](https://img.shields.io/badge/platform-Unix-darkgreen)](https://en.wikipedia.org/wiki/Unix)
[![Status: v1.0.0](https://img.shields.io/badge/status-v1.0.0-brightgreen)](https://github.com/guillaumeast/libstrui/releases/tag/v1.0.0)

> **`libstrui`** is a *tiny* **C++17 header‑only library** for measuring terminal strings.  
> Think of it as `cut`, `sed`, or `wc`, but *escape‑safe*, **UTF‑8‑capable** (incl. wide & combined emojis).  
> Ready to drop in **one header**.

---

## ✨ Features

- **UTF‑8 aware** (powered by [`libunistring`](https://www.gnu.org/software/libunistring/))
- **ANSI / escape‑safe** cleaning & width detection
- **Visual width** handling (CJK, wide & combined emojis)
- **Line height** calculation
- **Substring occurrence counting**
- **Split** & **repeat** helpers
- **Zero‑dependency** at runtime, header‑only at build time
- Plays nicely with any POSIX shell tool or C++ project

---

## 🛠️ Usage

Just include the header and go:

```cpp
#include <StrUI.hpp>   // path relative to your project
#include <iostream>

int main() {
    std::cout << strui::width("\033[31m1🛑4\033[0m") << std::endl;  // → 4
}
```

Add the *include* directory to your compiler flags, e.g.:

```bash
g++ -std=c++17 -I/path/to/libstrui/include example.cpp -lunistring
```

> **Note:** `libunistring` is only required at *link* time when you compile the optional `.cpp` tests.  
> The header does `#ifdef` guards so you can keep your project header‑only if you already link `libunistring`.

---

## 🧩 API surface

| Function                                      | Description                                   |
|-----------------------------------------------|-----------------------------------------------|
| `strui::width(str)`                           | Return *visual* width (columns) of `str`      |
| `strui::height(str)`                          | Return number of *lines* in `str`             |
| `strui::clean(str)`                           | Remove ANSI *escape sequences*                |
| `strui::split(str, sep)`                      | Vector‑split `str` on `sep`                   |
| `strui::join(str, sep = "")`                  | Return merged `std::string` (optional `sep`)  |
| `strui::repeat(count, str, sep = "")`         | Repeat `str` `count` times (optional `sep`)   |
| `strui::count(str, value)`                    | Count occurrences of `value` in `str`         |

> `Display width` is measured in `columns`, of `characters` or `strings`, when output to a device that uses `non-proportional fonts`.  
> Note that for some rarely used characters the actual `fonts` or `terminal emulators` can use a different `width`. There is no mechanism for communicating the `display width` of `characters` across a Unix pseudo-terminal (`tty`).  
> Also, there are scripts with complex rendering, like the `Indic` scripts. For these scripts, there is no such concept as `non-proportional fonts`. Therefore the results of these functions usually work fine on most scripts and on most `characters` but can fail to represent the actual `display width`.  
> 📚 See [libunistring documentation – Display width <uniwidth.h>](https://www.gnu.org/software/libunistring/manual/libunistring.html#uniwidth_002eh) for details on how display width is computed.

---

## 🧪 Test

No build is needed to *use* the library ✌️.

But you can build and run the library *test program*:

```bash
# run unit tests locally + inside an Ubuntu container (requires Docker)
sh tests/run.sh
```

---

## 📦 Dependencies

- [`libunistring`](https://www.gnu.org/software/libunistring/) ≥ 1.1 (link‑time only)
- Any **C++17** compiler (`g++`, `clang++`, …)

---

## 📁 Project structure

```
libstrui/
├── LICENCE.txt
├── README.md
├── include/
│   └── strui.hpp
└── tests/
    ├── run.sh
    ├── Makefile
    ├── test.cpp
    └── Dockerfile
```

---

## 👤 Author

Made with ❤️ by [@guillaumeast](https://github.com/guillaumeast)
