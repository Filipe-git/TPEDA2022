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

#pragma warning (disable: 4996)

#define J 8 //Numero Jobs

#pragma region Structs

/**
 * @brief Estrutura para armazenar uma Maquina
 *
 * Uma Máquina contém um código (@@cod).
 * Contém apontador para próxima maquina.
 */
typedef struct Maquinas {
	int cod;
	int t;
	struct Maquinas* next;
}Maquinas;


/**
 * @brief Estrutura para armazenar uma Operação
 *
 * Uma operação contém um código (@@cod), uma maquina associada (@@m) e o respetivo tempo (@@tempo).
 * Contém apontador para próxima operação.
 */

typedef struct Operacoes {
	int cod;
	struct Maquinas* m;
    struct Operacoes* next;
}Operacoes;

/**
 * @brief Estrutura para armazenar um Job
 *
 * Um Job contém um código (@@cod), produto (@@produto).
 * Contém apontador para próximo job.
 */
typedef struct Job {
	int cod;
	struct Operacoes* op;
	struct Job* next;
}Job;

/**
 * @brief Estrutura para armazenar uma maquina em ficheiro
 * 
 */
typedef struct MaquinasFile {
	int m;
	int t;
}MaquinasFile;
/**
 * @brief Estrutura para armazenar uma operação em ficheiro
 *
 * Um jogo contém um código (@@cod), maquinas (@@m) e o tempo (@@tempo).
 * Não contém apontador
 */
typedef struct OperacoesFile {
	int o;
	int m;
	int t;
}OperacoesFile;

/**
 * @brief Estrutura para armazenar um job em ficheiro
 * 
 */
typedef struct JobFile {
	int j;
	int o;
	int m;
	int t;
}JobFile;

/* typedef struct TreeJob {
	Job* j;
	struct TreeJob* left;
	struct TreeJob* right;
}TreeJob; */

/* typedef struct Cel {
	int idJob;
	int idOper;
	//tempo
	//outras
} Cel;
 */

#pragma endregion
extern Operacoes* headLista;
#pragma region Funções



#pragma region Funções Máquina
Maquinas* CriaMaquinas(int cod, int t);
Maquinas* InsereMaquinasFim(Maquinas* m, Maquinas* novo);
bool ExisteMaquinas(Maquinas *m, int cod);
Maquinas* ProcuraMaquinas(Maquinas* m, int cod); 
void MostraListaMaquinas(Maquinas* m);
Maquinas* LerFileMaquinas(char *nomeFicheiro);
#pragma endregion

#pragma region Funções Operações
bool ExisteOperacoes(Operacoes* o, int cod);
Operacoes* CriaOperacoes(int cod);
Operacoes* InsereOperacoesFim(Operacoes* o, Operacoes* novo);
Operacoes* InsereMaquinasOperacao(Operacoes* ListaOperacoes,int idOperacao, Maquinas* maquinas,int idMaquina,int tempo);
Operacoes* AlteraOperacoes(Operacoes* o, int cod, Maquinas* novamaquina);
Operacoes* RemoveOperacoes(Operacoes* o, int cod);
Operacoes* ProcuraOperacoes(Operacoes* o, int cod); 
Operacoes* LerFileOperacoes(char *nomeFicheiro, Maquinas* m);
void MostraListaOperacoes(Operacoes* o);
void DestroiLista(Operacoes** o);
int QuantidadeMinima(Operacoes* o);
int QuantidadeMaxima(Operacoes* o);
int QuantidadeMedia(Operacoes* o);
#pragma endregion

#pragma region Funções Job
Job* CriaJob(int cod);
Job* InsereJobFim(Job* j, Job* novo);
bool ExisteJob(Job *j, int cod);
Job* RemoveJob(Job* j, int cod);
Job* ProcuraJob(Job* j, int cod);
Job* AlteraCodigoJob(Job* j, int cod, int novocodigo);
Job* AlteraOperacaoJob(Job* j, Operacoes* o, int codjob, int codoperacao, int novaoperacao);
Job* RemoveOperacaoJob(Job* listajobs, int idoperacao, int idjob);
Job* InsereOperacaoJob(Job* j, Operacoes* o);
Job* LerFileJob(char *nomeFicheiro,Operacoes* o);
void CriaFileJobs(Job* j);
void MostraListaJob(Job* j);
void MostraALL(Job* j);
#pragma endregion


#pragma region Planeamento

void fcfs (Job *j);
void listprocs (Job *j);

#pragma	endregion