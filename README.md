# Dicionário com Hash

Este repositório refere-se ao trabalho da disciplina de Estrutura de Dados II. O projeto consiste em desenvolver um dicionário digital onde o usuário pode cadastrar palavras e seus significados, buscar e remover termos.

Nesta **sexta versão**, o sistema apresenta:

- Implementação básica de **tabela hash** para armazenamento das palavras, usando sondagem linear para tratamento de colisões.
- Menu funcional para **cadastrar**, **exibir** e **buscar** palavras no dicionário.
- Estrutura simplificada onde cada palavra possui um único significado.
- Inicialização da tabela com valores vazios para evitar dados inconsistentes.
- Tratamento de entrada de dados com limpeza do buffer para evitar erros na leitura.
- Preparação para futuras melhorias, como suporte a múltiplos significados e persistência em arquivo.


---
## 👨‍👧‍👧 Autores

👨‍🏫 **Professor:** Kennedy Reurison Lopes

👩‍🎓 **Discentes:**  
🔹 [Izadora Louyza Silva Figueiredo](https://github.com/liyuhi)  
🔹 [Lívian Maria Lucena Gomes Pinheiro](https://github.com/livianlucena)   
🔹 [Victor Hugo de Oliveira](https://github.com/Victor350br)

---

## 1. Funcionalidades

| Funcionalidade | Descrição                                                                            |
|----------------|-------------------------------------------------------------------------------------|
| Cadastrar      | Adiciona uma nova palavra e seu significado na tabela hash, com tratamento de colisão.|
| Exibir         | Exibe todas as palavras e significados armazenados na tabela hash.                   |
| Buscar         | Pesquisa por uma palavra na tabela hash, exibindo seu significado, se encontrada.    |
| Sair           | Encerra o programa. (Ainda sem salvar em arquivo nesta versão)                      |

---

## 2. Funcionamento do Sistema

O usuário interage com o sistema via menu no terminal:

- **Cadastrar**: inserir uma palavra e seu significado.
- **Exibir**: listar todas as palavras cadastradas e seus significados.
- **Buscar**: procurar uma palavra pelo nome e exibir seu significado.
- **Sair**: finaliza o programa.

---

### 2.1 Exemplo de Fluxo de Uso

### 2.1 Exemplo de fluxo de uso

- O usuário inicia o programa e recebe o menu.
- Pode cadastrar novas palavras com significado.
- Exibir o conteúdo da tabela hash a qualquer momento.
- Buscar uma palavra específica.
- Sair do programa.

---

### 2.2 Estrutura de pastas
```
DicionarioComHash/
├── dicionariohash/ # Código-fonte principal
│ └── main.c # Código da sexta versão com hash simples
├── README.md # Documentação atualizada do projeto

```

### 2.3 Funcionamento do sistema

O sistema de Dicionário Digital permite que o usuário realize as seguintes ações:

```
=========================== DICIONÁRIO DIGITAL ===========================

(1) Cadastrar
(2) Exibir
(3) Buscar
(4) Sair

<< Informe a opção:

```

#### Menu principal do sistema:

- **Cadastrar**: inserir uma palavra e seu significado.  
- **Exibir**: listar todas as palavras cadastradas e seus significados.  
- **Buscar**: procurar uma palavra pelo nome e exibir seu significado.  
- **Sair**: finaliza o programa.
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

- Implementar suporte a **múltiplos significados** por palavra.
- Adicionar persistência de dados com leitura e gravação em arquivo.
- Melhorar a função de hash para distribuir melhor as palavras.
- Tratar casos de tabela cheia e evitar loops infinitos na inserção e busca.
- Implementar remoção e atualização de palavras/significados.
- Melhorar a interface do usuário e validações.

---