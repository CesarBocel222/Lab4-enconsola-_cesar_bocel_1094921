#include "pch.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

struct nodo {
    int nodo;        // en este caso es un numero entero
    struct nodo* sig;
};

typedef struct nodo* Tlista;

