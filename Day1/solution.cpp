#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]){
    if(argc <= 1){
        cerr << "No input file" << endl;
        return EXIT_FAILURE;
    }

    ifstream inputFile(argv[1]);

    if(!inputFile.is_open()){
        cerr << "Can't open file." << endl;
        return EXIT_FAILURE;
    }

    int value;
    vector<int> list1;
    vector<int> list2;

    while(!inputFile.eof()){
        inputFile >> value;
        list1.push_back(value);

        inputFile >> value;
        list2.push_back(value);
    }

    inputFile.close();

    // First-half
    stable_sort(list1.begin(), list1.end());
    stable_sort(list2.begin(), list2.end());

    int distance;

    for(size_t i = 0; i < list1.size(); i++){
        int d = list2[i] - list1[i];
        distance += max(-d, d);
    }

    cout << distance << endl;

    //Second-Half
    int similarity = 0;
    map<int, int> freq;

    for(int x : list2){
        freq[x]++;
    }

    for(int x : list1){
        similarity += x * freq[x];
    }

    cout << similarity << endl;

    return 0;
}
