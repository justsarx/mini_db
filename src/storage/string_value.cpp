//
// Created by Sarthak on 2/17/2026.
//

#include "storage/string_value.hpp"

StringValue::StringValue(std::string value)
    : value_(std::move(value)) {}

std::string StringValue::toString() const {
    return value_;
}
