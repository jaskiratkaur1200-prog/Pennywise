#include <stdio.h>
#include <string.h>

struct Expense
{
    int id;
    char category[20];
    char description[50];
    float amount;
};

struct Expense e[100];

int count = 0;
int nextId = 1;


// FUNCTION 1: SEARCH EXPENSE

void searchExpense();

void searchExpense()
{
    int id, i;

    printf("\nEnter expense ID to search: ");
    scanf("%d", &id);

    for(i = 0; i < count; i++)
    {
        if(e[i].id == id)
        {
            printf("\nExpense Found!\n");
            printf("ID: %d\n", e[i].id);
            printf("Category: %s\n", e[i].category);
            printf("Description: %s\n", e[i].description);
            printf("Amount: Rs %.2f\n", e[i].amount);

            return;
        }
    }

    printf("Expense not found!\n");
}


// FUNCTION 2: EDIT EXPENSE

void editExpense();

void editExpense()
{
    int id, i;
    float amount;
    char description[50];

    printf("\nEnter expense ID to edit: ");
    scanf("%d", &id);

    for(i = 0; i < count; i++)
    {
        if(e[i].id == id)
        {
            printf("\nOld description: %s\n", e[i].description);

            printf("Enter new description: ");
            scanf(" %49[^\n]", description);

            printf("Old amount: Rs %.2f\n", e[i].amount);

            printf("Enter new amount: Rs ");
            scanf("%f", &amount);

            if(amount <= 0)
            {
                printf("Invalid amount!\n");
                return;
            }

            strcpy(e[i].description, description);
            e[i].amount = amount;

            printf("Expense updated successfully!\n");
            return;
        }
    }

    printf("Expense not found!\n");
}


// FUNCTION 3: DELETE EXPENSE

void deleteExpense();

void deleteExpense()
{
    int id, i;
    int position = -1;

    printf("\nEnter expense ID to delete: ");
    scanf("%d", &id);

    for(i = 0; i < count; i++)
    {
        if(e[i].id == id)
        {
            position = i;
            break;
        }
    }

    if(position == -1)
    {
        printf("Expense not found!\n");
        return;
    }

    for(i = position; i < count - 1; i++)
    {
        e[i] = e[i + 1];
    }

    count--;

    printf("Expense deleted successfully!\n");
}