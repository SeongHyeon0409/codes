#include <string>
#include <iostream>

class CCharacter {

public :
    CCharacter ();
    ~CCharcter ();

    void SayMyName()
    {
        std::cout << "My Namie is " << m_Name << std::endl;
    }
protected:
    std :: string m_Name;

}