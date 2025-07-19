# Dicionário com Hash

Este repositório refere-se ao trabalho da disciplina de Estrutura de Dados II. O projeto consiste em desenvolver um dicionário digital onde o usuário pode cadastrar palavras e seus significados, buscar e remover termos.  

Nesta **quinta versão**, o sistema foi aprimorado com:
- Suporte mais robusto a **múltiplos significados** por palavra, com uso de listas encadeadas dentro da estrutura de cada entrada.
- Implementação completa da **persistência de dados**, com carregamento do dicionário a partir de um arquivo texto na inicialização e salvamento automático ao final.
- Estrutura modular para futura aplicação de uma **tabela hash** para otimizar buscas e remoções.

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
| Cadastrar      | Adiciona uma nova palavra ao dicionário, permitindo múltiplos significados por palavra.                      |
| Remover        | Remove uma palavra do dicionário com confirmação do usuário.                                                 |
| Exibir         | Exibe todas as palavras cadastradas e seus significados.                                                     |
| Atualizar      | Permite acrescentar novos significados a uma palavra já existente.                                           |
| Buscar         | (A ser implementado) Permitirá procurar palavras usando tabela hash.                                         |
| Salvar         | Salva o conteúdo do dicionário em arquivo texto (`Texto.txt`).                                               |
| Carregar       | Carrega o conteúdo salvo do arquivo texto ao iniciar o programa.                                             |
| Sair           | Salva automaticamente os dados e encerra a execução do programa.                                             |

---

## 2. Funcionamento do Sistema

O usuário interage através de um menu no terminal com as seguintes opções:

- **Cadastrar**: adiciona uma nova palavra e um significado associado.
- **Atualizar**: permite adicionar novos significados a uma palavra já existente.
- **Remover**: exclui completamente uma palavra do dicionário.
- **Exibir**: mostra o conteúdo atual da estrutura em memória.
- **Sair**: salva os dados no arquivo e encerra o programa.

---

### 2.1 Exemplo de Fluxo de Uso

- O usuário inicia o programa, que automaticamente carrega os dados salvos.
- O usuário pode cadastrar uma nova palavra com seus significados.
- Também é possível remover palavras, exibir todas as registradas ou adicionar significados adicionais.
- Ao sair, o programa salva todas as alterações no arquivo `texto.txt`.

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
(5) Buscar
(6) Sair 

<< Informe a opção:

```

#### Menu principal do sistema:

- **Cadastrar**: o sistema permite cadastrar uma nova palavra e seus significados no dicionário, armazenando-os na lista encadeada.  
- **Remover**: o sistema permite remover uma palavra existente, solicitando confirmação antes da exclusão.  
- **Exibir**: o sistema exibe todas as palavras e seus significados atualmente armazenados na lista e no arquivo texto.  
- **Atualizar**: o sistema permite adicionar mais significados a uma palavra já existente.  
- **Buscar**: *(em desenvolvimento)* — a função permitirá localizar rapidamente uma palavra, otimizando o acesso com estrutura de hash.  
- **Sair**: o sistema salva todos os dados da lista no arquivo texto para garantir persistência e encerra a execução do programa.
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

### 4. Próximos Passos

- Implementar a função **Buscar** utilizando **tabela hash**.
- Aplicar **função de espalhamento** (hash function) para distribuição eficiente das palavras.
- Melhorar o sistema de atualização para suporte a edição completa de significados e palavras.

---