#include "Creature.h"
#include <iostream>

Creature::Creature(std::string creatureName, int initialHitPoints, int initialAttackValue)
    : name(creatureName), hitPoints(initialHitPoints), attackValue(initialAttackValue) {
    if (hitPoints > 100 || attackValue > 50) {
        std::cout << "Creature " << name << " instantly decomposes!\n";
        hitPoints = 0;
        attackValue = 0;
    }
}

void Creature::attack(Creature& target) {
    std::cout << name << " attacks " << target.getName() << "!\n";
    target.takeDamage(attackValue);
}

void Creature::takeDamage(int damage) {
    hitPoints -= damage;
    if (hitPoints <= 0) {
        std::cout << name << " is dead!\n";
    }
}

void Creature::displayInfo() const {
    std::cout << "Creature Information - Name: " << name
        << ", Hit Points: " << hitPoints
        << ", Attack Value: " << attackValue << "\n";
}

std::string Creature::getName() const {
    return name;
}

int Creature::getHitPoints() const {
    return hitPoints;
}

int Creature::getAttackValue() const {
    return attackValue;
}

FlyingCreature::FlyingCreature(std::string creatureName, int initialHitPoints, int initialAttackValue)
    : Creature(creatureName, initialHitPoints, initialAttackValue) {
}

void FlyingCreature::specialAttack(Creature& target) {
    std::cout << getName() << " performs a double attack on " << target.getName() << "!\n";
    target.takeDamage(2 * getAttackValue());
    takeDamage(10);
}

BloodthirstyCreature::BloodthirstyCreature(std::string creatureName, int initialHitPoints, int initialAttackValue)
    : Creature(creatureName, initialHitPoints, initialAttackValue) {
}

void BloodthirstyCreature::specialAttack(Creature& target) {
    int damage = getAttackValue() / 2;
    std::cout << getName() << " performs a bloodthirsty attack on " << target.getName() << "!\n";
    target.takeDamage(damage);
    takeDamage(-damage); // Heal the creature (up to its initial hit points)
}

FusionCreature::FusionCreature(std::string creatureName, int initialHitPoints, int initialAttackValue)
    : Creature(creatureName, initialHitPoints, initialAttackValue) {
}

void FusionCreature::absorbCreature(Creature& target) {
    if (target.getHitPoints() <= getHitPoints() && target.getAttackValue() <= getAttackValue()) {
        std::cout << getName() << " absorbs " << target.getName() << "!\n";
        takeDamage(-target.getAttackValue()); // Heal by the absorbed creature's attack value
        target.takeDamage(target.getHitPoints()); // Target creature is killed
        attackValue += target.getAttackValue(); // Increase attack value
        hitPoints += target.getHitPoints(); // Increase hit points
        if (hitPoints > 500 && attackValue > 200) {
            std::cout << getName() << " becomes a perfect creature and turns against its creator! The world is destroyed.\n";
            exit(0); // Terminate the program
        }
    }
    else {
        std::cout << "Cannot absorb " << target.getName() << ". The target is stronger!\n";
    }
}
