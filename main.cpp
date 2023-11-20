#include "Creature.h"

int main() {
    // Example usage
    Creature creature1("Monster1");
    Creature creature2("Monster2", 80, 40);

    creature1.displayInfo();
    creature2.displayInfo();

    creature1.attack(creature2);

    creature1.displayInfo();
    creature2.displayInfo();

    FlyingCreature flyingCreature("Harpy", 120, 60);
    BloodthirstyCreature bloodthirstyCreature("Vampire", 60, 25);
    FusionCreature fusionCreature("UltimateMonster", 300, 150);

    flyingCreature.displayInfo();
    bloodthirstyCreature.displayInfo();
    fusionCreature.displayInfo();

    flyingCreature.specialAttack(creature2);
    bloodthirstyCreature.specialAttack(creature1);
    fusionCreature.absorbCreature(creature1);

    flyingCreature.displayInfo();
    bloodthirstyCreature.displayInfo();
    fusionCreature.displayInfo();

    return 0;
}
