//
// Created by Sarthak on 2/17/2026.
//

#pragma once

#include <string>

class Value {
public:
    virtual ~Value() = default;
    virtual std::string toString() const = 0;
};