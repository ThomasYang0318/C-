#include <iostream>
#include <fstream>
#include <vector>
#include <string>
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
int _getch() {
    termios oldattr, newattr;
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
    Player player = Player();
    vector<Destination> destinations = vector<Destination>();
    //vector<Box> boxes = vector<Box> ();
    string mapname;
    cout << "Welcome to Sokoban!" << endl;
    cout << "Enter the map name: ";
    cin >> mapname;
    Map map;
    map.LoadMap(mapname, player, destinations);

    int count = 0;
    char input;
    do {
        #ifdef __APPLE__
        system("clear"); // Clear screen //mac
        #endif
        #ifdef _WIN32
        system("cls"); // Clear screen //windows
        #endif
        map.ShowMap();

        // for(int i = 0; i < destinations.size(); i++){
        //     destinations[i].Display();
        // }

        cout << endl << "0 is player, 1 is box, 2 is destination"<< endl
             << "- is road, / is wall, I is box on destination" << endl
             << "--------------------------------------------" << endl
             << "Use w,a,s,d to move the player" << endl
             << "w to move up,"<< endl
             << "s to move down," << endl
             << "a to move left," << endl
             << "d to move right" << endl
             << "r to reset map" << endl
             << "q to quit" << endl
             << "--------------------------------------------" << endl;

        input = _getch();

        int x = player.GetX();
        int y = player.GetY();
        int dx = 0;
        int dy = 0;
        switch (input) {
            case 'w': // Up
                dx = 0;
                dy = -1;
                break;
            case 's': // Down
                dx = 0;
                dy = 1;
                break;
            case 'a': // Left
                dx = -1;
                dy = 0;
                break;
            case 'd': // Right
                dx = 1;
                dy = 0;
                break;
            case 'r': // Reset map
                map.Reset(mapname, player, destinations);
                count = 0;
                break;
        }
        // for(int i = 0; i < destinations.size(); i++){
        //     if(player.GetX() == destinations[i].GetX() && player.GetY() == destinations[i].GetY()){
        //         destinations[i].ChangeObjectInside(1);
        //         count++;
        //     }
        // }
        if(map.GetMap(x + dx, y + dy) == '-'){
            for(int i = 0; i < destinations.size(); i++){
                if(player.GetX() == destinations[i].GetX() && player.GetY() == destinations[i].GetY()){
                    destinations[i].ChangeObjectInside(0);
                    count--;
                }
            }
            player.Move(dx, dy);
            map.ChangeMap(x, y, '-');
            map.ChangeMap(player.GetX(), player.GetY(), '0');
        }
        else if(map.GetMap(x + dx, y + dy) == '1'){
            for(int i = 0; i < destinations.size(); i++){
                if(player.GetX() == destinations[i].GetX() && player.GetY() == destinations[i].GetY()){
                    destinations[i].ChangeObjectInside(0);
                    count--;
                }
            }
            if(map.GetMap(x + 2 * dx, y + 2 * dy) == '-'){
                player.Move(dx, dy);
                map.ChangeMap(x, y, '-');
                map.ChangeMap(player.GetX(), player.GetY(), '0');
                map.ChangeMap(player.GetX() + dx, player.GetY() + dy, '1');
            }
            else if(map.GetMap(x + 2 * dx, y + 2 * dy) == '2'){
                player.Move(dx, dy);
                map.ChangeMap(x, y, '-');
                map.ChangeMap(player.GetX(), player.GetY(), '0');
                map.ChangeMap(player.GetX() + dx, player.GetY() + dy, 'I');
                for(int i = 0; i < destinations.size(); i++){
                    if(destinations[i].GetX() == player.GetX() + dx && destinations[i].GetY() == player.GetY() + dy){
                        destinations[i].ChangeObjectInside(1);
                        count++;
                    }
                }
            }
            if(map.CheckGameOver(player.GetX() + dx, player.GetY() + dy, destinations) && map.GetMap(player.GetX() + dx, player.GetY() + dy) == '1'){
                #ifdef __APPLE__
                system("clear"); // Clear screen //mac
                #endif
                #ifdef _WIN32
                system("cls"); // Clear screen //windows
                #endif
                map.ShowMap();
                cout << "Boxes can't move, game over!" << endl;
                char input;
                cout << "Press any key to quit" << endl;
                input = _getch();
                return 0;
            }
        }
        else if(map.GetMap(x + dx, y + dy) == '2'){
            for(int i = 0; i < destinations.size(); i++){
                if(player.GetX() == destinations[i].GetX() && player.GetY() == destinations[i].GetY()){
                    destinations[i].ChangeObjectInside(0);
                    count--;
                }
            }
            player.Move(dx, dy);
            map.ChangeMap(x, y, '-');
            map.ChangeMap(player.GetX(), player.GetY(), '0');
            for(int i = 0; i < destinations.size(); i++){
                if(destinations[i].GetX() == player.GetX() && destinations[i].GetY() == player.GetY()){
                    destinations[i].ChangeObjectInside(1);
                    count++;
                }
            }
        }
        else if(map.GetMap(x + dx, y + dy) == 'I' && (map.GetMap(x + 2 * dx, y + 2 * dy) == '-' || map.GetMap(x + 2 * dx, y + 2 * dy) == '2')){
            for(int i = 0; i < destinations.size(); i++){
                if(player.GetX() == destinations[i].GetX() && player.GetY() == destinations[i].GetY()){
                    destinations[i].ChangeObjectInside(0);
                    count--;
                }
            }
            player.Move(dx, dy);
            map.ChangeMap(x, y, '-');
            map.ChangeMap(player.GetX(), player.GetY(), '0');
            if(map.GetMap(player.GetX() + dx, player.GetY() + dy) == '-'){
                map.ChangeMap(player.GetX() + dx, player.GetY() + dy, '1');
            }
            else if(map.GetMap(player.GetX() + dx, player.GetY() + dy) == '2'){
                map.ChangeMap(player.GetX() + dx, player.GetY() + dy, 'I');
                for(int i = 0; i < destinations.size(); i++){
                    if(destinations[i].GetX() == player.GetX() + dx && destinations[i].GetY() == player.GetY() + dy){
                        destinations[i].ChangeObjectInside(1);
                        count++;
                    }
                }
            }
            if(map.CheckGameOver(player.GetX() + dx, player.GetY() + dy, destinations) && map.GetMap(player.GetX() + dx, player.GetY() + dy) == '1'){
                #ifdef __APPLE__
                system("clear"); // Clear screen //mac
                #endif
                #ifdef _WIN32
                system("cls"); // Clear screen //windows
                #endif
                map.ShowMap();
                cout << "Boxes can't move, game over!" << endl;
                char input;
                cout << "Press any key to quit" << endl;
                input = _getch();
                return 0;
            }
        }
        for(int i = 0; i < destinations.size(); i++){
            if(destinations[i].ObjectInside() == false){
                map.ChangeMap(destinations[i].GetX(), destinations[i].GetY(), '2');
            }
        }
        for(int i = 0; i < destinations.size(); i++){
            if(count == destinations.size()){
                bool isAtDestination = false;
                for(int i = 0; i < destinations.size(); i++){
                    if(player.GetX() == destinations[i].GetX() && player.GetY() == destinations[i].GetY()){
                        isAtDestination = true;
                        break;
                    }
                }
                if(!isAtDestination){
                    #ifdef __APPLE__
                    system("clear"); // Clear screen //mac
                    #endif
                    #ifdef _WIN32
                    system("cls"); // Clear screen //windows
                    #endif
                    map.ShowMap();
                    // player.Display();
                    // cout << "Number of destinations: " << destinations.size() << endl;
                    // cout << count << endl;
                    // for(int i = 0; i < destinations.size(); i++){
                    //     destinations[i].Display();
                    // }
                    cout << "You win!" << endl;
                    char input;
                    cout << "Press any key to quit" << endl;
                    input = _getch();
                    return 0;
                }
            }
        }
    } while (input != 'q'); // Quit when 'q' is pressed
    if(input == 'q'){
        #ifdef __APPLE__
        system("clear"); // Clear screen //mac
        #endif
        #ifdef _WIN32
        system("cls"); // Clear screen //windows
        #endif
        cout << "Thanks for playing!" << endl;
        char input;
        cout << "Press any key to quit" << endl;
        input = _getch();
        return 0;
    }
    return 0;
}