//
// Created by Sarthak on 2/17/2026.
//

#pragma once
#include <string>
#include <vector>

enum class CommandType {
    Set,
    Get,
    Exit,
    Invalid
};

struct Command {
    CommandType type;
    std::vector<std::string> args;
};