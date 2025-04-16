// https://github.com/kmgb/PatternScan/blob/master/mem.h

#ifndef PATTERNSCAN_MEM_H
#define PATTERNSCAN_MEM_H

#include <iostream>
#include <optional>
#include <sstream>
#include <stdexcept>
#include <vector>
#include <memory>
#include <windows.h>

uintptr_t scan(uintptr_t start, uintptr_t length, std::string const& pattern);

uintptr_t scan_back(uintptr_t start, uintptr_t length, std::string const& pattern);

#endif //PATTERNSCAN_MEM_H