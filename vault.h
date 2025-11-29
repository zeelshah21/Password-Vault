#ifndef VAULT_H
#define VAULT_H

#define MAX_LEN 50
#define DATA_FILE "data.bin"

typedef struct {
    char website[MAX_LEN];
    char username[MAX_LEN];
    unsigned long passwordHash;
} Account;

void addAccount();
void viewAccounts();
void searchAccount();
void updatePassword();
void deleteAccount();

unsigned long hashPassword(const char* str);

#endif
