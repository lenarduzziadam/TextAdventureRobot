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

void fightBrigands(int *playerWon) {
    int playerHealth = 20;
    int playerAttack = 5;
    int playerDefense = 3;

    int brigandHealth = 15;
    int brigandAttack = 4;

    printf("\nYou step out from the shadows, preparing to confront the brigands.\n");

    while (playerHealth > 0 && brigandHealth > 0) {
        int action;
        printf("\nYour Health: %d | Brigand's Health: %d\n", playerHealth, brigandHealth);
        printf("Choose your action:\n");
        printf("1. Attack\n");
        printf("2. Defend\n");
        printf("\nEnter your choice: ");
        scanf("%d", &action);

        if (action == 1) {
            printf("\nYou attack the brigand!\n");
            brigandHealth -= playerAttack;
            printf("You dealt %d damage to the brigand.\n", playerAttack);
        } else if (action == 2) {
            printf("\nYou brace yourself for the brigand's attack.\n");
            int reducedDamage = brigandAttack - playerDefense;
            if (reducedDamage < 0) reducedDamage = 0;
            printf("The brigand attacks but deals only %d damage due to your defense.\n", reducedDamage);
            playerHealth -= reducedDamage;
            continue;
        } else {
            printf("\nInvalid action! The brigand takes advantage of your hesitation and attacks.\n");
        }

        // Brigand's Turn
        if (brigandHealth > 0) {
            printf("\nThe brigand retaliates!\n");
            playerHealth -= brigandAttack;
            printf("The brigand dealt %d damage to you.\n", brigandAttack);
        }
    }

    if (playerHealth > 0) {
        printf("\nYou have defeated the brigand!\n");
        *playerWon = 1;
    } else {
        printf("\nYou have been defeated by the brigand...\n");
        printf("SYSTEM FAILURE. SHUTTING DOWN...\n");
        *playerWon = 0;
    }
}

void continueStoryAfterFight(int playerWon) {
    if (playerWon) {
        printf("\nThe noblewoman looks at you with a mix of awe and thinly veiled fear.\n");
        printf("\"You... saved me,\" she says hesitantly. \"Perhaps you are not the monster I thought.\"\n");
        printf("The driver, battered but alive, nods his thanks silently.\n");

        printf("\nWhat will you do next?\n");
        printf("1. Join the noblewoman on her carriage ride to town.\n");
        printf("2. Go your own way.\n");

        int choice;
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("\nYou climb onto the carriage, sitting beside the driver.\n");
            printf("The noblewoman keeps her distance, occasionally glancing at you with suspicion.\n");
            printf("\nWhen you arrive in the town, the people whisper and stare, unsure whether to revere or fear you.\n");
            printf("Some bow their heads in respect, while others avert their eyes.\n");
        } else if (choice == 2) {
            printf("\nYou decide to part ways, heading down a different path.\n");
            printf("Eventually, you come across a small settlement of about 15 people.\n");
            printf("The peasants stop their work to gawk at you, their expressions a mix of curiosity and fear.\n");
            printf("Their whispers reach your auditory sensors: \"What manner of creature is this?\"\n");
        } else {
            printf("\nInvalid choice. The system shuts down.\n");
        }
    } else {
        printf("\nThe brigands overwhelm you, and the noblewoman is taken hostage.\n");
        printf("The driver is left for dead, and your systems fail. GAME OVER.\n");
    }
}

void slaughter() {
    printf("\nYou decide to eliminate the unknown human element.\n");
    printf("As you strike, you hear a sickening squelch, like a watermelon bursting, followed by piercing screams.\n");
    printf("In the distance, the wail of a woman and the cries of a baby echo through the air.\n");
    printf("The sharp sound of metal being drawn from a scabbard cuts through the chaos.\n");

    printf("\nSummoning your full strength, you drive your fist through the assailant's metal armor.\n");
    printf("But in doing so, you realize too late that their blade has found its mark, damaging your internal systems.\n");

    printf("\nThe threat has been neutralized, but your power core has been compromised.\n");
    printf("Your strength is now reduced to that of a normal human.\n");

    printf("\nWhat will you do next?\n");
    printf("1. Continue searching for other humans.\n");
    printf("2. Do nothing and wait.\n");
    printf("3. Attempt a self-diagnostic scan.\n");

    int subchoice;
    printf("\nEnter your choice: ");
    scanf("%d", &subchoice);

    if (subchoice == 1) {
        printf("\nYou venture further and come across a small settlement of approximately 15 people.\n");
    } else if (subchoice == 2) {
        printf("\nAs you remain motionless, a richly dressed noblewoman passes by in a wheeled carriage, driven by a burly coachman.\n");
        printf("The noblewoman glances disdainfully at the countryside and mutters under her breath, loud enough for the driver to hear:\n");
        printf("\"Such squalor. These peasants should be grateful I even tolerate traveling through their wretched lands.\"\n");
        printf("The driver says nothing, his hands gripping the reins tightly, his expression stoic.\n");

        printf("\nYou stay hidden, watching as the carriage creaks down the dirt road.\n");
        printf("After a few moments, you notice shadows moving among the trees.\n");
        printf("A group of brigands emerges, blocking the carriage's path.\n");
        printf("The leader shouts, \"Stop! Hand over the lady and the goods, and no one gets hurt!\"\n");

        printf("\nWhat will you do?\n");
        printf("1. Continue to remain hidden and do nothing.\n");
        printf("2. Intervene to stop the brigands.\n");

        int brigandChoice;
        printf("\nEnter your choice: ");
        scanf("%d", &brigandChoice);

        if (brigandChoice == 1) {
            printf("\nYou remain in the shadows, silently observing.\n");
            printf("The brigands drag the noblewoman out of the carriage, ignoring her screams of protest.\n");
            printf("Her driver tries to defend her but is quickly overwhelmed and left for dead.\n");
            printf("The brigands disappear into the forest, taking the woman hostage.\n");
            printf("\nYou hear the cries of the wounded driver as he calls for help, but you do nothing.\n");
        } else if (brigandChoice == 2) {
            int playerWon = 0;
            fightBrigands(&playerWon);
            continueStoryAfterFight(playerWon);
        } else {
            printf("\nInvalid choice. The system shuts down.\n");
        }
    } else if (subchoice == 3) {
        printf("\nInitiating self-diagnostic scan...\n");
        printf("DIAGNOSTIC COMPLETE: Full strength recovery impossible.\n");
        printf("Partial recovery may be achievable if certain components are replaced or repaired.\n");
    } else {
        printf("\nInvalid choice. The system shuts down.\n");
    }
}
