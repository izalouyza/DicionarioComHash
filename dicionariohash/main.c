/* Aplicar tabelas hash em uma aplicação real e Manipular dados textuais usando hashing.
Crie um programa que funcione como um dicionário: o usuário pode adicionar palavras e seus
significados, buscar e remover termos. Utilize uma tabela hash para organizar os dados.

-> Salvar e carregar o dicionário de um arquivo;
-> Suportar múltiplos significados por palavra.
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
#define max 50

// DECLARAÇÃO DE ESTRUTURAS
typedef struct dicio{
    char palavra[max];
    char signif[max*2];
    struct dicio *prox;
} dicio;

dicio *inicio = NULL;

// ========================= PROTÓTIPOS DE FUNÇÕES ========================= //
void Carregar();
void Cadastrar();           // SALVAR TEMPORARIAMENTE NA LISTA
void Remover();             // FUNÇÃO ONDE DEVERÁ SER IMPLEMENTADO A HASH
// void Ordenar();            // ORGANIZA EM ORDEM ALFABÉTICA
void Exibir();              // EXIBIR CONTÉUDO DA LISTA E DO ARQUIVO
void Atualizar();           // ATUALIZAR ALGUMA PALAVRA OU SIGNIFICADO
void Salvar();              // LIBERAR MEMÓRIA DAS ESTRUTURAS
   
// ================================== FUNÇÃO PRINCIPAL ================================== //
int main(){
    setlocale(LC_ALL, "");
    int opc = 0;
    Carregar();
    printf("\n========== DICIONÁRIO DIGITAL ==========\n\n");
    while(1){
        printf("[1] Cadastrar\n[2] Remover \n[3] Exibir \n[4] Atualizar \n[5] Sair \n>> ");
        while(scanf("%d", &opc) != 1) {printf("%s", falha); setbuf(stdin, NULL);}
        setbuf(stdin, NULL);
        switch (opc){
            case 1:   Cadastrar();              break;
            case 2:     Remover();              break;
            case 3:      Exibir();              break;
            case 4:   Atualizar();              break;
            case 5:      Salvar(); return 0;    break;
            default:    printf("%s", falha);    break;
        }
    }
}

// ================================= FUNÇÕES AUXILIARES ================================= //
void Carregar(){
    FILE *arquivo = fopen("Texto.txt", "r");
    if (arquivo == NULL) {printf("%s", vazio); return;}
    char linha[max*3];
    int paridade = 1;
    dicio *novo = NULL, *ultimo = NULL;
    while (fgets(linha, max*3, arquivo) != NULL) {
        if (paridade == 1) { // 1 (palavra) / 0 (significado)
            novo = malloc(sizeof(dicio));
            if (novo == NULL) {printf("%s", falha); fclose(arquivo); exit(1);}
            strcpy(novo->palavra, linha);
            novo->palavra[strcspn(novo->palavra, "\n")] = 0;
            novo->prox = NULL;
            if (inicio == NULL) {inicio = novo;} else {ultimo->prox = novo;}
            ultimo = novo;
            paridade = 0;
        }else{
            strcpy(novo->signif, linha);
            novo->signif[strcspn(novo->signif, "\n")] = 0;
            paridade = 1;
        }
    }
    fclose(arquivo);
}

void Inserir(dicio *no){
    printf("Digite uma palavra. \n>> ");
    fgets(no->palavra, max, stdin);
    no->palavra[strcspn(no->palavra, "\n")] = 0;
    
    printf("Digite uma palavra. \n>> ");
    fgets(no->signif, max, stdin);
    no->signif[strcspn(no->signif, "\n")] = 0;
}

void Cadastrar(){
    dicio *novo = malloc(sizeof(dicio));
    if(novo == NULL) {printf("%s (novo)\n", falha); return;}
    Inserir(novo);
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
            printf("# %-25s -> %s\n", atual->palavra, atual->signif);
            atual = atual->prox;
        }
        printf("--------------------------------------------------\n");
        printf("%s", suces);
    }else{printf("%s", vazio);}
}

void Atualizar(){
    if(inicio == NULL) {printf("%s", vazio); return;}
    
    char palvr[max] = " ";
    printf("Qual palavra deseja atualizar? \n>> ");
    fgets(palvr, max, stdin);
    palvr[strcspn(palvr, "\n")] = 0;

    dicio *atual = inicio;

    while(atual && strcmp(atual->palavra, palvr) != 0) {atual = atual->prox;}
    if (atual != NULL) {Inserir(atual);} else {printf("%s", vazio); return;}
    printf("%s", suces);
}

void Salvar(){
    FILE *arquivo = fopen("Texto.txt", "w");
    if(arquivo == NULL) {printf("%s (arquivo)\n", falha); exit(1);}
    if(inicio != NULL){
        dicio *atual = inicio, *temp = NULL;
        while (atual) {
            temp = atual->prox;
            fprintf(arquivo, "%s\n", atual->palavra);
            fprintf(arquivo, "%s\n", atual->signif);
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
FILE *arquivo = fopen("Texto.txt", "a");
if(arquivo == NULL){ printf("%s", falha); exit(1); }

fprintf(arquivo, "\n%s: ", novo->palavra);
fprintf(arquivo, "%s", novo->signif);

fclose(arquivo);

FILE *arquivo = fopen("Texto.txt", "r");
if(a1rquivo == NULL) { printf("%s", falha); exit(1); }
char c = fgetc(arquivo);
while(c != EOF) { printf("%c", c); c = fgetc(arquivo); }
fclose(arquivo);
printf("\n----------\n\n");*/