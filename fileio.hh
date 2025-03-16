#ifndef FILE_IO_UTILS_HH
#define FILE_IO_UTILS_HH

#include <iostream>
#include <fstream>
#include <filesystem>
#include <vector>
#include <string>

namespace FileIO {
    namespace fs = std::filesystem;

    // Get all files from the current directory
    std::vector<std::string> getFilesInDirectory(const std::string& path = ".") {
        std::vector<std::string> files;
        for (const auto& entry : fs::directory_iterator(path)) {
            if (fs::is_regular_file(entry.path())) {
                files.push_back(entry.path().string());
            }
        }
        return files;
    }

    // Check if a file exists
    bool fileExists(const std::string& filename) {
        return fs::exists(filename);
    }

    // Get file size
    std::uintmax_t getFileSize(const std::string& filename) {
        if (!fileExists(filename)) return 0;
        return fs::file_size(filename);
    }

    // Read entire file content into a string
    std::string readFile(const std::string& filename) {
        std::ifstream file(filename);
        if (!file.is_open()) {
            std::cerr << "Error: Cannot open file " << filename << std::endl;
            return "";
        }
        std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
        file.close();
        return content;
    }

    // Write content to a file (overwrite)
    bool writeFile(const std::string& filename, const std::string& content) {
        std::ofstream file(filename, std::ios::out);
        if (!file.is_open()) return false;
        file << content;
        file.close();
        return true;
    }

    // Append content to a file
    bool appendToFile(const std::string& filename, const std::string& content) {
        std::ofstream file(filename, std::ios::app);
        if (!file.is_open()) return false;
        file << content;
        file.close();
        return true;
    }

    // Delete a file
    bool deleteFile(const std::string& filename) {
        return fs::remove(filename);
    }

    // Create a directory
    bool createDirectory(const std::string& dirName) {
        return fs::create_directory(dirName);
    }
}

#endif // FILE_IO_UTILS_HH
