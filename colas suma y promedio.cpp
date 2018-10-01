#include<iostream>
#include<conio.h>
#include<string.h>
using namespace std;

struct nodo{
	int dato;
	struct nodo *sgte;
};

void pushcola(nodo *&, nodo *&, int);
bool ColaVacia(nodo *&);
void popcola(nodo *&, nodo *&, int);


int main () {
    nodo *frente = NULL;
    nodo *atras = NULL;
    int dato, x, cont, suma=0;
    int promedio;

    printf("ingrese el numero de elementos a sumar\n");
    scanf("%d",&x);
    pushcola(frente, atras,x);
    cont =1;

    while(cont<=x){
        suma += cont;
        cont++;
    }

    printf("\n la suma es %d: \n",suma);
    promedio = suma/x;
    printf("el promedio es: %d \n",promedio);
    printf("\n");

    while(frente != NULL){
        popcola(frente, atras, dato);
        if(frente != NULL){
            printf("%d",suma,promedio);
        }else{
            printf("%d %d\n",suma,promedio);
        }
    }


	return 0;
}

void pushcola(nodo *&frente, nodo *&atras, int x){
	nodo *nuevo_nodo = new nodo();
	nuevo_nodo-> dato = x;
	nuevo_nodo-> sgte = NULL;

	if(ColaVacia(frente)){
		frente = nuevo_nodo;
	}else{
		atras->sgte = nuevo_nodo;
	}
	atras = nuevo_nodo;
	printf("el dato %d se agrego corectamente a la cola \n", x);
}

bool ColaVacia(nodo *&frente){
	return (frente==NULL)?true : false;
}

void popcola(nodo *&frente, nodo *&atras, int x){
    x=frente->dato;
    nodo *aux = frente;

    if(frente==atras){
        frente = NULL;
        atras = NULL;
    }else{
        frente = frente->sgte;
    }
    delete aux;
}
