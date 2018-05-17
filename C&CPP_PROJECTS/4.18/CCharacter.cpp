#include<iostream>

class CCharcter{
    public:
        CCharacter(void);

        void SayMyName()
        {
           cout<< "My Name is" << name;
        }


    private:
        char* name;

};