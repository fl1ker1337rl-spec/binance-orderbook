#include <iostream>
#include <spdlog/spdlog.h>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

int main(int argc, char* argv[]) {
    spdlog::info("Orderbook Core Initialized!");

    json test_json = {
        {"symbol", "BTCUSDT"},
        {"status", "connected"},
        {"bids_count", 10}
    };

    spdlog::warn("Test JSON payload: {}", test_json.dump());

    return 0;
}