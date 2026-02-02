#include <iostream>   
#include <vector>     
#include <string>     
#include <set>        
#include <random>     
#include <algorithm>  

using namespace std;

//general functions
vector<char> getValid(vector<vector<char>> pieces) {
    vector<char> valid;
    for (const auto& group : pieces) {
        valid.insert(valid.end(), group.begin(), group.end());
    }
    return valid;
}

bool samePiece(char a, char b, vector<vector<char>> pieces) {
    for (const auto& group : pieces) {
        if (find(group.begin(), group.end(), a) != group.end()
            &&
            find(group.begin(), group.end(), b) != group.end()) {
            return true;
        }
    }
    return false;
}

int rng(int finish) {
    
    random_device random;
    mt19937 gen(random());
    uniform_int_distribution<> dist(0, finish - 1);
    return dist(gen);
}

vector<string> gen(vector<vector<char>> pieceType, int count) {
    vector<string> result;
    set<string> seen;
    vector<char> validLetters = getValid(pieceType);
    int finish = static_cast<int>(validLetters.size());

    while (result.size() < count) {
        char first = validLetters[rng(finish)];
        char second = validLetters[rng(finish)];

        if (first == second) continue;
        if (samePiece(first, second, pieceType)) continue;

        string pair = { first, second };
        if (seen.count(pair)) continue;

        result.push_back(pair);
        seen.insert(pair);
    }
    return result;
}


// corners
vector<vector<char>> cornerPieces = {
    {'A', 'E', 'R'},
    {'B', 'Q', 'N'},
    {'D', 'F', 'I'},
    {'H', 'S', 'X'},
    {'L', 'U', 'G'},
    {'K', 'V', 'P'},
    {'O', 'T', 'W'}
};

//edges
vector<vector<char>> edgePieces = {
    {'A', 'Q'},
    {'B', 'M'},
    {'D', 'E'},
    {'L', 'F'},
    {'J', 'P'},
    {'O', 'T'},
    {'R', 'H'},
    {'U', 'K'},
    {'V', 'O'},
    {'S', 'W'},
    {'G', 'X'}
};

//cenetrs
vector<vector<char>> centerFaces = {
    {'B', 'C', 'D'},
    {'E', 'F', 'G', 'H'},
    {'I', 'J', 'K', 'L'},
    {'M', 'N', 'O', 'P'},
    {'Q', 'R', 'S', 'T'},
    {'U', 'V', 'W', 'X'}
};

//wings
vector<string> wings(int count) {
    vector<string> result;
    set<string> seen;

    vector<char> wingLetters = {
        'A','B','D','E','F','G','H','I','J','K',
        'L','M','N','O','P','Q','R','S','T','U',
        'V','W','X'
    };
    int finish = static_cast<int>(wingLetters.size());

    while (result.size() < count) {
        char first = wingLetters[rng(finish)];
        char second = wingLetters[rng(finish)];

        if (first == second) continue;

        string pair = { first, second };
        if (seen.count(pair)) continue;

        result.push_back(pair);
        seen.insert(pair);
    }

    return result;
}


int main() {
   
    int corner = 4;

    int edge = 6;

    int center = 8;

    int wing = 12;


    //corners
    vector<string> pairs = gen(cornerPieces, corner);
    cout << "\nGenerated corner pairs:\n";
    for (const string& p : pairs) {
        cout << p << endl;
    }


    //edges/midges
    vector<string> edgePairs = gen(edgePieces, edge);
    cout << "\nGenerated edge pairs:\n";
    for (const string& p : edgePairs) {
        cout << p << endl;
    }

    //centers
    vector<string> centerPairs = gen(centerFaces, center);
    cout << "\nGenerated center pairs:\n";
    for (const string& p : centerPairs) {
        cout << p << endl;
    }


    //wings
    vector<string> wingPairs = wings(wing);
    cout << "\nGenerated wing pairs:\n";
    for (const string& p : wingPairs) {
        cout << p << endl;
    }

    return 0;
}