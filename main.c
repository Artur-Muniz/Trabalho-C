#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "functions.h"

void menu(void);

int main()
{

    int opcao;
    int qtd_alunos = 0;
    char nome_aluno[30];
    int posicao = 0;
    alocarMemoria();

    for (;;)
    {

        printf("\n");
        menu();

        scanf("%d", &opcao);
        fflush(stdin);

        if (qtd_alunos >= 3)
        {
            alunos = realloc(alunos, sizeof(aluno) * (qtd_alunos + 1));
        }
        if (opcao == 1)
        {

            alunos[qtd_alunos] = cadastrar();

            while (verificacaoNotas(qtd_alunos) == 0)
            {

                alunos[qtd_alunos] = cadastrar();
            }

            qtd_alunos++;
        }
        else if (opcao == 2)
        {
            excluirAluno(alunos, qtd_alunos);

            qtd_alunos--;

            alunos = realloc(alunos, sizeof(aluno) * qtd_alunos);
        }

        else if (opcao == 3)
        {
            buscarNome(qtd_alunos);
        }

        else if (opcao == 4)
        {
            relatorio(qtd_alunos);
        }

        else if (opcao == 5)
        {
            liberarMemoria();
            break;
        }
        else
        {
            printf("\nOpcao invalida! \nTente Novamente:");
        }
    }

    return 0;
}

void menu()
{
    printf("\n1 - Incluir aluno\n2 - Excluir aluno\n3 - Pesquisar aluno\n4 - Relatorio de Notas\n5 - Sair\n");
    printf("\nDigite a opcao desejada: ");

    return;
}