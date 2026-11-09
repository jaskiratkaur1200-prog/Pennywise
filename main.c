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

float income = 0;
float budget = 0;


// ADD INCOME

void addIncome();

void addIncome()
{
    float amount;

    printf("\nEnter income: Rs ");
    scanf("%f", &amount);

    if(amount <= 0)
    {
        printf("Invalid amount!\n");
        return;
    }

    income = income + amount;

    printf("Income added successfully!\n");
}


// SET BUDGET

void setBudget();

void setBudget()
{
    float amount;

    printf("\nEnter monthly budget: Rs ");
    scanf("%f", &amount);

    if(amount <= 0)
    {
        printf("Invalid budget!\n");
        return;
    }

    budget = amount;

    printf("Budget set successfully!\n");
}


// ADD EXPENSE

void addExpense();

void addExpense()
{
    int choice;
    float amount;

    if(count >= 100)
    {
        printf("Expense list is full!\n");
        return;
    }

    printf("\n----- ADD EXPENSE -----\n");

    printf("1. Food\n");
    printf("2. Transport\n");
    printf("3. Shopping\n");
    printf("4. Entertainment\n");
    printf("5. Education\n");
    printf("6. Other\n");

    printf("Choose category: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            strcpy(e[count].category, "Food");
            break;

        case 2:
            strcpy(e[count].category, "Transport");
            break;

        case 3:
            strcpy(e[count].category, "Shopping");
            break;

        case 4:
            strcpy(e[count].category, "Entertainment");
            break;

        case 5:
            strcpy(e[count].category, "Education");
            break;

        case 6:
            strcpy(e[count].category, "Other");
            break;

        default:
            printf("Invalid category!\n");
            return;
    }

    printf("Enter description: ");
    scanf(" %49[^\n]", e[count].description);

    printf("Enter amount: Rs ");
    scanf("%f", &amount);

    if(amount <= 0)
    {
        printf("Invalid amount!\n");
        return;
    }

    e[count].amount = amount;
    e[count].id = nextId;

    count++;
    nextId++;

    printf("Expense added successfully!\n");
}


// VIEW EXPENSES

void viewExpenses();

void viewExpenses()
{
    int i;

    if(count == 0)
    {
        printf("\nNo expenses found!\n");
        return;
    }

    printf("\n========== ALL EXPENSES ==========\n");

    printf("ID\tCategory\tAmount\tDescription\n");

    for(i = 0; i < count; i++)
    {
        printf("%d\t%s\tRs %.2f\t%s\n",
               e[i].id,
               e[i].category,
               e[i].amount,
               e[i].description);
    }
}


// MAIN FUNCTION

int main()
{
    int choice;

    do
    {
        printf("\n=========================================\n");
        printf("              PENNYWISE\n");
        printf("       PERSONAL EXPENSE TRACKER\n");
        printf("=========================================\n");

        printf("1.  Add Income\n");
        printf("2.  Set Monthly Budget\n");
        printf("3.  Add Expense\n");
        printf("4.  View All Expenses\n");
        printf("5.  Search Expense\n");
        printf("6.  Edit Expense\n");
        printf("7.  Delete Expense\n");
        printf("8.  Financial Summary\n");
        printf("9.  Category Analysis\n");
        printf("10. Budget Alert\n");
        printf("11. Savings Suggestions\n");
        printf("12. Exit\n");

        printf("=========================================\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                addIncome();
                break;

            case 2:
                setBudget();
                break;

            case 3:
                addExpense();
                break;

            case 4:
                viewExpenses();
                break;

            case 5:
                searchExpense();
                break;

            case 6:
                editExpense();
                break;

            case 7:
                deleteExpense();
                break;

            case 8:
                financialSummary();
                break;

            case 9:
                categoryAnalysis();
                break;

            case 10:
                budgetAlert();
                break;

            case 11:
                savingsSuggestion();
                break;

            case 12:
                printf("\nThank you for using PennyWise!\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while(choice != 12);

    return 0;
}