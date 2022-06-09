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

	
	Maquinas* m;
	Operacoes* op;
	Job* job;

	Maquinas* listamaq = NULL;
	Operacoes* listaop = NULL;
	Job* listajob = NULL;

	job = CriaJob(1);
	listajob = InsereJobFim(listajob, job);
	m = CriaMaquinas(1,2);
	listamaq = InsereMaquinasFim(listamaq, m);
	op = CriaOperacoes(1);
	listaop = InsereOperacoesFim(listaop, op);
	//listaop=InsereMaquinasOperacao(listaop, op->cod, listamaq, m->cod, m->t);
	//listajob=InsereOperacaoJob(listajob, listaop);
 
	job = CriaJob(5);
	listajob = InsereJobFim(listajob, job);
	m = CriaMaquinas(3,1);
	listamaq = InsereMaquinasFim(listamaq, m);
	op = CriaOperacoes(3);
	listaop = InsereOperacoesFim(listaop, op);
	//listaop=InsereMaquinasOperacao(listaop, op->cod, listamaq, m->cod, m->t);
	//listajob=InsereOperacaoJob(listajob, listaop);

	job = CriaJob(1);
	listajob = InsereJobFim(listajob, job);
	m = CriaMaquinas(3,5);
	listamaq = InsereMaquinasFim(listamaq, m);
	op = CriaOperacoes(2);
	listaop = InsereOperacoesFim(listaop, op);
	//listaop=InsereMaquinasOperacao(listaop, op->cod, listamaq, m->cod, m->t);
	//listajob=InsereOperacaoJob(listajob, listaop);

	job = CriaJob(4);
	listajob = InsereJobFim(listajob, job);
	m = CriaMaquinas(2,1);
	listamaq = InsereMaquinasFim(listamaq, m);
	op = CriaOperacoes(6);
	listaop = InsereOperacoesFim(listaop, op);
	//listaop=InsereMaquinasOperacao(listaop, op->cod, listamaq, m->cod, m->t);
	//listajob=InsereOperacaoJob(listajob, listaop);


	//Ler as maquinas do ficheiro criado
	//listamaq=LerFileMaquinas("fileall.txt");
	//MostraListaMaquinas(listamaq);

	//Ler as maquinas do ficheiro criado
	//listaop=LerFileOperacoes("fileall.txt");
	InsereMaquinasOperacao(listaop,listamaq);
	//MostraListaOperacoes(listaop);

	//Ler as maquinas do ficheiro criado
	//listajob=LerFileJob("fileall.txt");
	InsereOperacaoJob(listajob, listaop);
	//MostraListaJob(listajob);

	printf("\n\nAntes:\n");
	MostraALL(listajob);
	//Alterar código de todos os jobs igual ao valor do parametro
	//listajob=AlteraCodigoJob(listajob, 1, 2);

	//Alterar operação de um job que seja igual ao codigo do job e ao codigo de operacao passado por parametro
	//listajob=AlteraOperacaoJob(listajob,1,2,6);
	
	//Remover um job a partir do teu id
	listajob=RemoveJob(listajob, 5);

	//Remove operação de um job e recebe valores do proximo job da lista
	//listajob=RemoveOperacaoJob(listajob, 1, 1);

	
	//Mostrar toda a lista de jobs
	printf("\n\nDepois\n");
	MostraALL(listajob);

	//Criar ficheiro com jobs
	CriaFileJobs(listajob, listaop, listamaq);

	//Escalonamento
	//fcfs(listajob,listaop,listamaq);
	//listprocs(listajob);

	return 0;

}
