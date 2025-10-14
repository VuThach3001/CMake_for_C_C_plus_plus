# Seciton 1: Introduction

## Topic: Linux: Software Installation

## Date: [Insert Date Here]  

---

### Cue Column (Questions, Keywords, or Prompts)

- [Insert question or keyword]
- [Insert question or keyword]
- [Insert question or keyword]

---

### Notes Section (Main Notes)


**1. 📦 Development Tools Installation & Description**

This document lists commonly used development tools installed on Linux (Debian/Ubuntu) systems, along with their functions.

---

**2. 🧱 System Update Commands**

| Command                | Description                                                                                                  |
| ---------------------- | ------------------------------------------------------------------------------------------------------------ |
| `sudo apt-get update`  | Updates the package lists to retrieve information on the newest versions of packages and their dependencies. |
| `sudo apt-get upgrade` | Installs the newest versions of all packages currently installed on the system.                              |

---

**3. 🛠️ Mandatory Development Tools**

| Package                  | Description                                                                                                                          |
| ------------------------ | ------------------------------------------------------------------------------------------------------------------------------------ |
| `gcc`                    | GNU C Compiler — compiles C source code into executable programs.                                                                    |
| `g++`                    | GNU C++ Compiler — compiles C++ source code into executable programs.                                                                |
| `gdb`                    | GNU Debugger — helps debug programs written in C, C++, and other languages.                                                          |
| `make`                   | Automation tool that reads `Makefile` to build and manage projects efficiently.                                                      |
| `cmake`                  | Cross-platform build system generator that creates native build files (e.g., Makefiles) from configuration files (`CMakeLists.txt`). |
| `git`                    | Distributed version control system to manage source code history and collaborate on software projects.                               |
| `doxygen`                | Documentation generator for annotated source code, producing HTML, LaTeX, or other formats.                                          |
| `python3`, `python3-pip` | Python 3 programming language and its package installer (`pip`) for installing Python libraries.                                     |

---

**4. Optional Development & Utility Tools**

| Package        | Description                                                                                                                        |
| -------------- | ---------------------------------------------------------------------------------------------------------------------------------- |
| `lcov`         | Code coverage analysis tool for projects compiled with GCC. Works with `gcov` to generate coverage reports in HTML.                |
| `gcovr`        | Generates summarized or detailed coverage reports in various formats (HTML, XML, etc.) from `gcov` data.                           |
| `ccache`       | Compiler cache that speeds up recompilation by caching previous compilations.                                                      |
| `cppcheck`     | Static analysis tool for C/C++ code to detect bugs, style issues, and undefined behaviors.                                         |
| `llvm`         | Collection of modular and reusable compiler and toolchain technologies.                                                            |
| `clang-format` | Automatic code formatting tool for C, C++, Java, JavaScript, and other languages.                                                  |
| `clang-tidy`   | Static analysis and linting tool for C/C++ that detects potential errors and style violations.                                     |
| `curl`         | Command-line tool for transferring data with URLs (supports HTTP, FTP, etc.). Useful for downloading files or making API requests. |
| `zip`, `unzip` | Compression and decompression utilities for `.zip` archives.                                                                       |
| `tar`          | Archiving utility commonly used to package multiple files into `.tar` or `.tar.gz` files.                                          |
| `graphviz`     | Graph visualization software for generating diagrams from textual descriptions (e.g., call graphs, dependency graphs).             |

---
**5. Usage Notes**

- The **mandatory tools** are essential for building, debugging, and documenting most C/C++ projects.
- The **optional tools** are highly recommended for improving build speed, code quality, coverage analysis, and automation.
- You can install everything at once or pick only the tools relevant to your project.

```bash
# Install everything at once
sudo apt-get update && sudo apt-get upgrade -y
sudo apt-get install -y gcc g++ gdb make cmake git doxygen python3 python3-pip \
lcov gcovr ccache cppcheck llvm clang-format clang-tidy curl zip unzip tar graphviz
```

---

### Summary Section (Summary of Notes)

[Insert a brief summary of the key ideas and takeaways]
