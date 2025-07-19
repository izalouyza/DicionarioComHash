#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define succ "\n>> Operação realizada com sucesso.\n\n"
#define fail "\n>> Algo deu errado, tente novamente.\n\n"
#define empt "\n>> Nenhum item encontrado no momento.\n\n"

#define size_word 50
#define size_mean 100
#define size_hash 19

typedef struct palavra{
    char word[size_word];
    char mean[size_mean];
} palavra;

palavra hash_table[size_hash];

void mens(char par);
void Save();
void Load();
int MakeHashCode(int chave);
palavra GetWords();
void Insert();
void PrintHash();
void Search();
void Remove();

int main(){
    setlocale(LC_ALL, "");
    Load();
    char opc = ' ';

    while(opc != '5'){
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
    }
    return 0;
}

int MakeHashCode(int chave){
    return (chave % size_hash);
}

void mens(char par){
    switch (par){
        case 's': printf("%s", succ); break;
        case 'f': printf("%s", fail); break;
        case 'e': printf("%s", empt); break;
    }
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
    if(!arquivo){
        mens('f');
        exit(1);
    }
    char linha[size_hash];
    int indice = 0;
    int par = 0;
    
    while( fgets(linha, size_mean, arquivo) != NULL ){
        if(par == 0){
            indice = MakeHashCode(linha[0]);
            while (strcmp(hash_table[indice].word, "") != 0 ){
                indice = MakeHashCode(indice+1);
            }
            linha[strcspn(linha, "\n")] = 0;
            strcpy(hash_table[indice].word, linha);
            par = 1;
        }else{
            linha[strcspn(linha, "\n")] = 0;
            strcpy(hash_table[indice].mean, linha);
            par = 0;
        }
    }
    fclose(arquivo);
}

palavra GetWords(){
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
    palavra palav = GetWords();
    int indice = MakeHashCode(palav.word[0]);

    while( strcmp(hash_table[indice].word, "") != 0 ){
        indice = MakeHashCode(indice + 1);
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
    printf("\n------------------------------\n");
} //char letra = 'a'; /&& hash_table[i].word[0] == letra/

void Search(){
    char chave[size_word] = "";

    printf("# Pesquise pela palavra: \n>> ");
    fgets(chave, size_word, stdin);
    chave[strcspn(chave, "\n")] = 0;

    int indice = MakeHashCode(chave[0]);

    while( strcmp(hash_table[indice].word, "") != 0 ){
        if (  strcmp(hash_table[indice].word, chave) == 0 ){
            printf("\n>> RESULTADO OBTIDO:\n\n");
            printf("# %s\n", hash_table[indice].word);
            printf("-> %s\n", hash_table[indice].mean);
            printf("------------------------------\n");
            return;
        }else{
            indice = MakeHashCode(indice+1);
        }
    }
    mens('e');
}

void Remove(){
    char chave[size_word] = "";
     printf("# Pesquise pela palavra: \n>> ");
    fgets(chave, size_word, stdin);
    chave[strcspn(chave, "\n")] = 0;

    int indice = MakeHashCode(chave[0]);

    while( strcmp(hash_table[indice].word, "") != 0 ){
        if ( strcmp(hash_table[indice].word, chave) == 0 ){
            strcpy(hash_table[indice].word, "");
            strcpy(hash_table[indice].mean, "");
            mens('s');
            return;
        }else{
            indice = MakeHashCode(indice+1);
        }
    }
}