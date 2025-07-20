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
int MakeHashCode(int chave);
palavra GetInputValue();
void Insert();
void PrintHash();
void Search();
void Remove();

int main(){
    setlocale(LC_ALL, "pt_BR.UTF-8"); // Configurar a localidade para português
    system("chcp 65001"); // Mudar a página de código para UTF-8

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

int Hash_String(const char *word){
    int hash = 0;
    for (int i = 0; word[i] != '\0'; i++)
        hash += (int)word[i];
    return hash;
}

palavra GetInputValue(){
    palavra p;
    printf("# Digite uma palavra: \n>> ");
    fgets(p.word, size_word, stdin);
    p.word[strcspn(p.word, "\n")] = 0;

    printf("# Digite o significado: \n>> ");
    fgets(p.mean, size_mean, stdin);
    p.mean[strcspn(p.mean, "\n")] = 0;

    return p;
}

void Insert(){
    palavra palav = GetInputValue();
    int hash = Hash_String(palav.word);
    int indice = MakeHashCode(hash);

    int tentativas = 0;
    while (tentativas < size_hash) {
        if (strcmp(hash_table[indice].word, "") == 0) {
            hash_table[indice] = palav;
            mens('s');
            return;
        } else {
            mens('c');
            indice = (indice + 1) % size_hash;
            tentativas++;
        }
    }
    mens('f'); // tabela cheia
}

void PrintHash(){
    printf("\n%15s\n", "Conteúdo do dicionário: ");
    for(int i = 0; i < size_hash; i++){
        if (strcmp(hash_table[i].word, "") != 0) {
            printf("# %s\n", hash_table[i].word);
            printf("-> %s\n", hash_table[i].mean);
        }
    }
    printf("------------------------------\n");
}

void Search(){
    char chave[size_word];
    printf("# Pesquise pela palavra: \n>> ");
    fgets(chave, size_word, stdin);
    chave[strcspn(chave, "\n")] = 0;

    int hash = Hash_String(chave);
    int indice = MakeHashCode(hash);

    int tentativas = 0;
    while (tentativas < size_hash) {
        if (strcmp(hash_table[indice].word, "") == 0) {
            break; // posição vazia = não encontrado
        }
        if (strcmp(hash_table[indice].word, chave) == 0) {
            printf("\n>> RESULTADO OBTIDO:\n\n");
            printf("# %s\n", hash_table[indice].word);
            printf("-> %s\n", hash_table[indice].mean);
            printf("------------------------------\n");
            return;
        }
        indice = (indice + 1) % size_hash;
        tentativas++;
    }
    mens('e');
}

void Remove(){
    char chave[size_word];
    printf("# Pesquise pela palavra: \n>> ");
    fgets(chave, size_word, stdin);
    chave[strcspn(chave, "\n")] = 0;

    int hash = Hash_String(chave);
    int indice = MakeHashCode(hash);

    int tentativas = 0;
    while (tentativas < size_hash) {
        if (strcmp(hash_table[indice].word, "") == 0) {
            break;
        }
        if (strcmp(hash_table[indice].word, chave) == 0) {
            strcpy(hash_table[indice].word, "");
            strcpy(hash_table[indice].mean, "");
            mens('s');
            return;
        }
        indice = (indice + 1) % size_hash;
        tentativas++;
    }
    mens('e');
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
        // Se o arquivo ainda não existir, considere isso OK.
        return;
    }

    char word[size_word];
    char mean[size_mean];

    while (fgets(word, size_word, arquivo) != NULL &&
           fgets(mean, size_mean, arquivo) != NULL) {
        word[strcspn(word, "\n")] = 0;
        mean[strcspn(mean, "\n")] = 0;

        int hash = Hash_String(word);
        int indice = MakeHashCode(hash);
        int tentativas = 0;

        while (tentativas < size_hash) {
            if (strcmp(hash_table[indice].word, "") == 0) {
                strcpy(hash_table[indice].word, word);
                strcpy(hash_table[indice].mean, mean);
                break;
            }
            indice = (indice + 1) % size_hash;
            tentativas++;
        }
    }
    fclose(arquivo);
}
