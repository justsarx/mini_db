#include <iostream>
#include <string>

#include "parser/command.hpp"
#include "parser/command_parser.hpp"
#include "storage/kv_store.hpp"
#include "storage/string_value.hpp"

int main() {
    std::cout << "MiniDB starting...\n";

    KeyValueStore store;

    while (true) {
        std::cout << "MiniDB> ";

        std::string line;
        if (!std::getline(std::cin, line)) {
            break;
        }

        switch (auto [type, args] = parseCommand(line); type) {
            case CommandType::Set: {
                const std::string& key = args[0];
                const std::string& value = args[1];

                store.set(key, std::make_unique<StringValue>(value));
                std::cout << "OK\n";

                break;
            }

            case CommandType::Get: {
                const std::string& key = args[0];

                if (const Value* val = store.get(key)) {
                    std::cout << val->toString() << "\n";
                } else {
                    std::cout << "(nil)\n";
                }
                break;
            }

            case CommandType::Exit:
                std::cout << "Bye.\n";
                return 0;

            case CommandType::Invalid:
            default:
                std::cout << "ERROR: Invalid command\n";
                break;
        }
    }

    std::cout << "MiniDB shutting down...\n";
    return 0;
}