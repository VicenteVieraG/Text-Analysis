#pragma once
#include <string>
#include <inja/inja.hpp>

using namespace nlohmann;

struct SystemInfo {
    unsigned int cpu_cores;
    std::string cpu_model;
    std::uint64_t ram_bytes;
    std::string os_name;
    std::string os_version;
};

struct InputFileInfo {
    std::string name;
    std::string path;
    std::size_t size;
};

struct TemplateFileInfo {
    std::string name; // -> Change this for an enum
    std::string path;
};

struct ReportContext {
    SystemInfo system;
    InputFileInfo input_file;
    TemplateFileInfo template_file;
    std::string generated_at;
};

class Report {
    private:
        ReportContext context;
    public:
        Report();
};