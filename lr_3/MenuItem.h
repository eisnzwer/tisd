#ifndef MENU_ITEM_H
#define MENU_ITEM_H

#include <string>
#include <functional>

class MenuItem {
public:
    MenuItem(std::string label, std::function<void()> action);

    void execute();
    std::string getLabel() const;

private:
    std::string label;
    std::function<void()> action;
};

#endif
