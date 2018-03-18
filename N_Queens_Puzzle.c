#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void N_Queens(int *, int);
bool Promising(int *, int);

int length;

int main(void)
{
    printf("Please enter the size of the chessboard : ");
    scanf("%d", &length);

    int column[length + 1];
    memset(column, 0, sizeof(column));

    printf("\nThe position of %d queens is in : ", length);
    
    N_Queens(column, 0);
    printf("\n");

    return 0;
}

void N_Queens(int *column, int index)
{
    if (Promising(column, index)) {
        if (index == length) {
            /* Print the answer of the N Queens Puzzle */
            printf("\n\t(%d, %d)", 1, column[1]);

            for (int i = 2; i <= length; i++) {
                printf(", (%d, %d)", i, column[i]);
            }
        } else {
            for (int j = 1; j <= length; j++) {
                column[index + 1] = j;
                N_Queens(column, index + 1);
            }
        }
    }
}

bool Promising(int *column, int index)
{
    for (int k = 1; k < index; k++) {
        /* Check if the queens will attack each other */
        if ((column[index] == column[k]) || (abs(column[index] - column[k]) == index - k))
            return false;
    }

    return true;
}
