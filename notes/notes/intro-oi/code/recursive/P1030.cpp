#include <stdio.h>
#include <string.h>
char s[100], s1[100];
void search(char *s, char *s1) {
    char c;
    int x;
    
    if (strlen(s1) == 0) {
        return;
    }

    c = s1[strlen(s1) - 1];
    printf("%c", c); // Output root node
    x = strchr(s, c) - s + 1; // Find position of root node
    
    // strndup function: duplicates a specified number of characters from a given string
    if (x - 1 > 0) {
        search(strndup(s, x - 1), strndup(s1, x - 1)); // Process left subtree
    }
    if (strlen(s1) - x > 0) {
        search(strndup(s + x, strlen(s1) - x), strndup(s1 + x - 1, strlen(s1) - x)); // Process right subtree
    }
    
}

int main() {
    
    
    scanf("%s", s);
    scanf("%s", s1);
    
    search(strdup(s), strdup(s1));
    
    return 0;
}
