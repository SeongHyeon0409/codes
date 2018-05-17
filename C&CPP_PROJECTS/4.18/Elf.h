#include<iostream>
#include<CCharacter.h>

class Elf{
    public:
        CCharacter(void);

        void SayMyName()
        {
           cout<< "My Name is" << name;
        }

cdada
    private:
        char* name;

};