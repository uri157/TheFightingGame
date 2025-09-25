#pragma once
#include <string>

// Devuelve "assets/<rel>"
inline std::string asset(const std::string& rel) {
    return "assets/" + rel;
}
