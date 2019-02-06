#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//structure, kind of like an array afaik.
typedef struct playerStructure
{
    char name[50];
    int health;
    int mana;
    int attack;
    int defense;
    int gold;
} player;

//trying to make an "item" structure to be used in player's inventories mayb?
typedef struct itemStructure
{
    char name[50];
    int health;
    int mana;
    int damage;
}item;

//prototyping function
void displayStats(player Target);
void shop(player Target);
int fightOver();

//i know, i know... global stuff bad.. but its too many braincells right now and i just want to get proof of concept lol
//plus whos gonna 'haxor' my stuff like who would want dis
player Hero, Villain;

int main()
{
    //making hero member and giving it stats
    strcpy(Hero.name, "Sir Leeroy");
    Hero.health = 60;
    Hero.mana = 30;
    Hero.attack = 15;
    Hero.defense = 5;
    Hero.gold = 50;

    //and our baddie
    strcpy(Villain.name, "Mortimer the Terrible");
    Villain.health = 60;
    Villain.mana = 50;
    Villain.attack = 20;
    Villain.defense = 20;
    Villain.gold = 50;

    shop(Hero);
    fight(Hero, Villain);
    fightOver();

    return 0;
}

//takes an entity as an argument to print their name, health, and mana
void displayStats(player Target)
{
    printf("\nName: %s\nHealth: %d\tMana: %d\nAttack: %d\tDefense: %d\nGold: %d\n\n", Target.name, Target.health, Target.mana, Target.attack, Target.defense, Target.gold);
}

void shop(player Target)
{
    int decision;

    printf("Hey! You ready to fight yet? Stock up on what you want and head out into the ring when you're ready! (Enter to cont.)\n");
    //getchar to wait
    getchar();

    displayStats(Hero);
    printf("(Enter to cont.)\n");

    while(decision != 0){
        getchar();
        printf("What would you like to buy? Look through our catalog!\n");
        printf("1. 15gp A rusty iron short sword\n");
        printf("2. 20gp A round, sturdy wooden buckler shield\n");
        printf("3. 50gp A powerful DevTool, capable of smiting even the strongest of foes!\n");
        printf("To make a purchase, enter the corresponding number (0 to enter the Arena):\n");
        scanf("%d", &decision);

        switch(decision){
            case 0:
                printf("Good luck out there!\n");
                break;
            case 1:
                printf("An okay-ish choice! (Enter to cont.)\n");
                Hero.attack += 10;
                Hero.gold -= 15;
                printf("Your Attack is now: %d\n", Hero.attack);
                printf("Your Gold is now: %i\n", Hero.gold);
                getchar();
                break;
            case 2:
                printf("It might protect you some! (Enter to cont.)\n");
                Hero.defense += 5;
                Hero.gold -= 20;
                printf("Your Defense is now: %d\n", Hero.defense);
                printf("Your Gold is now: %i\n", Hero.gold);
                getchar();
                break;
            case 3:
                printf("It will not fail you. (Enter to cont.)\n");
                Hero.attack += 100;
                Hero.gold -= 50;
                printf("Your Attack is now: %d\n", Hero.attack);
                getchar();
                break;
        }
    }
}

//fight can be paused to go back to shop mid fight, but will resume with enemy getting a hit in... i like it like this
void fight(player Target, player Target2)
{
    //basic damage system, could be done better
    int pHit = Hero.attack - Villain.defense;
    int vHit = Villain.attack - Hero.defense;
    int decision;

    displayStats(Hero);
    displayStats(Villain);

    getchar();

    while(Hero.health > 0 || Villain.health > 0){
        printf("Please chose what to do next:\n");
        printf("1. Attack!\n");
        printf("2. Retreat...\n");
        scanf("%i", &decision);

        switch(decision){
            case 1:
                printf("\nYou swing valiantly!\n");
                Villain.health -= pHit;
                if(Villain.health <= 0)
                {
                    Hero.gold += 100;
                    Villain.health = 60;
                    fightOver();
                }
                else
                {
                    break;
                }

            case 2:
                printf("You find yourself in the shop!\n");
                shop(Hero);
                break;
        }
        printf("\nMortimer also strikes a blow!\n");
        Hero.health -= vHit;

        displayStats(Hero);
        displayStats(Villain);
    }
}

int fightOver()
{
    printf("\n\tCongrats, you won!\n\n");

    return 0;
}
