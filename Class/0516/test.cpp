#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char** argv ){
    if(argc != 3){
        cout << "Usage: ./a.out input_file output_file" << endl;
        return 1;
    }

    ifstream file(argv[1], ios::in);
    ofstream output(argv[2], ios::out);

    for(int i = 0; i < argc; i++){
        cout << argv[i] << endl;
    }

    return 0;
}