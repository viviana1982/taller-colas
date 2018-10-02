#include <iostream>

using namespace std;
struct nodo{
    int nro;
    nodo *sgte;
};
//prototipo de funciones
    void pushcola(nodo *&, nodo *&, int);
    void popcola(nodo *&, nodo *&, int);
    bool ColaVacia(nodo *);


int main()
{
    nodo *frente= NULL;
    nodo *atras = NULL;
    int x, nro;
    printf("ingrese un numero\n");
    scanf("%d",&x);
    pushcola(frente, atras, x);
    printf("ingrese otro numero\n");
    scanf("%d",&nro);

    printf("\n");
    printf("mostrando datos de la cola\n");

    while(frente != NULL){
        popcola(frente, atras, x);
        if(frente != NULL){
            printf("%d %d",x,nro);
        }else{
            printf("%d %d",x,nro);
        }
    }

    return 0;
}

void pushcola(nodo *&frente, nodo *&atras, int x){
    nodo *nuevo_nodo =new nodo();

    nuevo_nodo-> nro = x;
    nuevo_nodo->sgte = NULL;
    if(ColaVacia(frente)){
      frente = nuevo_nodo;
    }else{
        atras->sgte = nuevo_nodo;
    }
    atras = nuevo_nodo;
    printf("los datos %d, %d se agrgo corretamente a la cola\n");

}

bool ColaVacia(nodo *frente){
    return(frente==NULL)? true: false;

}

void popcola(nodo *&frente, nodo *&atras, int x){
    x = frente->nro;
    nodo *p_aux = frente;

    if(frente==atras){
        frente = NULL;
        atras = NULL;

    }else {
        frente = frente ->sgte;
    }
    delete p_aux;
}
