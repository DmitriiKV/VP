#include "../User/User.h"
#include "../Astronaut/Astronaut.h"
#include "../Engineer/Engineer.h"
#include <vector>
#include <fstream>

class Authorisation{
    public:
        wstring SignIn();
        wstring SignUp();
};