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
void clear(Tlista& lista)
{
    struct nodo* p;
    while (lista != NULL)
    {
        p = lista;
        lista = lista->sig;
        delete(p);
    }
}
int insertarAntesoDespues()
{
    int _op, band;
    cout << endl;
    cout << "\t 1. Antes de la posicion           " << endl;
    cout << "\t 2. Despues de la posicion         " << endl;

    cout << "\n\t Opcion : "; cin >> _op;

    if (_op == 1)
        band = -1;
    else
        band = 0;

    return band;
}
void insertar(Tlista& lista, int valor, int pos)
{
    Tlista q, t;
    int i;
    q = new(struct nodo);
    q->nodo = valor;

    if (pos == 1)
    {
        q->sig = lista;
        lista = q;
    }
    else
    {
        int x = insertarAntesoDespues();
        t = lista;

        for (i = 1; t != NULL; i++)
        {
            if (i == pos + x)
            {
                q->sig = t->sig;
                t->sig = q;
                return;
            }
            t = t->sig;
        }
    }
    cout << "   Error...Posicion no encontrada..!" << endl;
}
void MostrarLista(Tlista lista)
{
    int i = 0;
    while (lista != NULL)
    {
        cout << ' ' << i + 1 << ") " << lista->nodo << endl;
        lista = lista->sig;
        i++;
    }

}
void buscarElemento(Tlista lista, int valor)
{
    Tlista q = lista;
    int i = 1, band = 0;

    while (q != NULL)
    {
        if (q->nodo == valor)
        {
            cout << endl << " Encontrada en posicion " << i << endl;
            band = 1;
        }
        q = q->sig;
        i++;
    }

    if (band == 0)
        cout << "\n\n Numero no encontrado..!" << endl;
}