#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define succ "\n>> Operação realizada com sucesso.\n\n"
#define fail "\n>> Algo deu errado, tente novamente.\n\n"
#define empt "\n>> Nenhum item encontrado no momento.\n\n"

#define size_strg 50
#define size_sign 100
#define size_hash 19

typedef struct palavra{
    char name[size_strg];
    char mean[size_sign];
} palavra;

palavra hash_table[size_hash];

void mens(char par[]);
void Load();
int MakeHashCode(int chave);
palavra GetWords();
void Insert();
void PrintHash();
void Search();

int main(){
    setlocale(LC_ALL, "");
    Load();
    int opc = 0;

    while(opc != 4){
        printf("\n================ DICIONARIO DIGITAL ================\n");
        printf("[1] Cadastrar\n[2] Exibir \n[3] Buscar \n[4] Sair \n>> ");
        
        while(scanf("%d", &opc) != 1) {mens("fail"); setbuf(stdin, NULL);}
        setbuf(stdin, NULL);
        switch (opc){
            case 1:         Insert();      break;
            case 2:      PrintHash();      break;
            case 3:         Search();      break;
            default:    mens("fail");      break;
        }
    }
    return 0;
}

void mens(char par[]){
          if( strcmp(par, "succ") == 0 ){
        printf("%s", succ);
    }else if( strcmp(par, "fail") == 0 ){
        printf("%s", fail);
    }else if( strcmp(par, "empt") == 0 ){
        printf("%s", empt);
    }
}

void Load(){
    int i = 0;
    for(i = 0; i < size_hash; i++){
        strcpy(hash_table[i].name, "");
    }
}

int MakeHashCode(int chave){
    return (chave % size_hash);
}

palavra GetWords(){
    palavra p;

    printf("# Digite uma palavra: \n>> ");
    fgets(p.name, size_strg, stdin);
    p.name[strcspn(p.name, "\n")] = 0;

    printf("# Digite o significado: \n>> ");
    fgets(p.mean, size_strg, stdin);
    p.mean[strcspn(p.mean, "\n")] = 0;

    return p;
}

void Insert(){
    palavra palav = GetWords();
    int indice = MakeHashCode(palav.name[0]);

    while( strcmp(hash_table[indice].name, "") != 0 ){
        indice = MakeHashCode(indice + 1);
    }
    hash_table[indice] = palav;
    mens("succ");
}

void PrintHash(){
    printf("\n%15s\n", "Tabela Hash");
    
    for(int i = 0; i < size_hash; i++){
        if (hash_table[i].name){
            printf("# %s\n", hash_table[i].name);
            printf("-> %s\n", hash_table[i].mean);
        }
    }
    printf("\n------------------------------\n");
} //char letra = 'a'; /&& hash_table[i].name[0] == letra/

void Search(){
    char chave[size_strg] = "";

    printf("# Pesquise pela palavra: \n>> ");
    fgets(chave, size_strg, stdin);
    chave[strcspn(chave, "\n")] = 0;

    int indice = MakeHashCode(chave[0]);

    while( strcmp(hash_table[indice].name, "") != 0 ){
        if (  strcmp(hash_table[indice].name, chave) == 0 ){
            printf("\n>> RESULTADO OBTIDO:\n\n");
            printf("# %s\n", hash_table[indice].name);
            printf("-> %s\n", hash_table[indice].mean);
            printf("------------------------------\n");
            return;
        }else{
            indice = MakeHashCode(indice+1);
        }
    }
    mens("empt");
}