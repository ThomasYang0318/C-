#include <iostream>
#include "Player.h"
#include "Box.h"
#include "Map.h"
#ifdef _WIN32
#include <conio.h> // For _getch()
#endif

#ifdef __APPLE__
#include <termios.h>
#include <unistd.h>
#endif

using namespace std;

#ifdef __APPLE__
int getch() {
    struct termios oldattr, newattr;
    int ch;
    tcgetattr(STDIN_FILENO, &oldattr);
    newattr = oldattr;
    newattr.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newattr);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldattr);
    return ch;
}
#endif

int main() {
    Map map;
    map.loadMapFromFile();
    Player player(map);
    Box box(map);
    char input;
    do {
        #ifdef __APPLE__
        system("clear"); // Clear screen //mac
        #endif
        #ifdef _WIN32
        system("cls"); // Clear screen //windows
        #endif
        map.printMap();
        cout << "Use w to move up,"<< endl
             << "s to move down," << endl
             << "a to move left," << endl
             << "d to move right" << endl
             << "r to reset map" << endl
             << "q to quit" << endl;
        player.PrintPlayer();
        box.PrintBox();

        #ifdef __APPLE__
        input = getch(); // Get user input
        #endif

        #ifdef _WIN32
        input = _getch();
        #endif

        switch (input) {
            case 'w': // Up
                player.move(map, 0, -1);
                break;
            case 's': // Down
                player.move(map, 0, 1);
                break;
            case 'a': // Left
                player.move(map, -1, 0);
                break;
            case 'd': // Right
                player.move(map, 1, 0);
                break;
            case 'r': // Reset map
                map.resetMap();
                break;
            case 'o': // Save map to file
                map.saveMapToFile();
                break;
        }

    } while (input != 'q'); // Quit when 'q' is pressed

    return 0;
}

// #include <iostream>
// #include <fstream>
// #include "Player.h"
// #include "Box.h"
// #ifdef _WIN32
// #include <conio.h> // For _getch()
// #endif

// #ifdef __APPLE__
// #include <termios.h>
// #include <unistd.h>
// #endif

// using namespace std;

// vector< vector<char> > map;
// vector< vector<char> > OriginalMap;
// int rows, cols;

// #ifdef __APPLE__
// int getch() {
//     struct termios oldattr, newattr;
//     int ch;
//     tcgetattr(STDIN_FILENO, &oldattr);
//     newattr = oldattr;
//     newattr.c_lflag &= ~(ICANON | ECHO);
//     tcsetattr(STDIN_FILENO, TCSANOW, &newattr);
//     ch = getchar();
//     tcsetattr(STDIN_FILENO, TCSANOW, &oldattr);
//     return ch;
// }
// #endif

// void loadMapFromFile() {
//     ifstream file("mission.txt", ios::in);

//     file >> rows >> cols;

//     file.ignore(); // Ignore the newline character
//     string line;
//     for (int i = 0; i < rows; ++i){
//         if (std::getline(file, line)) {
//             map.push_back(vector<char>(line.begin(), line.end()));
//             OriginalMap.push_back(vector<char>(line.begin(), line.end()));
//         } else {
//             cerr << "Error: Unable to read line from file." << std::endl;
//             exit(1);
//         }
//     }
//     file.close();
// }

// void saveMapToFile() {
//     ofstream file("mission.txt", ios::out);

//     if (!file.is_open()) {
//         cerr << "Error: Unable to create file: " << endl;
//         return;
//     }

//     file << rows << " " << cols << endl;

//     for (int i = 0; i < map.size(); i++) {
//         for (int j = 0; j < map[i].size(); j++) {
//             file << map[i][j];
//         }
//         file << endl;
//     }

//     file.close();

//     cout << "Map saved successfully to " << file << endl;
// }

// void printMap() {
//     for (int i = 0; i < map.size(); i++) {
//         for (int j = 0; j < map[i].size(); j++) {
//             cout << map[i][j];
//         }
//         cout << endl;
//     }
// }

// // class Box{
// //     int BoxX, BoxY;
// // public:
// //     Box(){
// //         // Find box's initial position
// //         for (int i = 0; i < rows; ++i) {
// //             for (int j = 0; j < cols; ++j) {
// //                 if (OriginalMap[i][j] == '1') {
// //                     BoxX = j;
// //                     BoxY = i;
// //                     break;
// //                 }
// //             }
// //         }
// //     };
// //     ~Box(){
// //         //saveMapToFile();
// //     };
    
// //     void pushed (int dx, int dy){
// //         BoxX += dx;
// //         BoxY += dy;
// //     };
// //     void PrintBox(){
// //         cout << BoxX << " " << BoxY << endl;
// //     };
// // };

// // class Player{
// //     int PlayerX, PlayerY;
// //     int newPlayerX, newPlayerY;
// // public:
// //     Player(){
// //         //loadMapFromFile();

// //         // Find player's initial position
// //         for (int i = 0; i < rows; ++i) {
// //             for (int j = 0; j < cols; ++j) {
// //                 if (OriginalMap[i][j] == '0') {
// //                     PlayerX = j;
// //                     PlayerY = i;
// //                     break;
// //                 }
// //             }
// //         }
// //     };
// //     void move(int dx, int dy){
// //         newPlayerX = PlayerX + dx;
// //         newPlayerY = PlayerY + dy;

// //         if (map[newPlayerY][newPlayerX] == '-') {
// //             map[PlayerY][PlayerX] = '-';
// //             map[newPlayerY][newPlayerX] = '0';
// //             PlayerX = newPlayerX;
// //             PlayerY = newPlayerY;
// //         }else if(map[newPlayerY][newPlayerX] == '1'){
// //             // Check if there is a box in front of the player
// //             // If there is, move the box
// //             if(map[newPlayerY + dy][newPlayerX + dx] == '-'){
// //                 push(dx, dy);
// //                 map[PlayerY][PlayerX] = '-';
// //                 map[newPlayerY][newPlayerX] = '0';
// //                 map[newPlayerY + dy][newPlayerX + dx] = '1';
// //                 PlayerX = newPlayerX;
// //                 PlayerY = newPlayerY;
// //             }
// //             // If there is no box, do nothing
// //             // If there is a box and a wall, do nothing
// //         }
// //     };
// //     ~Player(){
// //     };
// //     void push(int dx, int dy){
// //         box.pushed(dx, dy);
// //     };
// //     void PrintPlayer(){
// //         cout << PlayerX << " " << PlayerY << endl;
// //     };
// //     Box box;
// // };

// void resetMap() {
//     map = OriginalMap;
// }

// int main() {
//     loadMapFromFile();
//     Player player(rows, cols, map, OriginalMap);
//     Box box(rows, cols, map, OriginalMap);
//     char input;
//     do {
//         #ifdef __APPLE__
//         system("clear"); // Clear screen //mac
//         #endif
//         #ifdef _WIN32
//         system("cls"); // Clear screen //windows
//         #endif
//         printMap();
//         cout << "Use w to move up,"<< endl
//              << "s to move down," << endl
//              << "a to move left," << endl
//              << "d to move right" << endl
//              << "r to reset map" << endl
//              << "q to quit" << endl;
//         player.PrintPlayer();
//         box.PrintBox();

//         #ifdef __APPLE__
//         input = getch(); // Get user input
//         #endif

//         #ifdef _WIN32
//         input = _getch();
//         #endif

//         switch (input) {
//             case 'w': // Up
//                 player.move(0, -1);
//                 break;
//             case 's': // Down
//                 player.move(0, 1);
//                 break;
//             case 'a': // Left
//                 player.move(-1, 0);
//                 break;
//             case 'd': // Right
//                 player.move(1, 0);
//                 break;
//             case 'r': // Reset map
//                 //Player::~Player();
//                 //Box::~Box();
//                 resetMap();
//                 //Player player;
//                 //Box box;
//                 break;
//             case 'o': // Save map to file
//                 saveMapToFile();
//                 break;
//         }

//     } while (input != 'q'); // Quit when 'q' is pressed

//     return 0;
// }