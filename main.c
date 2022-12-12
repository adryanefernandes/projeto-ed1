#include <stdio.h>
#include "locale.h"

#define TAM_VET 5
#define VERD 1
#define FALSO 0
#define ERRO -1

struct Aluno
{
    char nome[50];
    int telefone[11];
    int idade;
};

void iniciaPilha(int *Topo)
{
    *Topo = -1;
}

int pilhaCheia(int *Topo)
{
    if (*Topo == TAM_VET - 1)
        return (VERD);
    return (FALSO);
}

int pilhaVazia(int *Topo)
{
    if (*Topo == -1)
        return (VERD);
    return (FALSO);
}

int push(struct Aluno P[], int *Topo, struct Aluno valor)
{
    if (pilhaCheia(Topo))
    {
        printf("Erro - Ins. Pilha cheia");
        return (ERRO);
    }
    else
    {
        (*Topo)++;
        P[*Topo] = valor;
    }
    return (VERD);
}

int pop(struct Aluno P[], int *Topo, struct Aluno *valor)
{
    if (pilhaVazia(Topo))
    {
        printf("Erro - Ins. Pilha vazia");
        return (ERRO);
    }
    else
    {
        *valor = P[*Topo];
        (*Topo)--;
    }

    return (VERD);
}

void exibirVetor(struct Aluno P[], int *Topo)
{
    int i;
    printf("\nExibir elementos preenchidos de Vetor\n");
    for (i = 0; i <= *Topo; i++)
    {
        printf("\nElemento [%d]:", i);
        printf("\nNome: %s", P[i].nome);
        printf("\nTelefone: %s", P[i].telefone);
        printf("\nIdade: %d", P[i].idade);
    }
    printf("\n\n");
}

void Inicia_Fila(int *inicio, int *termino)
{
    *inicio = 0;
    *termino = -1;
}

int Fila_Vazia(int inicio, int termino)
{
    if (termino == TAM_VET - 1)
        return (VERD);
    return (FALSO);
}

int Insere_Fila(struct Aluno F[], int *termino, struct Aluno valor)
{
    if (*termino == TAM_VET - 1)
    {
        printf("Erro - Ins. Pilha cheia");
        return (ERRO);
    }
    else
    {
        (*termino)++;
        F[*termino] = valor;
    }
    return (VERD);
}

int Remove_Fila(struct Aluno F[], int *inicio, int *termino, struct Aluno *valor)
{
    if (*inicio > *termino)
    {
        printf("Erro - Ins. Fila vazia");
        return (ERRO);
    }
    else
    {
        *valor = F[*inicio];
        (*inicio)++;
    }

    return (VERD);
}

void Exibir_Fila(struct Aluno F[], int *inicio, int *termino)
{
    int i;
    printf("\nListar Fila:");
    for (i = *inicio; i <= *termino; i++)
    {
        printf("\nElemento [%d]:", i);
        printf("\nNome: %s", F[i].nome);
        printf("\nTelefone: %s", F[i].telefone);
        printf("\nIdade: %d", F[i].idade);
    }
    printf("\n\n");
}

int main()
{
    setlocale(LC_ALL, "Portuguese");

    struct Aluno F[TAM_VET];
    struct Aluno P[TAM_VET];
    int inicio, termino, Topo;
    int ok, op = 1;

    struct Aluno value;

    Inicia_Fila(&inicio, &termino);
    while (op != 5)
    {
        printf("\n\nMenu\n1-Inserir\n2-Excluir");
        printf("\n3-Listar\n4-Reiniciar Fila");
        printf("\n5-Fim\nOpcao: \n\n\n");
        scanf("%d", &op);

        if (op == 1)
        {
            printf("\nDigite o nome do aluno: ");
            scanf("%s", value.nome);

            printf("\nDigite o telefone do aluno: ");
            scanf("%s", value.telefone);

            printf("\nDigite a idade do aluno: ");
            scanf("%d", &value.idade);

            Insere_Fila(F, &termino, value);
        }
        else if (op == 2)
        {
            ok = Remove_Fila(F, &inicio, &termino, &value);

            if (ok != ERRO)
                printf("\nElemento removido: %f", value);
        }
        else if (op == 3)
        {
            Exibir_Fila(F, &inicio, &termino);
        }
        else if (op == 4)
        {
            Inicia_Fila(&inicio, &termino);
        }
    }

    iniciaPilha(&Topo);
    
    while (op != 0)
    {
        printf("\n\nMenu\n1-Inserir\n2-Excluir\n3-Exibir Vetor\n0-Fim\nOpcao: ");
        scanf("%d", &op);

        if (op == 1)
        {
            printf("\nDigite o nome do aluno: ");
            scanf("%s", value.nome);

            printf("\nDigite o telefone do aluno: ");
            scanf("%s", value.telefone);

            printf("\nDigite a idade do aluno: ");
            scanf("%d", &value.idade);

            push(P, &Topo, value);
        }
        else if (op == 2)
        {
            ok = pop(P, &Topo, &value);
            if (ok != ERRO)
            {
                printf("\n Elemento removido: %s", value.nome);
            }
        }
        else if (op == 3)
        {
            exibirVetor(P, &Topo);
        }
    }
    return 0;
}