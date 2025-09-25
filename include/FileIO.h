#pragma once

#include <filesystem>
#include <fstream>
#include <string>

#include "Assets.h"

namespace FileIO {
inline std::filesystem::path data_path(const std::string& name) {
        return std::filesystem::path(asset("data/")) / name;
}

inline void ensure_parent_exists(const std::filesystem::path& p) {
        std::error_code ec;
        std::filesystem::create_directories(p.parent_path(), ec);
}

inline void touch_if_missing(const std::filesystem::path& p, std::ios::openmode mode = std::ios::binary) {
        if (!std::filesystem::exists(p)) {
                ensure_parent_exists(p);
                std::ofstream o(p, (mode | std::ios::out) & ~std::ios::ate);
        }
}

inline std::ifstream open_ifstream_or_create(const std::string& name, std::ios::openmode mode = std::ios::binary) {
        auto p = data_path(name);
        touch_if_missing(p, mode);
        std::ifstream in(p, mode);
        return in;
}

inline void open_fstream_rw_or_create(const std::string& name, std::fstream& fs, std::ios::openmode mode) {
        auto p = data_path(name);
        touch_if_missing(p, std::ios::binary);
        fs.open(p, mode);
        if (!fs) {
                fs.clear();
                std::ofstream o(p, std::ios::binary | std::ios::trunc);
                fs.open(p, mode);
        }
}

inline std::ofstream open_ofstream_trunc(const std::string& name, std::ios::openmode mode = std::ios::binary | std::ios::trunc) {
        auto p = data_path(name);
        ensure_parent_exists(p);
        std::ofstream out(p, mode | std::ios::out);
        return out;
}
} // namespace FileIO
