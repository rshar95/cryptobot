#ifndef SIGNAL_H
#define SIGNAL_H

#include <string>

enum class SignalType {
    BUY,
    SELL
};

struct Signal {
    SignalType type;
    std::string pair;
    double price;
    int size;
};

#endif
