#include <stdio.h>

int main() {
    int pin = 0;
    int choice;
    float balance = 0.0;

    int type[10];
    float amount[10];
    float after[10];
    int count = 0;

    int first, i;

    printf("=== STUDENT ATM PROJECT ===\n\n");

    printf("Is this your first time? (1 = Yes, 0 = No): ");
    scanf("%d", &first);

    if (first == 1) {
        int newpin, confirmpin;

        while (1) {
            printf("Create your PIN: ");
            scanf("%d", &newpin);

            printf("Confirm your PIN: ");
            scanf("%d", &confirmpin);

            if (newpin == confirmpin) {
                pin = newpin;
                printf("PIN successfully created!\n");
                break;
            } else {
                printf("PINs do not match. Try again.\n");
            }
        }
    }

    int attempts = 3;
    while (attempts > 0) {
        int entered;

        printf("Enter PIN to login: ");
        scanf("%d", &entered);

        if (entered == pin) {
            printf("Login successful!\n");
            break;
        } else {
            attempts--;
            printf("Wrong PIN. Attempts left: %d\n", attempts);
        }

        if (attempts == 0) {
            printf("Too many wrong attempts. Exiting...\n");
            return 0;
        }
    }

    while (1) {
        printf("\n--- ATM MENU ---\n");
        printf("1. Balance Enquiry\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Transaction History\n");
        printf("5. Change PIN\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Current Balance: %.2f\n", balance);

                if (count < 10) {
                    type[count] = 1;
                    amount[count] = 0;
                    after[count] = balance;
                    count++;
                }
                break;

            case 2: {
                float deposit;
                printf("Enter deposit amount: ");
                scanf("%f", &deposit);

                if (deposit > 0) {
                    balance += deposit;
                    printf("Deposit successful!\n");

                    if (count < 10) {
                        type[count] = 2;
                        amount[count] = deposit;
                        after[count] = balance;
                        count++;
                    }
                } else {
                    printf("Invalid amount.\n");
                }
                break;
            }

            case 3: {
                float withdraw;
                printf("Enter withdrawal amount: ");
                scanf("%f", &withdraw);

                if (withdraw > 0 && withdraw <= balance) {
                    balance -= withdraw;
                    printf("Withdrawal successful!\n");

                    if (count < 10) {
                        type[count] = 3;
                        amount[count] = withdraw;
                        after[count] = balance;
                        count++;
                    }
                } else {
                    printf("Invalid or insufficient balance.\n");
                }
                break;
            }

            case 4:
                if (count == 0) {
                    printf("No transactions yet.\n");
                } else {
                    printf("\n--- Transaction History ---\n");

                    for (i = 0; i < count; i++) {
                        if (type[i] == 1)
                            printf("%d. Balance Check | Balance: %.2f\n", i+1, after[i]);
                        else if (type[i] == 2)
                            printf("%d. Deposit %.2f | Balance: %.2f\n", i+1, amount[i], after[i]);
                        else if (type[i] == 3)
                            printf("%d. Withdraw %.2f | Balance: %.2f\n", i+1, amount[i], after[i]);
                    }
                }
                break;

            case 5: {
                int oldPin, newPin, confirm;

                printf("Enter current PIN: ");
                scanf("%d", &oldPin);

                if (oldPin == pin) {
                    printf("Enter new PIN: ");
                    scanf("%d", &newPin);

                    printf("Confirm new PIN: ");
                    scanf("%d", &confirm);

                    if (newPin == confirm) {
                        pin = newPin;
                        printf("PIN changed successfully!\n");
                    } else {
                        printf("PINs do not match.\n");
                    }
                } else {
                    printf("Wrong current PIN.\n");
                }
                break;
            }

            case 6:
                printf("Thank you for using Student ATM!\n");
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
