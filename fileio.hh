#ifndef FILE_IO_UTILS_HH
#define FILE_IO_UTILS_HH

#include <iostream>
#include <fstream>
#include <filesystem>
#include <vector>
#include <string>

namespace FileIO {
    namespace fs = std::filesystem;

    // Get all files from a directory
    std::vector<std::string> getFilesInDirectory(const std::string& path = ".") {
        std::vector<std::string> files;
        for (const auto& entry : fs::directory_iterator(path)) {
            if (fs::is_regular_file(entry.path())) {
                files.push_back(entry.path().string());
            }
        }
        return files;
    }

    // Get all directories from a directory
    std::vector<std::string> getDirectoriesInDirectory(const std::string& path = ".") {
        std::vector<std::string> directories;
        for (const auto& entry : fs::directory_iterator(path)) {
            if (fs::is_directory(entry.path())) {
                directories.push_back(entry.path().string());
            }
        }
        return directories;
    }

    // Check if a file exists
    bool fileExists(const std::string& filename) {
        return fs::exists(filename) && fs::is_regular_file(filename);
    }

    // Check if a directory exists
    bool directoryExists(const std::string& dirname) {
        return fs::exists(dirname) && fs::is_directory(dirname);
    }

    // Get file size
    std::uintmax_t getFileSize(const std::string& filename) {
        if (!fileExists(filename)) return 0;
        return fs::file_size(filename);
    }

    // Get total directory size (recursive)
    std::uintmax_t getDirectorySize(const std::string& dirname) {
        if (!directoryExists(dirname)) return 0;
        std::uintmax_t totalSize = 0;
        for (const auto& entry : fs::recursive_directory_iterator(dirname)) {
            if (fs::is_regular_file(entry.path())) {
                totalSize += fs::file_size(entry.path());
            }
        }
        return totalSize;
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
        return fileExists(filename) && fs::remove(filename);
    }

    // Create a directory
    bool createDirectory(const std::string& dirName) {
        return fs::create_directory(dirName);
    }

    // Delete a directory (recursively)
    bool deleteDirectory(const std::string& dirName) {
        return directoryExists(dirName) && fs::remove_all(dirName) > 0;
    }
}

#endif // FILE_IO_UTILS_HH
