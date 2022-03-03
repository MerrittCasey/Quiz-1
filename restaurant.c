/*
    Outline:
    
    main(){
        get random number between 1 and 4
        use random number to determine meal type and cost

        declare float values for tip and tax

        scan for input

        check to make sure input is greater than 0

        divide input by 100

        multiply meal cost by tip amount and add to meal cost

        multiply total by tax amount and add to total

        print total
    }

*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    float mealCost = 0;
    
    time_t t;
    srand((unsigned) time(&t));
    int random = (rand() % 4) + 1;

    if(random == 1){
        mealCost = 9.95;
    }else if(random == 2){
        mealCost = 4.55;
    }else if(random == 3){
        mealCost = 13.25;
    }else if(random == 4){
        mealCost = 22.35;
    }

    float tip;
    float tax;
    float total = mealCost;

    int cont = 1;

    while(cont == 1){
        printf("Enter tip percentage: ");
        scanf("%f", &tip);

        if(tip < 0 ){
            printf("Tip must be greater than or equal to 0");
            printf("\n");
        }else{
            tip = (tip / 100);
            tip = (total * tip);
            total = (total + tip);

            cont = 0;
        }

    }
    printf("\n");
    
    cont = 1;
    
    while(cont == 1){
        printf("Enter tax percentage: ");
        scanf("%f", &tax);

        if(tax < 0 ){
            printf("Tax must be greater than or equal to 0");
            printf("\n");
        }else{
            tax = (tax / 100);
            tax = (total * tax);
            total = (total + tax);

            cont = 0;
        }

    }
    printf("\n");
    
    printf("Meal Cost Before Tax and Tip: $%.2f\n", mealCost);
    printf("Tip amount: $%.2f\n", tip);
    printf("Tax amount: $%.2f\n", tax);
    printf("Total MealCost: $%.2f\n", total);

    return 0;
}