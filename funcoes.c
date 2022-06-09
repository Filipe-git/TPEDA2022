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

void CriaFileJobs(Job* j, Operacoes* o, Maquinas* m){
	FILE *fp;
	Job* auxjob=j;
	Operacoes* auxop=o;
	Maquinas* auxm=m;
   	fp = fopen("fileall.txt" , "a" );

	while (auxjob!=NULL)
	{
		if (fp==NULL)
			printf("Nao foi possivel abrir o arquivo");
		else{
			fprintf(fp, "%d;%d;%d;%d\n", auxjob->cod, auxop->cod, auxm->cod, auxm->t);
		}
		auxjob=auxjob->next;
		auxop=auxop->next;
		auxm=auxm->next;
	}
   	fclose(fp);
}

#pragma region Maquina

/**
 * @brief Cria Maquina
 * 
 * @param cod 
 * @return Maquinas* 
 */
Maquinas* CriaMaquinas(int cod, int t)
{
	Maquinas* newMaquinas = (Maquinas*)malloc(sizeof(Maquinas));
	if (newMaquinas == NULL) return NULL;	//pode não haver memória!
	newMaquinas->cod = cod;
	newMaquinas->t = t;
	newMaquinas->next=NULL;
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
	//if (ExisteMaquinas(m, novo->cod)) return m;	//se existir não insere!

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

Maquinas* ProcuraMaquinas(Maquinas* m, int cod){
	if (m == NULL) return NULL;		//lista vazia
	else
	{
		Maquinas* aux = m;
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
 * @brief Mostra todas as operações na estrutura
 * 
 * @param o 
 */
void MostraListaMaquinas(Maquinas* m) {
    Maquinas* auxmaq = m;
	
    while (auxmaq) {
		printf("Maquina: %d - Tempo: %d\n\n", auxmaq->cod, auxmaq->t);
		auxmaq = auxmaq->next;
	}

}

/**
 * @brief 
 * 
 * @param nomeFicheiro 
 * @return Maquinas* 
 */
Maquinas* LerFileMaquinas(char *nomeFicheiro){
	FILE* fp; // apontador para descritor de ficheiro
	Maquinas* m = NULL;
	JobFile aux;
	Maquinas* novaMaq;

	char linhaficheiro[100];

    if ((fp = fopen(nomeFicheiro, "r")) == NULL) return NULL;

	while (fgets(linhaficheiro, 100, fp) != NULL){

		sscanf(linhaficheiro, "%d;%d;%d;%d", &aux.j,&aux.o,&aux.m,&aux.t);
		if (ExisteMaquinas(m, aux.m)==false)
		{
			novaMaq=CriaMaquinas(aux.m, aux.t);
			m=InsereMaquinasFim(m, novaMaq);
		}
		
	}
	//MostraListaMaquinas(m);
    fclose(fp);
	return m;
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
Operacoes* CriaOperacoes(int cod)
{
	Operacoes* newOperacoes = (Operacoes*)malloc(sizeof(Operacoes));
	if (newOperacoes == NULL) return NULL;	//pode não haver memória!
	newOperacoes->cod = cod;
	newOperacoes->m = NULL;
	newOperacoes->next = NULL;
	return newOperacoes;
}

/**
 * @brief 
 * 
 * @param o 
 * @param novo 
 * @return Operacoes* 
 */
Operacoes* InsereOperacoesFim(Operacoes* o, Operacoes* novo) {
	//Verificar se o nova Maquina já existe!
	//if (ExisteOperacoes(o, novo->cod)) return o;	//se existir não insere!

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
 * @brief 
 * Recebe inicio da lista de operações , o ID da operação a inserir valores, a maquina que vamos inserir fazendo a verificação pelo ID
 * @param inicioListaOperacoes 
 * @param idOperacao 
 * @param maquinas 
 * @param idMaquina 
 * @param tempo 
 * @return Operacoes* 
 */

Operacoes* InsereMaquinasOperacao(Operacoes* ListaOperacoes, Maquinas* maquinas){

    Operacoes* auxop = ListaOperacoes;
	Maquinas* auxm=maquinas;

    while (auxm!=NULL) {
		
		auxop->m=auxm;
		auxop->m->cod=auxm->cod;
		auxop->m->t=auxm->t;

		auxop = auxop->next;
		auxm = auxm->next;
		
	}
	return ListaOperacoes;
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
Operacoes* AlteraOperacoes(Operacoes* o, int cod, Maquinas* novamaquina) {
	Operacoes* aux = ProcuraOperacoes(o, cod);
	if (aux != NULL)		//se encontrou a operação
	{

		aux->m = novamaquina;
		
	}
	return o;
}
/**
 * @brief 
 * 
 * @param o 
 * @param codop 
 * @param codmaquina 
 * @param tempo 
 * @param novocodmaquina 
 * @param novotempo 
 * @return Operacoes* 
 */
Operacoes* AlteraMaquinaOperacoes(Operacoes* o, int codop, int codmaquina, int tempo, int novocodmaquina, int novotempo){
	Operacoes* aux;
	while (aux != NULL)		//se encontrou a operação
	{
		if (aux->cod==codop);
		{
			if (aux->m->cod==codmaquina)
			{
				if (aux->m->t==tempo)
				{
					aux->m->cod=novocodmaquina;
					aux->m->t=novotempo;
				}
				
			}

		}
		
		aux=aux->next;
		
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

/**
 * @brief Mostra todas as operações na estrutura
 * 
 * @param o 
 */
void MostraListaOperacoes(Operacoes* o) {
    Operacoes* auxop = o;
	
    while (auxop) {
		printf("Operacao: %d\nMaquina: %d\nTempo: %d\n\n", auxop->cod, auxop->m->cod, auxop->m->t);
		auxop = auxop->next;
	}

}

#pragma region Ficheiros Operacoes
/**
* @brief Preservar dados em ficheiro
* Grava todos os nodos da Lista em Ficheiro
*/
/* Operacoes* gravarOperacoesText(char* nomeFicheiro) {
	FILE* fp;
	Operacoes* o = NULL;;
	OperacoesFile auxOp;
	o->cod=auxOp.o;
	fp = fopen(nomeFicheiro, "w" );
   	fwrite(auxOp.o , 1 , sizeof(auxOp) , fp );

	fclose(fp);
	return 
} */

/**
 * @brief Função para ler os valores do file.txt
 * 
 * @param nomeFicheiro 
 * @param m 
 * @return Operacoes* 
 */
Operacoes* LerFileOperacoes(char *nomeFicheiro) {
    FILE* fp; // apontador para descritor de ficheiro
	Operacoes* o = NULL;
	JobFile aux;
	Maquinas* m=NULL;
	Operacoes* novaOp;
	char linhaficheiro[100];

    if ((fp = fopen(nomeFicheiro, "r")) == NULL) return NULL;

	while (fgets(linhaficheiro, 100, fp) != NULL){

		sscanf(linhaficheiro, "%d;%d;%d;%d", &aux.j,&aux.o,&aux.m,&aux.t);

		if (ExisteOperacoes(o, aux.o)==false)
		{
			novaOp=CriaOperacoes(aux.o);
			o=InsereOperacoesFim(o, novaOp);
		}		
	
		//o=InsereMaquinasOperacao(o, aux.o, m, aux.m, aux.t);
		
	}
	//MostraListaOperacoes(o);
    fclose(fp);
	return o;
}
#pragma endregion
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

	//if (o == NULL) return NULL; //Lista vazia
	Operacoes* aux = o;
	int cont=1;
	int valor=0;
	int soma=0;
	while (aux->cod==cont)
	{
		valor=aux->m->t;
		if (valor>aux->m->t)
		{
			valor==aux->m->t;
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

	//if (o == NULL) return NULL; //Lista vazia
	Operacoes* aux=o;
	int cont=1;
	int valor=0;
	int soma=0;
	while (aux->cod==cont)
	{
		valor=aux->m->t;
		if (valor<aux->m->t)
		{
			valor==aux->m->t;
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
	//if (o == NULL) return NULL;
	
    /* calculo a média */
	int soma = 0;
	int n = 0;
	int resultado = 0;
	while (aux) {
		
		soma+=aux->m->t; 
		n++;
		aux = aux->next;
	}
	resultado=soma/n;
	return resultado;
}

#pragma endregion

#pragma region Job
/**
 * @brief Cria novo Job
 * 
 * @return Job* 
 */
Job* CriaJob(int cod)
{
	Job* newJob = (Job*)malloc(sizeof(Job));
	if (newJob == NULL) return NULL;	//pode não haver memória!
	newJob->cod = cod;
	newJob->op = NULL;
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
	//if (ExisteJob(j, novo->cod)) return j;	//se existir não insere!

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
/**
 * @brief 
 * 
 * @param j 
 * @param cod 
 * @param novaoperacao 
 * @return Job* 
 */
Job* AlteraCodigoJob(Job* j, int cod, int novocodigo){
	Job* aux = ProcuraJob(j, cod);
	while (aux != NULL)		//se encontrou a operação
	{
		if (aux->cod==cod)
		{
			aux->cod=novocodigo;

		}
		
		aux=aux->next;
		
	}
	return j;
}

/**
 * @brief Alterar operação associada ao job
 * 
 * @param j 
 * @param o 
 * @param codjob 
 * @param codoperacao 
 * @param novaoperacao 
 * @return Job* 
 */
Job* AlteraOperacaoJob(Job* j, int codjob, int codoperacao, int novaoperacao){
	Job* aux = ProcuraOperacaoJob(j, codjob,codoperacao);
	while (aux != NULL)		//se encontrou a operação
	{
		if (aux->cod==codjob);
		{
			if (aux->op->cod==codoperacao)
			{
				aux->op->cod=novaoperacao;
			}

		}
		
		aux=aux->next;
		
	}
	return j;
}
/**
 * @brief 
 * 
 * @param o 
 * @param cod 
 * @return Job* 
 */
Job* RemoveJob(Job* j, int cod){
	if (j == NULL) return NULL;			//Lista vazia
	//if (!ExisteJob(j, cod)) return j;	//se não existe
	
	if (j->cod == cod) {		//remove no inicio da lista
		Job* aux = j;
		j = j->next;
		free(aux);
	}
	else
	{
		Job *aux = j;
		Job *auxAnt = aux;
		while (aux && aux->cod != cod) {	//procura para remover
			auxAnt = aux;
			aux = aux->next;
		}
		if (aux != NULL) {					//se encontrou, remove
			auxAnt->next = aux->next;
			free(aux);
		}
	}
	return j;
}
/**
 * @brief Remover operação de um job
 * 
 * @param j 
 * @param codoperacao 
 * @return Job* 
 */
Job* RemoveOperacaoJob(Job* listajobs, int idoperacao, int idjob){
	
	Job* aux = listajobs;

	while (aux!=NULL)
	{
		if (aux->cod == idjob)
		{
			Operacoes* auxOp = aux->op;
			Operacoes* auxOp2 = aux->op;

			while (auxOp != NULL)
			{
				if (auxOp->cod==idoperacao)
				{
					//se as listas forem identicas
					if (auxOp==aux->op)
					{
						aux->op=auxOp->next;
						free(auxOp);
						return listajobs;
					}

					//se nao forem
					else{
						auxOp2->next=auxOp->next;
						free(auxOp);
						return listajobs;
					}
					
				}
				auxOp2=auxOp;
				auxOp=auxOp->next;
			}
			
		}
		aux=aux->next;
		
	}
	return aux;
	
}

/**
 * @brief Função para inserir operações nos jobs
 * 
 * @param j 
 */
Job* InsereOperacaoJob(Job* j, Operacoes* o){
	Job* auxjob = j;
	Operacoes* auxop=o;

    while (auxop!=NULL) {
		
		auxjob->op=auxop;
		auxjob->op->m=auxop->m;

		auxjob = auxjob->next;
		auxop = auxop->next;
		
	}
	return j;
}

/**
 * @brief Verifica se job existe. Se existir devolve endereço operação!
 * 
 * @param o 
 * @param cod 
 * @return Apontador para job encontrada. 
 */
Job* ProcuraJob(Job* j, int cod) {
	if (j == NULL) return NULL;		//lista vazia
	else
	{
		Job* aux = j;
		while (aux!=NULL)
		{
			
			if (aux->cod == cod) {
				return (aux);		//encontrei
			}
			aux = aux->next;
		
		}
		return NULL;
		
	}
}
/**
 * @brief 
 * 
 * @param j 
 * @param cod 
 * @param codoperacao 
 * @return Job* 
 */
Job* ProcuraOperacaoJob(Job* j, int cod, int codoperacao) {
	if (j == NULL) return NULL;		//lista vazia
	else
	{
		Job* aux = j;
		while (aux != NULL) {
			if (aux->cod == cod && aux->op->cod==codoperacao) {
				return (aux);		//encontrei
			}
			aux = aux->next;
		}
		return NULL;
	}
}
#pragma endregion


#pragma region Files Jobs

/**
 * @brief 
 * 
 * @param nomeFicheiro 
 * @param o 
 * @return Job* 
 */
Job* LerFileJob(char *nomeFicheiro) {
    FILE *fp; // apontador para descritor de ficheiro
	Job *j = NULL;
	Operacoes *o=NULL;
	JobFile aux;
	Job* novoJob;

	char linhaficheiro[100];

    if ((fp = fopen(nomeFicheiro, "r")) == NULL) return NULL;

	while (fgets(linhaficheiro, 100, fp) != NULL){

		sscanf(linhaficheiro, "%d;%d;%d;%d", &aux.j, &aux.o, &aux.m, &aux.t);
		if (ExisteJob(j, aux.j)==false)
		{
			novoJob=CriaJob(aux.j);
			j=InsereJobFim(j, novoJob);
		}
		
		/* novoJob=CriaJob(aux.j);
		j=InsereJobFim(j, novoJob); */
		//j=InsereOperacaoJob(j, o);
	}
	//MostraListaJob(j);
    fclose(fp);
	return j;
}

/**
 * @brief Mostra todas as operações na estrutura
 * 
 * @param o 
 */
void MostraListaJob(Job* j) {
    Job* auxjob = j;
	
    while (auxjob) {
		printf("Job: %d\nOperacao: %d\nMaquina: %d\nTempo: %d\n\n", auxjob->cod,auxjob->op->cod,auxjob->op->m->cod,auxjob->op->m->t);
		auxjob = auxjob->next;
	}

}

void MostraALL(Job* j){

	Job* auxjob = j;
	while (auxjob)
	{
		
		printf("Job: %d\nOperacao: %d\nMaquina: %d\nTempo: %d\n\n", auxjob->cod, auxjob->op->cod, auxjob->op->m->cod, auxjob->op->m->t);
		auxjob=auxjob->next;
		
	}
	
}

#pragma endregion


#pragma region Planeamento


/**
 * @brief 
 * Escalonamento o primeiro que chega é o primeiro a sair, ou seja, será executado primeiro
 * @param j 
 * @param o 
 */
void fcfs (Job *j, Operacoes *o, Maquinas *m) {

    int tempo, tempmin=100, temptotal=0, auxop;
	Job *auxj = j;
	Job *auxj2 = j;
  	printf("\tEscalonamento\n");
    printf("\n");
	
	while (auxj!=NULL)
	{
	
		printf("\nJob: %d", auxj->cod);

		tempo = auxj->op->m->t;
		if (tempo<tempmin){
			tempmin=tempo;
			printf("\nTempo Operacao: %d", tempmin);
			temptotal+=tempmin;
		}
		
		auxj=auxj->next;
	}
	
  	
    printf("\n\n");

}

/* Listar Processos */
	void listprocs (Job *j) {
  	Job *auxj = j;
  	printf("\tListagem de Processos\n");
  	printf("\n");
  	while (auxj != NULL) {
    	printf("Processo: %d\tTempo: %d\n", auxj->cod, auxj->op->m->t);
    	auxj = auxj->next;

  	};
  	printf("\n\n");
 }

#pragma endregion
