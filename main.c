// This code is written by Ramir :)

// This nicely put together code also has some golden nuggets
// for the curious learners.

// This is also wayy overkill, but very fancy!

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

// Functional Prototypes Mayhem
void printLinkyList(node *head);
node *addAtEnd(node *head, int item);
void wrapperPrint(node *head);
int numEven(node *head);
int recur_Even(node *head);
int numOdd(node *head);
void printMenu(void);
node *deleteEle(node *head, int ele);
node *wrapperDestroy(node *head);
node *addAtBeg(node *head, int item);
node *createNode(int item);
void recurPrint(node *head);
node *destroyList(node *head);
void freedomMenu(void);

int main(void)
{

    srand(time(0));
    node *head = NULL;

    int choice, ele, decision;
    int randomNumber, false = 1;

    printf("You have a couple of choices here fellow!\n");
    printf("1. You'd like to fill in the Linked List with a certain amount of random integers.\n");
    printf("2. You'd like to do your own thing and have your fun!\n");
    printf("0. You'd like to just exit.\n");
    printf("\nEnter your choice: ");
    scanf("%d", &decision);

    if (decision == 1)
    {
        // This is where it's gonna be filled with random integers!!!
        int i, whatYouWannaDo;
        printf("Type in the number of random integers you'd want to fill the Linked List with : ");
        scanf("%d", &randomNumber);

        for (i = 0; i < randomNumber; i++)
            head = addAtEnd(head, (rand() % 100) + 1);

        printf("They have been inserted!\n");

        freedomMenu();

        while (false)
        {
            printf("What you wanna do: ");
            scanf("%d", &whatYouWannaDo);

            if (whatYouWannaDo == 1)
            {
                wrapperPrint(head);
            }
            else if (whatYouWannaDo == 2)
            {
                printf("There are %d even numbers in the list\n", numEven(head));
            }
            else if (whatYouWannaDo == 3)
            {
                printf("There are %d odd numbers in the list\n", numOdd(head));
            }
            else if (whatYouWannaDo == 4)
            {
                head = destroyList(head);
                printf("The list has beem destroyed!\n");
            }
            else if (whatYouWannaDo == 0)
            {
                printf("Thank you to have tried!!\n");
                false = 0;
            }
            else
            {
                printf("I don't know what's going on here!\n");
                false = 0;
            }
        }
    }
    else if (decision == 2)
    {
        // This is where the actual fun happens!!!
        printMenu();

        // ================================================================
        while (!0)
        {
            printf("What is your choice: ");
            scanf("%d", &choice);

            printf("=================================\n\n\n");

            if (choice == 1)
            {
                printf("Type in the value you'd like to  be added: ");
                scanf("%d", &ele);
                head = addAtEnd(head, ele);
            }
            else if (choice == 2)
            {
                wrapperPrint(head);
            }
            else if (choice == 3)
            {
                int even = recur_Even(head);
                if (even == 0)
                    printf("There are no even numbers in this LL.\n\n");
                else
                    printf("There are %d even numbers in the list\n", even);
            }
            else if (choice == 4)
            {
                int odd = numOdd(head);
                if (odd == 0)
                    printf("There are no odd numbers in this LL.\n\n");
                else
                    printf("There are %d odd numbers in the list!\n", odd);
            }
            else if (choice == 5)
            {
                printf("Type in the value you'd like to be added: ");
                scanf("%d", &ele);
                head = addAtBeg(head, ele);
            }
            else if (choice == 6)
            {
                printf("You have chosen to destroyyyy your list\n");
                printf("Press 1 if you really want to this, else press 0: ");
                scanf("%d", &ele);

                if (ele == 1)
                {
                    head = destroyList(head);
                    printf("Your list has been destroyed!\n");
                }
                else if (ele == 0)
                {
                    printf("You have recanted your choice of deleting your list.\n");
                    continue;
                }
                else
                {
                    printf("Wrong Option! Please try again!\n");
                    continue;
                }
            }
            else if (choice == 7)
            {
                printf("Please type in the element you'd like to delete from the list: ");
                scanf("%d", &ele);
                head = deleteEle(head, ele);
            }
            else if (choice == 8)
            {
                printMenu();
            }
            else if (choice == 0)
            {
                printf("Thank you for exiting our nice looking program!!\n");
                break;
            }
            else
            {
                printf("Wrong choice, try again!\n");
                continue;
            }
        }
        // ================================================================
    }
    else if (decision == 0)
    {
        printf("Thank you for just trying the minimum!\n");
        return 0;
    }
    else
    {
        printf("No such option exists!\n");
        return 0;
    }

    return 0;
}

void printMenu(void)
{
    printf("1. To add At the End\n");
    printf("2. Print List!\n");
    printf("3. To print the number of Even Numbers in our list!\n");
    printf("4. To print the number of Odd Numbers in our list!\n");
    printf("5. To add At the Beginning\n");
    printf("6. To destroy the List!!!\n");
    printf("7. To delete an element from the list!\n");
    printf("8. To print the Menu one more time.\n");
    printf("0. To exit our nice looking program!!!\n");
}

void freedomMenu(void)
{
    printf("1. Print List!\n");
    printf("2. To print the number of Even Numbers in our list!\n");
    printf("3. To print the number of Odd Numbers in our list!\n");
    printf("4. To destroy your list!\n");
    printf("0. To exit our nice looking program!!!\n");
}

node *addAtEnd(node *head, int item)
{
    node *temp = createNode(item);

    node *temp2;

    if (head == NULL)
        return temp;

    temp2 = head;

    while (temp2->next != NULL)
        temp2 = temp2->next;

    temp2->next = temp;

    return head;
}

// This is a nice put together print function
// It examplifies the traversal of a Linked List to some degrees
void printLinkyList(node *head)
{
    node *temp;
    if (head == NULL)
    {
        printf("Empty List!\n");
        return;
    }
    temp = head;

    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

// This is just a wrapper function that uses the recursive function to operate the print
// process
void wrapperPrint(node *head)
{
    if (head == NULL)
    {
        printf("Empty List, duhhh!\n\n\n");
        return;
    }

    printf("The values are: ");
    recurPrint(head);
    printf("\n\n\n");
}

// This function returns the number of even numbers in a list
// This also gives you more insight in the traversal of a Linked
// List.
int numEven(node *head)
{
    node *temp;
    int count = 0;
    if (head == NULL)
        return 0;

    temp = head;

    while (temp != NULL)
    {
        if (temp->data % 2 == 0)
            count++;
        temp = temp->next;
    }

    return count;
}

// This function return the number of odd numbers in a list
// This also gives you more insight in the traversal of a Linked
// List.
int numOdd(node *head)
{
    node *temp;
    int count = 0;
    if (head == NULL)
        return 0;

    temp = head;

    while (temp != NULL)
    {
        if (temp->data % 2)
            count++;
        temp = temp->next;
    }

    return count;
}

// Very fancy recursive printing function
void recurPrint(node *head)
{
    // Technically, this check is not required, because the wrapper function calling this
    // is already checking for NULL, but for good practice sake, always have it here!!
    if (head == NULL)
        return;

    printf("%d%s", head->data, (head->next == NULL) ? ".\n" : " -> ");
    recurPrint(head->next);
}

// This is a function in which we add an element at the beginning of the list
node *addAtBeg(node *head, int item)
{
    node *temp = createNode(item);

    if (head == NULL)
        return temp;

    temp->next = head;
    head = temp;

    return head;
}

node *createNode(int item)
{
    node *ptr = malloc(sizeof(node));
    ptr->data = item;
    ptr->next = NULL;

    return ptr;
}

int recur_Even(node *head)
{
    if (head == NULL)
        return 0;

    return (head->data % 2 == 0) + recur_Even(head->next);
}

// Fancy recursive function that will destroy the list
node *destroyList(node *head)
{
    if (head == NULL)
        return NULL;

    free(head);
    destroyList(head->next);

    return NULL;
}

node *wrapperDestroy(node *head)
{
    if (head == NULL)
    {
        printf("Your list is already empty, so can't be destroyed :(\n");
        return head;
    }
    head = destroyList(head);
    printf("Your list just made it to the void :-)\n");

    return NULL;
}

// This is not working, btw!
node *deleteEle(node *head, int ele)
{
    node *temp, *holder;

    if (head == NULL)
    {
        printf("Your list is empty, so nothing can be deleted from it!\n");
        return NULL;
    }

    temp = head;

    if (temp->data == ele)
    {
        printf("Element has been found, proceeding to delete it right now!\n");
        holder = temp;
        temp = temp->next->next;
        free(holder);
        return head;
    }

    while (temp->next != NULL)
    {
        if (temp->next->data == ele)
        {
            holder = temp;
            temp = temp->next;
            free(holder);
            printf("Element was found and deleted successfully!\n");
            return head;
        }
        temp = temp->next;
    }

    printf("The element you want to delete could not be found!\n");
    return head;
}
