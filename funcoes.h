#include <stdio.h>
#include <stdlib.h>

//cadastrar um candidato novo

void cadastra(FILE*fp, cad *cadastro){
	char lixo;
	system("clear");
	printf("Digite o numero de legenda do candidato, de 10 ate 100:\n");
	scanf("%d",&cadastro->nmrLegenda);
	legendaIgual(fp,cadastro);
	system("clear");
	printf("Legenda: %d\t\tSigla: \t\tNome: \t\tEnvolvimento na lava jato: \n\n",cadastro->nmrLegenda);
	printf("Digite a sigla do partido do candidato com ate 10 letras:\n");
	scanf /*         */(" %[^\n]",cadastro->sigla);
	tiraEnter(cadastro->sigla);
	siglaIgual(fp,cadastro);
	system("clear");
	printf("Legenda: %d\t\tSigla: %s\t\tNome: \t\tEnvolvimento na lava jato: \n\n",cadastro->nmrLegenda,cadastro->sigla);
	printf("Digite o nome do candidato:\n");
	scanf /*         */(" %[^\n]",cadastro->nome);
	tiraEnter(cadastro->nome);
	validaNome(cadastro->nome);
	arrumaNome(cadastro->nome);
	system("clear");
	printf("Legenda: %d\t\tSigla: %s\t\tNome: %s\t\tEnvolvimento na lava jato: \n\n",cadastro->nmrLegenda,cadastro->sigla,cadastro->nome);
	printf("Digite ""S"" se o candidato esta envolvido na lava jato e ""N"" caso ele nao esteja:\n");
	scanf(" %c",&cadastro->lavaJato);
	validaLavaJato(&cadastro->lavaJato);
	cadastro->lavaJato=toupper(cadastro->lavaJato);
	fp=fopen("eleicaoPrefeito.bin","ab");
	if(fp==NULL){
		system("clear");
		printf("Nao foi possivel cadastrar o candidato!\n");
		printf("\nEnter para voltar para o menu:\n");
		scanf("%c",&lixo);
        getchar();
		system("clear");
	}
	else{
		fwrite(cadastro,sizeof(cad),1,fp);
		fclose(fp);
		system("clear");
		printf("Legenda: %d\t\tSigla: %s\t\tNome: %s\t\tEnvolvimento na lava jato:  %c\n\n",cadastro->nmrLegenda,cadastro->sigla,cadastro->nome,cadastro->lavaJato);
		printf("O candidato foi cadastrado com sucesso!\n");
		printf("\nEnter para voltar para o menu:\n");
		scanf("%c",&lixo);
        getchar();
		getchar();
		system("clear");
	}
}

//modificar os dados cadastrais de um candidato

void modificaCad(FILE*fp,cad *cadastro,char menu){
	int bytes,legenda,cont=0;;
	FILE* fpSec;
	char lixo;
	system("clear");
	mostraLegendas(fp);
	printf("Digite a legenda do candidato a ser procurado:\n");
	scanf("%d",&legenda);
	fp=fopen("eleicaoPrefeito.bin","rb");
	if(fp==NULL){
		printf("Erro na abertura do arquivo\n");
		printf("\nEnter para voltar para o menu:\n");
		scanf("%c",&lixo);
        getchar();
		system("clear");
	}
	else{
		while(fread(cadastro,sizeof(cad),1,fp)){
			if(cadastro->nmrLegenda==legenda){
				bytes=ftell(fp)-sizeof(cad);
				cont++;
				break;
			}
		}
		fclose(fp);
		system("clear");
		if(cont==0){
			printf("Nao existe nenhum cadastro com esse numero de legenda!\n");
			printf("\nEnter para voltar para o menu:\n");
			scanf("%c",&lixo);
            getchar();
			system("clear");
		}
		else if(cont!=0){
			do{
				printf("Candidato %d\n\nNome: %s\t\tSigla: %s\t\t Envolvimento na lava jato:  %c\n\n",legenda,cadastro->nome,cadastro->sigla,cadastro->lavaJato);
				printf("Escolha qual campo do cadastro deseja modificar:\n1.Sigla do partido\n2.Envolvimento na lava jato\n3.Nome do candidato\n4.Deletar registro\n");
		
				scanf(" %c",&menu);
				switch(menu){
					case '1':
						system("clear");
						printf("Candidato %d\n\nNome: %s\t\tSigla: %s\t\t Envolvimento na lava jato:  %c\n\n",legenda,cadastro->nome,cadastro->sigla,cadastro->lavaJato);
						printf("Digite a nova sigla:\n");
				
						scanf /*         */(" %[^\n]",cadastro->sigla);
						tiraEnter(cadastro->sigla);
						siglaIgual(fp,cadastro);
						arrumaSigla(cadastro->sigla);
						fp=fopen("eleicaoPrefeito.bin","rb+");
						if(fp==NULL){
							system("clear");
							printf("Erro na abertura do arquivo\n");
							printf("\nEnter para voltar para o menu:\n");
							scanf("%c",&lixo);
                            getchar();
							system("clear");
						}
						else{
							fseek(fp,bytes,0);
							fwrite(cadastro,sizeof(cad),1,fp);
							fclose(fp);
							system("clear");
							printf("A sigla do %d foi alterada com sucesso!\n\n",legenda);
							printf("\nEnter para voltar para o menu:\n");
							scanf("%c",&lixo);
                            getchar();
							system("clear");
						}
						break;
					case '2':
						system("clear");
						printf("Candidato %d\n\nNome: %s\t\tSigla: %s\t\t Envolvimento na lava jato:  %c\n\n",legenda,cadastro->nome,cadastro->sigla,cadastro->lavaJato);
						printf("Digite o envolvimento na lava jato:\n");
						scanf(" %c",&cadastro->lavaJato);
						validaLavaJato(&cadastro->lavaJato);
						cadastro->lavaJato=toupper(cadastro->lavaJato);
						fp=fopen("eleicaoPrefeito.bin","rb+");
						if(fp==NULL){
							system("clear");
							printf("Erro na abertura do arquivo\n");
							printf("\nEnter para voltar para o menu:\n");
							scanf("%c",&lixo);
                            getchar();
							system("clear");
						}
						else{
							fseek(fp,bytes,0);
							fwrite(cadastro,sizeof(cad),1,fp);
							fclose(fp);
							system("clear");
							printf("O envolvimento na lava jato do %d foi alterado com sucesso!\n\n",legenda);
							printf("\nEnter para voltar para o menu:\n");
							scanf("%c",&lixo);
                            getchar();
							system("clear");
						}
						break;
					case '3':
						system("clear");
						printf("Candidato %d\n\nNome: %s\t\tSigla: %s\t\t Envolvimento na lava jato:  %c\n\n",legenda,cadastro->nome,cadastro->sigla,cadastro->lavaJato);
						printf("Digite o novo nome:\n");
						scanf /*         */(" %[^\n]",cadastro->nome);
						tiraEnter(cadastro->nome);
						validaNome(cadastro->nome);
						arrumaNome(cadastro->nome);
						fp=fopen("eleicaoPrefeito.bin","rb+");
						if(fp==NULL){
							system("clear");
							printf("Erro na abertura do arquivo\n");
							printf("\nEnter para voltar para o menu:\n");
							scanf("%c",&lixo);
                            getchar();
							system("clear");
						}
						else{
							fseek(fp,bytes,0);
							fwrite(cadastro,sizeof(cad),1,fp);
							fclose(fp);
							system("clear");
							printf("O nome do %d foi alterado com sucesso!\n\n",legenda);
							printf("\nEnter para voltar para o menu:\n");
							scanf("%c",&lixo);
                            getchar();
							system("clear");
						}
						break;
					case '4':
						fp=fopen("eleicaoPrefeito.bin","rb");
						if(fp==NULL){
							system("clear");
							printf("Erro na abertura do arquivo\n");
							printf("\nEnter para voltar para o menu:\n");
							scanf("%c",&lixo);
                            getchar();
							system("clear");
						}
						else{
							while(fread(cadastro,sizeof(cad),1,fp)){
								if(cadastro->nmrLegenda!=legenda){
									fpSec=fopen("arquivoSec.bin","ab");
										fwrite(cadastro,sizeof(cad),1,fpSec);
									fclose(fpSec);
								}
							}
							fclose(fp);
							remove("eleicaoPrefeito.bin");
							system("clear");
							if(rename("arquivoSec.bin","eleicaoPrefeito.bin")==0){
								printf("O cadastro foi deletado!\n\n");
								printf("\n1. Para cadastrar um novo candidato\nQualquer tecla para voltar para o menu\n");
						
								scanf(" %c",&menu);
								if(menu=='1'){
									system("clear");
									cadastra(fp,cadastro);
								}
								else{
							
									system("clear");
								}	
							}
							else{
								printf("O cadastro nao foi deletado!\n\n");
								printf("\nEnter para voltar para o menu:\n");
								scanf("%c",&lixo);
                                getchar();
								system("clear");
							}
						}
						break;
					default:
						system("clear");
						printf("Digite uma opcao valida!\n\n");
						break;
				}
			}while(menu<49 || menu>52);
		}
	}
}

//mostrar as legendas cadastradas

void mostraLegendas(FILE*fp){
	char lixo;
	cad ajuda;
	fp=fopen("eleicaoPrefeito.bin","rb");
	if(fp==NULL){
		printf("Falha ao abrir o arquivo!\n");
		printf("\nEnter para voltar para o menu:\n");
		scanf("%c",&lixo);
        getchar();
		system("clear");
	}
	else{
		printf("Numeros de legenda cadastrados:\n\n");
		while(fread(&ajuda,sizeof(cad),1,fp)){
			printf("%d\t",ajuda.nmrLegenda);
		}
		printf("\n\n");
		fclose(fp);
	}
}

//escolher o tipo de listagem feita pelo usuario

void tipoListagem(FILE *fp,cad cadastro,char menu){
	system("clear");
	do{
		printf("Digite 1 para mostrar os candidatos em ordem crescente ou 2 para decrescente:\n");

		scanf(" %c",&menu);
		switch(menu){
			case '1':
				listaCandidatosCrescente(fp,&cadastro,menu);
				break;
			case '2':
				listaCandidatosDecrescente(fp,&cadastro,menu);
			default:
				printf("Digite uma opcao valida:\n\n");
				break;
		}
	}while(menu<49 || menu>50);
}

//ordenar os nomes na ordem escolhida pelo usuario

void ordena(cad *cadastrosVet,char menu,int aux){
	int linha,coluna,ordenador;
	cad ajuda;
	switch(menu){
		case '1':
			ordenador=1;
			break;
		case '2':
			ordenador=-1;
			break;
	}
	for(linha=0;linha<aux;linha++){
    	for(coluna=0;coluna<aux-1;coluna++){
        	if(strcmp(cadastrosVet[coluna].nome,cadastrosVet[coluna+1].nome)==ordenador) {
        	    ajuda=cadastrosVet[coluna];
                cadastrosVet[coluna]=cadastrosVet[coluna+1];
            	cadastrosVet[coluna+1]=ajuda;
        	}
		}
    }
}

//mostrar os canditados cadastrados com seus nomes em ordem alfabetica

void listaCandidatosCrescente(FILE*fp,cad *cadastro,char menu){
    int size=0,aux=0,tam,cont=0;
	char s[10]="Lava Jato",n[12]="Ficha Limpa",lixo;
	fp=fopen("eleicaoPrefeito.bin","rb");
	if(fp==NULL){
		printf("Falha ao abrir o arquivo!\n");
		printf("\nEnter para voltar para o menu:\n");
		scanf("%c",&lixo);
        getchar();
		system("clear");
	}
	else{
		fseek(fp,0,SEEK_END);
		size=ftell(fp);
		rewind(fp);
		tam=size/sizeof(cad);
		cad cadastrosVet[tam];
		system("clear");
		if(size==0){
			fclose(fp);
			printf("Nao existem informacoes para serem lidas!\n\n");
			printf("\nEnter para voltar para o menu:\n");
			scanf(" %c",&lixo);
			getchar();
			system("clear");
		}
		else{
			while(fread(&cadastrosVet[aux],sizeof(cad),1,fp)){
				aux++;
			}
			fclose(fp);
			ordena(cadastrosVet,menu,aux);
    		printf("Candidatos:\n\nLegenda\t\tSigla do partido\t\tEnvolvimento na lava jato\t\tNome\n");
			for(cont=0;cont<aux;cont++){
				if(cadastrosVet[cont].lavaJato=='S'){
					printf("%-7d\t\t%-16s\t\t%-25s\t\t%-4s\n",cadastrosVet[cont].nmrLegenda,cadastrosVet[cont].sigla,s,cadastrosVet[cont].nome);
				}
				else if(cadastrosVet[cont].lavaJato=='N'){
					printf("%-7d\t\t%-16s\t\t%-25s\t\t%-4s\n",cadastrosVet[cont].nmrLegenda,cadastrosVet[cont].sigla,n,cadastrosVet[cont].nome);
				}
			}
			printf("\nEnter para voltar para o menu:\n");
			scanf("%c",&lixo);
            getchar();
			system("clear");
		}
	}
}

//mostrar os canditados cadastrados com seus nomes em ordem decrescente

void listaCandidatosDecrescente(FILE*fp,cad *cadastro,char menu){
    int size=0,aux=0,tam,cont=0;
	char s[10]="Lava Jato",n[12]="Ficha Limpa",lixo;
	fp=fopen("eleicaoPrefeito.bin","rb");
	if(fp==NULL){
		printf("Falha ao abrir o arquivo!\n");
		printf("\nEnter para voltar para o menu:\n");
		scanf("%c",&lixo);
        getchar();
		system("clear");
	}
	else{
		fseek(fp,0,SEEK_END);
		size=ftell(fp);
		rewind(fp);
		tam=size/sizeof(cad);
		cad cadastrosVet[tam];
		system("clear");
		if(size==0){
			fclose(fp);
			printf("Nao existem informacoes para serem lidas!\n\n");
			printf("\nEnter para voltar para o menu:\n");
			scanf("%c",&lixo);
	        getchar();
			system("clear");
		}
		else{
			while(fread(&cadastrosVet[aux],sizeof(cad),1,fp)){
				aux++;
			}
			fclose(fp);
			ordena(cadastrosVet,menu,aux);
    		printf("Candidatos:\n\nLegenda\t\tSigla do partido\t\tEnvolvimento na lava jato\t\tNome\n");
			for(cont=0;cont<aux;cont++){
				if(cadastrosVet[cont].lavaJato=='S'){
					printf("%-7d\t\t%-16s\t\t%-25s\t\t%-4s\n",cadastrosVet[cont].nmrLegenda,cadastrosVet[cont].sigla,s,cadastrosVet[cont].nome);
				}
				else if(cadastrosVet[cont].lavaJato=='N'){
					printf("%-7d\t\t%-16s\t\t%-25s\t\t%-4s\n",cadastrosVet[cont].nmrLegenda,cadastrosVet[cont].sigla,n,cadastrosVet[cont].nome);
				}
			}
			printf("\nEnter para voltar para o menu:\n");
			scanf("%c",&lixo);
            getchar();
			system("clear");
		}
	}
}

//mostrar os canditados cadastrados que estao envolvidos na lava jato com seus partidos em ordem alfabetica 

void listaLavaJato(FILE*fp,cad *cadastro){
    int linha,coluna,size=0,aux=0,tam,cont=0;
	char lixo;
	fp=fopen("eleicaoPrefeito.bin","rb");
	if(fp==NULL){
		printf("Falha ao abrir o arquivo!\n");
		printf("\nEnter para voltar para o menu:\n");
		scanf("%c",&lixo);
        getchar();
		system("clear");
	}
		else{
		fseek(fp,0,SEEK_END);
		size=ftell(fp);
		rewind(fp);
		tam=size/sizeof(cad);
		cad cadastrosVet[tam],ajuda;
		system("clear");
		if(size==0){
			fclose(fp);
			printf("Nao existem informacoes para serem lidas!\n\n");
			printf("\nEnter para voltar para o menu:\n");
			scanf("%c",&lixo);
            getchar();
			system("clear");
		}
		else{
			while(fread(&cadastrosVet[aux],sizeof(cad),1,fp)){
				aux++;
			}
			fclose(fp);
    		for(linha=0;linha<aux;linha++){
    		    for(coluna=0;coluna<aux-1;coluna++){
    		        if(strcmp(cadastrosVet[coluna].sigla,cadastrosVet[coluna+1].sigla)==1) {
    		            ajuda=cadastrosVet[coluna];
    		            cadastrosVet[coluna]=cadastrosVet[coluna+1];
    		            cadastrosVet[coluna+1]=ajuda;
    		        }
    		    }
    		}
    		printf("Envolvidos na lava jato:\n\nSigla do partido\t\tLegenda\t\tNome\n");
			for(cont=0;cont<aux;cont++){
			    if(cadastrosVet[cont].lavaJato=='S' || cadastrosVet[cont].lavaJato=='s'){
				    printf("%-16s\t\t%-7d\t\t%-4s\n",cadastrosVet[cont].sigla,cadastrosVet[cont].nmrLegenda,cadastrosVet[cont].nome);
				}
			}
			printf("\nEnter para voltar para o menu:\n");
			scanf("%c",&lixo);
            getchar();
			system("clear");
		}
	}
}

//deletar o arquivo de registro e criar um novo sem nada

void deleta(FILE*fp,char menu){
	char lixo;
	system("clear");
	do{
	printf("Voce tem certeza que deseja excluir todos os arquivos? Se sim digite ""S"" se nao digite ""N""\n");
	scanf(" %c",&menu);
	menu=toupper(menu);
	system("clear");
		switch(menu){
			case 'S':
				fp=fopen("eleicaoPrefeito.bin","wb");
				if(fp==NULL){
					printf("Falha ao abrir o arquivo!\n");
					printf("\nEnter para voltar para o menu:\n");
					scanf("%c",&lixo);
                    getchar();
					system("clear");
				}
				else{
					fclose(fp);
					printf("Os dados foram apagados com sucesso!\n\n");
					printf("Enter para voltar para o menu:\n");
					scanf("%c",&lixo);
                    getchar();
					system("clear");
				}
				break;
			case 'N':
				printf("Operacao cancelada! Os dados nao foram apagados!\n\n");
				printf("Enter para voltar para o menu:\n");
				scanf("%c",&lixo);
                getchar();
				system("clear");
				break;
			default:
				printf("Digite uma opcao valida:\n\n");
		}
	}while(menu!='S' && menu!='N');
}

//verificar se ja exite um numero de legenda igual

void legendaIgual(FILE*fp,cad *cadastro){
	cad ajuda;
	char lixo;
	fp=fopen("eleicaoPrefeito.bin","rb");
	if(fp==NULL){
		printf("Falha ao abrir o arquivo!\n");
		printf("\nEnter para voltar para o menu:\n");
		scanf("%c",&lixo);
        getchar();
		system("clear");
	}
	else{

		validaLegenda(&cadastro->nmrLegenda);
		while(fread(&ajuda,sizeof(cad),1,fp)){
			while(ajuda.nmrLegenda==cadastro->nmrLegenda){
				system("clear");
				printf("Digite uma legenda que nao foi cadastrada ainda:\n");
				scanf("%d",&cadastro->nmrLegenda);
				validaLegenda(&cadastro->nmrLegenda);
				rewind(fp);
			}
		}
		fclose(fp);
	}
}

//verificar se ja exite uma sigla igual

void siglaIgual(FILE*fp,cad *cadastro){
	cad ajuda;
	char lixo;
	fp=fopen("eleicaoPrefeito.bin","rb");
	if(fp==NULL){
		printf("Falha ao abrir o arquivo!\n");
		printf("\nEnter para voltar para o menu:\n");
		scanf("%c",&lixo);
        getchar();
		system("clear");
	}
	else{

		validaSigla(cadastro->sigla);
		arrumaSigla(cadastro->sigla);
		while(fread(&ajuda,sizeof(cad),1,fp)){
			while(strcmp(ajuda.sigla,cadastro->sigla)==0){
				system("clear");
				printf("Digite uma legenda que nao foi cadastrada ainda:\n");
				scanf /*         */(" %[^\n]",cadastro->sigla);
				tiraEnter(cadastro->sigla);
				validaSigla(cadastro->sigla);
				arrumaSigla(cadastro->sigla);
				rewind(fp);
			}
		}
		fclose(fp);
	}
}

//validar legenda

void validaLegenda(int *legenda){
	while(*legenda<10 || *legenda>100){
		system("clear");
		printf("Digite uma legenda valida, de 10 ate 100:\n");
		scanf("%d",legenda);
	}
}

//validar sigla

void validaSigla(char* sigla){
	while(strlen(sigla)<1){
		system("clear");
		printf("Digite uma sigla valida, com ate 10 letras:\n");

		scanf /*         */(" %[^\n]",sigla);
		tiraEnter(sigla);
	}
}
//validar o envolvimento na lava jato

void validaLavaJato(char *lavaJato){
	while(*lavaJato!='S' && *lavaJato!='N' && *lavaJato!='s' && *lavaJato!='n'){
		system("clear");
		printf("Digite uma resposta valida, ""S"" ou ""N"":\n");

		scanf(" %c",lavaJato);
	}
}

//validar nome

void validaNome(char *nome){
	while(strlen(nome)<1){
		system("clear");
		printf("Digite um nome valido:\n");

		scanf /*         */(" %[^\n]",nome);
		tiraEnter(nome);
	}
}

//tirar o enter na string 

void tiraEnter(char* string){
	int tam;
	tam=strlen(string);
	if(string[tam-1]=='\n'){
		string[strlen(string)-1]='\0';
	}
}

//padronizar o nome

void arrumaNome(char *nome){
    int aux;
    for(aux=0;aux<strlen(nome);aux++){
        nome[aux]=tolower(nome[aux]);
    }
    nome[0]=toupper(nome[0]);
}

//padronizar a sigla

void arrumaSigla(char *sigla){
	int aux;
    for(aux=0;aux<strlen(sigla);aux++){
        sigla[aux]=toupper(sigla[aux]);
    }
}