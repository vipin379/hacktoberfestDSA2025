#include <stdio.h>
#include <string.h>

int main() {
    char mainStr[100], subStr[50];

    // Input main string
    printf("Enter the main string: ");
    fgets(mainStr, sizeof(mainStr), stdin);
    mainStr[strcspn(mainStr, "\n")] = '\0'; // remove trailing newline

    // Input substring
    printf("Enter the substring to search: ");
    fgets(subStr, sizeof(subStr), stdin);
    subStr[strcspn(subStr, "\n")] = '\0'; // remove trailing newline

    // Search for substring
    char *position = strstr(mainStr, subStr);

    if (position != NULL) {
        printf("Substring found at position: %ld\n", position - mainStr + 1); // 1-based index
    } else {
        printf("Substring not found.\n");
    }

    return 0;
}
