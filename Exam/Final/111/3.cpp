#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>

using namespace std;

void BuildNameMapAndList(map<string, int> &NameMap, vector<int> &followlist ,string name){
    if(NameMap.find(name) == NameMap.end()){
        NameMap[name] = NameMap.size();
    }
    followlist.push_back(NameMap.find(name)->second);
}

int main(int argc, char **argv){
    if(argc != 4){
        cout << "Usage: ./a.out input.txt output.txt output.txt" << endl;
        exit(0);
    }

    ifstream snfile(argv[1], ios::in);
    ofstream out1(argv[2], ios::out);
    ofstream out2(argv[3], ios::out);

    if(!snfile || !out1 || !out2){
        cout << "Fail to open " << argv[1] << "/" << argv[2] << "/" << argv[3] << endl;
        exit(0);
    }
    
    vector< vector<int> > SoNet;

    map<string, int> NameMap;
    char line[256];

    snfile.getline(line, 256);
    while(!snfile.eof()){
        vector<int> followlist;
        string s(line);

        int pos = s.find("");
        while(pos != string::npos){
            if(pos != 0){
                BuildNameMapAndList(NameMap, followlist, s.substr(0, pos));
            }
            s = s.substr(pos+1);
            pos = s.find("");
        }
        if(s.length() != 0){
            BuildNameMapAndList(NameMap, followlist, s);
        }

        SoNet.push_back(followlist);
        snfile.getline(line, 256);
    }

    for(map<string, int>::iterator it = NameMap.begin(); it != NameMap.end(); it++){
        out1 << it->second << " " << it->first << endl;
    }

    for(int i = 0; i < SoNet.size(); i++){
        for(int j = 0; j < SoNet[i].size(); j++){
            out2 << SoNet[i][j] << " ";
        }
        out2 << endl;
    }
    return 0;
}