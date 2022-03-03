/*
    Outline:
    
    main(){
        read max from file and save to local variable

        output menu options

        scan for user input

        if user input is 1 call playGame()

        if user input is 2 call changeMax()

        if user input is 3 output thank you message and respective game info

        save data to file

        close file
    }

    void playGame(){
        generate random number between 1 and max value

        ask for user input

        check if user input is "q" otherwise compare to generated number

        if input is wrong then repeat keep track of total games played while going

    }

    void changeMax(){
        ask for user input 

        if user input isn't to large for int to handle

        change max variable

    }

*/
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void playGame();
void changeMax();

int max;
int numberOfGames = 0;
int wins[10];
int trys[10];

int main(){
    for(int i =0; i < 10; i++){
        trys[i] = 0;
    }
    
    FILE* ifile = fopen("save_user_max_number.txt", "r");

    fscanf(ifile, "%d", &max);

    fclose(ifile);

    printf("WELCOME TO GUESSING GAME\n");

    int cont = 1;

    while(cont == 1){
        printf("\n");
        printf("Press 1 to play a game\n");
        printf("Press 2 to change the max number\n");
        printf("Press 3 to quit\n");

        int input;
        scanf("%d", &input);

        if(input == 1){
            playGame();
        }else if(input == 2){
            changeMax();
        }else if(input == 3){
            printf("\n");
            printf("Thanks for playing!\n");
            printf("\n");
            printf("Here are your results\n");
            printf("---------------------\n");

            for(int i = 0; i < 10; i++){
                if(trys[i] != 0){
                    if(wins[i] == 0){
                        printf("You lost game %d with %d try(s)\n", i + 1, trys[i]);
                    }else if(wins[i] == 1){
                        printf("You won game %d with %d try(s)\n", i + 1, trys[i]);
                    }
                }
            }
            cont = 0;
        }else{
            printf("Invalid input pls try again!\n");
        }
    }

    FILE* ofile = fopen("save_user_max_number.txt", "w");
    fprintf(ofile, "%d", max);
    fclose(ofile);

    return 0;
}

void playGame(){
    printf("\n");
    printf("LETS PLAY!\n");

    time_t t;
    srand((unsigned) time(&t));
    int random = (rand() % max) + 1;

    printf("Generated a random number between 1 and %d\n", max);
    printf("\n");

    int cont = 1;
    int count = 0;

    while(cont == 1){
        char str[10];
        int quit = 0;
        int guess = 0;
        printf("Take a guess: ");
        scanf("%s", &str[0]);
        
        for(int i = 0; i < 10; i++){
            if(str[0] == 113){
                quit = 1;
                break;
            }

            guess = atoi(str);
        }

        if(quit == 1){
            printf("\n");
            printf("Well you lose then quitter!\n");
            count++;
            for(int i = 0; i < 10; i++){
                if(trys[i] == 0){
                    trys[i] = count;
                    wins[i] = 0;
                    break;
                }
            }

            numberOfGames++;
            cont = 0;
        }else{
            if(guess == random){
                count++;
                printf("\n");
                printf("Congratulations you got it!\n");
                printf("It only took you %d trys!\n", count);

                for(int i = 0; i < 10; i++){
                    if(trys[i] == 0){
                        trys[i] = count;
                        wins[i] = 1;
                        break;
                    }
                }   

                numberOfGames++;
                cont = 0;
            }else if(guess < random){
                printf("Wrong your too low!\n");
                count++;
            }else if(guess > random){
                printf("Wrong your too high!\n");
                count++;
            }
        }
    }
}

void changeMax(){
    printf("\n");
    printf("Lets change the max value!\n");

    int newMax;
    int cont = 1;

    while(cont == 1){
        printf("\n");
        printf("Enter a number between 1 and 2,147,483,647: ");  
        scanf("%d", &newMax);

        if(newMax < 1){
            printf("Invalid input try again\n");
        }else{
            max = newMax;
            printf("max value changed!\n");
            cont = 0;
        }

    }
}