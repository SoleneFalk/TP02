#ifndef CREATURE_H
#define CREATURE_H

#include <string>

class Creature {
protected:
    std::string name;
    int hitPoints;
    int attackValue;

public:
    Creature(std::string creatureName, int initialHitPoints = 100, int initialAttackValue = 50);
    void attack(Creature& target);
    void takeDamage(int damage);
    void displayInfo() const;
    std::string getName() const;
    int getHitPoints() const;
    int getAttackValue() const;
};

class FlyingCreature : public Creature {
public:
    FlyingCreature(std::string creatureName, int initialHitPoints = 100, int initialAttackValue = 50);
    void specialAttack(Creature& target);
};

class BloodthirstyCreature : public Creature {
public:
    BloodthirstyCreature(std::string creatureName, int initialHitPoints = 100, int initialAttackValue = 50);
    void specialAttack(Creature& target);
};

class FusionCreature : public Creature {
public:
    FusionCreature(std::string creatureName, int initialHitPoints = 100, int initialAttackValue = 50);
    void absorbCreature(Creature& target);
};

#endif 
