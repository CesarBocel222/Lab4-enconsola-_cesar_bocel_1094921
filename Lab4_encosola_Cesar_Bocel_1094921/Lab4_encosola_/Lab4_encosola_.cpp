#include "pch.h"
#include <iostream>
#include <stdlib.h>
using namespace std;
//creacion del nodo y de alghunas funciones basada de la pagina https://blog.martincruz.me/2012/10/listas-enlazadas-simples-en-c.html
struct nodo {
    int nodo;        // en este caso es un numero entero
    struct nodo* sig;
};

typedef struct nodo* Tlista;

void agregar(Tlista& lista, int valor)
{
    Tlista t, q = new(struct nodo);

    q->nodo = valor;
    q->sig = NULL;

    if (lista == NULL)
    {
        lista = q;
    }
    else
    {
        t = lista;
        while (t->sig != NULL)
        {
            t = t->sig;
        }
        t->sig = q;
    }

}
