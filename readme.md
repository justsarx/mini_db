A small, educational in-memory key–value database written in C++20 with a simple interactive CLI (REPL). It supports basic string values and list values, inspired by a tiny subset of Redis-like commands.

[![CMake on a single platform](https://github.com/justsarx/mini_db/actions/workflows/cmake-single-platform.yml/badge.svg)](https://github.com/justsarx/mini_db/actions/workflows/cmake-single-platform.yml)
## Features

- Interactive prompt: `MiniDB> `
- In-memory key–value storage
- Value types:
  - **String**
  - **List** (supports push/pop)
- Commands:
  - `SET <key> <value>`
  - `GET <key>`
  - `LPUSH <key> <value>`
  - `LPOP <key>`
  - `EXIT`

## Project layout

- `include/` — public headers (parser, storage, value types)
- `src/` — implementation
- `tests/` — tests (if present in your checkout)
- `CMakeLists.txt` — CMake build configuration
- `.github/workflows/` — CI workflow (CMake build)

## Requirements

- C++20-compatible compiler (MSVC / clang / GCC)
- CMake (recommended 3.20+)


