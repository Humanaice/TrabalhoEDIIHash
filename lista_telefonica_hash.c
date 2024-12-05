#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include <time.h>

#define TABLE_SIZE 100
#define NAME_SIZE 50
#define PHONE_SIZE 15

typedef struct PhoneNode
{
    char phone[PHONE_SIZE];
    struct PhoneNode *next;
} PhoneNode;

typedef struct ContactNode
{
    char name[NAME_SIZE];
    PhoneNode *phones;
    struct ContactNode *next;
} ContactNode;

typedef struct
{
    ContactNode *buckets[TABLE_SIZE];
} ContactTable;

unsigned int hash(char *name)
{
    unsigned int hash = 0;
    while (*name)
    {
        hash = (hash << 5) + *name++;
    }
    return hash % TABLE_SIZE;
}

ContactTable *createTable()
{
    ContactTable *table = (ContactTable *)malloc(sizeof(ContactTable));
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        table->buckets[i] = NULL;
    }
    return table;
}

void criarPhone(ContactNode *contact, char *phone)
{
    PhoneNode *newPhone = (PhoneNode *)malloc(sizeof(PhoneNode));
    strcpy(newPhone->phone, phone);
    newPhone->next = contact->phones;
    contact->phones = newPhone;
}

void adicionarContato(ContactTable *table, char *name, char *phone)
{
    clock_t start = clock();

    unsigned int index = hash(name);
    ContactNode *current = table->buckets[index];
    while (current)
    {
        if (strcmp(current->name, name) == 0)
        {
            criarPhone(current, phone);
            clock_t end = clock();
            double time_spent = (double)(end - start) / CLOCKS_PER_SEC * 1000;
            printf("Telefone adicionado ao contato existente: %s - %s (Tempo: %f ms)\n", name, phone, time_spent);
            return;
        }
        current = current->next;
    }

    ContactNode *newNode = (ContactNode *)malloc(sizeof(ContactNode));
    strcpy(newNode->name, name);
    newNode->phones = NULL;
    criarPhone(newNode, phone);
    newNode->next = table->buckets[index];
    table->buckets[index] = newNode;

    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC * 1000;
    printf("Contato adicionado: %s - %s (Tempo: %f ms)\n", name, phone, time_spent);
}

void buscarContato(ContactTable *table, char *name)
{
    clock_t start = clock();

    unsigned int index = hash(name);
    ContactNode *current = table->buckets[index];
    while (current)
    {
        if (strcmp(current->name, name) == 0)
        {
            clock_t end = clock();
            double time_spent = (double)(end - start) / CLOCKS_PER_SEC * 1000;
            printf("Contato encontrado: %s (Tempo: %f ms)\n", current->name, time_spent);
            PhoneNode *phone = current->phones;
            while (phone)
            {
                printf("Telefone: %s\n", phone->phone);
                phone = phone->next;
            }
            return;
        }
        current = current->next;
    }

    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC * 1000;
    printf("Contato nao encontrado. (Tempo: %f ms)\n", time_spent);
}

void removerContato(ContactTable *table, char *name)
{
    unsigned int index = hash(name);
    ContactNode *current = table->buckets[index];
    ContactNode *previous = NULL;
    while (current)
    {
        if (strcmp(current->name, name) == 0)
        {
            if (previous)
            {
                previous->next = current->next;
            }
            else
            {
                table->buckets[index] = current->next;
            }
            PhoneNode *phone = current->phones;
            while (phone)
            {
                PhoneNode *temp = phone;
                phone = phone->next;
                free(temp);
            }
            free(current);
            printf("Contato removido: %s\n", name);
            return;
        }
        previous = current;
        current = current->next;
    }
    printf("Contato nao encontrado.\n");
}

void exibirContatos(ContactTable *table)
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        ContactNode *current = table->buckets[i];
        while (current)
        {
            printf("Contato: %s\n", current->name);
            PhoneNode *phone = current->phones;
            while (phone)
            {
                printf("Telefone: %s\n", phone->phone);
                phone = phone->next;
            }
            current = current->next;
        }
    }
}

int main()
{
    ContactTable *table = createTable();
    int opcao;
    char name[NAME_SIZE];
    char phone[PHONE_SIZE];

    do
    {
        printf("\nEscolha uma opcao:\n");
        printf("1 - Adicionar contato\n");
        printf("2 - Buscar contato por nome\n");
        printf("3 - Remover contato\n");
        printf("4 - Exibir todos os contatos\n");
        printf("0 - Sair\n");
        printf("Digite uma opcao: ");

        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("Digite o nome: ");
            scanf("%s", name);
            printf("Digite o telefone: ");
            scanf("%s", phone);
            adicionarContato(table, name, phone);
            break;
        case 2:
            printf("Digite o nome: ");
            scanf("%s", name);
            buscarContato(table, name);
            break;
        case 3:
            printf("Digite o nome: ");
            scanf("%s", name);
            removerContato(table, name);
            break;
        case 4:
            exibirContatos(table);
            break;
        case 0:
            printf("Saindo...\n");
            break;
        default:
            printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}
