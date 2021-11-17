#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

void coletarTotal(int *total);
void sortear(int *faceSorteada);
void inicializarVet(int *vetorDado);

int main()
{
    srand(time(NULL));                         //Inicialização  do comando rand()
    UINT CPAGE_UTF8 = 65001;                   //Inicialização  da alternativa ao SetLocale, visto que, o setLocale não está funcionando no meu
    UINT CPAGE_DEFAULT = GetConsoleOutputCP(); //computador
    SetConsoleOutputCP(CPAGE_UTF8);

    int totalSorteio;
    int i;
    int facesDado[32]; //acredito que não faça mal utilizar esse tipo de lista nesse caso
    int faceSorteada;

    inicializarVet(facesDado);   //Função para atribuir valor de 0 a todos os elementos do vetor. Para iniciar a contagem das faces
    coletarTotal(&totalSorteio); //função para coletar o imput de simulações do usuário

    for (i = 0; i < totalSorteio; i++) //achei mais prático deixar o for loop na função main mesmo.
    {
        sortear(&faceSorteada);                                        //função responsável por sortear as faces.
        *(facesDado + faceSorteada) = *(facesDado + faceSorteada) + 1; //contagem de quantas vezes cada face  foi  sorteada
    }

    for (i = 0; i < 32; i++) //print da quantidade de vezes que cada face foi sorteada
    {
        printf("\nA face número %d foi sorteada %d vezes.", i + 1, *(facesDado + i));
    }

    SetConsoleOutputCP(CPAGE_DEFAULT); //final da alternativa ao setLocale
    Sleep(15000);                      //Adicionei isso pro terminal do windows não fechar imediatamente quando o programa finalizar, ao abrir pelo .exe. Visto que,
                                       //eu estava realizando uns testes por lá, porque achei melhor de visualizar.
    return 0;
}

void sortear(int *faceSorteada)
{
    *(faceSorteada) = rand() % 32;
}

void coletarTotal(int *total)
{
    printf("Quantas vezes deseja simular o lançamento de um dado de 32 faces? (Apenas números inteiros, por favor) ");
    scanf(" %d", &*(total));
}

void inicializarVet(int *vetorDado)
{
    int i;
    for (i = 0; i < 32; i++)
    {
        *(vetorDado + i) = 0;
    }
}