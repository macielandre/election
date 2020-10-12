#define MAX_SIGLA 10

void cadastra(FILE*fp, cad *cadastro);
void modificaCad(FILE*fp, cad*cadastro,char menu);
void mostraLegendas(FILE*fp);
void tipoListagem(FILE *fp,cad cadastro,char menu);
void ordena(cad *cadastrosVet,char menu,int aux);
void listaCandidatosCrescente(FILE*fp,cad *cadastro,char menu);
void listaCandidatosDecrescente(FILE*fp,cad *cadastro,char menu);
void listaLavaJato(FILE*fp,cad *cadastro);
void deleta(FILE*fp,char menu);
void legendaIgual(FILE*fp,cad *cadastro);
void siglaIgual(FILE*fp,cad *cadastro);
void validaLegenda(int*legenda);
void validaSigla(char* sigla);
void validaLavaJato(char *lavaJato);
void validaNome(char *nome);
void tiraEnter(char* string);
void arrumaNome(char *nome);
void arrumaSigla(char *sigla);
void validaOpcao(int *opcao);
void validaOpcaoCad(int *opcao);