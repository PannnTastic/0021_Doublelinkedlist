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

bool search (int rollno, node **previous, node **current){
    *previous = NULL;
    *current = START;
    while (*current != NULL && (*current)->noMhs != rollno)
    {
        *previous = *current;
        *current = (*current)->next;
    }
    return (*current != NULL);
}

void deletenode(){
    node *previous, *current;
    int rollno;

    cout << "\nMasukkan Nim yang ingin di hapus : ";
    cin >> rollno;

    if (START == NULL){
        cout << "List Kosong" << endl;
        return;
    }

    current = START;
    previous = NULL;

    while (current != NULL && current->noMhs != rollno)
    {
        previous = current;
        current = current->next;
    }

    if (current == NULL)
    {
        cout << "\033[31mNim yang anda cari " << rollno << " tidak ditemukan\033[0m" << endl;
        return;
    }

    if (current == START)
    {
        START = START->next;
        if (START != NULL)
        {
            START->prev = NULL;
        }
    }
    else{
        previous->next = current->next;
        if (current->next != NULL)
        {
            current->next->prev = previous;
        } 
    }

    delete current;
    cout << "\x1b[32mNim yang anda Masukkan " << rollno << " telah dihapus\x1b[0m" << endl;
    
    
    
}
