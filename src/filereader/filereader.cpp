#include <filesystem>
#include <fstream>
#include <limits>
#include <stdexcept>
#include <string>

#include <filereader.hpp>

namespace FileReader {
    std::string readFile(const std::filesystem::path& path){
        std::ifstream file(path, std::ios::binary | std::ios::ate);

        if(!file.is_open()) throw std::runtime_error("Could not open file: " + path.string());

        const std::streampos size = file.tellg();

        if(size < 0)  throw std::runtime_error("Could not get file size: " + path.string());

        if(
            static_cast<unsigned long long>(size) >
            static_cast<unsigned long long>(std::numeric_limits<std::streamsize>::max())
        ) throw std::runtime_error("File too large to read: " + path.string());

        file.seekg(0);
        std::string buffer(static_cast<std::size_t>(size), '\0');

        if(!file.read(buffer.data(), static_cast<std::streamsize>(buffer.size()))){
            throw std::runtime_error("Could not read entire file: " + path.string());
        }

        return buffer;
    }
};