#include <stdio.h>
#include <string.h>

#define item 15
#define name_len 50

void addItem(char names[][name_len], int codes[], int ammount[], int *count);
void display(char names[][name_len], int codes[], int ammount[], int count);
void search(char names[][name_len], int codes[], int ammount[], int count);
void update(char names[][name_len], int codes[], int ammount[], int count);
void low(char names[][name_len], int codes[], int ammount[], int count);

void main()
{
    char itemNames[item][name_len];
    int itemCodes[item];
    int itemq[item];
    int itemC = 0;
    int choice;
    do
    {
        printf("\n--- Inventory Management System ---\n");
        printf("1. Add Items\n");
        printf("2. Display All Items\n");
        printf("3. Search for an Item\n");
        printf("4. Update Item Quantity\n");
        printf("5. Find Item with Lowest Quantity\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addItem(itemNames, itemCodes, itemq, &itemC);
            break;
        case 2:
            display(itemNames, itemCodes, itemq, itemC);
            break;
        case 3:
            search(itemNames, itemCodes, itemq, itemC);
            break;
        case 4:
            update(itemNames, itemCodes, itemq, itemC);
            break;
        case 5:
            low(itemNames, itemCodes, itemq, itemC);
            break;
        case 6:
            printf("Exiting the program...\n");
            break;
        default:
            printf("Invaid command!!\n\n\n");
        }

    } while (choice != 6);
}
void addItem(char names[][name_len], int codes[], int ammount[], int *count)
{
    if (*count >= item)
    {
        printf("Inventory Full!!!");
        return;
    }
    printf("Enter the name of the item: ");
    scanf("%s", names[*count]);
    printf("Enter the item code: ");
    scanf("%d", &codes[*count]);
    printf("Enter the Quantity: ");
    scanf("%d", &ammount[*count]);
    (*count)++;
    printf("\tItem added successfully.!!!\n");
}

void display(char names[][name_len], int codes[], int ammount[], int count)
{
    if (count == 0)
    {
        printf("No item in inventory!!!\n");
        return;
    }
    for (int i = 0; i < count; i++)
    {
        printf("Name: %s , Item Code: %d,Quantity: %d\n ", names[i], codes[i], ammount[i]);
    }
}
void search(char names[][name_len], int codes[], int ammount[], int count)
{
    int code;
    printf("Enter item code to search: ");
    scanf("%d", &code);
    for (int i = 0; i < count; i++)
    {
        if (codes[i] == code)
        {
            printf("item Found : Name: %s, Item Code: %d, Quantity: %d\n", names[i], codes[i], ammount[i]);
            return;
        }
    }

    printf("Ïtem With code %d not Found!!", code);
}

void update(char names[][name_len], int codes[], int ammount[], int count)
{
    int code, n;
    printf("Enter new code to update: ");
    scanf("%d", &code);

    for (int i = 0; i < count; i++)
    {
        if (codes[i] == code)
        {
            printf("Enter New Quantity: ");
            scanf("%d", &n);
            ammount[i] = n;
            printf("Item Quantity Updated Successfully!!!\n");
            return;
        }
    }

    printf("Item with code %d not found.\n", code);
}

void low(char names[][name_len], int codes[], int ammount[], int count)
{
    if (count == 0)
    {
        printf("No Item in Inventory!!!!!\n");
        return;
    }
    int minIndex = 0;
    for (int i = 1; i < count; i++)
    {
        if (ammount[i] < ammount[minIndex])
        {
            minIndex = i;
        }
    }
    printf("Item with lowest quantity: Name: %s, Item Code: %d, Quantity: %d\n", names[minIndex], codes[minIndex], ammount[minIndex]);
}
