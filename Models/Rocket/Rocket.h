#pragma once

#include <locale>
#include <string>

using namespace std; 

class Rocket {
    private:
    wstring m_name{};
    wstring m_type{};
    double m_payload_capacity{};
    wstring m_purpose{};
    friend wostream& operator<<(wostream& rout, const Rocket& rocket);
    friend wistream& operator>>(wistream& rin, Rocket& rocket);
    
    public:
    // Rocket(wstring, wstring, int);
    void NewInfo();
    void PrintInfo();
    wstring getName() const;
    wstring getType() const;
    double getPayloadCapacity() const;
    wstring getPurpose() const;
    void setName();
    void setType();
    void setPayloadCapacity();
    void setPurpose();
    void PrintItem();
    bool operator<(const Rocket& other) const;
    bool operator>(const Rocket& other) const; 
};

