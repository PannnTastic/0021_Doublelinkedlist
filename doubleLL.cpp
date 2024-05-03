#include<iostream>
using namespace std;

struct  node
{
    int noMhs;
    string name;
    node* next;
    node* prev;
};

node* START = NULL;

void addnode(){
    node* nodebaru = new node();
    cout << "Masukkan NIM : ";
    cin >> nodebaru->noMhs;
    cout << "Masukkan Nama : ";
    cin >> nodebaru->name;
