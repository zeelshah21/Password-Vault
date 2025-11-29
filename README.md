# PasswordVault – Simple C Password Manager

PasswordVault is a lightweight command-line password manager built in C.  
It securely stores usernames and passwords using a custom hashing function and binary file storage.  
This project was created to practice file I/O, hashing, structs, and menu-driven application design.

---

## Features
- Add a new account (website + username + password)  
- Securely store passwords using hashing  
- View saved accounts in a structured table  
- Search for accounts by website  
- Update passwords  
- Delete entries  
- All data saved locally in a binary file  
- Fully menu-driven interface  

---

##  Technologies Used
- C programming  
- Struct-based data storage  
- File I/O (`fopen`, `fwrite`, `fread`)  
- Hashing algorithm (DJB2-inspired)  
- Command-line interface  

---

##  Step-by-Step Explanation

### **1. Start Program**
- Loads existing accounts from `data.bin`  
- Displays interactive menu  

### **2. Add Account**
- Enter website, username, password  
- Password is hashed  
- Saved to binary file using `fwrite`  

### **3. View Accounts**
- Reads entries from `data.bin`  
- Displays each account in clean table format  
- Shows website, username, and hashed password  

### **4. Search Accounts**
- User enters website name  
- Performs linear search  
- Displays the matching entry if found  

### **5. Update Password**
- Search for specific account  
- User enters new password  
- Hash recalculated and saved  

### **6. Delete Account**
- Copies all entries **except** the target one into `temp.bin`  
- Replaces original file  

---


