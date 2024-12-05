# Tabela Hash - Professor Lucas

# Exercício: Implementação de Lista Telefônica com Hash Table

## Descrição

Você deverá implementar uma aplicação em C ou C++ que funcione como uma lista telefônica. A aplicação deverá utilizar uma tabela hash para armazenar pares de dados (nome e número de telefone) em memória, possibilitando uma busca rápida pelo número de telefone associado a um nome específico.

## Objetivo

Praticar o uso de tabelas hash para resolver problemas de indexação e busca eficiente. O aluno deve compreender e implementar uma estratégia de hash, bem como lidar com colisões.

## Requisitos

1. **Estrutura de Dados (Tabela Hash)**

   - A lista telefônica deve ser implementada usando uma tabela hash. Utilize uma função hash para associar cada nome a um índice na tabela.
   - Lide com colisões de dados, utilizando a técnica de _encadeamento_ (listas ligadas) ou _endereçamento aberto_ (linear probing, quadratic probing, etc.), conforme sua escolha.

2. **Armazenamento em Memória**

   - O programa deve armazenar todos os dados em memória, sem uso de banco de dados ou arquivos externos.

3. **Funcionalidades da Lista Telefônica**

   - **Adicionar novo contato:** Permitir que o usuário insira um nome e um número de telefone para adicioná-los à tabela hash.
   - **Buscar contato:** Através de um nome fornecido pelo usuário, buscar o número de telefone correspondente e exibir na tela.
   - **Remover contato:** Permitir que o usuário remova um contato, se ele existir na lista.
   - **Mostrar todos os contatos:** Exibir todos os contatos armazenados na tabela hash (nome e número).

4. **Interface do Usuário**

   - O programa deve ter uma interface simples de console, onde o usuário pode escolher as opções:
     - `1` - Adicionar contato
     - `2` - Buscar contato por nome
     - `3` - Remover contato
     - `4` - Exibir todos os contatos
     - `0` - Sair

5. **Medição de Desempenho**

   - Calcule e exiba o tempo médio de busca e inserção de um contato (em milissegundos). Isso permitirá aos alunos compreenderem a eficiência da tabela hash em operações de busca e inserção.

6. **Tratamento de Erros**
   - Caso o usuário tente buscar ou remover um contato que não existe, exibir uma mensagem de erro apropriada.
   - Caso de duplicidade de nomes (se desejado, permita a inserção de múltiplos números para um mesmo nome ou apenas um).

## Exemplo de Execução

```plaintext
Escolha uma opção:
1 - Adicionar contato
2 - Buscar contato por nome
3 - Remover contato
4 - Exibir todos os contatos
0 - Sair

Digite uma opção: 1
Nome: Maria
Telefone: 12345
Contato adicionado com sucesso.

Digite uma opção: 2
Nome: Maria
Telefone de Maria: 12345 (tempo de busca: 0.02 ms)
```

## Sugestões Adicionais

- Para a função hash, você pode utilizar uma função simples, como a soma dos valores ASCII dos caracteres do nome, ou, para um desafio extra, uma função hash mais eficiente (por exemplo, a função `std::hash` em C++).
- Teste o programa com diferentes tamanhos de tabela para observar o impacto de colisões e performance de busca.
