# Dicionário com Hash

Este repositório refere-se ao trabalho da disciplina de Estrutura de Dados II. O projeto consiste em desenvolver um dicionário digital onde o usuário pode cadastrar palavras e seus significados, buscar e remover termos. Nesta terceira versão, é utilizada uma estrutura de dados lista encadeada para organizar os dados, com funcionalidades para salvar os dados em arquivo texto, garantindo persistência entre execuções.

---
## 👨‍👧‍👧 Autores

👨‍🏫 **Professor:** Kennedy Reurison Lopes

👩‍🎓 **Discentes:**  
🔹 [Izadora Louyza Silva Figueiredo](https://github.com/liyuhi)  
🔹 [Lívian Maria Lucena Gomes Pinheiro](https://github.com/livianlucena)   
🔹 [Victor Hugo de Oliveira](https://github.com/Victor350br)

---

## 1. Funcionalidades

| Funcionalidade | Descrição                                                                                               |
|---------------|--------------------------------------------------------------------------------------------------------|
| Cadastrar     | Permite adicionar uma nova palavra e seu significado ao dicionário, armazenando na lista encadeada.    |
| Remover       | Remove uma palavra da lista encadeada, com confirmação do usuário, e atualiza a estrutura em memória. |
| Exibir        | Exibe todas as palavras e significados armazenados na lista e lê o conteúdo do arquivo texto.          |
| Sair          | Salva os dados no arquivo texto e encerra o programa.                                                 |

---

## 2. Funcionamento do Sistema

O usuário interage através de um menu no terminal, escolhendo entre as opções disponíveis (Cadastrar, Remover, Exibir, Sair).  

- As palavras e significados são armazenados temporariamente em uma lista encadeada durante a execução.  
- Ao sair, os dados da lista são salvos no arquivo `texto.txt` para persistência entre execuções.  
- A exibição pode mostrar o conteúdo tanto da lista em memória quanto do arquivo texto.  

---


### 2.1 Exemplo de Fluxo de Uso

---

### 2.2 Estrutura de pastas
```
DicionarioComHash/
├── dicionariohash/ # Código-fonte principal
│ └── main.c # Código do dicionário com lista encadeada
├── texto.txt # Arquivo texto onde os dados são salvos
├── README.md # Documentação do projeto

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

