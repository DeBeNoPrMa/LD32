#include"Network.h"
#include<string.h>
#include<vector>
#include "Game.h"
#include "Beasts.h"

Network::Network(Game* g) 
    : game(g)
{
    init();
}

void Network::init() {
    Beasts beasts = Beasts(100, 100, 100, 100, 100, 100);
    for (int i = 0; i < num_cities; i++) {
        cities.push_back(City(game, i, beasts));
        for (int j = 0; j < num_cities; j++) {
            adjacency_table[i][j] = false;
        }
    }
}

Network::~Network() {
}

void Network::addPath(int a, int b) {
    changePath(a, b, true);
}

void Network::destroyNode(int n) {
    for (int i = 0; i < num_cities; i++) {
        changePath(n, i, false);
    }
}

void Network::draw() {
    for (std::vector<City>::iterator it = cities.begin(); it != cities.end(); it++) {
        it->draw();
    }
}

void Network::update() {
    for (std::vector<City>::iterator it = cities.begin(); it != cities.end(); it++) {
        it->update();
    }
}

void Network::changePath(int a, int b, bool value) {
    adjacency_table[a][b] = value; 
    adjacency_table[b][a] = value;
}

// Crec que hauria de funcionar, no n'estic gens segur per aixo haha
bool Network::isValidPath(std::vector<int> path) {
    bool adj_table[num_cities][num_cities];
    memcpy(adj_table, adjacency_table, sizeof(adjacency_table));

    int previous = path[0];
    std::vector<int>::iterator it = path.begin(); it++;
    for (; it != path.end(); it++) {
        if (adj_table[*it][previous] == true) {
            changePath(*it, previous, false);
            previous = *it;
        }
        else {
            return false;
        }
    }
    return true;
}

City* Network::getCity(int id) {
    return &cities[id];
}

// Tampoc tinc molt clar si funcionara, estava parlant de kung fu
std::vector<int> Network::getNeighbours(int id) {
    std::vector<int> neighbours;

    for (int i = 0; i < num_cities; i++) {
        if (adjacency_table[id][i] == true) {
            neighbours.push_back(i);
        }
    }

    return neighbours;
}

int Network::getCityByCoords(sf::Vector2f coords) {
    for (int i = 0; i < num_cities; i++) {
        if (cities[i].isInside(coords)) {
            return i;
        }
    }

    return -1;
}
