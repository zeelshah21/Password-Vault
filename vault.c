#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "vault.h"

unsigned long hashPassword(const char* str) {
    unsigned long hash = 5381;
    int c;

    while ((c = *str++))
        hash = ((hash << 5) + hash) + c;

    return hash;
}

void addAccount() {
    Account acc;
    FILE* file = fopen(DATA_FILE, "ab");

    if (!file) {
        printf("Error opening file.\n");
        return;
    }

    printf("Enter website: ");
    scanf("%s", acc.website);

    printf("Enter username: ");
    scanf("%s", acc.username);

    char password[50];
    printf("Enter password: ");
    scanf("%s", password);

    acc.passwordHash = hashPassword(password);

    fwrite(&acc, sizeof(Account), 1, file);
    fclose(file);

    printf("Account saved!\n");
}

void viewAccounts() {
    FILE* file = fopen(DATA_FILE, "rb");
    if (!file) {
        printf("No saved accounts found.\n");
        return;
    }

    Account acc;

    printf("\nSaved Accounts:\n");
    printf("---------------------------\n");

    while (fread(&acc, sizeof(Account), 1, file)) {
        printf("Website: %s\n", acc.website);
        printf("Username: %s\n", acc.username);
        printf("Password Hash: %lu\n", acc.passwordHash);
        printf("---------------------------\n");
    }

    fclose(file);
}

void searchAccount() {
    char website[MAX_LEN];
    printf("Enter website to search: ");
    scanf("%s", website);

    FILE* file = fopen(DATA_FILE, "rb");
    if (!file) {
        printf("No accounts found.\n");
        return;
    }

    Account acc;
    int found = 0;

    while (fread(&acc, sizeof(Account), 1, file)) {
        if (strcmp(acc.website, website) == 0) {
            printf("Website: %s\n", acc.website);
            printf("Username: %s\n", acc.username);
            printf("Password Hash: %lu\n", acc.passwordHash);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("No account found for that website.\n");

    fclose(file);
}

void updatePassword() {
    char website[MAX_LEN];
    printf("Enter website to update: ");
    scanf("%s", website);

    FILE* file = fopen(DATA_FILE, "rb");
    FILE* temp = fopen("temp.bin", "wb");

    if (!file || !temp) {
        printf("Error opening files.\n");
        return;
    }

    Account acc;
    int found = 0;

    while (fread(&acc, sizeof(Account), 1, file)) {
        if (strcmp(acc.website, website) == 0) {
            char newPass[50];
            printf("Enter new password: ");
            scanf("%s", newPass);

            acc.passwordHash = hashPassword(newPass);
            found = 1;
        }
        fwrite(&acc, sizeof(Account), 1, temp);
    }

    fclose(file);
    fclose(temp);

    remove(DATA_FILE);
    rename("temp.bin", DATA_FILE);

    if (found)
        printf("Password updated!\n");
    else
        printf("Website not found.\n");
}

void deleteAccount() {
    char website[MAX_LEN];
    printf("Enter website to delete: ");
    scanf("%s", website);

    FILE* file = fopen(DATA_FILE, "rb");
    FILE* temp = fopen("temp.bin", "wb");

    if (!file || !temp) {
        printf("Error opening files.\n");
        return;
    }

    Account acc;
    int deleted = 0;

    while (fread(&acc, sizeof(Account), 1, file)) {
        if (strcmp(acc.website, website) != 0) {
            fwrite(&acc, sizeof(Account), 1, temp);
        } else {
            deleted = 1;
        }
    }

    fclose(file);
    fclose(temp);

    remove(DATA_FILE);
    rename("temp.bin", DATA_FILE);

    if (deleted)
        printf("Account deleted!\n");
    else
        printf("Website not found.\n");
}
