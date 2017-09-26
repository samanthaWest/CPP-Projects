/* Lab 9 (HOME) 
   Filename: String.cpp
   Name: Samantha West (128111168)
   Date: 2017/07/30
   * Updated to try and solve & use substr memb func + minimized code *
   Description: a string class which uses dynamic memory to
   execute commonly used cstring funcs to copy, add, create 
   and print dynamic strings in a program.
*/ ///////////////////////////////////////////////////////
#include <cstring>
#include <iostream>
#include "String.h"
using namespace std;

namespace sict{
    
    // Default Constructor (default capacity of 1)
    String::String(int capacity){
        // *NOTE* capacity = size of internal buffer
        // length = length of actual data string
        // Capacity > Length + 1 ?
        if (capacity > 1 ? (m_capacity = capacity) : (m_capacity = 1));
        m_pString = new char[m_capacity];
        m_pString[0] = '\0';
    }

    //  Constructor receiving 2 parameters (compare capacity with string length + 1)
    String::String(const char* pSource, int capacity){
        if (capacity > (strlen(pSource)+1) ? (m_capacity = capacity) : (m_capacity = (strlen(pSource) + 1)));
        m_pString = new char[m_capacity];
        strncpy(m_pString, pSource, m_capacity);
    }

    // Copy Constructor 
    String::String(const String& other, int capacity){
        if (capacity > (strlen(other.m_pString) + 1) ? (m_capacity = capacity) : (m_capacity = (strlen(other.m_pString) + 1))) {
            m_pString = new char[m_capacity];
            strcpy(m_pString, other.m_pString);
        }
    }

    // String::resize(int newsize)  
    void String::resize(int newsize) {
        if (newsize > (strlen(m_pString))) {
            // set new size
            m_capacity = newsize;
            // store origonal data in back-up string to prevent loss
            char * m_pString2 = new char[m_capacity];
            strncpy(m_pString2, m_pString, m_capacity);

            // Delete, re-allocate and grow buffer size
            delete[] m_pString;
            m_pString = nullptr;
            m_pString = new char[m_capacity];
            strncpy(m_pString, m_pString2, m_capacity);
        }
    }
                                            
    // String::operator=(const String& other)
    String& String::operator=(const String& other) {
        // check for self assignment
        if (this != &other) {
            // shallow copy
            m_capacity = strlen(other.m_pString) + 1;
            resize(m_capacity);
            strcpy(m_pString, other.m_pString);
        }
        return *this;
    }

    // String::~String
    String::~String() {
        delete[] m_pString;
        m_pString = nullptr;
    }

    // String::length()
    int String::length() const {
        return strlen(m_pString);
    }

    // String::operator const char*() const
    String::operator const char *() const {
        return &m_pString[0];
    }

    // String::empty()
    bool String::empty() const {
        bool valid;
        if (length() == 0 ? valid = true : valid = false);
        return valid;
    }
    
    // String::operator bool()     
    String::operator bool() const {
        // bool valid;
        // if (length() != 0 && m_pString != '\0' && m_pString[0] != ' ' ? valid = true : valid = false);
        return !empty();
    }
     
    // String::operator==(const String& s2) const     
    bool String::operator==(const String& s2) const
    {
        bool valid = strcmp(m_pString, s2.m_pString) == 0;
        return valid;
    }
    
    // String::operator+=(const String& s2) 
    String& String::operator+=(const String& s2) {
        // *this = *this +2
        *this = (substr(0,length())+s2); // testing substr func
        return *this;
    }
    
    // String::operator+(const String& s2) const
    String String::operator+(const String& s2) const {   
        char* m_pString2 = new char[length() + (s2.length() + 1)];
        strcpy(m_pString2, m_pString);
        strcat(m_pString2, s2.m_pString);
        return m_pString2; 
    }
    
    // String::operator+=(char c)
    String& String::operator+= (char c) {
        char c_[2];
        c_[0] = c;
        c_[1] = '\0';
        // resize capacity to current + 2 for 1 char and null byte
        resize(m_capacity + 2);
        strcat(m_pString, c_); 
        return *this;
    }
   
    // String::substr
    // ?????????
    String String::substr(int index, int len) const { 
        String temp;
        // if not empty copies to temp string
        if (!empty()) {
            temp.m_pString = new char[length() + 1];
            for (int i = index; i < index + len + 1; i++) {
                temp.m_pString[i] = m_pString[i];
            }
            temp.m_pString[len] = '\0';
        }  // else return an empty string
        return temp;
    }

    // operator<<
    std::ostream& operator<<(std::ostream& ostream, const String &s) {
        ostream << s.operator const char *();
        return ostream;
    }

    // operator>>
    std::istream& operator>>(std::istream& istream, String &s) {
        s = "";
        char tempC = 0;
        do
        {
            tempC = istream.get();
            if (tempC != '\n')
            {
                s += tempC;
            }
            else
                break;
        } while(1);
        return istream;
    }

  
}
