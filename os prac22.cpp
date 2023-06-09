#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 3
#define MAX_FILES 3
#define MAX_FILENAME_LENGTH 20

struct User {
    char name[MAX_FILENAME_LENGTH];
    char files[MAX_FILES][MAX_FILENAME_LENGTH];
    int fileCount;
};

struct Directory {
    struct User users[MAX_USERS];
    int userCount;
};

void createUserDirectory(struct Directory* dir, char* username) {
    if (dir->userCount >= MAX_USERS) {
        printf("User directory limit reached\n");
        return;
    }

    struct User newUser;
    strcpy(newUser.name, username);
    newUser.fileCount = 0;

    dir->users[dir->userCount] = newUser;
    dir->userCount++;

    printf("User directory created for %s\n", username);
}

void createFile(struct Directory* dir, char* username, char* filename) {
    int userIndex = -1;

    for (int i = 0; i < dir->userCount; i++) {
        if (strcmp(dir->users[i].name, username) == 0) {
            userIndex = i;
            break;
        }
    }

    if (userIndex == -1) {
        printf("User directory for %s not found\n", username);
        return;
    }

    struct User* user = &(dir->users[userIndex]);

    if (user->fileCount >= MAX_FILES) {
        printf("File limit reached for %s\n", username);
        return;
    }

    strcpy(user->files[user->fileCount], filename);
    user->fileCount++;

    printf("File %s created in %s's directory\n", filename, username);
}

int main() {
    struct Directory dir;
    dir.userCount = 0;

    createUserDirectory(&dir, "user1");
    createUserDirectory(&dir, "user2");
    createUserDirectory(&dir, "user3");

    createFile(&dir, "user1", "file1");
    createFile(&dir, "user1", "file2");
    createFile(&dir, "user1", "file3");
    createFile(&dir, "user2", "file4");
    createFile(&dir, "user2", "file5");
    createFile(&dir, "user3", "file6");

    return 0;
}
