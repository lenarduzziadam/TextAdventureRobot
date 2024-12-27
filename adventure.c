#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file = fopen("story.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open story file.\n");
        return 1;
    }

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }

    fclose(file);

    // Add input handling here for choices
    int choice;
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    printf("You chose option %d. (Future branching goes here.)\n", choice);
    return 0;
}
