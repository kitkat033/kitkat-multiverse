// https://github.com/kmgb/PatternScan/blob/master/mem.cpp

#include "mem.h"

std::optional<uint8_t> string_to_byte(std::string s) {
    if (s.length() != 2) {
        return {};
    }

    auto char1 = std::toupper(s[0]),
        char2 = std::toupper(s[1]);

    int nibble_a = (char1 >= '0' && char1 <= '9') ? char1 - '0'
        : (char1 >= 'A' && char1 <= 'F') ? 0xA + (char1 - 'A')
        : -1;
    int nibble_b = (char2 >= '0' && char2 <= '9') ? char2 - '0'
        : (char2 >= 'A' && char2 <= 'F') ? 0xA + (char2 - 'A')
        : -1;

    if (nibble_a == -1 || nibble_b == -1)
        return {};

    return ((uint8_t)nibble_a << 4) | (uint8_t)nibble_b;
}

uintptr_t scan_codestyle(uintptr_t start, uintptr_t length, uint8_t const* bytes, bool const* mask, std::size_t pat_len) {
    auto u_start = (uintptr_t)start;

    for (uintptr_t addr = u_start; addr + pat_len <= u_start + length; addr++) {
        for (int i = 0; i < pat_len; i++) {
            if (mask[i] && *(uint8_t*)(addr + i) != bytes[i]) {
                break;
            }

            if (i == pat_len - 1) {
                return addr;
            }
        }
    }

    return 0;
}

uintptr_t scan(uintptr_t start, uintptr_t length, std::string const& pattern) {
    std::istringstream iss{ pattern };
    std::string s;
    std::vector<std::string> list;

    while (std::getline(iss, s, ' ')) {
        if (!s.empty()) {
            list.push_back(s);
        }
    }

    auto bytes = std::make_unique<uint8_t[]>(list.size());
    auto mask = std::make_unique<bool[]>(list.size());

    int i = 0;
    for (auto const& l : list) {
        if (l == "?" || l == "??") {
            mask[i] = false;
        }
        else {
            auto byte = string_to_byte(l);

            if (!byte) {
                throw std::invalid_argument("Invalid IDA pattern");
            }

            bytes[i] = *byte;
            mask[i] = true;
        }

        i++;
    }

    return scan_codestyle(start, length, bytes.get(), mask.get(), list.size());
}