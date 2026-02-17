//
// Created by Sarthak on 2/17/2026.
//

#include "storage/kv_store.hpp"

bool KeyValueStore::set(const std::string& key,
                        std::unique_ptr<Value> value) {
    store_[key] = std::move(value);
    return true;
}

const Value* KeyValueStore::get(const std::string& key) const {
    auto it = store_.find(key);
    if (it == store_.end()) {
        return nullptr;
    }
    return it->second.get();
}