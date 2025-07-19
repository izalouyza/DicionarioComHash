/* Aplicar tabelas hash em uma aplicação real e Manipular dados textuais usando hashing.
Crie um programa que funcione como um dicionário: o usuário pode adicionar palavras e seus
significados, buscar e remover termos. Utilize uma tabela hash para organizar os dados.

-> Salvar e carregar o dicionário de um arquivo; (OK)
-> Suportar múltiplos significados por palavra. (QUASE)
--------------------------------------------------------------------------------------*/

// BIBLIOTECAS E MÓDULOS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

// DECLARAÇÃO DE CONSTANTES
#define suces "\n>> Operação realizada com sucesso.\n\n"
#define falha "\n>> Algo deu errado, tente novamente.\n\n"
#define vazio "\n>> Nenhum item encontrado.\n\n"
#define max 50 // Máximo de caracteres
#define tam 19 // Tamanho máximo da hash

// DECLARAÇÃO DE ESTRUTURAS
typedef struct mult_sigs{
    char signif[max*2];
    struct mult_sigs *prox;
} mult_sigs;

typedef struct dicio{
    char palavra[max];
    // A ideia é dar um jeito de converter o valor char para numérico a fim de gerar uma chave
    mult_sigs *signifs;
    struct dicio *prox;
} dicio;

dicio *inicio = NULL;

// ========================= PROTÓTIPOS DE FUNÇÕES ========================= //
void Carregar();
void Cadastrar();           // SALVAR TEMPORARIAMENTE NA LISTA
void Remover();             // FUNÇÃO ONDE DEVERÁ SER IMPLEMENTADO A HASH
// void Ordenar();            // ORGANIZA EM ORDEM ALFABÉTICA
void Exibir();              // EXIBIR CONTÉUDO DA LISTA E DO ARQUIVO
void Atualizar();           // ATUALIZAR ALGUMA PALAVRA/SIGNIFICADO OU ACRESCENTAR MAIS UM SIGNIFICADO
void Buscar();
void Salvar();              // LIBERAR MEMÓRIA DAS ESTRUTURAS
   
// ================================== FUNÇÃO PRINCIPAL ================================== //
int main(){
    setlocale(LC_ALL, "");
    Carregar();
    int opc = 0;
    printf("\n========== DICIONÁRIO DIGITAL ==========\n\n");
    while(1){
        printf("[1] Cadastrar\n[2] Remover \n[3] Exibir \n[4] Atualizar \n[5] Buscar \n[6] Sair \n>> ");
        while(scanf("%d", &opc) != 1) {printf("%s", falha); setbuf(stdin, NULL);}
        setbuf(stdin, NULL);
        switch (opc){
            case 1:   Cadastrar();              break;
            case 2:     Remover();              break;
            case 3:      Exibir();              break;
            case 4:   Atualizar();              break;
            case 5:      Buscar();              break;
            case 6:      Salvar(); return 0;    break;
            default:    printf("%s", falha);    break;
        }
    }
}

// ================================= FUNÇÕES AUXILIARES ================================= //
void Carregar(){
    FILE *arquivo = fopen("texto.txt", "r");
    if (arquivo == NULL) {printf("%s", vazio); return;}
    char linha[max*3];
    dicio *novo = NULL, *ultimo = NULL;
    mult_sigs *sig = NULL;
    while (fgets(linha, max*3, arquivo) != NULL) {
        if (linha[0] == '#') {
            novo = malloc(sizeof(dicio));
            if (novo == NULL) {printf("%s", falha); fclose(arquivo); exit(1);}
            strcpy(novo->palavra, linha);
            novo->palavra[strcspn(novo->palavra, "\n")] = 0;
            novo->prox = NULL;
            
            if (inicio == NULL) {
                inicio = novo;
            } else {
                ultimo->prox = novo;
            }
            ultimo = novo;
        } else {
            sig = malloc(sizeof(mult_sigs));
            if (sig == NULL) {printf("%s", falha); fclose(arquivo); exit(1);}
            strcpy(sig->signif, linha);
            sig->signif[strcspn(sig->signif, "\n")] = 0;
            novo->signifs = sig;
        }
    }
    fclose(arquivo);
}

void Inserir(dicio *no, mult_sigs *sig){
    printf("Digite uma palavra. \n>> ");
    fgets(no->palavra, max, stdin);
    no->palavra[strcspn(no->palavra, "\n")] = 0;
    
    printf("Digite um significado. \n>> ");
    fgets(sig->signif, max, stdin);
    sig->signif[strcspn(sig->signif, "\n")] = 0;

    sig->prox = NULL;
    no->signifs = sig;
}

void Cadastrar(){
    dicio *novo = malloc(sizeof(dicio));
    mult_sigs *sig = malloc(sizeof(mult_sigs));
    if(!novo || !sig) {printf("%s\n", falha); return;}
    Inserir(novo, sig);
    novo->prox = inicio;
    inicio = novo;
    printf("%s", suces);
}

void Remover(){ // AQUI DEVERÁ SER IMPLEMENTADO O ALGORITMO HASH
    if(inicio == NULL) {printf("%s", vazio); return;}
    
    char palvr[max] = " ";
    printf("Qual palavra deseja remover? \n>> ");
    fgets(palvr, max, stdin);
    palvr[strcspn(palvr, "\n")] = 0;

    dicio *atual = inicio, *anter = NULL;

    while(atual && strcmp(atual->palavra, palvr) != 0){ 
        anter = atual;
        atual = atual->prox;            
    }
    if (atual == NULL) {printf("%s", vazio); return;}
    else{
        int opc = 0;
        printf("Tem certeza de que deseja remover { %s }? \n[1] Sim \n[0] Não \n>> ", atual->palavra);
        while( scanf("%d", &opc) != 1){printf("%s", falha); setbuf(stdin, NULL);}
        setbuf(stdin, NULL);
        if (opc == 0) {return;}
    }
    if (anter == NULL){
        inicio = atual->prox;
    } else{
        anter->prox = atual->prox;
    }
    printf("%s", suces);
    free(atual);
}
 
void Exibir(){ // A ESTÉTICA DE EXIBIÇÃO DOS RESULTADOS PODE SER APRIMORADA
    if(inicio != NULL){
        printf("\n%25s\n", "DICIONÁRIO ELETRÔNICO");
        printf("--------------------------------------------------\n");
        dicio *atual = inicio;
        while(atual){
            printf("%-25s\n", atual->palavra);
            mult_sigs *sig = atual->signifs;
            while(sig){
                printf("-> %s\n", sig->signif);
                sig = sig->prox;
            }
            atual = atual->prox;
        }
        printf("--------------------------------------------------\n");
        printf("%s", suces);
    }else{printf("%s", vazio);}
}

void Atualizar(){ // Deverá conter a hash
    if(inicio == NULL) {printf("%s", vazio); return;}
    
    char palvr[max] = " ";
    printf("Qual palavra deseja atualizar? \n>> ");
    fgets(palvr, max, stdin);
    palvr[strcspn(palvr, "\n")] = 0;

    dicio *atual = inicio;
    mult_sigs *sig = atual->signifs;
    while(atual && strcmp(atual->palavra, palvr) != 0) {atual = atual->prox;}
    if (atual != NULL) {Inserir(atual, sig);} else {printf("%s", vazio); return;}
    printf("%s", suces);
}

void Buscar(){
    printf("\n>> Tem que ver isso aí :D\n\n");
}

void Salvar(){
    FILE *arquivo = fopen("texto.txt", "w");
    if(arquivo == NULL) {printf("%s (arquivo)\n", falha); exit(1);}
    if(inicio != NULL){
        dicio *atual = inicio, *temp = NULL;
        while (atual) {
            temp = atual->prox;
            fprintf(arquivo, "%s\n", atual->palavra);
            mult_sigs *sig = atual->signifs, *stemp = NULL;
            while(sig){
                stemp = sig->prox;
                fprintf(arquivo, "%s\n", sig->signif);
                free(sig);
                sig = stemp;
            }
            free(atual);
            atual = temp;
        }
    }
    fclose(arquivo);
    printf("\n>> Conteúdo salvo.\n");
    printf("%s", suces);
}

// ==================== CODIGOS DE REFERÊNCIA COM POSSÍVEIS UTILIDADES NO FUTURO ====================

/*
FILE *arquivo = fopen("texto.txt", "a");
if(arquivo == NULL){ printf("%s", falha); exit(1); }

fprintf(arquivo, "\n%s: ", novo->palavra);
fprintf(arquivo, "%s", novo->signif);

fclose(arquivo);

FILE *arquivo = fopen("texto.txt", "r");
if(a1rquivo == NULL) { printf("%s", falha); exit(1); }
char c = fgetc(arquivo);
while(c != EOF) { printf("%c", c); c = fgetc(arquivo); }
fclose(arquivo);
printf("\n----------\n\n");*/