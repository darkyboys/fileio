# 📂 FileIO Utility – Advanced C++ File Handling (STL Only)

**FileIO** is a lightweight, header-only C++ library that provides essential **file I/O utilities** using **only the C++ STL** (`<filesystem>`, `<fstream>`, etc.). It simplifies file operations such as reading, writing, appending, listing files, and more.

## 🚀 Features
✅ **List files** in a directory  
✅ **Check if a file exists**  
✅ **Get file size**  
✅ **Read an entire file** into a string  
✅ **Write content to a file** (overwrite mode)  
✅ **Append content** to a file  
✅ **Delete a file**  
✅ **Create a directory**  

> **STL-Only**: No external dependencies—works with standard C++17 and later.

---

## 📥 Installation
Simply download `fileio.hh` and include it in your project:

```cpp
#include "fileio.hh"
```

---

## 📌 Usage Example

```cpp
#include "fileio.hh"
#include <iostream>

int main() {
    std::string filename = "example.txt";

    // Check if file exists
    if (!FileIO::fileExists(filename)) {
        FileIO::writeFile(filename, "Hello, FileIO!");
    }

    // Read the file
    std::cout << "File Content: " << FileIO::readFile(filename) << std::endl;

    // Append content
    FileIO::appendToFile(filename, "\nAppended content.");

    // Display updated content
    std::cout << "Updated Content: " << FileIO::readFile(filename) << std::endl;

    // Get file size
    std::cout << "File Size: " << FileIO::getFileSize(filename) << " bytes\n";

    return 0;
}
```

---

## 📂 API Reference

### 🔹 Get Files in a Directory
```cpp
std::vector<std::string> FileIO::getFilesInDirectory(const std::string& path = ".");
```
Returns a list of file names in the specified directory.

### 🔹 Check if a File Exists
```cpp
bool FileIO::fileExists(const std::string& filename);
```
Returns `true` if the file exists, otherwise `false`.

### 🔹 Get File Size
```cpp
std::uintmax_t FileIO::getFileSize(const std::string& filename);
```
Returns the file size in bytes.

### 🔹 Read a File
```cpp
std::string FileIO::readFile(const std::string& filename);
```
Reads the entire file and returns its content as a string.

### 🔹 Write to a File (Overwrite)
```cpp
bool FileIO::writeFile(const std::string& filename, const std::string& content);
```
Writes content to a file, overwriting existing data.

### 🔹 Append to a File
```cpp
bool FileIO::appendToFile(const std::string& filename, const std::string& content);
```
Appends content to the file.

### 🔹 Delete a File
```cpp
bool FileIO::deleteFile(const std::string& filename);
```
Deletes the specified file.

### 🔹 Create a Directory
```cpp
bool FileIO::createDirectory(const std::string& dirName);
```
Creates a new directory.

---

## 🔧 Requirements
- **C++17 or later** (requires `<filesystem>`)
- **Linux, macOS, or Windows**

---

## 📜 License
This project is licensed under the **MIT License**.

---

## ⭐ Support
If you find this useful, give it a ⭐ on GitHub!


Copyright (c) ghgltggamer 2024
