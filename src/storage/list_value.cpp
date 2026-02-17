//
// Created by Sarthak on 2/17/2026.
//

#include "storage/list_value.hpp"

void ListValue::lpush(std::unique_ptr<Value> value) {
    elements_.insert(elements_.begin(), std::move(value));
}

std::unique_ptr<Value> ListValue::lpop() {
    if (elements_.empty()) {
        return nullptr;
    }

    auto val = std::move(elements_.front());
    elements_.erase(elements_.begin());
    return val;
}

std::string ListValue::toString() const {
    return "[list]";
}
