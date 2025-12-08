<p align="center">
  <img src="https://capsule-render.vercel.app/api?type=waving&color=32CD32&height=200&section=header&text=Dicion%C3%A1rio%20Hash&fontSize=40&fontColor=ffffff" />
</p>

Repositório do projeto desenvolvido ao longo da 2ª e 3ª unidades da disciplina **Laboratório de Algoritmos e Estruturas de Dados II (PEX1247)**. Este sistema simula um **dicionário digital**, permitindo ao usuário **cadastrar, buscar, remover** e **exibir palavras e seus significados**, utilizando uma **tabela hash com tratamento de colisões** e **persistência em arquivo**.

![Linguagem](https://img.shields.io/badge/Linguagem-C-blue)
![Ambiente](https://img.shields.io/badge/Ambientes-VSCode_&_LaTeX-blue)
![Último commit](https://img.shields.io/github/last-commit/izalouyza/DicionarioComHash)

---

## Funcionalidades Principais do Projeto

- Cálculo de hash por soma de códigos ASCII (**Hash_String**).
- Tratamento de colisões com **sondagem linear** e aviso visual.
- Persistência de dados em arquivo `dicionario.txt`, com **carregamento automático na inicialização** e salvamento ao sair.
- Operações completas: **cadastrar**, **buscar**, **remover** e **exibir** palavras.
- Interface amigável com mensagens claras sobre erros, sucesso, colisões e elementos não encontrados.
- Inicialização segura da tabela para evitar dados inconsistentes.
- Leitura de entrada com tratamento de buffer.

---

## 👥 Autores

👨‍🏫 **Professor:** [Kennedy Reurison Lopes](https://github.com/kennedyufersa)

👩‍🎓 **Discentes:**  
🔹 [Izadora Louyza Silva Figueiredo](https://github.com/izalouyza) — *GitMaster*  
🔹 [Lívian Maria Lucena Gomes Pinheiro](https://github.com/livianlucena) — *Redatora*  
🔹 [Victor Hugo de Oliveira](https://github.com/Victor350br) — *Codificador e Apresentador*

---

## Aprendizados Adquiridos

Este projeto permitiu a aplicação prática de conceitos como:
- Estruturas de dados (tabelas hash e vetores).
- Manipulação de arquivos em C.
- Tratamento de colisões.

---

## Problemas Encontrados

Durante o desenvolvimento do projeto, enfrentamos os seguintes desafios:

- **Implementação da Tabela Hash:** ajustes no cálculo do hash e no tratamento de colisões com sondagem linear para evitar sobrescritas e loops infinitos.
- **Múltiplos Significados:** reestruturação dos dados para suportar mais de um significado por palavra, exigindo alterações nas funções de cadastro, busca e exibição.
- **Persistência em Arquivo:** dificuldades em criar um formato de leitura/escrita confiável e compatível com as estruturas em memória.
- **Leitura de Strings:** problemas com `scanf` e `fgets`, exigindo cuidados com o buffer e leitura de entradas com espaços.
- **Testes e Manutenção:** necessidade de testar todos os fluxos (inclusive com colisões e remoções) e garantir que o sistema permanecesse funcional a cada alteração.

Todos os problemas foram resolvidos com testes, ajustes na lógica e colaboração em equipe.

---

## Funcionalidades do Sistema

| Função     | Descrição                                                                                         |
|-------------|---------------------------------------------------------------------------------------------------|
| Cadastrar   | Adiciona uma nova palavra e seu significado.            |
| Exibir      | Mostra todas as palavras e significados armazenados.                                             |
| Buscar      | Localiza uma palavra e exibe seu significado, se a palavra estiver cadastrada.                               |
| Remover     | Exclui uma palavra do dicionário.                                                |
| Sair        | Salva automaticamente os dados no arquivo `dicionario.txt` e finaliza o programa.                     |

---

## Funcionamento do Sistema

O usuário interage com o sistema via menu no terminal:

```text
=========================== DICIONÁRIO DIGITAL ===========================

(1) Cadastrar
(2) Exibir
(3) Buscar
(4) Remover
(5) Sair

<< Informe a opção:
```
#### Menu Principal do Sistema:

- **Cadastrar**: inserir uma palavra e seu significado.  
- **Exibir**: listar todas as palavras cadastradas e seus significados.  
- **Buscar**: procurar uma palavra pelo nome e exibir seu significado.  
- **Remover**: excluir uma palavra do dicionário.  
- **Sair**: salva os dados e finaliza o programa.
---

## Estrutura de Pastas

```bash
DicionarioComHash/
src/
├── dicionariohash/
│   └── main.c
├── documentacao/
│   ├── Apresentacao_DicionariocomHash.pdf
│   └── Relatorio_Dicionario_com_Hash.pdf
└── README.md
```
- `dicionariohash/`: pasta que contém o código-fonte do sistema.
- `documentacao/`:  pasta com os documentos do projeto.
- `main.c`: arquivo principal com toda a lógica do programa.
- `Apresentacao_DicionariocomHash.pdf`: apresentação do projeto em formato PDF.
- `Relatorio_Dicionario_com_Hash.pdf`: relatório técnico do projeto em formato PDF.
- `README.md`: documento com informações gerais sobre o projeto.
---

## Como Compilar e Executar

1. Certifique-se de ter um compilador C instalado (ex: GCC).

2. Clone este repositório:

```bash
git clone https://github.com/izalouyza/DicionarioComHash
```

3. Acesse a pasta do projeto:

```bash
cd DicionarioComHash/dicionariohash
```

4. Compile o código:

```bash
gcc -o dicionario main.c
```

5. Execute o programa:

```bash
.\dicionario 
```
---

