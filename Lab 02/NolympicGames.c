#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Country_t
{
    char name[21];
    int gold, silver, bronze;
};
typedef struct Country_t Country;

void CountrySwap(Country *c1, Country *c2)
{
    char tName[21];
    strcpy(tName, c1->name);
    int tGold = c1->gold;
    int tSilver = c1->silver;
    int tBronze = c1->bronze;

    strcpy(c1->name, c2->name);
    c1->gold = c2->gold;
    c1->silver = c2->silver;
    c1->bronze = c2->bronze;

    strcpy(c2->name, tName);
    c2->gold = tGold;
    c2->silver = tSilver;
    c2->bronze = tBronze;
}

int main()
{
    int n;
    scanf("%d", &n);
    Country *arr = malloc(sizeof(Country));
    for (int i = 0; i < n; i++)
    {
        scanf("%s", arr[i].name);
        scanf("%d", &arr[i].gold);
        scanf("%d", &arr[i].silver);
        scanf("%d", &arr[i].bronze);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j].gold < arr[j + 1].gold ||
                (arr[j].gold == arr[j + 1].gold && arr[j].silver < arr[j + 1].silver) ||
                (arr[j].gold == arr[j + 1].gold && arr[j].silver == arr[j + 1].silver && arr[j].bronze < arr[j + 1].bronze))
                CountrySwap(&arr[j], &arr[j + 1]);
        }
    }

    for (int i = 0; i < n; i++)
        printf("%s\n", arr[i].name);

    return 0;
}