#include <iostream>
#include <vector>
#include <thread>
#include <atomic>
#include <algorithm>
#include <cmath>
#include "exchange_api.h"
#include "alpha_strategy.h"

class CryptoBot {
public:
    CryptoBot(ExchangeAPI& api, AlphaStrategy& strategy)
        : api_(api), strategy_(strategy), isRunning_(false) {}
    void start() {
        isRunning_ = true;
        thread_ = std::thread(&CryptoBot::run, this);
    }
    void stop() {
        isRunning_ = false;
        if (thread_.joinable()) {
            thread_.join();
        }
    }
    void run() {
        while (isRunning_) {
            auto signals = strategy_.getSignals();
            for (const auto& signal : signals) {
                if (signal.type == SignalType::BUY) {
                    api_.placeOrder(signal.pair, signal.price, signal.size, OrderType::LIMIT);
                }
                else if (signal.type == SignalType::SELL) {
                    api_.placeOrder(signal.pair, signal.price, signal.size, OrderType::LIMIT);
                }
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(strategy_.interval()));
        }
    }

private:
    ExchangeAPI& api_;
    AlphaStrategy& strategy_;
    std::atomic<bool> isRunning_;
    std::thread thread_;
};

int main() {
    ExchangeAPI api("API_KEY", "SECRET_KEY");
    AlphaStrategy strategy;
    CryptoBot bot(api, strategy);
    bot.start();
    // Wait for user input to stop the bot
    std::string input;
    std::cin >> input;
    bot.stop();
    return 0;
}
