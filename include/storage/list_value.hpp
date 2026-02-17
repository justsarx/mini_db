//
// Created by Sarthak on 2/17/2026.
//

#pragma once

#include "storage/value.hpp"
#include <vector>
#include <memory>

class ListValue final : public Value {
public:
    void lpush(std::unique_ptr<Value> value);
    std::unique_ptr<Value> lpop();

    std::string toString() const override;

private:
    std::vector<std::unique_ptr<Value>> elements_;
};
