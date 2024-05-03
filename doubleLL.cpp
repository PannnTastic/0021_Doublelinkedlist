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
