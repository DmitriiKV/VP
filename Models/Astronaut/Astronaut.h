#include "../User/User.h"

using namespace std; 

class Astronaut : public User {
    private:
    wstring m_mission{};
    
    public:
    void setMission();
    wstring getMission();
    void PrintInfo() override; 
};

