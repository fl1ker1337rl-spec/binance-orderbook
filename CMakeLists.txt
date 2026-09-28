cmake_minimum_required(VERSION 3.14)
project(binance_orderbook CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ВОТ ЭТА СТРОКА ГЕНЕРИРУЕТ compile_commands.json ДЛЯ VS CODE:
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

list(APPEND CMAKE_PREFIX_PATH "/opt/homebrew" "/usr/local")

find_package(Boost REQUIRED COMPONENTS system thread)
find_package(OpenSSL REQUIRED)
find_package(spdlog REQUIRED)
find_package(nlohmann_json REQUIRED)

include_directories(include /opt/homebrew/include)

add_executable(binance_orderbook src/main.cpp)

target_link_libraries(binance_orderbook
    PRIVATE
        Boost::system
        Boost::thread
        OpenSSL::Crypto
        OpenSSL::SSL
        spdlog::spdlog
        nlohmann_json::nlohmann_json
)