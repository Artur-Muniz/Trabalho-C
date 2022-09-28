#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    char nome[30];
    int nota1;
    int nota2;
} aluno;

aluno *alunos;

int alocarMemoria(void)
{
    alunos = (aluno *)malloc(3 * sizeof(aluno));
}

aluno cadastrar()
{
    aluno cadastro_aluno;

    printf("\nDigite o nome do aluno: ");
    gets(cadastro_aluno.nome);
    fflush(stdin);
    printf("Digite a nota 1: ");
    scanf("%d", &cadastro_aluno.nota1);
    fflush(stdin);
    printf("Digite a nota 2: ");
    scanf("%d", &cadastro_aluno.nota2);
    fflush(stdin);

    return cadastro_aluno;
}

int verificacaoNotas(int qtd_alunos)
{

    if (alunos[qtd_alunos].nota1 >= 0 && alunos[qtd_alunos].nota1 <= 10 && alunos[qtd_alunos].nota2 >= 0 && alunos[qtd_alunos].nota2 <= 10)
    {
        printf("\nAluno cadastrado com sucesso!\n");

        return 1;
    }
    else if (alunos[qtd_alunos].nota1 > 10 || alunos[qtd_alunos].nota1 < 0)
    {
        printf("Nota 1 invalida!\n");
        printf("Tente Novamente!\n");

        return 0;
    }
    else if (alunos[qtd_alunos].nota2 > 10 || alunos[qtd_alunos].nota2 < 0)
    {
        printf("Nota 2 invalida!\n");
        printf("Tente Novamente!\n");

        return 0;
    }
}

void relatorio(int qtd_alunos)
{
    printf("\n\n***** Relatorio de Notas *****\n\n");
    for (int i = 0; i < qtd_alunos; i++)
    {

        printf("\nNome: %s | Nota 1: %d | Nota 2: %d", alunos[i].nome, alunos[i].nota1, alunos[i].nota2);

        if ((alunos[i].nota1 + alunos[i].nota2) / 2 >= 6)
        {
            printf("\nSitucao: Aprovado\n\n");
        }
        else if ((alunos[i].nota1 + alunos[i].nota2) / 2 < 6 && (alunos[i].nota1 + alunos[i].nota2) / 2 > 4)
        {
            printf("\nSitucao: Recuperacao\n\n");
        }
        else
        {
            printf("\nSitucao: Reprovado\n\n");
        }
    }

    return;
}

int liberarMemoria(void)
{
    free(alunos);
    printf("\n\nMemoria liberada");
    printf("\n\nAte a proxima!!");
}

void buscarNome(int qtd_alunos)
{
    char nome_aluno[30];

    printf("Digite o nome do aluno: ");
    gets(nome_aluno);
    fflush(stdin);

    for (int i = 0; i < qtd_alunos; i++)
    {
        if (strncmp(nome_aluno, alunos[i].nome, strlen(nome_aluno)) == 0)
        {
            printf("Aluno encontrado!\n");
            printf("| %s | %d | %d |\n", alunos[i].nome, alunos[i].nota1, alunos[i].nota2);
        }
    }

    return;
}

void excluirAluno(aluno *alunos, int qtd_alunos)
{
    char nome_aluno[30];
    int posicao = 0;

    printf("\nDigite o nome do aluno: ");
    gets(nome_aluno);
    fflush(stdin);

    for (int i = 0; i < qtd_alunos; i++)
    {
        if (strncmp(nome_aluno, alunos[i].nome, strlen(nome_aluno)) == 0)
        {
            posicao = i;

            for (int j = posicao; j < qtd_alunos; j++)
            {
                alunos[j] = alunos[j + 1];
            }
        }
    }

    printf("\nAluno removido com sucesso!\n");

    return;
}