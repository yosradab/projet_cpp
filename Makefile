# Makefile pour compiler le serveur et le client

CXX = g++
CXXFLAGS = -std=c++11 -Wall
MYSQL_FLAGS = $(shell mysql_config --cflags --libs)

all: serveur client

serveur: serveur.cpp
	$(CXX) $(CXXFLAGS) serveur.cpp -o serveur

client: client.cpp
	$(CXX) $(CXXFLAGS) client.cpp -o client $(MYSQL_FLAGS)

clean:
	rm -f serveur client

.PHONY: all clean