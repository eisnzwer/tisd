// MenuItem.h
#pragma once
#include <string>
#include <functional>

class MenuItem {
public:
    MenuItem(const std::string& label, std::function<void()> action);
    std::string getLabel() const;
    void execute() const;

private:
    std::string label;
    std::function<void()> action;
};
