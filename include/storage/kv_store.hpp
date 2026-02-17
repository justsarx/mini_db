//
// Created by Sarthak on 2/17/2026.
//

#pragma once

#include <string>
#include <optional>
#include <memory>
#include <unordered_map>
#include "storage/value.hpp"

class KeyValueStore {
public:
    bool set(const std::string& key, std::unique_ptr<Value> value);
    const Value* get(const std::string& key) const;


private:
    std::unordered_map<std::string, std::unique_ptr<Value>> store_;
};
