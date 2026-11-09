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


// FUNCTION 1: CALCULATE TOTAL EXPENSE

float totalExpense();

float totalExpense()
{
    float total = 0;
    int i;

    for(i = 0; i < count; i++)
    {
        total = total + e[i].amount;
    }

    return total;
}


// FUNCTION 2: FINANCIAL SUMMARY

void financialSummary();

void financialSummary()
{
    float total;

    total = totalExpense();

    printf("\n========== FINANCIAL SUMMARY ==========\n");

    printf("Total Income: Rs %.2f\n", income);

    printf("Total Expenses: Rs %.2f\n", total);

    printf("Available Balance: Rs %.2f\n",
           income - total);

    if(budget > 0)
    {
        printf("Monthly Budget: Rs %.2f\n", budget);

        printf("Remaining Budget: Rs %.2f\n",
               budget - total);
    }
    else
    {
        printf("Monthly Budget: Not set\n");
    }
}


// FUNCTION 3: CATEGORY ANALYSIS

void categoryAnalysis();

void categoryAnalysis()
{
    char categories[6][20] =
    {
        "Food",
        "Transport",
        "Shopping",
        "Entertainment",
        "Education",
        "Other"
    };

    float totals[6] = {0};

    int i, j, highest = 0;

    if(count == 0)
    {
        printf("\nNo expenses available!\n");
        return;
    }

    for(i = 0; i < count; i++)
    {
        for(j = 0; j < 6; j++)
        {
            if(strcmp(e[i].category, categories[j]) == 0)
            {
                totals[j] = totals[j] + e[i].amount;
            }
        }
    }

    printf("\n========== CATEGORY ANALYSIS ==========\n");

    for(i = 0; i < 6; i++)
    {
        printf("%s: Rs %.2f\n",
               categories[i], totals[i]);
    }

    for(i = 1; i < 6; i++)
    {
        if(totals[i] > totals[highest])
        {
            highest = i;
        }
    }

    printf("\nHighest Spending Category: %s\n",
           categories[highest]);

    printf("Highest Spending Amount: Rs %.2f\n",
           totals[highest]);
}


// FUNCTION 4: BUDGET ALERT

void budgetAlert();

void budgetAlert()
{
    float total, percentage;

    if(budget <= 0)
    {
        printf("\nPlease set your monthly budget first!\n");
        return;
    }

    total = totalExpense();

    percentage = (total / budget) * 100;

    printf("\n========== BUDGET ALERT ==========\n");

    printf("Monthly Budget: Rs %.2f\n", budget);

    printf("Total Spent: Rs %.2f\n", total);

    printf("Budget Used: %.2f%%\n", percentage);

    if(percentage >= 100)
    {
        printf("\nALERT: Budget limit reached or exceeded!\n");
    }
    else if(percentage >= 80)
    {
        printf("\nWARNING: 80%% or more of your budget used!\n");
    }
    else if(percentage >= 50)
    {
        printf("\nNOTICE: Half or more of your budget used.\n");
    }
    else
    {
        printf("\nGOOD: Your spending is under control.\n");
    }
}


// FUNCTION 5: SAVINGS SUGGESTIONS

void savingsSuggestion();

void savingsSuggestion()
{
    float food = 0;
    float shopping = 0;
    float entertainment = 0;

    float total;
    int i;

    total = totalExpense();

    if(total == 0)
    {
        printf("\nNo expenses recorded yet!\n");
        return;
    }

    for(i = 0; i < count; i++)
    {
        if(strcmp(e[i].category, "Food") == 0)
        {
            food = food + e[i].amount;
        }
        else if(strcmp(e[i].category, "Shopping") == 0)
        {
            shopping = shopping + e[i].amount;
        }
        else if(strcmp(e[i].category, "Entertainment") == 0)
        {
            entertainment = entertainment + e[i].amount;
        }
    }

    printf("\n========== SAVINGS SUGGESTIONS ==========\n");

    if(food > total * 0.40)
    {
        printf("Food spending is high.\n");
        printf("Try reducing outside food expenses.\n\n");
    }

    if(shopping > total * 0.30)
    {
        printf("Shopping spending is high.\n");
        printf("Avoid unnecessary purchases.\n\n");
    }

    if(entertainment > total * 0.25)
    {
        printf("Entertainment spending is high.\n");
        printf("Try setting an entertainment spending limit.\n\n");
    }

    if(budget > 0 && total > budget)
    {
        printf("You have exceeded your monthly budget.\n");
        printf("Reduce non-essential expenses.\n\n");
    }

    if(budget > 0 && total < budget * 0.50)
    {
        printf("Great! You are spending less than half "
               "of your budget.\n\n");
    }

    printf("Keep tracking your expenses regularly!\n");
}