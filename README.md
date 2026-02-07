# Jutge.org Problems

![Language](https://img.shields.io/badge/Language-C%2B%2B-blue.svg?style=for-the-badge&logo=c%2B%2B)
![Status](https://img.shields.io/badge/Status-Learning-yellow.svg?style=for-the-badge)
![Platform](https://img.shields.io/badge/Platform-Jutge.org-orange.svg?style=for-the-badge)

Welcome! This repository contains problems and notes from **[Jutge.org](https://jutge.org)** courses from the UPC.

> **Note:** These are just my messy codes (and maybe some from my friends). I am not a professional; I created this repository mainly to **practice using Git and GitHub**. The solutions work, but they might not always be the most optimized. Use them as a reference!

---

## How it works

To avoid duplication, this repository uses a **"Single Source"** structure:

1.  **Code:** Every problem solution lives in the `src/` folder (e.g., `src/P12345.cc`).
2.  **Organization:** Since UPC courses often reuse problems, I use separate **Markdown lists** to organize them by courses.

### Repository Structure

```text
/jutge.org
│
├── /src                   <-- All source files live here
│   ├── P12345_Example.cc
│   └── ...
│
├── /lists                 <-- Ordered lists for each course
│   ├── /algorismia-fme-2025-2026
│   ├── /pro1-fib-2024-2025-q1
│   └── ...
│
├── README.md              <-- Main entry point
...
```

## Format:

    ProblemNumber_language_Title-version.cc

Example:

    P14098_en_Multisets_4-v3.cc

Title:  Multisets 4

Problem Number: P14098

Version: 3

Language: English
    




## Course Navigation

Click on the links below to view the specific problem list for each course:

| Course | Subject | Year/Semester | List |
| :--- | :--- | :---: | :--- |
| **PRO1** | Programació 1-FIB | 2024-2025 Q1 | [📄 View Problems](./lists/pro1-fib-2024-2025-q1/) |
| **ALGO** | Algorismia-FME | 2025-2026 | [📄 View Problems](./lists/algorismia-fme-2025-2026/) |
| **EDA** | Estructures de Dades i Algorismes-FIB | 2025-2026 Q2 | [📄 View Problems](./lists/eda-fib-q2-2025-2026/) |

---

## Usage

If you want to run these codes on your local machine:

1.  **Clone the repository:**
    ```bash
    git clone https://github.com/reskoldo73/jutge.org.git
    ```
2.  **Compile a problem** (example using g++ on Linux with suggested flags):
    ```bash
    g++ -Wall -Wextra -Wpedantic -O2 src/P12345_ProblemName.cc
    ./a.out <in.txt >out.txt
    or
    ./a.out <sample.inp >sample.out
    ```
3. **Compare outputs**:
    ```bash
    diff out.txt expected.txt
    or
    diff sample.out sample.cor
    ```

---

## 🤝 Contributing

All suggestions are welcome!

* Found a bug?
* Know a cleaner solution?
* Want to add a list for a new course year?
* Want to add a missing problem?

Feel free to open a **Pull Request** or create an **Issue**.

---

## 📬 Contact

If you want to contribute to the lists or have any questions, feel free to reach out:

* **GitHub:** [@reskoldo73](https://github.com/reskoldo73)
* **Discord:** [@reskoldo73](https://discord.com/users/529429413297913866)
* **Email:** [reskoldo73@gmail.com](mailto:reskoldo73@gmail.com)

---
_Happy Coding!_ 