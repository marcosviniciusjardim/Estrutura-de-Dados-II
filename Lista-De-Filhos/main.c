#include <stdio.h>
#include <stdlib.h>
#include "Lista-De-Filhos.h"

struct lista
{
    char info;
    struct lista *prox;
};
typedef struct lista Lista;

struct arvNaria
{
    char info;
    Lista *filhos;
};
typedef struct arvNaria ArvNaria;

int main()
{
    ArvNaria *a = criaArvNaria('A'); //criando arvNaria a
    ArvNaria *b = criaArvNaria('B'); //criando arvNaria b
    ArvNaria *c = criaArvNaria('C'); //criando arvNaria c
    ArvNaria *d = criaArvNaria('D'); //criando arvNaria d

    insereArvNaria(a,b); //adicionando árvore b como primeira subarvore de a
    insereArvNaria(a,c); //adicionando árvore c como primeira subarvore de a
    insereArvNaria(a,d); //adicionando árvore d como primeira subarvore de a

    printf("Imprimindo arvNaria a\n");
    imprimeArvNaria(a);
    printf("\n");

    printf("Imprimindo subArvNaria de a\n");
    subArvNaria(a);
    printf("\n");

    printf("Verificando elemento B na arvNaria a\n");
    printf("%i",estaArvNaria(a,'B'));
    printf("\n\n");

    printf("Verificando se a arvNaria a e vazia\n");
    printf("%i",vazioArvNaria(a));
    printf("\n\n");

    printf("Eliminando elemento B da arvNaria a\n\n");
    elimSubArvNaria(a,'B');

    printf("Imprimindo arvNaria a\n");
    imprimeArvNaria(a);
    printf("\n");

    printf("Retornando raiz da arvNaria a\n");
    printf("%c",raizArvNaria(a));
    printf("\n\n");

    printf("Destruindo arvNaria a\n\n");
    destruirArvNaria(a);

    a = inicArvnaria();

    printf("Exibindo arvNaria a\n\n");
    imprimeArvNaria(a);

    return 0;
}
