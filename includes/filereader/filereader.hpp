#pragma once
#include <string>
#include <filesystem>

namespace FileReader {
    std::string readFile(const std::filesystem::path& path);
};