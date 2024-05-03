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
    if (START == NULL || nodebaru->noMhs <= START -> noMhs){
        if(START != NULL && nodebaru->noMhs == START -> noMhs){
            cout << "NIM sudah ada " << endl;
            return;
        }
        nodebaru ->next = START;
        if (START != NULL){
            START->prev = nodebaru;
        }
        nodebaru->prev = NULL;
        START = nodebaru;
    }
    else{
        node *current = START;
        node *previous = NULL;

        while ( current != NULL && current->noMhs < nodebaru->noMhs){
            previous = current;
            current = current->next;
        }

        nodebaru->next = current;
        nodebaru->prev = previous;

        if (current != NULL){
            current->prev = nodebaru;
        }

        if ( previous != NULL){
            previous->next = nodebaru;
        }
        else{
            START = nodebaru;
        }
    }
}

bool search (){
    
}
