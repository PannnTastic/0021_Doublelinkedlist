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

bool listempty(){
    return (START == NULL);
}

void traverse (){
    if (listempty())
    {
        cout << "List Kosong " << endl;
    }
    else{
        cout << "\nRecords in ascending order of roll number are : " << endl;
        node *current = START;
        while (current != NULL){
            cout << current->noMhs << " " << current->name << endl;
            current = current->next;
        }
    }  
}

void revtraverse (){
    if (listempty()){
        cout << "\nList Kosong " << endl;
    }
    else{
        cout << "\nRecords in descending order of roll number are :" <<endl;
        node *current = START;
        while (current->next != NULL)
        {
            current = current->next;
        }
        while (current != NULL)
        {
            cout << current->noMhs << " " << current->name << endl;
            current = current->prev;
        }    
    }
}

void searchdata(){
    if (listempty() == true){
        cout << "\nList kosong\n";
    }
    node *prev, *curr;
    prev = curr = NULL;
    cout << "\nMasukkan Nim yang ingin dicari : ";
    int num;
    cin >> num;
    if (search(num, &prev, &curr)== false){
        cout << "Nim tidak ditemukan\n";
    }
    else{
        cout << "\nNim ditemukan\n";
        cout << "\nNIM : "<< curr->noMhs <<endl;
        cout << "\nNama : " << curr->name << endl;
    }
}

int main (){
    while (true)
    {
        try
        {
            cout << "\nPilihan\n";
            cout << "1. Tambahkan Data\n";
            cout << "2. Hapus Data\n";
            cout << "3. Lihat semua data Ascending\n";
            cout << "4. Lihat semnua data Descending\n";
            cout << "5. Cari Data\n";
            cout << "6. Keluar\n";
            cout << "\nMasukkan Pilihan : ";
            int pil;
            cin >> pil;

            switch (pil){
                case 1 : addnode();
                    break;
                case 2 : deletenode();
                    break;
                case 3 : traverse();
                    break;
                case 4 : revtraverse();
                    break;
                case 5 : searchdata();
                    break;
                case 6 : 
                    return 0;
                default : 
                    cout << "\nInvalid option\n";
                    break;
            }
        }
        catch(exception & e)
        {
            cout << "Periksa kembali pilihan yang dimasukkan\n";
        }
        
    }
    
}


