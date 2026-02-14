#include <stdio.h>

int main() {
    int pin = 0;          // Stores user's PIN
    int choice;           // Menu choice
    float balance = 0;    // Account balance

    // Transaction history arrays (max 10 records)
    int type[10];         // 1 = Balance check, 2 = Deposit, 3 = Withdraw
    float amount[10];     // Amount involved
    float after[10];      // Balance after transaction
    int count = 0;        // Number of transactions stored

    int first, i;

    printf("=== STUDENT ATM PROJECT ===\n\n");

    // Step 1: First-time user setup
    printf("Is this your first time? (1 = Yes, 0 = No): ");
    scanf("%d", &first);

    if (first == 1 || (first == 0 && pin == 0)) {
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

    // Step 2: PIN validation (3 attempts)
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

    // Step 3: ATM Menu
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
            case 1: // Balance enquiry
                printf("Your current balance is: %.2f\n", balance);
                if (count < 10) {
                    type[count] = 1;
                    amount[count] = 0;
                    after[count] = balance;
                    count++;
                }
                break;

            case 2: { // Deposit
                float deposit;
                printf("Enter amount to deposit: ");
                scanf("%f", &deposit);
                if (deposit > 0) {
                    balance += deposit;
                    printf("Deposited %.2f successfully!\n", deposit);
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

            case 3: { // Withdraw
                float withdraw;
                printf("Enter amount to withdraw: ");
                scanf("%f", &withdraw);
                if (withdraw > 0 && withdraw <= balance) {
                    balance -= withdraw;
                    printf("Withdrawn %.2f successfully!\n", withdraw);
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

            case 4: // Transaction history
                if (count == 0) {
                    printf("No transactions yet.\n");
                } else {
                    printf("\n--- TRANSACTION HISTORY ---\n");
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

            case 5: { // Change PIN
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

            case 6: // Exit
                printf("Thank you for using Student ATM. Goodbye!\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
