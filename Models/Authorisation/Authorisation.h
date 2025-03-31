#ifndef AUTHORISATION_H
#define AUTHORISATION_H

#include "../User/User.h"
#include "../Astronaut/Astronaut.h"
#include "../Engineer/Engineer.h"
#include <vector>
#include <fstream>

class Authorisation{
    public:
        wstring SignIn();
        wstring SignUp();
        void ExportToFile(vector<Astronaut*>& astronaut, vector<Engineer*>& engineer);
        wstring AuthorisationMenu();
};

#endif