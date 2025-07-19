/* Aplicar tabelas hash em uma aplicação real e Manipular dados textuais usando hashing.
Crie um programa que funcione como um dicionário: o usuário pode adicionar palavras e seus
significados, buscar e remover termos. Utilize uma tabela hash para organizar os dados.

EXTRAS OPCIONAIS
-> Salvar e carregar o dicionário de um arquivo; (OK)
-> Suportar múltiplos significados por palavra.

CRITÉRIOS DE AVALIAÇÃO:
? Funcionamento correto das operações (30%)
? Uso eficaz de hash (20%)
? Interface amigável no terminal (20%)
? Relatório com análise e exemplos (30%)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

void mens(char par){
    switch (par){
        case 's': printf("\n>> Operação realizada com sucesso.\n\n");    break;
        case 'f': printf("\n>> Algo deu errado, tente novamente.\n\n");  break;
        case 'e': printf("\n>> Nenhum item encontrado no momento.\n\n"); break;
        case 'c': printf("\n>> ATENÇÃO: Ocorrência de colisão.\n\n");    break;
        default:  printf("\n>> (Parâmetro errado)\n\n");
    }
}

#define size_word 50
#define size_mean 100
#define size_hash 19

typedef struct palavra{
    char word[size_word];
    char mean[size_mean];
} palavra;

palavra hash_table[size_hash];

void Save();
void Load();
int Hash_String(const char *word);
int Collision_Handler(int indice);
int MakeHashCode(int chave);
palavra GetInputValue();
void Insert();
void PrintHash();
void Search();
void Remove();

int main(){
    setlocale(LC_ALL, "");
    Load();
    char opc = ' ';
    do{
        printf("\n================ DICIONARIO DIGITAL ================\n");
        printf("[1] Cadastrar\n[2] Exibir \n[3] Buscar \n[4] Remover \n[5] Sair \n>> ");
        scanf("%c", &opc);
        setbuf(stdin, NULL);
        switch (opc){
            case '1':           Insert();     break;
            case '2':        PrintHash();     break;
            case '3':           Search();     break;
            case '4':           Remove();     break;
            case '5':             Save();     break;
            default:           mens('f');     break;
        }
    }while(opc != '5');
    return 0;
}

int MakeHashCode(int chave){
    return (chave % size_hash);
}

int Collision_Handler(int indice){
    mens('c');
    return MakeHashCode(indice + 1);
}

int Hash_String(const char *word){
    int hash = 0;
    int i = 0;
    while(word[i] != '\0'){
        hash += (int)word[i];
        i++;
    }
    return hash;
}

void Save(){
    FILE *arquivo = fopen("texto.txt", "w");
    if(!arquivo){
        mens('f');
        exit(1);
    }

    for(int i = 0; i < size_hash; i++){
        fprintf(arquivo, "%s\n", hash_table[i].word);
        fprintf(arquivo, "%s\n", hash_table[i].mean);
    }

    fclose(arquivo);
}

void Load(){
    FILE *arquivo = fopen("texto.txt", "r");
    if (!arquivo){
        mens('f');
        exit(1);
    }

    char word[size_word];
    char mean[size_mean];
    int hash = 0;
    int indice = 0;

    while (fgets(word, size_hash, arquivo) != NULL &&
           fgets(mean, size_mean, arquivo) != NULL) {
        word[strcspn(word, "\n")] = 0;
        mean[strcspn(mean, "\n")] = 0;

        hash = Hash_String(word);
        indice = MakeHashCode(hash);

        while (hash_table[indice].word[0] != '\0') {
            indice = Collision_Handler(indice);
        }

        strcpy(hash_table[indice].word, word);
        strcpy(hash_table[indice].mean, mean);
    }
    fclose(arquivo);
}


palavra GetInputValue(){
    palavra p;

    printf("# Digite uma palavra: \n>> ");
    fgets(p.word, size_word, stdin);
    p.word[strcspn(p.word, "\n")] = 0;

    printf("# Digite o significado: \n>> ");
    fgets(p.mean, size_word, stdin);
    p.mean[strcspn(p.mean, "\n")] = 0;

    return p;
}

void Insert(){
    palavra palav = GetInputValue();

    int hash = Hash_String(palav.word);
    int indice = MakeHashCode(hash);

    while( strcmp(hash_table[indice].word, "") != 0 ){
        indice = Collision_Handler(indice);
    }
    hash_table[indice] = palav;
    mens('s');
}

void PrintHash(){
    printf("\n%15s\n", "Conteúdo do dicionário: ");
    
    for(int i = 0; i < size_hash; i++){
        printf("# %s\n", hash_table[i].word);
        printf("-> %s\n", hash_table[i].mean);
    }
    printf("------------------------------\n");
}

void Search(){
    char chave[size_word] = "";

    printf("# Pesquise pela palavra: \n>> ");
    fgets(chave, size_word, stdin);
    chave[strcspn(chave, "\n")] = 0;

    int hash = Hash_String(chave);
    int indice = MakeHashCode(hash);

    while( strcmp(hash_table[indice].word, "") != 0 ){
        if (  strcmp(hash_table[indice].word, chave) == 0 ){
            printf("\n>> RESULTADO OBTIDO:\n\n");
            printf("# %s\n", hash_table[indice].word);
            printf("-> %s\n", hash_table[indice].mean);
            printf("------------------------------\n");
            return;
        }else{
            indice = Collision_Handler(indice);
        }
    }
    mens('e');
}

void Remove(){
    char chave[size_word] = "";

    printf("# Pesquise pela palavra: \n>> ");
    fgets(chave, size_word, stdin);
    chave[strcspn(chave, "\n")] = 0;

    int hash = Hash_String(chave);
    int indice = MakeHashCode(hash);

    while( strcmp(hash_table[indice].word, "") != 0 ){
        if ( strcmp(hash_table[indice].word, chave) == 0 ){
            strcpy(hash_table[indice].word, "");
            strcpy(hash_table[indice].mean, "");
            mens('s');
            return;
        }else{
            indice = Collision_Handler(indice);
        }
    }
    mens('e');
}