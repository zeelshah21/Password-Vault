#include <stdio.h>
#include "vault.h"

int main() {
    int choice;

    while (1) {
        printf("\n=== PasswordVault ===\n");
        printf("1. Add Account\n");
        printf("2. View Accounts\n");
        printf("3. Search Account\n");
        printf("4. Update Password\n");
        printf("5. Delete Account\n");
        printf("6. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addAccount(); break;
            case 2: viewAccounts(); break;
            case 3: searchAccount(); break;
            case 4: updatePassword(); break;
            case 5: deleteAccount(); break;
            case 6: printf("Goodbye!\n"); return 0;
            default: printf("Invalid choice.\n");
        }
    }

    return 0;
}
