# Dicionário com Hash

Este repositório refere-se ao trabalho da disciplina de Estrutura de Dados II. O projeto consiste em desenvolver um dicionário digital onde o usuário pode cadastrar palavras e seus significados, buscar e remover termos. Nesta quarta versão, foi implementada uma estrutura de dados baseada em lista encadeada, com suporte para múltiplos significados por palavra, além da funcionalidade de salvar e carregar o dicionário de um arquivo texto, garantindo persistência entre execuções. Ainda está prevista a implementação da tabela hash para otimização da busca e remoção.

---
## 👨‍👧‍👧 Autores

👨‍🏫 **Professor:** Kennedy Reurison Lopes

👩‍🎓 **Discentes:**  
🔹 [Izadora Louyza Silva Figueiredo](https://github.com/liyuhi)  
🔹 [Lívian Maria Lucena Gomes Pinheiro](https://github.com/livianlucena)   
🔹 [Victor Hugo de Oliveira](https://github.com/Victor350br)

---

## 1. Funcionalidades

| Funcionalidade | Descrição                                                                                                     |
|----------------|--------------------------------------------------------------------------------------------------------------|
| Cadastrar      | Permite adicionar uma nova palavra e seus múltiplos significados ao dicionário, armazenando na lista encadeada.|
| Remover        | Remove uma palavra da lista encadeada, com confirmação do usuário, atualizando a estrutura em memória.       |
| Exibir         | Exibe todas as palavras e seus significados armazenados na lista e lê o conteúdo do arquivo texto.            |
| Atualizar      | Permite modificar a palavra ou o(s) significado(s) de um termo já cadastrado.                                 |
| Salvar         | Salva os dados do dicionário no arquivo texto para persistência entre execuções.                             |
| Carregar       | Carrega os dados do arquivo texto para a lista encadeada ao iniciar o programa.                              |
| Sair           | Salva os dados no arquivo texto e encerra o programa.                                                       |

---

## 2. Funcionamento do Sistema

O usuário interage através de um menu no terminal, escolhendo entre as opções disponíveis (Cadastrar, Remover, Exibir, Atualizar, Sair).  

- As palavras e significados são armazenados temporariamente em uma lista encadeada durante a execução.  
- Ao iniciar, o programa carrega os dados do arquivo `texto.txt` para a lista.  
- Ao sair, os dados são salvos no arquivo `texto.txt` para persistência.  
- A estrutura ainda pode ser otimizada futuramente com tabela hash.

---

### 2.1 Exemplo de Fluxo de Uso

- O usuário inicia o programa, que carrega os dados salvos.  
- O usuário escolhe cadastrar uma palavra nova com seus significados.  
- O usuário pode buscar, remover ou atualizar palavras existentes.  
- Ao finalizar, o usuário sai e o programa salva todas as alterações no arquivo.

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

O sistema de Dicionário Digital permite que o usuário realize as seguintes ações:

```
=========================== DICIONÁRIO DIGITAL ===========================

(1) Cadastrar  
(2) Remover  
(3) Exibir  
(4) Atualizar  
(5) Sair  

<< Informe a opção:

```

#### Menu principal do sistema:

- **Cadastrar**: o sistema permite cadastrar uma nova palavra e seus significados no dicionário, armazenando-os na lista encadeada.  
- **Remover**: o sistema permite remover uma palavra existente, solicitando confirmação antes da exclusão.  
- **Exibir**: o sistema exibe todas as palavras e seus significados atualmente armazenados na lista e no arquivo texto.  
- **Atualizar**: o sistema permite modificar uma palavra ou seus significados já cadastrados.  
- **Sair**: o sistema salva todos os dados da lista no arquivo texto para garantir persistência e encerra a execução do programa.


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

