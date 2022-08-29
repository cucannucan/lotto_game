/* This program demonstrates Lotto game. It has 6 options in main menu.
First the user should enter 6 numbers to start the game.
There are 6 functions which are for entering numbers, displaying numbers, sorting numbers, showing if you win or lose, showing the frequency of the numbers that you have entered and last one exiting the program.

Name: Ceren Ucan
Student ID: D21124013
Date: 16/03/2022
TU 856/1
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 6    // Size of the array as only 6 numbers are entered
#define FREQ 43   // For displaying the numbers
#define ARRAY 200 // Storing the frequency

// Function signatures
void enternumbers(int *, int *);
void display(int *);
void sort(int *);
void play(int *, int *);
void freq(int *, int *);
void menu();

// Error checking for entering the number twice
int error_checking(int *user_lottonumber);

// Error checking for entering the first option
void error_checking1();

int main(void)
{
    char exit_control[5] = "Y"; // if the user wants to exit
    char exit_request[5];
    do
    {
        menu(); // display menu untill the user wants to exit
        printf("Are you sure to exit? Y/N");

        scanf("%s", &exit_request[5]);
        printf("You exit the program");
    } while (strcmp(exit_control, exit_request) != 0);
}

void menu()
{
    int menu;  // To display the menu

    menu = 0; // To display the menu over and over

    // checking select 1 before selecting other options
    int selectOnefirst = 0;

    // the user numbers are stored
    int user_lottonumber[SIZE];

    int winning_numbers[SIZE] = {1, 3, 5, 7, 9, 11};

    // Frequency array storage
    int frequencyChecker[ARRAY] = {0};

    do
    {
        // Main menu
        printf("\n 1. Enter your numbers to play                                                                             ");
        printf("\n 2. Display the numbers you entered                                                                        ");
        printf("\n 3. Sort your numbers in an increasing order                                                               ");
        printf("\n 4. See if you won the lotto                                                                               ");
        printf("\n 5. Display the frequency of the numbers                                                                   ");
        printf("\n 6. Exit the Lotto Game                                                                                    ");

        printf("\n\nYou must complete option 1 from the menu before moving on.");

        printf("\n\nPlease select from the menu: ");

        // Entering for the menu
        scanf("%d", &menu);

        // the user can only select the options from 1-6 from the menu
        if (menu > 6)
        {
            error_checking1();
        }

        // function to allow the user to enter the numbers
        if (menu == 1)
        {
            enternumbers(user_lottonumber, frequencyChecker);
            selectOnefirst++;
        }

        // function to display the entered numbers
        if (menu == 2 && selectOnefirst == 1)
        {
            display(user_lottonumber);
        }

        // function to sort the numbers in an increasing order
        if (menu == 3 && selectOnefirst == 1)
        {
            sort(user_lottonumber);
        }

        // function to show if the user won the lotto
        if (menu == 4 && selectOnefirst == 1)
        {
            play(user_lottonumber, winning_numbers);
        }

        // function to see the frequency of numbers
        if (menu == 5 && selectOnefirst == 1)
        {
            freq(user_lottonumber, frequencyChecker);
            selectOnefirst--;
        }

    } while (menu != 6); // end loop

    // ending
    printf("\nYou will exit the program\n");
}

// Getting the users numbers Function 1
void enternumbers(int *user_lottonumber, int *frequencyChecker)
{
    int i;
    int number_checker;
    number_checker = 1;

    // Resetting the Array to 0
    for (i = 0; i < SIZE; i++)
    {
        *(user_lottonumber + i) = 0;
    }

    printf("Welcome to the Lotto Game. Pick your numbers.\n");
    printf("Note: You must pick from 1-42\n\n");

    for (i = 0; i < SIZE; i++)
    {
        do
        {
            number_checker = 1;

            // Telling the user to enter in their 6 numbers
            printf("\nPlease enter your %d numbers in: ", SIZE);
            scanf("%d", user_lottonumber + i);

            // Error checking
            if (error_checking(user_lottonumber) || (!(*(user_lottonumber + i) > 0 && *(user_lottonumber + i) < 43)))
            {
                number_checker = 0;
                printf("\nThe number you have selected is either already selected or invalid.\n");
                printf("\nPlease select a number between 1-42 also don't select the same number again.\n");
            }

            // Calculating the Frequency
            if (number_checker == 1)
            {
                // Checking the numbers entered on against the numbers on the frequencyChecker
                *(frequencyChecker + *(user_lottonumber + i)) = *(frequencyChecker + *(user_lottonumber + i)) + 1;
            }

        } // End do

        while (!number_checker); // While not 0 run the code

    } // End for

} // End enternumbers()

// Displaying the user entered numbers Function 2
void display(int *user_lottonumber)
{
    int i;

    printf("Here are the numbers that you have selected: \n");

    for (i = 0; i < SIZE; i++)
    {
        printf("%d ", *(user_lottonumber + i));
    }

} // End display()

// Sorting the User Lotto numbers Function 3
void sort(int *user_lottonumber)
{
    int n;
    int m;
    int place;

    // Bubble Sort
    for (n = 0; n < SIZE; n++)
    {
        for (m = n; m < SIZE; m++)
        {
            if (*(user_lottonumber + n) > *(user_lottonumber + m)) // an ascending order
            {
                place = *(user_lottonumber + n);
                *(user_lottonumber + n) = *(user_lottonumber + m);
                *(user_lottonumber + m) = place;

            } // End if

        } // End for

    } // End for

    // Displaying the ordered numbers
    printf("Here your numbers ordered: \n");

    for (n = 0; n < SIZE; n++)
    {
        printf("%d ", *(user_lottonumber + n));
    }

} // End sort()

// Seeing if the user won Function 4
void play(int *user_lottonumber, int *winning_numbers)
{
    int i;
    int c;
    int compareNum = 0;

    // checks if the user matches the winning numbers
    for (i = 0; i < SIZE; i++)
    {
        for (c = 0; c < SIZE; c++)
        {
            if (*(user_lottonumber + i) == *(winning_numbers + c))
            {
                compareNum++; // Incrementing
            }
        }
    }

    // If 6 numbers match
    if (compareNum == 6)
    {
        printf("You have won the Jackpot!");
    }

    // If 5 numbers match
    if (compareNum == 5)
    {
        printf("You have won a New car!");
    }

    // If 4 numbers match the user wins this
    if (compareNum == 4)
    {
        printf("You have won a Weekend away!");
    }

    // If 3 numbers and the bonus matches,c the user wins this
    if (compareNum == 3)
    {
        printf("You have won a Cinema Pass!");
    }

    // If the none of the numbers the user entered match, the user doesn't win anything
    if (compareNum == 0 || compareNum == 1 || compareNum == 2)
    {
        printf("You have not won anything.");
    }

} // End play()

// Frequency of numbers Function 5
void freq(int *user_lottonumber, int *frequencyChecker)
{
    int i;
   // int j;
    //int adder;

    // Prints the frequency of each element
    for (i = 0; i < FREQ; i++)
    {
        if (*(frequencyChecker + i) != 0)
        {
            printf("Number %d has been selected %d times.\n", i, *(frequencyChecker + i));
        }
    }

} // End freq()

// Error Checking making sure the user doesn't enter the same number in again
int error_checking(int *user_lottonumber)
{
    int add;
    int k;

    for (add = 0; add < SIZE; add++)
    {
        for (k = add + 1; k < SIZE; k++)
        {
            // Checks if the array has any duplicates
            if (*(user_lottonumber + add) == *(user_lottonumber + k) && *(user_lottonumber + k) != 0)
            {
                return (1); // If there is a duplicate then return 1

            } // End if

        } // End second for

    } // End first for

    return 0; // If there is no duplicate return 0

} // End error_checking();

void error_checking1()
{
    // Showing the user the problem, in this case if the user doesn't select
    // between 1-6 from the menu then this will show up
    printf("Invalid Option, please select again");
    printf("\nYou are now going to be shown the menu again\n");

} // End error_checking1()