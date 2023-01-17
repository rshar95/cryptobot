CC = g++
CFLAGS = -std=c++11 -O3
LDFLAGS = -lboost_system -lssl -lcrypto

SOURCES = main.cpp exchange_api.cpp alpha_strategy.cpp
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = cryptobot

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
    $(CC) $(OBJECTS) -o $@ $(LDFLAGS)

.cpp.o:
    $(CC) $(CFLAGS) -c $< -o $@

clean:
    rm -rf $(OBJECTS) $(EXECUTABLE)
