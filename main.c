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


int main(){

	
	Job *j1 = CriaJob(1, "camisolas");
	Job *j2 = CriaJob(2, "sapatos");
	Maquinas *m1 = CriaMaquinas(1);
	Maquinas *m2 = CriaMaquinas(2);
	Operacoes *o11 = CriaOperacoes(1, j1->cod, m1->cod, 4); //cod, maquina, tempo

	Operacoes* OPLista = NULL;
	OPLista = InsereOperacoesFim(OPLista, o11);
	bool aux = ExisteOperacoes(OPLista, 1);
	MostraLista(OPLista);
	OPLista=AlteraOperacoes(OPLista, 1, j2->cod, m2->cod, 5); 
	MostraLista(OPLista);
	OPLista = RemoveOperacoes(OPLista, 1);
	MostraLista(OPLista);

	/*Utilizar ficheiros*/
	
	bool b = gravarOperacoesText("Dados.txt", OPLista);
	DestroiLista(&OPLista);
	OPLista = lerOperacoesText("Dados.txt");
	MostraLista(OPLista);

	return 0;

}