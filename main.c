#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "struct.h"
#include "prototipos.h"
#include "funcoes.h"

int main(){
	FILE *fp;
	char continuar,menu;
	cad cadastro;
	fp=fopen("eleicaoPrefeito.bin","ab");
	system("clear");
	if(fp==NULL){
		printf("Nenhum cadastro foi realizado ainda!\n\n");
	}
	fclose(fp);
	do{
		printf("Escolha uma das opcoes\n1. Cadastrar novo candidato\n2. Modificar dados do candidato\n3. Listar todos os candidatos cadastrados\n4. Selecionar os candidatos cadastrados que estao envolvidos com a Lava Jato\n5. Apagar arquivo com cadastros de todos candidatos\n0. Sair do programa\n");
		scanf(" %c",&continuar);
		switch(continuar){
			case '0':
				break;
			case '1':
				cadastra(fp,&cadastro);
				break;
			case '2':
				modificaCad(fp,&cadastro,menu);
				break;
			case '3':
				tipoListagem(fp,cadastro,menu);
				break;
			case '4':
				listaLavaJato(fp,&cadastro);
				break;
			case '5':
				deleta(fp,menu);
				break;
			default:
				system("clear");
				printf("Digite uma opcao valida:\n\n");
		}
	}while(continuar!='0');
	return 0;
}
