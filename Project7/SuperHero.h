/* Lab 7: Derived Classes (HOME)
Filename: SuperHero.h
Date: 2017/07/04
Name: Samantha West
Student ID: 128111168
Description: Hero's of class Hero battle against one another 
based on their individual statistics(attack,health,max health).
Outcome is determined using member functions, overloaded ostream operators and 
global helper functions to calculate attacks, check health, respawn and display
the winner.
*//////////////////////////////////////////////
///////////////////////////////////////////////
#ifndef SUPERHERO_H
#define SUPERHERO_H

#include "Hero.h"

class SuperHero: public Hero {
    int m_superPowerAttackBonus; // superpower:  attack bonus
    int m_superPowerDefendBonus;      // superpower:  defense

public:
    // constructors  
    SuperHero();
    SuperHero(const char* name, 
            int maximumHealth, 
            int attack,
            
            int superPowerAttack, 
            int superPowerDefend);

    int getAttack() const; 
    int getDefend() const; 
 };

void applyDamage (SuperHero& A,  SuperHero& B);
const SuperHero & operator*(const SuperHero &, const SuperHero &);

#endif
