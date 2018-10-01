#include <iostream>

using namespace std;
struct nodo{
    int nro;
    struct nodo *sgte;
};
typedef struct nodo *puntero;

class cola{
    public:
    cola(void);
    void Encolar(int);
    int Desencolar(void);
    bool ColaVacia(void);
    void mostrarCola(void);
    void VaciarCola(void);

    private:
    puntero delante;
    puntero atras;
};

cola::cola(void){
    delante = NULL;
    atras = NULL;
}

bool cola::ColaVacia(){
    if(delante=NULL)
        return true;
    else return false;

}

void cola::Encolar(int x){
    puntero p_aux;

    p_aux=new(struct nodo);
    p_aux->nro=x;
    p_aux->sgte=NULL;

    if(delante==NULL)
        delante=p_aux;
    else atras->sgte =p_aux;
    atras=p_aux;
}

int cola::Desencolar(void){
    int n;
    puntero p_aux;

    p_aux=delante;
    n=p_aux->nro;
    delante=(delante)->sgte;
    delete(p_aux);
    return n;
}

void cola::mostrarCola(void){
    puntero p_aux;
    p_aux=delante;
    while(p_aux!=NULL){
        printf("\n\t");
        printf("%d",p_aux->nro);
        p_aux=p_aux->sgte;
    }

}

void cola::VaciarCola(void){
    puntero p_aux, r_aux;
    p_aux=p_aux->sgte;

    while (p_aux!=NULL){
        r_aux=p_aux;
        p_aux=p_aux->sgte;
        delete(r_aux);
    }
    delante=NULL;
    atras = NULL;

}
int menu(void){

   printf("\n\n\t------------------------------------|\n");
   printf("\t|      IMPLEMENTACION DE UNA COLA   |\n");
   printf("\t|-----------------------------------|\n");
   printf("\t|                                   |\n");
   printf("\t|        1.INCOLAR                  |\n");
   printf("\n\t|        2.DESNCOLAR                |\n");
   printf("\n\t|        3.MOSTRAR COLA             |\n");
   printf("\n\t|        4.VACIAR COLA              |\n");
   printf("\n\t|        5.SALIR                    |\n");
   printf("\t|-----------------------------------|\n");
   printf("\t ingrese opcion: ");
}

int main()
{
   system("color 1f");
   cola cola;
   int x;
   int op;

   do{
    menu();
    scanf("%d",&op);

    switch(op){
    case 1:
        printf("\n\t ingrese el numero a encolar: ");
        scanf("%d",&x);
        //printf("%d",x);
        cola.Encolar(x);
        printf("\n\n\t agrgado numero %d", x);
        printf("\n\n\t");
        break;

    case 2:
        if(cola.ColaVacia()==true)
            printf("\n\n\t cola vacia...");
        else{
            x=cola.Desencolar();
            printf("\n\n\t eliminado numero ",x);
            printf("\n\n\t");
        }
        break;

    case 3:
        printf("\n\n\t mostrando cola");
        printf("\n\n");
        if(cola.ColaVacia()!=true)
            cola.mostrarCola();
        else
            printf("\n\n\tcola vacia..");
            printf("\n\n");
        break;

    case 4:
        cola.VaciarCola();
        printf("\n\n\tcola eliminada..");
        printf("\n\n");
    break;

    default:
        printf("\n\n");
        printf("\n\n\tingrese una opcion valida...");

    }
    system("pause");
    system("cls");

   }while(op!=5);

    return 0;
}
