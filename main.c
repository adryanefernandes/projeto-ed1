#include <stdio.h>
#include "locale.h"

#define TAM_VET 5
#define ERRO -1
#define VERDADEIRO 1
#define FALSO 0

struct Aluno
{
    char nome[50];
    int telefone;
    int idade;
};

int menu();
void fila();

// Funções usadas na fila
int menuFila();
void iniciarFila(int *inicio, int *termino);
int insereFila(struct Aluno F[], int *termino);
int removeFila(struct Aluno F[], int *inicio, int *termino, struct Aluno *valor);
void exibirFila(struct Aluno F[], int *inicio, int *termino);

// Funções usadas na pilha
void pilha();
int menuPilha();
void iniciaPilha(int *topo);
int push(struct Aluno P[], int *topo);
int pop(struct Aluno P[], int *topo, struct Aluno *valor);
int pilhaCheia(int *topo);
int pilhaVazia(int *topo);
void exibirVetor(struct Aluno P[], int *topo);

int main()
{
    setlocale(LC_ALL, "Portuguese");

    int opc = menu(opc);

    // Lida com a escolha do usuário
    switch (opc)
    {
    case 0:
        printf("Até a próxima! ;)");
        return 0;
    case 1:
        fila();
        break;
    case 2:
        pilha();
        break;
    }

    return 0;
}

// Primeiro menu
// Usuário escolhe a estrutura de dados que quer usar ou sai do programa
int menu()
{
    int opc;
    do
    {
        printf("Deseja utilizar qual estrutura?\n");
        printf("[1] Fila\n");
        printf("[2] Pilha\n");
        printf("[0] Sair\n\n");
        printf("Digite a opção que deseja: ");
        scanf("%d", &opc);
    } while (opc != 0 && opc != 1 && opc != 2);

    return opc;
}

// Inicio Fila
void fila()
{
    int inicio, termino, ok;
    int opc;

    struct Aluno fila[TAM_VET];
    struct Aluno value;
    iniciarFila(&inicio, &termino);

    // Lida com a escolha do usuário
    do
    {
        opc = menuFila();

        switch (opc)
        {
        case 1:
            insereFila(fila, &termino);
            break;

        case 2:
            ok = removeFila(fila, &inicio, &termino, &value);

            if (ok != ERRO)
            {
                printf("\nElemento removido:\n");
                printf("Nome: %s\n", value.nome);
                printf("Telefone: %d\n", value.telefone);
                printf("Idade: %d\n", value.idade);
            }

            break;

        case 3:
            exibirFila(fila, &inicio, &termino);
            break;

        case 4:
            iniciarFila(&inicio, &termino);
            break;
        }
    } while (opc != 0);
}

int menuFila()
{
    int opc;

    do
    {
        printf("\n\nMenu:\n");
        printf("[1] Inserir\n");
        printf("[2] Excluir\n");
        printf("[3] Listar\n");
        printf("[4] Reiniciar Fila\n");
        printf("[0] Fim\n");
        printf("\nDigite a opção escolhida: ");
        scanf("%d", &opc);
    } while (opc != 0 && opc != 1 && opc != 2 && opc != 3 && opc != 4);

    return opc;
}

int insereFila(struct Aluno fila[], int *termino)
{
    struct Aluno value;

    printf("\nDigite as informações do aluno: \n\n");
    printf("Nome: ");
    scanf("%s", &value.nome);

    printf("Telefone: ");
    scanf("%d", &value.telefone);

    printf("Idade: ");
    scanf("%d", &value.idade);

    if (*termino == TAM_VET - 1)
    {
        printf("Erro - Ins. Pilha cheia");
        return (VERDADEIRO);
    }
    else
    {
        (*termino)++;
        fila[*termino] = value;
    }
    return (VERDADEIRO);
}

int removeFila(struct Aluno F[], int *inicio, int *termino, struct Aluno *valor)
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

    return (VERDADEIRO);
}

void exibirFila(struct Aluno F[], int *inicio, int *termino)
{
    int i;
    printf("\nFila:\n");
    for (i = *inicio; i <= *termino; i++)
    {
        printf("\n\nElemento [%d]:", i);
        printf("\nNome: %s", F[i].nome);
        printf("\nTelefone: %d", F[i].telefone);
        printf("\nIdade: %d", F[i].idade);
    }
    printf("\n\n");
}

void iniciarFila(int *inicio, int *termino)
{
    *inicio = 0;
    *termino = -1;
}
// Fim Fila

// Inicio pilha
void pilha()
{
    int topo, opc, ok;
    struct Aluno P[TAM_VET];
    struct Aluno value;

    iniciaPilha(&topo);

    do
    {
        opc = menuPilha();

        switch (opc)
        {
        case 1:
            push(P, &topo);
            break;
        case 2:
            ok = pop(P, &topo, &value);

            if (ok != ERRO)
            {
                printf("\nElemento removido:\n");
                printf("Nome: %s\n", value.nome);
                printf("Telefone: %d\n", value.telefone);
                printf("Idade: %d\n", value.idade);
            }

            break;
        case 3:
            exibirVetor(P, &topo);
            break;
        }

    } while (opc != 0);
}

int menuPilha()
{
    int opc;

    do
    {
        printf("\n\nMenu:\n");
        printf("[1] Inserir\n");
        printf("[2] Excluir\n");
        printf("[3] Exibir vetor\n");
        printf("[0] Fim\n");
        printf("\nDigite a opção escolhida:");
        scanf("%d", &opc);
    } while (opc != 0 && opc != 1 && opc != 2 && opc != 3);

    return opc;
}

void iniciaPilha(int *topo)
{
    *topo = -1;
}

// Insere na pilha
int push(struct Aluno P[], int *topo)
{
    struct Aluno value;

    printf("\nDigite as informações do aluno: \n\n");
    printf("Nome: ");
    scanf("%s", &value.nome);

    printf("Telefone: ");
    scanf("%d", &value.telefone);

    printf("Idade: ");
    scanf("%d", &value.idade);

    if (pilhaCheia(topo))
    {
        printf("Erro - Ins. Pilha cheia");
        return (ERRO);
    }
    else
    {
        (*topo)++;
        P[*topo] = value;
    }
    return (VERDADEIRO);
}

int pilhaCheia(int *topo)
{
    if (*topo == TAM_VET - 1)
        return (VERDADEIRO);
    return (FALSO);
}

// Remove item da pilha
int pop(struct Aluno P[], int *topo, struct Aluno *valor)
{
    if (pilhaVazia(topo))
    {
        printf("Erro - Ins. Pilha vazia");
        return (ERRO);
    }
    else
    {
        *valor = P[*topo];
        (*topo)--;
    }

    return (VERDADEIRO);
}

int pilhaVazia(int *topo)
{
    if (*topo == -1)
        return (VERDADEIRO);
    return (FALSO);
}

void exibirVetor(struct Aluno P[], int *topo)
{
    int i;
    printf("\n\nExibir elementos preenchidos de Vetor\n");
    for (i = 0; i <= *topo; i++)
    {
        printf("\nElemento [%d]:", i);
        printf("\nNome: %s", P[i].nome);
        printf("\nTelefone: %d", P[i].telefone);
        printf("\nIdade: %d", P[i].idade);
    }
    printf("\n\n");
}