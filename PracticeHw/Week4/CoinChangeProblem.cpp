#include<iostream>
using namespace std;

int main()
{
	int coins[4] = {1, 5, 10, 50};
	int price = 0;
    while (true){
        cout << "How much do you want to change: ";
        cin >> price;
        if(price == 0)
            break;
        int arr[price + 1];
	    for(int i = 0; i < price + 1; i++)
		    arr[i] = 0;
        arr[0] = 1;
        for(int i = 0; i < 4; i++){
		    for(int j = coins[i]; j < price + 1; j++)
			    arr[j] += arr[j - coins[i]];
	    }
        cout << "There are "<< arr[price] << " ways can change." << endl;
    }	
}
/*
int main(){
    while(cin > 0)
    int coin = 0;
    cout << "What's your coin: ";
    cin >> coin;
    cout << "There are "<< change(coin) << " ways can change.";
}
*/