#include "exchange_api.h"
#include <map>
#include <utility>
#include <curl/curl.h>

class MyExchangeAPI : public ExchangeAPI {
public:
    MyExchangeAPI(const std::string& apiKey, const std::string& secretKey)
        : ExchangeAPI(apiKey, secretKey) {}

    double getCurrentPrice(const std::string& pair) override {
        // Get the current price from the exchange's API
        CURL* curl = curl_easy_init();
        // Prepare the request
        std::string url = "https://api.exchange.com/ticker/" + pair;
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        // Perform the request
        CURLcode res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            // Handle error
            return -1;
        }
        // Parse the response
        double price;
        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &price);
        curl_easy_cleanup(curl);
        return price;
    }

    void placeOrder(const std::string& pair, double price, int size, OrderType type) override {
        // Prepare the request body
        std::map<std::string, std::string> data;
        data["pair"] = pair;
        data["price"] = std::to_string(price);
        data["size"] = std::to_string(size);
        data["type"] = (type == OrderType::LIMIT) ? "limit" : "market";
        // Perform the request
        CURL* curl = curl_easy_init();
        std::string url = "https://api.exchange.com/order";
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data);
              // Set the API key and secret key for authentication
        std::string auth = apiKey_ + ":" + secretKey_;
        curl_easy_setopt(curl, CURLOPT_USERPWD, auth.c_str());
        // Perform the request
        CURLcode res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            // Handle error
            std::cerr << "Error placing order: " << curl_easy_strerror(res) << std::endl;
        }
        curl_easy_cleanup(curl);
    }
};

