# Plagiarism-Detection-System
# 📚 Plagiarism Checker using Suffix Trie (C++ & Tkinter GUI)

A fast and scalable plagiarism detection engine built in **C++** using **Suffix Trie** data structures to identify overlapping n-gram phrases between two text files. A **Python Tkinter GUI** frontend makes it user-friendly for non-technical users.

---

## 🚀 Features

- 🔍 Trie-based n-gram phrase matching (configurable n).
- ⚡ Fast detection for 400K+ word files in under 5 seconds.
- 📊 Similarity scoring with Low / Moderate / High classification.
- 🖥️ GUI frontend built in Python (Tkinter).
- 📁 Drag-and-drop or browse to upload text files.
- 🧪 Stress-tested for multi-million word corpora.

---

## 🛠️ Tech Stack

- **C++** (core logic)
- **Python 3 / Tkinter** (GUI)
- **CMake** (build system)
- **Bash** (wrapper for ease of use)

---

## 📁 Project Structure
```
.
├── main.cpp                          # Main driver code in C++
├── SuffixTrie.h                      # Suffix Trie implementation
├── CMakeLists.txt                    # CMake build config
├── run.sh                            # Shell script to build + run + output
├── file1.txt                         # Input file 1 (user provided)
├── file2.txt                         # Input file 2 (user provided)
├── results.txt                       # Output result (auto-written)
└── gui.py                            # Python GUI
```



---

## 🔧 Build & Run Instructions

▶️ Compile C++ Program with CMake
```bash
mkdir build
cd build
cmake ..
make
./PlagiarismChecker
```

▶️ Or use the shell script
```bash
chmod +x run.sh
./run.sh
```

🖱️ Launch the GUI (Python)
```bash
python3 gui.py
```
`
🙋‍♂️ Author
Nitin Kumar
`
`
Indian Institute of Technology Kharagpur
`



