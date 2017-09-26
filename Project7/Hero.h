/* Lab 7: Derived Classes (HOME)
Filename: Hero.h
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
#ifndef HERO_H
#define HERO_H

#include <iostream>
#define MAX_CHAR 41

class Hero {
    char m_name[41];
    int  m_attack;
    int  m_maximumHealth;
    int  m_health;

    bool isEmpty() const;

public:
    // constructors
    Hero();
    Hero(const char name[], int maximumHealth, int attack);

    // member functions
    void respawn();
    bool isAlive() const { return m_health > 0; }
    int  getAttack() const { return m_attack; }
    void deductHealth(int);
    void display(std::ostream&) const;

    // friend helper function to insert name into ostream
    friend std::ostream& operator<<(std::ostream&, const Hero&);
};

void applyDamage(Hero& A, Hero& B);
const Hero & operator*(const Hero &, const Hero &);

#endif

