#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int ticket_fare = 60;
    int total_value = 0;
    char input[100];

    printf("Enter banknotes to purchase the ticket:\n");
    fgets(input, 100, stdin);

    char *token = strtok(input, " ");
    while (token != NULL) {
        int banknote = atoi(token);

        if (banknote <= 0 || banknote > 100) {
            printf("Invalid banknote. Please enter a valid banknote between 1 and 100 Taka.\n");
        }
        else {
            total_value += banknote;

            if (total_value < ticket_fare) {
                printf("Total amount received so far: %d.\n", total_value);
            }
            else if (total_value == ticket_fare) {
                printf("Total amount received: %d. Ticket purchased.\n", total_value);
                return 0;
            }
            else {
                int change = total_value - ticket_fare;
                printf("Total amount received: %d. Ticket purchased. Change: %d.\n", total_value, change);
                return 0;
            }
        }

        token = strtok(NULL, " ");
    }

    if (total_value < ticket_fare) {
        printf("Insufficient amount received. Please enter more banknotes.\n");
    }

    return 0;
}
