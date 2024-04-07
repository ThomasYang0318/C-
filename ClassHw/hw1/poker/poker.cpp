#include "PokerCard.h"
#include <iostream>

using namespace std;

PokerCard::PokerCard(){};

void PokerCard::numTB(int count){
    for(int i = 0; i < 7; i++){
        if(count == 9)
            cout << num[count] << " ";
        else 
            cout << num[count] << " "; 
    }
};
/*
void PokerCard::numSide(int count){
    if(count == 9)
        cout << num[count];
    else 
        cout << " " << num[count]; 
};
*/

void PokerCard::suit1(int suit, int count){
    switch(suit){
    case 1:
        cout << num[count] << "     *     " << num[count];
        break;
    case 2:
        cout << num[count] << "     *     " << num[count];
        break;
    case 3:
        cout << num[count] << "   *   *   " << num[count];
        break;
    case 4:
        cout << num[count] << "     *     " << num[count];
        break;
    }
};

void PokerCard::suit2(int suit, int count){
    switch(suit){
    case 1:
        cout << num[count] << "     *     " << num[count];
        break;
    case 2:
        cout << num[count] << "    ***    " << num[count];
        break;
    case 3:
        cout << num[count] << "  *** ***  " << num[count];
        break;
    case 4:
        cout << num[count] << "   *****   " << num[count];
        break;
    }
};

void PokerCard::suit3(int suit, int count){
    switch(suit){
    case 1:
        cout << num[count] << "   *****   " << num[count];
        break;
    case 2:
        cout << num[count] << "   *****   " << num[count];
        break;
    case 3:
        cout << num[count] << "   *****   " << num[count];
        break;
    case 4:
        cout << num[count] << "  *** ***  " << num[count];
        break;
    }
};
void PokerCard::suit4(int suit, int count){
    switch(suit){
    case 1:
        cout << num[count] << "     *     " << num[count];
        break;
    case 2:
        cout << num[count] << "    ***    " << num[count];
        break;
    case 3:
        cout << num[count] << "    ***    " << num[count];
        break;
    case 4:
        cout << num[count] << "     *     " << num[count];
        break;
    }
};

void PokerCard::suit5(int suit, int count){
    switch(suit){
    case 1:
        cout << num[count] << "    ***    " << num[count];
        break;
    case 2:
        cout << num[count] << "     *     " << num[count];
        break;
    case 3:
        cout << num[count] << "     *     " << num[count];
        break;
    case 4:
        cout << num[count] << "    ***    " << num[count];
        break;
    }
};

/*
cout case 1:
        cout << "    **    " << endl
             << " ** ** **  " << endl
             << " ** *  ** " << endl
             << "    *    " << endl
             << "   ***   " << endl;
        }
        break;
    case 2:
        cout << "    *    " << endl
             << "   ***   " << endl
             << "  *****  " << endl
             << "   ***   " << endl
             << "    *    " << endl;
        break;
    case 3:
        cout << "  *   *  " << endl
             << " *** *** " << endl
             << "  *****  " << endl
             << "   ***   " << endl
             << "    *    " << endl;
        break;
    case 4:
        cout << "    *    " << endl
             << "  *****  " << endl
             << " *** *** " << endl
             << "    *    " << endl
             << "   ***   " << endl;
        break;
    }

*/
