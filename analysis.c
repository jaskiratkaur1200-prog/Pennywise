
#include <stdio.h>
#include <string.h>

struct Expense
{
    int id;
    char category[20];
    float amount;
};

struct Expense a1[100];

int count = 0;
float income, budget;


// FUNCTION 1: ADD EXPENSE

void addExpense()
{
    int ch;

    if(count >= 100)
    {
        printf("Expense limit reached!\n");
        return;
    }

    printf("\n1. Food\n2. Transport\n3. Shopping\n");
    printf("4. Entertainment\n5. Education\n6. Other\n");

    printf("Enter category: ");
    scanf("%d", &ch);

    switch(ch)
    {
        case 1: strcpy(a1[count].category, "Food"); break;
        case 2: strcpy(a1[count].category, "Transport"); break;
        case 3: strcpy(a1[count].category, "Shopping"); break;
        case 4: strcpy(a1[count].category, "Entertainment"); break;
        case 5: strcpy(a1[count].category, "Education"); break;
        case 6: strcpy(a1[count].category, "Other"); break;

        default:
            printf("Invalid category!\n");
            return;
    }

    printf("Enter amount: ");

    if(scanf("%f", &a1[count].amount) != 1)
    {
        printf("Invalid amount!\n");
        while(getchar() != '\n');
        return;
    }

    if(a1[count].amount <= 0)
    {
        printf("Amount must be greater than zero!\n");
        return;
    }

    a1[count].id = count + 1;
    count++;

    printf("Expense added successfully!\n");
}


// FUNCTION 2: TOTAL EXPENSE

float totalExpense()
{
    float total = 0;
    int i;

    for(i = 0; i < count; i++)
    {
        total = total + a1[i].amount;
    }

    return total;
}


// FUNCTION 3: VIEW EXPENSES

void viewExpenses()
{
    int i;

    if(count == 0)
    {
        printf("\nNo expenses recorded!\n");
        return;
    }

    printf("\n========== ALL EXPENSES ==========\n");

    for(i = 0; i < count; i++)
    {
        printf("\nID: %d", a1[i].id);
        printf("\nCategory: %s", a1[i].category);
        printf("\nAmount: Rs %.2f\n", a1[i].amount);
    }
}


// FUNCTION 4: FINANCIAL SUMMARY

void financialSummary()
{
    float total = totalExpense();

    printf("\n========== FINANCIAL SUMMARY ==========\n");

    printf("Total Income: Rs %.2f\n", income);
    printf("Total Expenses: Rs %.2f\n", total);
    printf("Available Balance: Rs %.2f\n", income - total);
    printf("Remaining Budget: Rs %.2f\n", budget - total);
}


// FUNCTION 5: CATEGORY ANALYSIS

void categoryAnalysis()
{
    char categories[6][20] =
    {
        "Food", "Transport", "Shopping",
        "Entertainment", "Education", "Other"
    };

    float totals[6] = {0};

    int i, j;

    if(count == 0)
    {
        printf("\nNo expenses available!\n");
        return;
    }

    for(i = 0; i < count; i++)
    {
        for(j = 0; j < 6; j++)
        {
            if(strcmp(a1[i].category, categories[j]) == 0)
            {
                totals[j] = totals[j] + a1[i].amount;
            }
        }
    }

    printf("\n========== CATEGORY ANALYSIS ==========\n");

    for(i = 0; i < 6; i++)
    {
        printf("%s: Rs %.2f\n", categories[i], totals[i]);
    }
}


// FUNCTION 6: BUDGET ALERT

void budgetAlert()
{
    float total = totalExpense();

    printf("\n========== BUDGET ALERT ==========\n");

    printf("Budget Used: %.2f%%\n", (total / budget) * 100);

    if(total >= budget)
    {
        printf("ALERT! Budget limit reached or exceeded.\n");
    }
    else if(total >= budget * 0.8)
    {
        printf("WARNING! 80%% of budget used.\n");
    }
    else
    {
        printf("You are within your budget.\n");
    }
}


// MAIN FUNCTION

int main()
{
    int choice;

    printf("Enter Monthly Income: Rs ");

    if(scanf("%f", &income) != 1 || income < 0)
    {
        printf("Invalid income!\n");
        return 0;
    }

    printf("Enter Monthly Budget: Rs ");

    if(scanf("%f", &budget) != 1 || budget <= 0)
    {
        printf("Invalid budget!\n");
        return 0;
    }

    do
    {
        printf("\n\n========== EXPENSE TRACKER ==========\n");

        printf("1. Add Expense\n");
        printf("2. View Expenses\n");
        printf("3. Financial Summary\n");
        printf("4. Category Analysis\n");
        printf("5. Budget Alert\n");
        printf("6. Exit\n");

        printf("\nEnter your choice: ");

        if(scanf("%d", &choice) != 1)
        {
            printf("Invalid input!\n");
            while(getchar() != '\n');
            choice = 0;
            continue;
        }

        switch(choice)
        {
            case 1:
                addExpense();
                break;

            case 2:
                viewExpenses();
                break;

            case 3:
                financialSummary();
                break;

            case 4:
                categoryAnalysis();
                break;

            case 5:
                budgetAlert();
                break;

            case 6:
                printf("\nThank you for using Expense Tracker!\n");
                break;

            default:
                printf("\nInvalid choice! Try again.\n");
        }

    } while(choice != 6);

    return 0;
}
