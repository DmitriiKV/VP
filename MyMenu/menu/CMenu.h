#pragma once

#include <cstddef>
#include <string>
#include "./CMenuItem.h"

using namespace std;


class CMenu {
    public:
        CMenu(string, CMenuItem *, size_t);
        int getSelect() const;
        bool isRun() const;
        string getTitle();
        size_t getCount() const;
        CMenuItem *getItems();
        void print();
        int runCommand();

        // int CMenu::setSelect(int select) const {
        //     if (select < 1 or select > count) {
        //         m_select = select
        //     }
        // }

    private:
        int select{-1};
        size_t count{};
        bool running{};
        string title{};
        CMenuItem *items{};
};