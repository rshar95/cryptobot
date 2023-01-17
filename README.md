# CryptoBot
A C++ crypto trading bot that executes trades based on capturing alpha in high-frequency trading.

## Requirements
- C++11 or later
- Boost libraries
- OpenSSL
- Exchange API library (e.g. `ccxt`)

## Getting Started
1. Clone the repository: `git clone https://github.com/rshar95/cryptobot.git`
2. Build the project: `make`
3. Run the bot: `./cryptobot`
4. To stop the bot, press any key and then enter.

## Description
This bot uses advanced statistical analysis and machine learning techniques to identify profitable trading opportunities based on historical market data and real-time market data. The bot runs on a separate thread and uses the sleep_for method to sleep between iterations.

The bot takes as input an object of "ExchangeAPI" and "AlphaStrategy" classes. The ExchangeAPI class is responsible for communicating with the exchange, handling authentication and encryption, and placing the orders. The AlphaStrategy class is responsible for generating the trading signals, it uses advanced statistical analysis and machine learning techniques to identify profitable trading opportunities based on historical market data and real-time market data.

## Note
This is just an example, it should not be used in a production environment as it doesn't have any risk management, stop loss or profit taking. Additionally, the use of a trading strategy based on capturing alpha in high-frequency trading is a complex task that requires a deep understanding of the crypto market and advanced mathematical and programming skills.

## Disclaimer
This code is for educational and demonstration purposes only. It should not be used in a production environment without proper testing and modification. The author of this code is not responsible for any financial losses that may result from the use of this code.

## Author
[Richa Sharma](https://github.com/rshar95)

## License
This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details.
