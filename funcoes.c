/**
 * @file funcoes.c
 * @author Filipe Alves 19573
 * @brief Trablho Prático AED 2022
 * @version 0.1
 * @date 2022-04-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdio.h>
#include "dados.h"


#pragma region Job
/**
 * @brief Cria Job
 * 
 * @param cod 
 * @param prod 
 * @return Job* 
 */
Job* CriaJob(int cod, char* prod){
	Job* newJob = (Job*)malloc(sizeof(Job));
	if (newJob == NULL) return NULL;	//pode não haver memória!
	newJob->cod = cod;
	strcpy(newJob->produto, prod);
	newJob->next = NULL;
	return newJob;
}
/**
 * @brief Insere Job no fim da lista.
 * 
 * @param j 
 * @param novo 
 * @return Job* 
 */
Job* InsereJobFim(Job* j, Job* novo){
	//Verificar se o novo Job já existe!
	if (ExisteJob(j, novo->cod)) return j;	//se existir não insere!

	if (j == NULL) {		//lista vazia
		j = novo;
	}
	else
	{
		//Posicionar-se no fim da lista
		Job* aux = j;
		while (aux->next != NULL) {
			aux = aux->next;
		}
		//insere no fim da lista
		aux->next = novo;
	}
	return j;
}
/**
 * @brief Verifica se job existe.
 * 
 * @param j 
 * @param cod 
 * @return true 
 * @return false 
 */
bool ExisteJob(Job *j, int cod){
	if (j == NULL) return false;
	Job* aux = j;
	while (aux != NULL) {
		if (aux->cod == cod)
			return true;
		aux = aux->next;
	}
	return false;
}
#pragma endregion


#pragma region Maquina

/**
 * @brief Cria Maquina
 * 
 * @param cod 
 * @return Maquinas* 
 */
Maquinas* CriaMaquinas(int cod)
{
	Maquinas* newMaquinas = (Maquinas*)malloc(sizeof(Maquinas));
	if (newMaquinas == NULL) return NULL;	//pode não haver memória!
	newMaquinas->cod = cod;
    return newMaquinas;
}

/**
 * @brief Insere Maquina no final da lista
 * 
 * @param m 
 * @param novo 
 * @return Maquinas* 
 */
Maquinas* InsereMaquinasFim(Maquinas* m, Maquinas* novo) {
	//Verificar se o nova Maquina já existe!
	if (ExisteMaquinas(m, novo->cod)) return m;	//se existir não insere!

	if (m == NULL) {		//lista vazia
		m = novo;
	}
	else
	{
		//Posicionar-se no fim da lista
		Maquinas* aux = m;
		while (aux->next != NULL) {
			aux = aux->next;
		}
		//insere no fim da lista
		aux->next = novo;
	}
	return m;
}

/**
 * @brief Verifica se maquina existe. Se existir devolve Bool!
 * 
 * @param m 
 * @param cod 
 * @return true 
 * @return false 
 */
bool ExisteMaquinas(Maquinas *m, int cod) {
	if (m == NULL) return false;
	Maquinas* aux = m;
	while (aux != NULL) {
		if (aux->cod == cod)
			return true;
		aux = aux->next;
	}
	return false;
}


#pragma endregion


#pragma region Operações
/**
 * @brief Cria nova operação
 * 
 * @param cod 
 * @param m 
 * @param tempo
 * @param j
 * @return Operacoes* 
 */
Operacoes* CriaOperacoes(int cod, Job* j, Maquinas* m, int tempo)
{
	Operacoes* newOperacoes = (Operacoes*)malloc(sizeof(Operacoes));
	if (newOperacoes == NULL) return NULL;	//pode não haver memória!
	newOperacoes->cod = cod;
    newOperacoes->m.cod = m;
	newOperacoes->j.cod = j;
	newOperacoes->tempo = tempo;
	newOperacoes->next = NULL;
	return newOperacoes;
}

/**
 * @brief Insere operação no final da lista
 * 
 * @param o 
 * @param novo 
 * @return Operacoes* 
 */
Operacoes* InsereOperacoesFim(Operacoes* o, Operacoes* novo) {
	//Verificar se o nova operação já existe!
	if (ExisteOperacoes(o, novo->cod)) return o;	//se existir não insere!

	if (o == NULL) {		//lista vazia
		o = novo;
	}
	else
	{
		//Posicionar-se no fim da lista
		Operacoes* aux = o;
		while (aux->next != NULL) {
			aux = aux->next;
		}
		//insere no fim da lista
		aux->next = novo;
	}
	return o;
}

/**
 * @brief Verifica se operação existe. Se existir devolve Bool!
 * 
 * @param o 
 * @param cod 
 * @return true 
 * @return false 
 */
bool ExisteOperacoes(Operacoes *o, int cod) {
	if (o == NULL) return false;
	Operacoes* aux = o;
	while (aux != NULL) {
		if (aux->cod == cod)
			return true;
		aux = aux->next;
	}
	return false;
}

/**
 * @brief Verifica se operação existe. Se existir devolve endereço operação!
 * 
 * @param o 
 * @param cod 
 * @return Apontador para operação encontrada. 
 */
Operacoes* ProcuraOperacoes(Operacoes* o, int cod) {
	if (o == NULL) return NULL;		//lista vazia
	else
	{
		Operacoes* aux = o;
		while (aux != NULL) {
			if (aux->cod == cod) {
				return (aux);		//encontrei
			}
			aux = aux->next;
		}
		return NULL;
	}
}

/**
 * @brief Altera operação.
 * 
 * @param o 
 * @param cod 
 * @param novamaquina 
 * @param novotempo 
 * @return Operacoes* 
 */
Operacoes* AlteraOperacoes(Operacoes* o, int cod, Maquinas* novamaquina, int novotempo) {
	Operacoes* aux = ProcuraOperacoes(o, cod);
	if (aux != NULL)		//se encontrou a operação
	{

        aux->m.cod = novamaquina;
		aux->tempo = novotempo;
		
	}
	return o;
}

/**
 * @brief Remove operação. Indexado pelo seu código (cod)
 * 
 * @param o 
 * @param cod 
 * @return Operacoes* 
 */
Operacoes* RemoveOperacoes(Operacoes* o, int cod) {
	if (o == NULL) return NULL;			//Lista vazia
	//if (!ExisteOperacoes(o, cod)) return o;	//se não existe

	if (o->cod == cod) {		//remove no inicio da lista
		Operacoes* aux = o;
		o = o->next;
		free(aux);
	}
	else
	{
		Operacoes *aux = o;
		Operacoes *auxAnt = aux;
		while (aux && aux->cod != cod) {	//procura para remover
			auxAnt = aux;
			aux = aux->next;
		}
		if (aux != NULL) {					//se encontrou, remove
			auxAnt->next = aux->next;
			free(aux);
		}
	}
	return o;
}


/* -----------------------------------------------------
*	Métodos para mostrar no ecrã
   -----------------------------------------------------*/


/**
 * @brief Mostra todas as operações na estrutura
 * 
 * @param o 
 */
void MostraLista(Operacoes* o) {
	Operacoes* aux = o;
	while (aux) {		//mesmo que while (aux!=NULL)
		MostraOperacoes(aux);
		aux = aux->next;
	}
}
/**
 * @brief Mostra dados de um nodo
 * 
 * @param nodo 
 */
void MostraOperacoes(Operacoes* nodo) {
	if (nodo != NULL)
	{
		printf("\nCodigo: %d\n", nodo->cod);
		printf("Job: %d\n", nodo->j.cod);
		printf("Maquina: %d\n", nodo->m.cod);
		printf("Tempo: %d\n", nodo->tempo);
		
	}
}

/**
* @brief Preservar dados em ficheiro
* Grava todos os nodos da Lista em Ficheiro
*/
bool gravarOperacoesText(char* nomeFicheiro, Operacoes* o) {
	FILE* fp;

	if (o == NULL) return false;
	if ((fp = fopen(nomeFicheiro, "wt")) == NULL) return false;
	//grava n registos no ficheiro
	Operacoes* aux = o;
	OperacoesFile auxOperacoes;	//para gravar em ficheiro!
	while (aux) {		//while(aux!=NULL)
		//Colocar no registo de ficheiro a inf que está no registo de memória
		auxOperacoes.cod = aux->cod;
		auxOperacoes.j = aux->j;
		auxOperacoes.m = aux->m;
		auxOperacoes.tempo = aux->tempo;
		fwrite(&auxOperacoes, sizeof(OperacoesFile), 1, fp);
		aux = aux->next;
	}
	fclose(fp);
	return true;
}

/**
* @brief Lê informação de ficheiro
*/
Operacoes* lerOperacoesText(char* nomeFicheiro) {
	FILE* fp;
	Operacoes* o = NULL;
	Operacoes* aux;

	if ((fp = fopen(nomeFicheiro, "rt")) == NULL) return NULL;
	//lê n registos no ficheiro
	OperacoesFile auxOperacoes;
	while (fread(&auxOperacoes, sizeof(OperacoesFile), 1, fp)){
		aux = CriaOperacoes(auxOperacoes.cod, auxOperacoes.j.cod, auxOperacoes.m.cod, auxOperacoes.tempo);
		o = InsereOperacoesOrdenado(o, aux);
	}
	fclose(fp);
	return o;
}

/**
* @brief Insere Operacoes ordenado pelo código
* @param [in] o		Inicio da Lista
* @param [in] novo	Nova operação a inserir
* @return	Inicio da Lista
*/
Operacoes* InsereOperacoesOrdenado(Operacoes* o, Operacoes* novo) {
	if (ExisteOperacoes(o, novo->cod)) return o;

	if (o == NULL) {
		o = novo;		//Insere no início
	}
	else
	{
		Operacoes* aux = o;
		Operacoes* auxAnt = NULL;
		while (aux && aux->cod < novo->cod) {
			auxAnt = aux;
			aux = aux->next;
		}
		if (auxAnt == NULL) {	//Insere no meio
			novo->next = o;
			o = novo;
		}
		else
		{
			auxAnt->next = novo;	//Insere no fim
			novo->next = aux;
		}
	}
	return o;
}

/**
* @brief Destroi todos os nodos da lista
* @param [in]	o	Apontador para inicio da Lista
*/
void DestroiLista(Operacoes** o) {
	if (o != NULL) {
		Operacoes* aux;
		while (*o) {
			aux = *o;
			*o = (*o)->next;
			free(aux);
		}
	}
}

/**
 * @brief Determinação da quantidade mínima de unidades de tempo necessárias para completar o job e listagem das
 * respetivas operações
 * 
 * @param o 
 * @return int
 */
int QuantidadeMinima(Operacoes* o){

	if (o == NULL) return NULL; //Lista vazia
	Operacoes* aux = o;
	int cont=1;
	int valor=0;
	int soma=0;
	while (aux->cod==cont)
	{
		valor=aux->tempo;
		if (valor>aux->tempo)
		{
			valor==aux->tempo;
			soma=valor+soma;
		}
		aux = aux->next;
	}
	cont++;
	return soma;
}

/**
 * @brief Determinação da quantidade maxima de unidades de tempo necessárias para completar o job e listagem das
 * respetivas operações
 * 
 * @param o 
 * @return int 
 */
int QuantidadeMaxima(Operacoes* o){

	if (o == NULL) return NULL; //Lista vazia
	Operacoes* aux;
	int cont=1;
	int valor=0;
	int soma=0;
	while (aux->cod==cont)
	{
		valor=aux->tempo;
		if (valor<aux->tempo)
		{
			valor==aux->tempo;
			soma=valor+soma;
		}
		aux = aux->next;
	}
	cont++;
	return soma;
}

/**
 * @brief Determinação da quantidade media de unidades de tempo necessárias para completar o job e listagem das
 * respetivas operações
 * 
 * @param o 
 * @return float 
 */
int QuantidadeMedia(Operacoes* o){

	Operacoes* aux;
	if (o == NULL) return NULL;
	
    /* calculo a média */
	int soma = 0;
	int n = 0;
	int resultado = 0;
	while (aux) {
		
		soma+=aux->tempo; 
		n++;
		aux = aux->next;
	}
	resultado=soma/n;
	return resultado;
}

#pragma endregion
