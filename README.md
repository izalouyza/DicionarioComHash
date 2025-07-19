# Dicionário com Hash

Este repositório refere-se ao trabalho da disciplina de **Laboratório de Algoritmos e Estruturas de Dados II (PEX1247)**. O projeto consiste em desenvolver um dicionário digital onde o usuário pode cadastrar palavras e seus significados, buscar e remover termos.

O sistema de dicionário digital apresenta:

- Função **Hash_String** que calcula o hash pela soma dos códigos ASCII dos caracteres da palavra.
- Implementação de **tratamento de colisões** com sondagem linear e aviso de colisão.
- Persistência completa dos dados em arquivo texto (`texto.txt`), com carregamento na inicialização e salvamento ao sair.
- Funcionalidades completas para **cadastrar**, **exibir**, **buscar** e **remover** palavras.
- Interface amigável com mensagens específicas para sucesso, erro, colisão e item não encontrado.
- Estrutura simplificada, onde cada palavra possui um único significado.
- Inicialização da tabela com valores vazios para evitar dados inconsistentes.
- Tratamento adequado de entrada de dados e limpeza do buffer para evitar erros na leitura.

---
## 👨‍👧‍👧 Autores

👨‍🏫 **Professor:** Kennedy Reurison Lopes

👩‍🎓 **Discentes:**  
🔹 [Izadora Louyza Silva Figueiredo](https://github.com/liyuhi) — *GitMaster*  
🔹 [Lívian Maria Lucena Gomes Pinheiro](https://github.com/livianlucena) — *Redatora e Apresentadora*  
🔹 [Victor Hugo de Oliveira](https://github.com/Victor350br) — *Codificador e Apresentador*

---

## 1. Funcionalidades

| Funcionalidade | Descrição                                                                                  |
|----------------|-------------------------------------------------------------------------------------------|
| Cadastrar      | Adiciona uma nova palavra e seu significado na tabela hash, tratando colisões com sondagem linear. |
| Exibir         | Exibe todas as palavras e significados armazenados na tabela hash.                         |
| Buscar         | Pesquisa por uma palavra na tabela hash, exibindo seu significado, se encontrada.          |
| Remover        | Remove uma palavra do dicionário, liberando a posição na tabela hash.                      |
| Sair           | Salva o conteúdo do dicionário em arquivo texto (`texto.txt`) e encerra o programa.       |

---

## 2. Funcionamento do Sistema

O usuário interage com o sistema via menu no terminal:

- **Cadastrar**: inserir uma palavra e seu significado.  
- **Exibir**: listar todas as palavras cadastradas e seus significados.  
- **Buscar**: procurar uma palavra pelo nome e exibir seu significado.  
- **Remover**: excluir uma palavra do dicionário.  
- **Sair**: salva os dados em arquivo e finaliza o programa.

---

### 2.1 Exemplo de fluxo de uso

- O usuário inicia o programa e os dados salvos são carregados automaticamente.  
- Pode cadastrar novas palavras com significado.  
- Exibir o conteúdo da tabela hash a qualquer momento.  
- Buscar uma palavra específica.  
- Remover palavras do dicionário.  
- Sair do programa com salvamento automático dos dados.

---

### 2.2 Estrutura de pastas
```
DicionarioComHash/
├── dicionariohash/ 
│ └── main.c 
└── README.md 

```
- **main.c**: código-fonte do projeto.

---
### 2.3 Funcionamento do sistema

O sistema de Dicionário Digital permite que o usuário realize as seguintes ações:

```
=========================== DICIONÁRIO DIGITAL ===========================

(1) Cadastrar
(2) Exibir
(3) Buscar
(4) Remover
(5) Sair

<< Informe a opção:

```

#### Menu principal do sistema:

- **Cadastrar**: inserir uma palavra e seu significado.  
- **Exibir**: listar todas as palavras cadastradas e seus significados.  
- **Buscar**: procurar uma palavra pelo nome e exibir seu significado.  
- **Remover**: excluir uma palavra do dicionário.  
- **Sair**: salva os dados e finaliza o programa.

---

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
---
