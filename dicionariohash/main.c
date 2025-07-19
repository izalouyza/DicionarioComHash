#include <stdio.h>
#include <locale.h>

#define mens "\n>> Erro, tente novamente.\n\n"

void cadastro(){ printf("Cadastrar\n"); }
void remover() { printf("Remover\n");   }
void exibir()  { printf("Exibir\n");    }

int main(){
    setlocale(LC_ALL, "");
    int opc = 0;
    printf("\n========== DICIONÁRIO ELETRÔNICO ==========\n\n");
    while(1){
        printf("[1] Cadastrar\n[2] Remover \n[3] Exibir \n[4] Sair\n>> ");
        while (scanf("%d", &opc) != 1){ printf("%s", mens); setbuf(stdin, NULL); }
        switch (opc){
            case 1:              cadastro();    break;
            case 2:               remover();    break;
            case 3:                exibir();    break;
            case 4:                return 0;    break;
            default:     printf("%s", mens);    break;
        }
        setbuf(stdin, NULL);
    }
}