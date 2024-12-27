#include <stdio.h>
#include <stdlib.h>

void communicate();
void scan();
void observe();
void slaughter();
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

    switch (choice) {
            case 1:
                communicate();
                break;
            case 2:
                scan();
                break;
            case 3:
                observe();
                break;
            case 4:
                slaughter();
                break;
            default:
                printf("Invalid choice. The system shuts down.\n");
                return 1;
        }

    return 0;
}

// Communication Path
void communicate() {
    printf("\nYou decide to communicate with the villagers.\n");
    printf("They seem startled as your voice echoes with mechanical precision.\n");
    printf("1. Explain that you are a helper from another world.\n");
    printf("2. Claim to be a divine messenger.\n");

    int subchoice;
    printf("\nEnter your choice: ");
    scanf("%d", &subchoice);

    if (subchoice == 1) {
        printf("\nThe villagers are confused by your words. They argue among themselves about your intentions.\n");
        printf("Do you:\n");
        printf("1. Offer to demonstrate your abilities.\n");
        printf("2. Remain passive and let them decide.\n");

        int action;
        scanf("%d", &action);

        if (action == 1) {
            printf("\nYou demonstrate your advanced knowledge by repairing a broken plow.\n");
            printf("The villagers are awestruck and begin to trust you.\n");
        } else {
            printf("\nThe villagers grow suspicious of your silence. They decide to imprison you.\n");
        }
    } else if (subchoice == 2) {
        printf("\nThe villagers believe you are a messenger from the heavens.\n");
        printf("They treat you with reverence but expect miracles you may not be able to deliver.\n");
    } else {
        printf("\nInvalid choice. The system shuts down.\n");
    }
}

// Scanning Path
void scan() {
    printf("\nYou activate your environmental sensors to scan the surroundings.\n");
    printf("Your sensors detect low levels of technology, wooden structures, and biological activity.\n");
    printf("1. Continue scanning for threats.\n");
    printf("2. Stop scanning and observe the villagers.\n");

    int subchoice;
    printf("\nEnter your choice: ");
    scanf("%d", &subchoice);

    if (subchoice == 1) {
        printf("\nYour scan reveals an approaching band of armed individuals. They seem hostile.\n");
        printf("Do you:\n");
        printf("1. Warn the villagers.\n");
        printf("2. Prepare to defend yourself.\n");

        int action;
        scanf("%d", &action);

        if (action == 1) {
            printf("\nThe villagers are grateful for your warning and begin fortifying their defenses.\n");
        } else {
            printf("\nYou prepare for battle. The villagers watch in awe as you display advanced combat capabilities.\n");
        }
    } else if (subchoice == 2) {
        printf("\nThe villagers notice your passive observation and start to whisper among themselves.\n");
    } else {
        printf("\nInvalid choice. The system shuts down.\n");
    }
}

// Observation Path
void observe() {
    printf("\nYou decide to remain silent and observe the villagers.\n");
    printf("They approach cautiously, unsure of what to make of you.\n");
    printf("1. Allow them to examine you.\n");
    printf("2. Back away to avoid contact.\n");

    int subchoice;
    printf("\nEnter your choice: ");
    scanf("%d", &subchoice);

    if (subchoice == 1) {
        printf("\nThe villagers tentatively examine your metallic frame. They debate whether you are divine or a demon.\n");
    } else if (subchoice == 2) {
        printf("\nYour retreat makes the villagers uneasy. They decide to summon their leader to investigate.\n");
    } else {
        printf("\nInvalid choice. The system shuts down.\n");
    }
}

void slaughter(){
    printf("\nYou decide to attempt to kill the unknwon human element.\n");
    printf("You hear a squishy sound like a watermelon bursting and a series of screams\n");
    printf("\n if you listen close you hear a baby crying and a woman wailing you hear metal being brought out of a scabbard.\n");
    printf("You access your full strength and punch right through the individuals metal armour but\n");
    printf("you quickly realize the assailant made contact, damage your internal structure.\n");

    printf("\nThe threat has been sucessfully dealth with but your strength basis is now that of a normal human.\n");
    printf("What will you do next?\n");

    int subchoice;

    printf("\n1. Continue on looking for humans\n");
    printf("2. Do nothing and wait\n");
    printf("3. Try to access your internal data for self diagnostic\n");

    printf("\nEnter your choice: ");
    scanf("%d", &subchoice);

    if(subchoice == 1){
        printf("\nYou come across a small settlment of approximately 15 people");
    } else if(subchoice == 2){
        printf("\nA richly dressed noble woman passes through by wheel house with a burly driver\n");

        printf("1. Do nothing\n");
        printf("2. Approch the wheelhouse. \n");
        printf("\nWhat will you do?: ");

        int innerChoiceTwo;

        scanf("%d", &innerChoiceTwo);

        //continue loop logic here
    } else if(subchoice == 3){
        printf("\nPERFORMING SELF DIAGNOSIS FULL RECOVERABILITY OF STRENGTH IMPOSSIBLE\n");
        printf("However, Partial recoverability is possible if....");

    } else{
        printf("\nINVALID CHOICE SYSTEM SHUT DOWN");
    }

}