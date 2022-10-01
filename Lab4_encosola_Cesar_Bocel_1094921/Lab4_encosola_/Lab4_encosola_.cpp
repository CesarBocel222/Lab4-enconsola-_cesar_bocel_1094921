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
void contarLista(Tlista lista)
{
    int contador = 0;
    while (lista != NULL)
    {
        lista = lista->sig;
        contador++;
    }
    cout << "la cantidad de la lista es de " << contador << endl;
}
void UltimaPosicion(Tlista lista)
{
    int contador = 0;
    int mostrar = 0;
    while (lista != NULL)
    {
        mostrar = lista->nodo;
        lista = lista->sig;
        contador++;
    }
    cout << "la cantidad final de la lista es de " << mostrar << endl;
}
void eliminarElemento(Tlista& lista, int valor)
{
    Tlista p, ant;
    p = lista;

    if (lista != NULL)
    {
        while (p != NULL)
        {
            if (p->nodo == valor)
            {
                if (p == lista)
                    lista = lista->sig;
                else
                    ant->sig = p->sig;

                delete(p);
                return;
            }
            ant = p;
            p = p->sig;
        }
        cout << " Lista vaciada";
    }
    else
        cout << " Lista vacia..!";
}

void menu1()
{
    cout << "\n\t\tLISTA ENLAZADA SIMPLE\n\n";
    cout << " 1. Agregar a la lista              " << endl;
    cout << " 2. Limpiar lista                   " << endl;
    cout << " 3. Mostrar cantidad                " << endl;
    cout << " 4. Insertar en una posicion        " << endl;
    cout << " 5. Mostrar lista                   " << endl;
    cout << " 6. Buscar elemento                 " << endl;
    cout << " 7. Eliminar un elemento            " << endl;
    cout << " 8. Ultima posicion                 " << endl;
    cout << " 9. Ir a Ejercicio2                 " << endl;


    cout << "\n INGRESE OPCION: ";
}
struct carta {
    int numero = 0;
    char color = 'R';
    struct carta* sig;
};
    typedef struct carta* Tlistacarta;
void agregarcartasN(Tlistacarta& lista, int valor)
{
    Tlistacarta t, q= new(struct carta);
    q->numero = valor;
    q ->sig = NULL;

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
void agregarcartasC(Tlistacarta& lista, char col)
{
    Tlistacarta t, q = new(struct carta);
    q->color = col;
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
void Mostrarcartas(Tlistacarta lista)
{
    int i = 0;
    while (lista != NULL)
    {
        cout << ' ' << i + 1 << ") " << lista->numero  << lista->color << endl;
        lista = lista->sig;
        i++;
    }

}
void insertarN(Tlistacarta& lista, int valor,int pos)
{
    Tlistacarta q, t;
    int i;
    q = new(struct carta);
    q->numero = valor;

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
void insertarC(Tlistacarta& lista,char color, int pos)
{
    Tlistacarta q, t;
    int i;
    q = new(struct carta);
    q->color = color;

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
void menu2()
{
    cout << "\n\t\tLISTA ENLAZADA SIMPLE\n\n";
    cout << " 1. Agregar carta                   " << endl;
    cout << " 2. sacar carta alazar              " << endl;
    cout << " 3. Mostrar lista                   " << endl;
    cout << " 4. Insertar en una posicion        " << endl;
    cout << " 5. Finalizar                       " << endl;

    
    cout << " TABLERO                            " << endl; 
    cout << "  G1    G2     G3    G4    G5    G6   G7    " << endl;
    cout << "  1)    2)     3)    4)    5)    6)   7)   " << endl;
    cout << "        8)     9)    10)   11)   12)  13)  " << endl;
    cout << "               14)   15)   16)   17)  18)  " << endl;
    cout << "                     19)   20)   21)  22)  " << endl;
    cout << "                           23)   24)  25)  " << endl;
    cout << "                           26)   27)  28)  " << endl;
    cout << "                                 29)  30)  " << endl;
    cout << "                                      31)  " << endl;
    cout << "\n\t\t\n\n";
    cout << "\n INGRESE OPCION: ";
}

int main()
{
    Tlista lista = NULL;
    Tlistacarta lcartas = NULL;
    int opcion;     
    int _dato;  // elemenento a ingresar
    int pos;    // posicion a insertar
    char _color; //color de la carta

    do
    {
        menu1();  cin >> opcion;

        switch (opcion)
        {
        case 1:
            cout << "\n Numero a agregar: "; cin >> _dato;
            agregar(lista, _dato);
            break;

        case 2:
            cout << "\n Lista borrada\n\n";
            clear(lista);
            break;

        case 3:
            cout << "\n Cantidad en la lista\n\n";
            contarLista(lista);
            break;


        case 4:

            cout << "\n Numero a insertar: "; cin >> _dato;
            cout << " Posicion : ";       cin >> pos;
            insertar(lista, _dato, pos);
            break;


        case 5:
            cout << "\n\n Mostrar lista\n\n";
            MostrarLista(lista);
            break;


        case 6:
            cout << "\n Valor a buscar: "; cin >> _dato;
            buscarElemento(lista, _dato);
            break;

        case 7:

            cout << "\n Valor a eliminar: "; cin >> _dato;

            eliminarElemento(lista, _dato);
            break;

        case 8:
            cout << "\n Cantidad en la lista\n\n";
            UltimaPosicion(lista);
            break;
        }

        cout << endl << endl;
        system("pause");  system("cls");

    } while (opcion != 9);

    do
    {
        menu2();  cin >> opcion;

        switch (opcion)
        {
        case 1:
            cout << "\n Numero a agregar: "; cin >> _dato;
            if (_dato >= 1 && _dato <=13)
            {
                agregarcartasN(lcartas, _dato);
            }
            else
            {
                cout << "\n Error ";
                break;
            }
            cout << "\n Ingrese color: "; cin >> _color;
            cout << "\n Importante poner en mayusculas ";
            if (_color == 'N' || _color == 'R')
            {
                agregarcartasC(lcartas, _color);
            }
            break;

        case 2:
            if (lcartas == NULL)
            {
                cout << "\n No hay cartas ";
            }
            else
            {
                int random = rand();
                int i = 0;
                while (lista != NULL)
                {
                    i++;
                }
                random = rand() % i;
                cout << "\n La carta en la poscicion " << i << endl;
            }

            break;

        case 3:
            cout << "\n Cantidad en la lista\n\n";
            Mostrarcartas(lcartas);
            break;


        case 4:
            cout << "\n Insertar carta a mover: "; cin >> _dato;
            cout << "\n Ingrese color: "; cin >> _color;
            cout << " Posicion : ";       cin >> pos;
            insertarN(lcartas, _dato, pos);
            insertarC(lcartas, pos, pos);
            break;

            cout << endl << endl;
            system("pause");  system("cls");
        }
    } while (opcion != 5);
    system("pause");

    system("pause");
    return 0;
}
