#ifndef ASTRONAUT_H
#define ASTRONAUT_H

#include "../User/User.h"

using namespace std; 

class Astronaut : public User {
    private:
    wstring m_mission{};
    friend wostream& operator<<(wostream& aout, const Astronaut& astronaut);
    friend wistream& operator>>(wistream& ain, Astronaut& astronaut);
    
    public:
    Astronaut() = default;
    Astronaut(const wstring& surname, const wstring& name, int age, const wstring& mission);
    void setMission();
    wstring getMission() const;
    void PrintInfo() override; 
    bool operator<(const Astronaut& other) const;
    bool operator>(const Astronaut& other) const;
};

#endif