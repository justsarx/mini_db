//
// Created by Sarthak on 2/17/2026.
//

#pragma once

#include "storage/value.hpp"

class StringValue final : public Value {
public:
    explicit StringValue(std::string value);
    std::string toString() const override;

private:
    std::string value_;
};