#include <stdio.h>
#include <stdlib.h>
typedef struct a
{
    struct a *d;
    int z;
    struct a *iz;
}arbol;


void asignaarbol(arbol**);
void creaarbol(arbol*);
void preorden(arbol*);
void inorden(arbol*);
void posorden(arbol*);
void creaABB(arbol**);
void llenaABB(arbol**,int);
void busABB(arbol*);
int busqueda(arbol*,int);
void elABB(arbol**);
int borraABB(arbol**,arbol*,int);
void posli(arbol**);
void inor(arbol*,int*);
int pidval(void);
char opcion(void);
char pidvalch(void);


int main()
{
    arbol *p=NULL;
    int a,b=0;
    do
    {
        system("cls");
        printf("ARBOLES\n");
        printf("1-CREAR ARBOL BINARIO\n2-IMPRIME PREORDEN\n3-IMPRIME INORDEN\n4-IMPRIME POSORDEN\n5-INSERTA ELEMENTOS EN UN ARBOL BINARIO DE BUSQUEDA\n");
        printf("6-BUSCA ELEMENTO EN UN ABB\n7-BORRA UN ELEMENTO EN UN ABB\n8-TERMINAR\n");
        printf("QUE DESEAS HACER=");
        a=pidval();
        switch(a)
        {
            case 1:
              asignaarbol(&p);
              creaarbol(p);
              break;
            case 2:
                system("cls");
                if(p==NULL)
                   printf("ARBOL VACIO\n");
                preorden(p);
                system("pause");
                break;
            case 3:
                system("cls");
                if(p==NULL)
                   printf("ARBOL VACIO\n");
                inorden(p);
                system("pause");
                break;
            case 4:
                system("cls");
                if(p==NULL)
                   printf("ARBOL VACIO\n");
                posorden(p);
                system("pause");
                break;
            case 5:
                if(b==0)
                {
                    posli(&p);
                    p=NULL;
                    b=1;
                }
                creaABB(&p);
                break;
            case 6:
                busABB(p);
                break;
            case 7:
                elABB(&p);
                break;
        }
    }
    while(a!=8);
    posli(&p);
    return(0);
}


int pidval(void)
{
    char c;
    int z,a;
    do
    {
        fflush(stdin);
        a=scanf("%d%c",&z,&c);
        if(a!=2||c!='\n')
            printf("DATO INCORRECTO POR FAVOR INGRESA UN NUMERO VALIDO\n");
    }
    while(a!=2||c!='\n');
    return(z);
}


char opcion(void)
{
    char a;
    do
    {
        printf("¿Que Deseas Hacer?=");
        a=pidvalch();
        a=toupper(a);
        if(a!='S'&&a!='N')
            printf("OPCION INVALIDA\n");
    }
    while(a!='S'&&a!='N');
    return(a);
}


char pidvalch(void)
{
    char m,h;
    int a;
    do
    {
        fflush(stdin);
        a=scanf("%c%c",&m,&h);
        if(a!=2||h!='\n')
              printf("INTENTA DE NUEVO\n");
    }
    while(a!=2||h!='\n');
    return(m);
}


void asignaarbol(arbol **p)
{
    *p=(arbol*)malloc(sizeof(arbol));
    if(*p==NULL)
    {
        printf("SIN MEMORIA\n");
        free(*p);
        system("pause");
        exit(1);
    }
}


void creaarbol(arbol *p)
{
    system("cls");
    printf("ALGORITMO QUE CREA UN ARBOL\n");
    char c;
    arbol *q;
    printf("DAME UN NUMERO=");
    p->z=pidval();
    printf("EL NODO TIENE HIJO IZQUIERDO=");
    c=opcion();
    if(c=='S')
    {
         asignaarbol(&q);
         p->iz=q;
         creaarbol(q);
    }
    else
        p->iz=NULL;
    printf("EL NODO TIENE HIJO DERECHO=");
    c=opcion();
    if(c=='S')
    {
         asignaarbol(&q);
         p->d=q;
         creaarbol(q);
    }
    else
        p->d=NULL;
}


void preorden(arbol *p)
{
    if(p!=NULL)
    {
        printf("%d\t",p->z);
        preorden(p->iz);
        preorden(p->d);
    }
}


void inorden(arbol *p)
{
    if(p!=NULL)
    {
        inorden(p->iz);
        printf("%d\t",p->z);
        inorden(p->d);
    }
}


void posorden(arbol *p)
{
    if(p!=NULL)
    {
        posorden(p->iz);
        posorden(p->d);
        printf("%d\t",p->z);
    }
}


void creaABB(arbol **p)
{
    int n;
    system("cls");
    printf("NUMERO A INSERTAR=");
    n=pidval();
    if(*p==NULL)
    {
        asignaarbol(&(*p));
        (*p)->z=n;
        (*p)->iz=NULL;
        (*p)->d=NULL;
    }
    else
        llenaABB(&(*p),n);
}


void llenaABB(arbol **p,int n)
{
    arbol *q;
    if(n<=((*p)->z))
    {
        if((*p)->iz==NULL)
        {
            asignaarbol(&q);
            (*p)->iz=q;
            q->z=n;
            q->iz=NULL;
            q->d=NULL;
        }
        else
            llenaABB(&(*p)->iz,n);
    }
    else
    {
        if((*p)->d==NULL)
        {
            asignaarbol(&q);
            (*p)->d=q;
            q->z=n;
            q->iz=NULL;
            q->d=NULL;
        }
        else
            llenaABB(&(*p)->d,n);
    }
}


void busABB(arbol *p)
{
    int n,z;
    system("cls");
    printf("QUE ELEMENTO DESEAS BUSCAR\n");
    n=pidval();
    if(p==NULL)
    {
        printf("ARBOL VACIO\n");
        system("pause");
    }
    else
        z=busqueda(p,n);
    if(z==0)
    {
        printf("NO EXISTE EL ELEMENTO\n");
        system("pause");
    }
}


int busqueda(arbol *p,int n)
{
    int a=0;
    if(p!=NULL)
    {
      if(p->z==n)
        {
             printf("ELEMENTO EXISTENTE =%d\n",p->z);
             system("pause");
             a=1;
        }
         else
            if(p->z<n)
                a=busqueda(p->d,n);
            else
                a=busqueda(p->iz,n);
    }
    return(a);
}


void elABB(arbol **p)
{
    int n,z;
    system("cls");
    arbol *k=NULL;
    printf("QUE ELEMENTO DESEAS BORRAR=");
    n=pidval();
    if(*p==NULL)
    {
        printf("ARBOL VACIO\n");
        system("pause");
    }
    else
        z=borraABB(&(*p),k,n);
    if(z==0)
    {
        printf("NO EXISTE EL ELEMENTO\n");
        system("pause");
    }
}


int borraABB(arbol **p,arbol *k,int n)
{
    int a=0,b=0;
    if(*p!=NULL)
    {
      if((*p)->z==n)
      {
          a=1;
            if(k==NULL)
            {
                if((*p)->d==NULL&&(*p)->iz==NULL)
                {
                     free(*p);
                     *p=NULL;
                }
                else
                    if((*p)->d!=NULL&&(*p)->iz!=NULL)
                        {
                            inor((*p)->iz,&b);
                            (*p)->z=b;
                            a=borraABB(&((*p)->iz),*p,b);
                        }
                    else
                        if((*p)->d!=NULL&&(*p)->iz==NULL)
                          {
                             k=*p;
                            *p=(*p)->d;
                            free(k);
                          }
                        else
                           if((*p)->iz!=NULL&&(*p)->d==NULL)
                            {
                                k=*p;
                                *p=(*p)->iz;
                                free(k);
                            }

            }
            else//k!=NULL
            {
                if((*p)->d==NULL&&(*p)->iz==NULL)
                {
                        if(k->iz==*p)
                         {
                             free(*p);
                             *p=k;
                             (*p)->iz=NULL;
                         }
                         else
                         {
                             free(*p);
                             *p=k;
                             (*p)->d=NULL;
                         }
                }
                else
                    if((*p)->d!=NULL&&(*p)->iz!=NULL)
                    {
                            inor((*p)->iz,&b);
                            (*p)->z=b;
                            a=borraABB(&((*p)->iz),NULL,b);
                    }
                    else
                        if((*p)->d!=NULL&&(*p)->iz==NULL)
                        {
                            if(k->z>(*p)->z)
                            {
                                   arbol *w=NULL;
                                   w=*p;
                                   *p=k;
                                   (*p)->iz=(w)->d;
                                   free(w);
                            }
                            else
                            {
                                   arbol *w=NULL;
                                   w=*p;
                                   *p=k;
                                   (*p)->d=(w)->d;
                                   free(w);
                            }
                        }
                        else
                           if((*p)->iz!=NULL&&(*p)->d==NULL)
                            {
                               if(k->z>(*p)->z)
                               {
                                   arbol *w=NULL;
                                   w=*p;
                                   *p=k;
                                   (*p)->iz=(w)->iz;
                                   free(w);
                               }
                               else
                               {
                                   arbol *w=NULL;
                                   w=*p;
                                   *p=k;
                                   (*p)->d=(w)->iz;
                                   free(w);
                               }
                            }
            }
        }
        else
        {
           k=*p;
           if((*p)->z<n)
              a=borraABB(&(*p)->d,k,n);
           else
              a=borraABB(&(*p)->iz,k,n);
        }
    }
    return(a);
}


void posli(arbol **p)
{
    if(*p!=NULL)
    {
        posli(&(*p)->iz);
        posli(&(*p)->d);
       free(*p);
    }
}


void inor(arbol *p,int *a)
{
    if(p!=NULL)
    {
        inor(p->iz,a);
        *a=p->z;
        inor(p->d,a);
    }
}
