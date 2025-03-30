#include "../User/User.h"

using namespace std; 

class Astronaut : public User {
    private:
    wstring m_mission{};
    friend wostream& operator<<(wostream& aout, const Astronaut& astronaut);
    friend wistream& operator>>(wistream& ain, Astronaut& astronaut);
    
    public:
    void setMission();
    wstring getMission() const;
    void PrintInfo() override; 
    bool operator<(const Astronaut& other) const;
    bool operator>(const Astronaut& other) const;
};

