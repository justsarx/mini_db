//
// Created by Sarthak on 2/17/2026.
//

#include "parser/command_parser.hpp"

#include <algorithm>
#include <cctype>
#include <sstream>

namespace {

    std::string toUpper(std::string s) {
        std::ranges::transform(s, s.begin(),
                               [](const unsigned char c) { return std::toupper(c); });
        return s;
    }

    std::vector<std::string> tokenize(const std::string& input) {
        std::istringstream iss(input);
        std::vector<std::string> tokens;
        std::string token;

        while (iss >> token) {
            tokens.push_back(token);
        }

        return tokens;
    }

} // anonymous namespace

Command parseCommand(const std::string& input) {
    auto tokens = tokenize(input);

    if (tokens.empty()) {
        return {CommandType::Invalid, {}};
    }

    const std::string keyword = toUpper(tokens[0]);

    if (keyword == "SET") {
        if (tokens.size() != 3) {
            return {CommandType::Invalid, {}};
        }
        return {CommandType::Set, {tokens[1], tokens[2]}};
    }

    if (keyword == "GET") {
        if (tokens.size() != 2) {
            return {CommandType::Invalid, {}};
        }
        return {CommandType::Get, {tokens[1]}};
    }

    if (keyword == "EXIT") {
        if (tokens.size() != 1) {
            return {CommandType::Invalid, {}};
        }
        return {CommandType::Exit, {}};
    }

    return {CommandType::Invalid, {}};
}
