#ifndef AUTHORISATION_H
#define AUTHORISATION_H

#include "../User/User.h"

#include "../MyVectorAstronaut/MyVectorAstronaut.h"
#include "../MyVectorEngineer/MyVectorEngineer.h"

class MyVectorEngineer;
class MyVectorAstronaut;

class Authorisation{
    public:
        wstring SignIn();
        wstring SignUp();
        void ExportToFile(MyVectorAstronaut astronaut, MyVectorEngineer engineer);
        wstring AuthorisationMenu();
        Authorisation() = default;
};

#endif