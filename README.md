# Dicionário com Hash

Esse repositório refere-se ao trabalho da disciplina de Estrutura de Dados II. O projeto é destinado a desenvolver um dicionário utilizando a estrutura de dados hash, com funcionalidades para cadastrar, remover, exibir palavras e seus significados, armazenando os dados em arquivo texto.

---
## 👨‍👧‍👧 Autores

👨‍🏫 **Professor:** Kennedy Reurison Lopes

👩‍🎓 **Discentes:**  
🔹 [Izadora Louyza Silva Figueiredo](https://github.com/liyuhi)  
🔹 [Lívian Maria Lucena Gomes Pinheiro](https://github.com/livianlucena)   
🔹 [Victor Hugo de Oliveira](https://github.com/Victor350br)

---

## 1. Funcionalidades

| Funcionalidade | Características                                                                                           |
|----------------|----------------------------------------------------------------------------------------------------------|
| Cadastrar      | Permite adicionar uma nova palavra e seu significado ao dicionário, salvando os dados em arquivo texto. |
| Remover        | (Em desenvolvimento) Permite remover uma palavra do dicionário.                                         |
| Exibir         | Exibe todas as palavras e significados cadastrados, lendo os dados do arquivo texto.                     |
| Sair           | Encerra a execução do programa.                                                                          |

---

## 2. Como o sistema funciona?

O usuário interage via menu no terminal, podendo escolher entre as opções disponíveis (Cadastrar, Remover, Exibir, Sair). As palavras e significados cadastrados são armazenados em um arquivo texto chamado `Texto.txt`, permitindo persistência dos dados entre execuções.

---

### 2.1 Exemplo de Fluxo de Uso

---
=======
## 💡 Funcionalidades

| Funcionalidade | Características                                                                                         |
|----------------|--------------------------------------------------------------------------------------------------------|
| Cadastrar      | Adiciona uma nova palavra ao dicionário eletrônico.                                                    |
|                | *(Atualmente, a função `cadastro()` está implementada apenas como placeholder com impressão na tela.)* |
| Remover        | Remove uma palavra do dicionário.                                                                      |
|                | *(A função `remover()` ainda está em desenvolvimento.) *                                              |
| Exibir         | Mostra todas as palavras cadastradas.                                                                 |
|                | *(A função `exibir()` ainda será implementada com a estrutura de dados adequada.)*                     |
| Sair           | Encerra a execução do programa.                                                                        |


### 2.2 Estrutura de pastas
```
DicionarioComHash/
├── dicionariohash/ # Pasta com o código-fonte principal
│ └── main.c # Código do dicionário com funções de cadastro, remoção e exibição
├── README.md # Documentação inicial do projeto
```

### 2.3 Funcionamento do sistema


### 3. Como compilar e executar o sistema

Para compilar e executar o sistema, siga os passos abaixo:

1. Primeiramente, certifique-se de ter um ambiente que suporte a linguagem C e um compilador (por exemplo, GCC).
   
2. Clone o repositório do projeto:

```
git clone https://github.com/liyuhi/DicionarioComHash
```

3. Acesse a pasta do projeto e siga até o diretório onde os códigos estão alocados:
   
```
cd DicionarioComHash
```
```
cd dicionariohash
```

4. Compile o programa:

```
gcc -o dicionario main.c 
```

5. Execute o programa:
   
```
.\dicionario
```

