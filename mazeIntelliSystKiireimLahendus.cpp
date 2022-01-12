#include <iostream>
#include <map>
#include <bits/stdc++.h>
#include <utility>
using namespace std;
 
pair <int, int> startPunkt;
pair <int, int> exitPunkt;
vector<vector<char>> v2li
{
    {'#','#','#','#','#','#','#','S','#'},
    {'#','X','X','X','X','X','X','X','#'},
    {'#','X','#','#','X','#','#','X','#'},
    {'#','X','#','#','X','#','#','X','#'},
    {'#','X','#','#','X','#','#','X','#'},
    {'#','X','X','X','X','X','X','X','#'},
    {'#','#','E','#','#','#','#','#','#'}
};

int findStart(){
    for(int i=0; i<v2li.size(); i++){
        for(int j=0; j<v2li[0].size(); j++){
            if(v2li[i][j] == 'S'){
                startPunkt.first = i;
                startPunkt.second = j;
                return 1;
            }
        }
    }
    cout << "Start ei olnud leitud!" << endl;
    return 0;
}
int findExit(){
    for(int i=0; i<v2li.size(); i++){
        for(int j=0; j<v2li[0].size(); j++){
            if(v2li[i][j] == 'E'){
                exitPunkt.first = i;
                exitPunkt.second = j;
                return 1;
            }
        }
    }
    cout << "Exit ei olnud leitud!" << endl;
    return 0;
}

void print(){
    for(int i=0; v2li.size() > i; i++){
        for(int j=0; v2li[0].size() > j; j++){
            cout << v2li[i][j];
        }
        cout << endl;
    }
    cout << endl;
}
 
bool kasSees(pair<int,int> punkt){
    if(punkt.first<7 & punkt.second<9 & punkt.first>=0 & punkt.second>=0){return true;}
    return false;
}
 
vector< pair<int,int> > kusOli;
vector< pair<int,int> > kiiremTee;
int kiiremTeePikkus = 99999;
vector< vector< pair<int,int> > > nodeRoad;

void printKiirem(){
    for(int i=0; kiiremTee.size()>i; i++){
        cout << "(" << kiiremTee[i].first << ":" << kiiremTee[i].second << ")" << endl;
    }
}

void nextSamm(pair<int,int> punkt){
    //cout << punkt.first << "-" << punkt.second << endl;
    if(kusOli.size()+2>=kiiremTeePikkus){return;}
    kusOli.push_back(punkt);
    pair<int,int> uusPunkt;
    if(kasSees(punkt)){
        uusPunkt.first = punkt.first;
        uusPunkt.second = punkt.second+1;
        if(kasSees(uusPunkt)){ //paremale
            if(v2li[uusPunkt.first][uusPunkt.second] == 'E'){
                kusOli.push_back(uusPunkt);
                kiiremTee = kusOli;
                kiiremTeePikkus = kiiremTee.size();
                kusOli.pop_back();
                kusOli.pop_back();
                return;
            }
            if(v2li[uusPunkt.first][uusPunkt.second] == 'X'){
                v2li[uusPunkt.first][uusPunkt.second] = '.';
                nextSamm(uusPunkt);
                v2li[uusPunkt.first][uusPunkt.second] = 'X';
            } 
        }
        uusPunkt.first = punkt.first-1;
        uusPunkt.second = punkt.second;
        if(kasSees(uusPunkt)){ //ylesse
            if(v2li[uusPunkt.first][uusPunkt.second] == 'E'){
                kusOli.push_back(uusPunkt);
                kiiremTee = kusOli;
                kiiremTeePikkus = kiiremTee.size();
                kusOli.pop_back();
                kusOli.pop_back();
                return;
            }
            if(v2li[uusPunkt.first][uusPunkt.second] == 'X'){
                v2li[uusPunkt.first][uusPunkt.second] = '.';
                nextSamm(uusPunkt);
                v2li[uusPunkt.first][uusPunkt.second] = 'X';
            }
        }
        uusPunkt.first = punkt.first;
        uusPunkt.second = punkt.second-1;
        if(kasSees(uusPunkt)){ //vasakule
            if(v2li[uusPunkt.first][uusPunkt.second] == 'E'){
                kusOli.push_back(uusPunkt);
                kiiremTee = kusOli;
                kiiremTeePikkus = kiiremTee.size();
                kusOli.pop_back();
                kusOli.pop_back();
                return;
            }
            if(v2li[uusPunkt.first][uusPunkt.second] == 'X'){
                v2li[uusPunkt.first][uusPunkt.second] = '.';
                nextSamm(uusPunkt);
                v2li[uusPunkt.first][uusPunkt.second] = 'X';
            } 
        }
        uusPunkt.first = punkt.first+1;
        uusPunkt.second = punkt.second;
        if(kasSees(uusPunkt)){ //alla
            if(v2li[uusPunkt.first][uusPunkt.second] == 'E'){
                kusOli.push_back(uusPunkt);
                kiiremTee = kusOli;
                kiiremTeePikkus = kiiremTee.size();
                kusOli.pop_back();
                kusOli.pop_back();
                return;
            }
            if(v2li[uusPunkt.first][uusPunkt.second] == 'X'){
                v2li[uusPunkt.first][uusPunkt.second] = '.';
                nextSamm(uusPunkt);
                v2li[uusPunkt.first][uusPunkt.second] = 'X';
            }
        }
        kusOli.pop_back();
    }
}
 
int main(){
    if(findStart() & findExit()){
        print();
        nextSamm(startPunkt);
        printKiirem();
    }
    else{ cout << "Labyrinti ei saa lahendada" << endl; }
}