#include "../User/User.h"

using namespace std; 

class Engineer : public User {
    private:
    wstring m_specialisation{};
    friend wostream& operator<<(wostream& eout, const Engineer& engineer);
    friend wistream& operator>>(wistream& ein, Engineer& engineer);
    
    public:
    void setSpecialisation();
    wstring getSpecialisation() const;
    void PrintInfo() override;
    bool operator<(const Engineer& other) const;
    bool operator>(const Engineer& other) const;
};

