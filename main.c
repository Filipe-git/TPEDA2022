/**
 * @file main.c
 * @author Filipe Alves 19573
 * @brief Trabalho Prático AED 2022
 * @version 0.1
 * @date 2022-04-18
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdio.h>
#include <locale.h>
#include "dados.h"

#pragma warning( disable : 4996 ) //evita MSG ERROS: _CRT_SECURE_NO_WARNINGS

int main(){

	
	setlocale(LC_ALL, "Portuguese");

	
	Maquinas* listamaq = NULL;
	Operacoes* listaop = NULL;
	Job* listajob = NULL;
	
	Maquinas* m;
	Operacoes* op;
	Job* job;
	job = CriaJob(1);
	listajob = InsereJobFim(listajob, job);
	m = CriaMaquinas(1,2);
	listamaq = InsereMaquinasFim(listamaq, m);
	op = CriaOperacoes(1);
	listaop = InsereOperacoesFim(listaop, op);
	listaop=InsereMaquinasOperacao(listaop, op->cod, listamaq, m->cod, m->t);
	listajob=InsereOperacaoJob(listajob, listaop);

	job = CriaJob(5);
	listajob = InsereJobFim(listajob, job);
	m = CriaMaquinas(3,1);
	listamaq = InsereMaquinasFim(listamaq, m);
	op = CriaOperacoes(3);
	listaop = InsereOperacoesFim(listaop, op);
	listaop=InsereMaquinasOperacao(listaop, op->cod, listamaq, m->cod, m->t);
	listajob=InsereOperacaoJob(listajob, listaop);

	job = CriaJob(1);
	listajob = InsereJobFim(listajob, job);
	m = CriaMaquinas(3,5);
	listamaq = InsereMaquinasFim(listamaq, m);
	op = CriaOperacoes(2);
	listaop = InsereOperacoesFim(listaop, op);
	listaop=InsereMaquinasOperacao(listaop, op->cod, listamaq, m->cod, m->t);
	listajob=InsereOperacaoJob(listajob, listaop);

	job = CriaJob(4);
	listajob = InsereJobFim(listajob, job);
	m = CriaMaquinas(2,1);
	listamaq = InsereMaquinasFim(listamaq, m);
	op = CriaOperacoes(6);
	listaop = InsereOperacoesFim(listaop, op);
	listaop=InsereMaquinasOperacao(listaop, op->cod, listamaq, m->cod, m->t);
	listajob=InsereOperacaoJob(listajob, listaop);

	
	//Utilizar ficheiros

	//Criar ficheiro com jobs
	//CriaFileJobs(listajob);

	//Ler as maquinas do ficheiro criado
	//listamaq=LerFileMaquinas("fileall.txt");

	//Ler as maquinas do ficheiro criado
	//listaop=LerFileOperacoes("fileall.txt", listamaq);

	//Ler as maquinas do ficheiro criado
	//listajob=LerFileJob("fileall.txt", listaop); 

	//Inserir
	//listajob=InsereOperacaoJob(listajob, listaop);

	//Alterar código de um job
	//listajob=AlteraCodigoJob(listajob, 1, 2);

	//Alterar operação de um job
	//listajob=AlteraOperacaoJob(listajob, listaop,1,1,7);
	
	//Remover um job a partir do teu id
	//listajob=RemoveJob(listajob, 1);

	//Remove operação de um job
	//listajob=RemoveOperacaoJob(listajob, 1, 1);

	//Mostrar toda a lista de jobs
	MostraALL(listajob);

	//Escalonamento
	//fcfs(listajob);
	//listprocs(listajob);

	return 0;

}
