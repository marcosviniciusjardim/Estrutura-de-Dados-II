#include <stdio.h>
#include <stdlib.h>
#include "Vetor-De-Apontadores.h"
#define M 5

struct arvNaria
{
    int quantidade;
    char info;
    struct arvNaria *filhos[M];
};
typedef struct arvNaria ArvNaria;

ArvNaria *inicArvNaria(void) //cria e retorna uma arvNaria vazia
{
    return NULL;
} //Pos: inicArvnaria == arvore vazia

ArvNaria *criaArvNaria(char c) //cria e retorna uma arvNaria(folha)com a raiz igual à TipoAN
{
    ArvNaria *a = (ArvNaria*)malloc(sizeof(ArvNaria));
    a->quantidade = 0;
    a->info = c;
    int aux;
    for(aux=M; aux >=0; aux--)
        a->filhos[aux] = "None"; //preenchendo cada posição do vetor filho como None para melhor visualização
    a->filhos[M -1] = '\0'; //última posição do vetor filho recebe o \0
    return a;
} //Pos:criaArvNaria == ArvNaria a com raiz TipoAN

ArvNaria *subArvNaria(ArvNaria *a) //Retorna a lista de sub-árvoresassociadas a arvNaria a
{
    if(!vazioArvNaria(a)) //Pre:ArvNaria a não é vazia
    {
        int i;
        for(i=0; a->filhos[i] != '\0'; i++)
        {
            if(a->filhos[i] == "None")
                printf("<None\n");
            else
                printf("<%c\n",a->filhos[i]);
        }
    }
} //Pos:subArvNaria== lista das sub-arvores de a

char raizArvNaria(ArvNaria *a) //Retorna a raiz da arvNaria a
{
    if(!vazioArvNaria(a)) //Pre:ArvNaria a não é vazia
        return a->info;
} //Pos: raizArvNaria == o elemento da raiz

int vazioArvNaria(ArvNaria *a) //informa se a árvore é vazia
{
    return (a == NULL);
} //pos: vazioArvNaria == true se a for vazio do contrário false.

void insereArvNaria(ArvNaria *a, ArvNaria *sa) //adiciona a árvore sa como primeira subarvore de a
{
    if(!vazioArvNaria(a) && !estaArvNaria(a,sa->info)) //pre: a não é vazia e sa já existe
    {
        if(a->quantidade != M -1)
        {
            int aux;
            int pega = -1; //pega primeira posição livre
            for(aux=0; a->filhos[aux] != '\0'; aux++) //vetor filho incrementa até última posição
            {
                if(a->filhos[aux] == "None") //caso posição do vetor filho for None ele adicionará nela
                {
                    pega = aux;
                    break;
                }
            }
            if(pega != -1)
            {
                a->filhos[pega] = sa->info;
                a->quantidade++;
            }
        }
        else
            printf("Arvore cheia\n\n");
    }
} //Pos: insereArvNaria == sa é a primeira subárvore de a

void adicionaArvNaria(ArvNaria *a, ArvNaria *sa) //adiciona a árvore sa como última subarvore de a
{
    if(!vazioArvNaria(a) && !estaArvNaria(a,sa->info)) //Pre: a não é vazia e sa já existe
    {
        if(a->quantidade != M -1)
        {
            int aux;
            int pega = -1; //pega ultima posição livre
            for(aux=M -1; aux>=0; aux--) //vetor filho decrementa até primeira posição
            {
                if(a->filhos[aux] == "None") //caso posição do vetor filho for None ele adicionará nela
                {
                    pega = aux;
                    break;
                }
            }
            if(pega != -1)
            {
                a->filhos[pega] = sa->info;
                a->quantidade++;
            }
        }
        else
            printf("Arvore cheia\n\n");
    }
} //Pos: adicionaArvNaria == sa é a última subárvore de a

void elimSubArvNaria(ArvNaria *a, char c) //desassocia (mas não destrói) a i-ésima subarvore de a
{
    if(!vazioArvNaria(a) && estaArvNaria(a, c)) //pre: a não é vazia e tem subavores
    {
        int aux;
        int pega = 0;
        for(aux = 0; a->filhos[aux] != '\0'; aux++)
        {
            if(a->filhos[aux] == c) //caso seja o elem
                pega = aux;
        }
        a->filhos[pega] = "None";
        a->quantidade--; //decrementa quantidade de filhos
    }
} //pos: elimSubArvNaria == a arvore a não tem mais associada a subarvore i

void destruirArvNaria(ArvNaria *a) //destróie a ArvNaria a, desalocando a memória ocupada
{
    if(!vazioArvNaria(a)) //pre: a não é vazia
    {
        int i;
        for(i=0; a->filhos[i] != '\0'; i++)
            a->filhos[i] = '\0';
        free(a);
    }
} //Pos: destruirArvNaria == toda memória alocada por ArvNaria a é devolvida.

int estaArvNaria(ArvNaria *a, char c) //verifica se elem está em ArvNaria a
{
    if(!vazioArvNaria(a)) //pre: a não é vazia
    {
        int i;
        for(i=0; a->filhos[i] != '\0'; i++)
        {
            if(a->filhos[i] == c) //caso elem esteja no vetor
                return 1;
        }
        return 0;
    }
} //pos: estaArvNaria == true se elem está em a e false do contrário

void imprimeArvNaria(ArvNaria *a) //imprime as informações associadas aos nós da ArvNaria a
{
    if(!vazioArvNaria(a)) //pre: a não é vazia
    {
        int i;
        printf("<%c\n",raizArvNaria(a)); //imprime raiz
        for(i=0; a->filhos[i] != '\0'; i++)
        {
            if(a->filhos[i] == "None")
                printf("<None\n");
            else
                printf("<%c\n",a->filhos[i]);
        }
    }
} //pos: Imprime == o campo da informação da ArvNaria a e suas subarvores são exibidos
