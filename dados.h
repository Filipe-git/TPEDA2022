/**
 * @file dados.h
 * @author Filipe Alves 19573
 * @brief Trabalho Prático EDA 2022
 * @version 0.1
 * @date 2022-04-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdbool.h>
#include <stdlib.h>

//Define para definir limite de Jobs e Operações

#define N 7 //Ainda não usado

#pragma region Structs

/**
 * @brief Estrutura para armazenar uma Maquina
 *
 * Uma Máquina contém um código (@@cod).
 * Contém apontador para próxima maquina.
 */
typedef struct Maquinas {
	int cod;
	struct Maquinas* next;
}Maquinas;

/**
 * @brief Estrutura para armazenar um Job
 *
 * Um Job contém um código (@@cod), produto (@@produto).
 * Contém apontador para próximo job.
 */
typedef struct Job {
	int cod;
    char produto;
	struct Job* next;
}Job;

/**
 * @brief Estrutura para armazenar uma Operação
 *
 * Uma operação contém um código (@@cod), uma maquina associada (@@m) e o respetivo tempo (@@tempo).
 * Contém apontador para próxima operação.
 */

typedef struct Operacoes {
	int cod;
    int tempo;
	Maquinas m;
	Job j;
    struct Operacoes* next;
}Operacoes;

/**
 * @brief Estrutura para armazenar uma operação em ficheiro
 *
 * Um jogo contém um código (@@cod), maquinas (@@m) e o tempo (@@tempo).
 * Não contém apontador
 */
typedef struct OperacoesFile {
	int cod;
	int tempo;
	struct Maquinas m;
	struct Job j;
	
}OperacoesFile;

#pragma endregion
extern Operacoes* headLista;
#pragma region Funções


#pragma region Funções Máquina
Maquinas* CriaMaquinas(int cod);
Maquinas* InsereMaquinasFim(Maquinas* m, Maquinas* novo);
bool ExisteMaquinas(Maquinas *m, int cod);
#pragma endregion

#pragma region Funções Job
Job* CriaJob(int cod, char prod);
Job* InsereJobFim(Job* j, Job* novo);
bool ExisteJob(Job *j, int cod);
#pragma endregion

#pragma region Funções Opereações
bool ExisteOperacoes(Operacoes* o, int cod);
Operacoes* CriaOperacoes(int cod, Job* j, Maquinas* m, int tempo);
Operacoes* InsereOperacoesFim(Operacoes* o, Operacoes* novo);
Operacoes* AlteraOperacoes(Operacoes* o, int cod, Job* novojob, Maquinas* novamaquina, int novotempo);
Operacoes* RemoveOperacoes(Operacoes* o, int cod);
Operacoes* ProcuraOperacoes(Operacoes* o, int cod); 
bool gravarOperacoesText(char* nomeFicheiro, Operacoes* o);
Operacoes* lerOperacoesText(char* nomeFicheiro);
Operacoes* InsereOperacoesOrdenado(Operacoes* o, Operacoes* novo);
void MostraLista(Operacoes* o);
void MostraOperacoes(Operacoes* nodo);
void DestroiLista(Operacoes** o);
//Calculos //EM FALTA
int QuantidadeMinima(Operacoes* o);
int QuantidadeMaxima(Operacoes* o);
int QuantidadeMedia(Operacoes* o);
#pragma endregion
#pragma endregion
