#include "Map.h"

Map::Map() {
    //loadMapFromFile();
}

void Map::loadMapFromFile() {
    ifstream file("mission.txt", ios::in);

    file >> rows >> cols;

    file.ignore(); // Ignore the newline character
    string line;
    for (int i = 0; i < rows; ++i){
        if (std::getline(file, line)) {
            map.push_back(vector<char>(line.begin(), line.end()));
            OriginalMap.push_back(vector<char>(line.begin(), line.end()));
        } else {
            cerr << "Error: Unable to read line from file." << std::endl;
            exit(1);
        }
    }
    file.close();
}

void Map::saveMapToFile() {
    ofstream file("mission.txt", ios::out);

    if (!file.is_open()) {
        cerr << "Error: Unable to create file: " << endl;
        return;
    }

    file << rows << " " << cols << endl;

    for (int i = 0; i < map.size(); i++) {
        for (int j = 0; j < map[i].size(); j++) {
            file << map[i][j];
        }
        file << endl;
    }

    file.close();

    cout << "Map saved successfully to " << file << endl;
}

void Map::printMap() {
    for (int i = 0; i < map.size(); i++) {
        for (int j = 0; j < map[i].size(); j++) {
            cout << map[i][j];
        }
        cout << endl;
    }
}

void Map::resetMap() {
    map = OriginalMap;
    PlayerX = initialPlayerX;
    PlayerY = initialPlayerY;
}