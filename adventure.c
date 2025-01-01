#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <strings.h>
#include <sys/types.h>
#include <signal.h>

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
void puzzleChallenge() {
    printf("\nYou encounter a locked chest. Solve the puzzle to unlock it.\n");

    pid_t pid = fork(); // Create a child process

    if (pid < 0) {
        perror("Fork failed");
        exit(1);
    } else if (pid == 0) {
        // Child process: Execute the puzzle mini-game
        char *args[] = {"./puzzle_game", NULL}; // Ensure the puzzle_game executable exists in the same directory
        execvp(args[0], args);

        // If execvp fails
        perror("Failed to launch the puzzle mini-game");
        exit(1);
    } else {
        // Parent process: Wait for the child process to complete
        int status;
        wait(&status); // Wait for the child process to finish

        if (WIFEXITED(status) && WEXITSTATUS(status) == 0) {
            printf("\nThe puzzle is solved! The chest unlocks, revealing valuable items.\n");
        } else {
            printf("\nYou failed to solve the puzzle. The chest remains locked.\n");
        }

        // Continue with the adventure
        printf("\nYou step away from the chest and continue exploring.\n");
    }
}

// Scanning Path
void scanLockedDoor();
void scanAncientDevice();
void scanHiddenEnemy();
void scanRiddleWall();

void scan() {
    printf("\nYou activate your environmental sensors to scan the surroundings.\n");
    printf("Your sensors detect low levels of technology, wooden structures, and biological activity.\n");

    int mainChoice;
    printf("\nWhat will you focus on?\n");
    printf("1. Continue scanning for threats.\n");
    printf("2. Explore specific points of interest detected by your sensors.\n");
    printf("3. Stop scanning and observe the villagers.\n");

    printf("\nEnter your choice: ");
    scanf("%d", &mainChoice);

    if (mainChoice == 1) {
        printf("\nYour scan reveals an approaching band of armed individuals. They seem hostile.\n");
        printf("Do you:\n");
        printf("1. Warn the villagers.\n");
        printf("2. Prepare to defend yourself.\n");

        int action;
        scanf("%d", &action);

        if (action == 1) {
            printf("\nThe villagers are grateful for your warning and begin fortifying their defenses.\n");
        } else if (action == 2) {
            printf("\nYou prepare for battle. The villagers watch in awe as you display advanced combat capabilities.\n");
        } else {
            printf("\nInvalid choice. Returning to scanning options.\n");
        }
    } else if (mainChoice == 2) {
        int scanChoice;
        printf("\nYour sensors pick up multiple points of interest. What will you investigate?\n");
        printf("1. A locked metallic door.\n");
        printf("2. A strange energy signature from an ancient device.\n");
        printf("3. Movement in the shadows.\n");
        printf("4. Cryptic carvings on a stone wall.\n");

        printf("\nEnter your choice: ");
        scanf("%d", &scanChoice);

        if (scanChoice == 1) {
            scanLockedDoor(); // Locked door scenario
        } else if (scanChoice == 2) {
            scanAncientDevice(); // Ancient device scenario
        } else if (scanChoice == 3) {
            scanHiddenEnemy(); // Hidden enemy scenario
        } else if (scanChoice == 4) {
            scanRiddleWall(); // Riddle wall scenario
        } else {
            printf("\nInvalid choice. Returning to scanning options.\n");
        }
    } else if (mainChoice == 3) {
        printf("\nThe villagers notice your passive observation and start to whisper among themselves.\n");
    } else {
        printf("\nInvalid choice. The system shuts down.\n");
    }
}

// Scenario Implementations

void scanLockedDoor() {
    printf("\nYour scan reveals a hidden metallic door buried under rubble.\n");
    printf("The door is locked and requires a mechanism to open.\n");
    printf("Solve the puzzle to unlock the door.\n");

    puzzleChallenge(); // Puzzle game integration

    printf("\nIf you solved the puzzle, the door creaks open, revealing a hidden room filled with ancient artifacts.\n");
    printf("If you failed, the door remains firmly shut, a mystery for another time.\n");
}

void scanAncientDevice() {
    printf("\nYour scan detects an ancient device embedded in the ground. It emits faint energy signatures.\n");
    printf("It looks like a control panel, though the symbols on it are unfamiliar.\n");

    int choice;
    printf("\nWhat will you do?\n");
    printf("1. Attempt to activate the device.\n");
    printf("2. Leave it alone.\n");

    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("\nYou attempt to activate the device. The symbols begin to glow faintly.\n");
        printf("Solve the puzzle to configure the device.\n");

        puzzleChallenge(); // Puzzle game integration

        printf("\nIf you solved the puzzle, the device hums to life, projecting a holographic map of the area.\n");
        printf("If you failed, the device shuts down, refusing to reactivate.\n");
    } else if (choice == 2) {
        printf("\nYou decide to leave the device alone, sensing that tampering with it could be risky.\n");
    } else {
        printf("\nInvalid choice. Returning to scanning options.\n");
    }
}

void scanHiddenEnemy() {
    printf("\nYour scan reveals movement in the shadows—a figure lurking with a weapon.\n");
    printf("It seems like an ambush! What will you do?\n");

    int choice;
    printf("\n1. Confront the figure.\n");
    printf("2. Try to sneak away.\n");

    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("\nYou confront the hidden figure, and they leap out to attack!\n");
        printf("Prepare for combat.\n");
        // Call combat logic here
    } else if (choice == 2) {
        printf("\nYou try to sneak away, but the figure notices you and gives chase!\n");
        // Add chase or escape logic here
    } else {
        printf("\nInvalid choice. Returning to scanning options.\n");
    }
}

void scanRiddleWall() {
    printf("\nYour scan reveals a stone wall with strange carvings.\n");
    printf("The carvings form a riddle:\n");
    printf("\"I am always hungry, I must always be fed. The finger I touch, will soon turn red. What am I?\"\n");

    char answer[20];
    printf("\nEnter your answer: ");
    scanf("%s", answer);

    if (strcasecmp(answer, "fire") == 0) {
        printf("\nCorrect! The wall slides open, revealing a hidden passage.\n");
    } else {
        printf("\nIncorrect. The wall remains closed.\n");
    }
}

void timeOutHandler(int sig) {
    printf("\nTime's up! You failed to act in time.\n");
    exit(0);
}

void timedChallenge() {
    signal(SIGALRM, timeOutHandler);
    alarm(10); // 10-second timer

    int choice;
    printf("Enter your choice quickly: ");
    scanf("%d", &choice);

    alarm(0); // Cancel the alarm if a choice is made
    if (choice == 1) {
        printf("\nYou rush toward the noise and find a group of villagers arguing.\n");
    } else if (choice == 2) {
        printf("\nYou remain hidden, watching the scene unfold.\n");
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
void brigandAttack() {
    printf("\nThe brigand continues to threaten the noblewoman.\n");
    sleep(3);
    printf("\nThe noblewoman screams as the brigand prepares to strike!\n");
}

void villageFire() {
    printf("\nThe fire is spreading rapidly through the village!\n");
    sleep(3);
    printf("\nVillagers are panicking as their homes burn.\n");
}

void parallelEvents() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        exit(1);
    } else if (pid == 0) {
        // Child process: Brigand attack
        brigandAttack();
        exit(0);
    } else {
        // Parent process: Village fire
        villageFire();

        // Wait for the child process to finish
        wait(NULL);
        printf("\nBoth events have concluded. Your choice might have changed the outcome.\n");
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
            printf("Their whispers reach your auditory sensors: \"What manner of man is this?\"\n");
            
            int inChoice;

            printf("\nWhat would you like to do next?\n");
            printf("1. Confront the individual who whispered that directly.\n");
            printf("2. Look for a building to enter.\n");
            printf("3. Speak with the man who whispered but in a casual way, inquiring about the location.\n");

            printf("Enter choice: ");
            scanf("%d", &inChoice);

            if (inChoice == 1) {
                printf("\nYou stride directly toward the man who whispered, your movements mechanical but deliberate.\n");
                printf("\"What did you mean by that?\" you demand, your voice carrying an unnatural clarity.\n");
                printf("The man stumbles backward, his eyes wide with fear. \"You... you're no man! You're some sort of sorcery!\"\n");
                printf("\nThe other villagers gather closer, murmuring among themselves. Their wary glances become outright hostile.\n");
                printf("One villager steps forward with a hoe, gripping it tightly. \"Leave this place, demon, or face the wrath of God!\"\n");
                printf("You realize any further confrontation might escalate the situation. What will you do?\n");
                printf("1. Attempt to explain yourself.\n");
                printf("2. Leave the village immediately.\n");

                int confrontChoice;
                printf("Enter choice: ");
                scanf("%d", &confrontChoice);

                if (confrontChoice == 1) {
                    printf("\nYou raise your hands in a calming gesture. \"I am not a demon,\" you say evenly. \"I am a traveler, seeking only information.\"\n");
                    printf("The man with the hoe hesitates but keeps his weapon raised. \"Prove it! No demon would help us!\"\n");
                    printf("\nThe crowd watches closely. You could offer to help them with their work, but it might expose your advanced knowledge.\n");
                    printf("Alternatively, you could leave now and avoid further risk.\n");
                    // Further branching here
                } else if (confrontChoice == 2) {
                    printf("\nDeciding it's not worth the risk, you turn and leave the village, the hostile whispers of the peasants fading behind you.\n");
                    printf("You continue your journey, pondering your next move.\n");
                } else {
                    printf("\nInvalid choice. The system shuts down.\n");
                }
            } else if (inChoice == 2) {
                printf("\nYou scan the settlement for a building to enter. Most appear to be simple wooden structures with thatched roofs.\n");
                printf("You notice a larger building at the center of the village, likely a gathering hall or church.\n");
                printf("\nDo you:\n");
                printf("1. Enter the larger building directly.\n");
                printf("2. Approach a smaller home and knock on the door.\n");

                int buildingChoice;
                printf("Enter choice: ");
                scanf("%d", &buildingChoice);

                if (buildingChoice == 1) {
                    printf("\nYou walk toward the large building, the villagers' eyes following your every move.\n");
                    printf("The door creaks open, and inside you find a small group of people seated around a table.\n");
                    printf("They look up in alarm, their conversation stopping mid-sentence.\n");
                    printf("A man at the head of the table stands. \"Who are you, stranger? What brings you here?\"\n");
                    // Continue branching here
                } else if (buildingChoice == 2) {
                    printf("\nYou approach a modest home and knock on the door. After a moment, an elderly woman cautiously opens it.\n");
                    printf("\"What do you want?\" she asks, her eyes narrowing suspiciously.\n");
                    printf("\nYou could ask her for information about the settlement or try to reassure her that you mean no harm.\n");
                    // Continue branching here
                } else {
                    printf("\nInvalid choice. The system shuts down.\n");
                }
            } else if (inChoice == 3) {
                printf("\nYou approach the man who whispered, keeping your tone casual. \"I mean no harm,\" you say. \"Can you tell me what this place is?\"\n");
                printf("The man looks startled but recovers quickly. \"This is Green Hollow,\" he says hesitantly. \"A small farming village.\"\n");
                printf("\nThe man seems curious about you, though his fear lingers. \"Where are you from, stranger? You don't look like anyone I've ever seen.\"\n");
                printf("How will you respond?\n");
                printf("1. Tell him the truth about your origins.\n");
                printf("2. Give a vague response to avoid suspicion.\n");

                int responseChoice;
                printf("Enter choice: ");
                scanf("%d", &responseChoice);

                if (responseChoice == 1) {
                    printf("\nYou decide to tell the truth. \"I come from a place far away,\" you say. \"A land of machines and knowledge.\"\n");
                    printf("The man frowns, clearly confused. \"Machines? I don't understand. Are you some sort of wizard?\"\n");
                    printf("\nThe other villagers begin to gather around, whispering nervously. You sense their suspicion growing.\n");
                    // Continue branching here
                } else if (responseChoice == 2) {
                    printf("\nYou offer a vague response. \"I come from far away,\" you say. \"I'm simply passing through.\"\n");
                    printf("The man nods slowly, though his suspicion remains. \"Well, stranger, you won't find much here but hard work and wary eyes.\"\n");
                    printf("\nYou sense that any further interaction might risk exposing your true nature.\n");
                    // Continue branching here
                } else {
                    printf("\nInvalid choice. The system shuts down.\n");
                }
            } else {
                printf("\nInvalid choice. The system shuts down.\n");
            }
            
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
