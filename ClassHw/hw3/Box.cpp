#include "Box.h"

Box::Box(Map& map){
    // Find box's initial position
    for (int i = 0; i < map.rows; ++i) {
        for (int j = 0; j < map.cols; ++j) {
            if (map.OriginalMap[i][j] == '1') {
                BoxX = j;
                BoxY = i;
                break;
            }
        }
    }
}

void Box::Pushed(int dx, int dy) {
    BoxX += dx;
    BoxY += dy;
}

void Box::PrintBox() {
    cout << BoxX << " " << BoxY << endl;
}