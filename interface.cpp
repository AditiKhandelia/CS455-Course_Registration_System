#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <utility>
#include <unordered_map>

extern void printDelimiter();

#include "commands.cpp"
#include "types.cpp"

using namespace std;

class Interface 
{
    public:
    void runInterface() 
    {
        showWelcomeMessage();
        while (true) 
        {
            showNavigationMenu();
            getUserSelection();
            if(checkExitCondition()) 
            {
                break;
            }
            executeOption();
        }
        performExit();
    }

    protected:
    virtual ~Interface() {}
    virtual void showWelcomeMessage() = 0;
    virtual void showNavigationMenu() = 0;
    virtual void getUserSelection() = 0;
    virtual int checkExitCondition() = 0;
    virtual void executeOption() = 0;
    unordered_map<int, Command*> commands;

    private:
    virtual void performExit() 
    {
        printDelimiter();
        cout << "Returning to previous menu." << endl;
    }
};

class StudentInterface : public Interface
{
    private: 
    StudentOption::StudentOption option;
    public:
    StudentInterface()
    {
        commands[StudentOption::DISPLAY_COURSES] = new DisplayCoursesCommand();
        commands[StudentOption::REGISTER_COURSE] = new RegisterCourseCommand();
        commands[StudentOption::BUILD_SCHEDULE] = new BuildScheduleCommand();
        commands[StudentOption::VIEW_SCHEDULE] = new ViewScheduleCommand();
    }
    void showWelcomeMessage() override
    {
        printDelimiter();
        cout << "Student Interface" << endl;
    }
    void showNavigationMenu() override
    {
        printDelimiter();
        cout << "Select an option:" << endl;
        cout << "1. Display Courses" << endl;
        cout << "2. Register Course" << endl;
        cout << "3. Build Schedule" << endl;
        cout << "4. View Schedule" << endl;
        cout << "5. Exit" << endl;
    }
    void getUserSelection() override
    {
        printDelimiter();
        int choice;
        cout << "Enter your selection: ";
        cin >> choice;
        if(choice == StudentOption::DISPLAY_COURSES || choice == StudentOption::REGISTER_COURSE || choice == StudentOption::BUILD_SCHEDULE || choice == StudentOption::STUDENT_EXIT || choice == StudentOption::VIEW_SCHEDULE)
        {
            option = static_cast<StudentOption::StudentOption>(choice);
        }
        else
        {
            cout << "Invalid selection. Please try again." << endl;
            getUserSelection();
        }
    }
    int checkExitCondition() override
    {
        return option == StudentOption::STUDENT_EXIT;
    }
    void executeOption() override
    {
        commands[option]->execute();
    }
};

class AdministratorInterface : public Interface
{
    private:
    AdministratorOption::AdministratorOption option;
    public:
    AdministratorInterface()
    {
        commands[AdministratorOption::ADD_COURSE] = new AddCourseCommand();
        commands[AdministratorOption::DISPLAY_COURSES] = new DisplayCoursesCommand();
    }
    void showWelcomeMessage() override
    {
        printDelimiter();
        cout << "Administrator Interface" << endl;
    }
    void showNavigationMenu() override
    {
        printDelimiter();
        cout << "Select an option:" << endl;
        cout << "1. Add Course" << endl;
        cout << "2. Display Courses" << endl;
        cout << "3. Exit" << endl;
    }
    void getUserSelection() override
    {
        printDelimiter();
        int choice;
        cout << "Enter your selection: ";
        cin >> choice;
        if(choice == AdministratorOption::ADD_COURSE || choice == AdministratorOption::DISPLAY_COURSES || choice == AdministratorOption::ADMINISTRATOR_EXIT)
        {
            option = static_cast<AdministratorOption::AdministratorOption>(choice);
        }
        else
        {
            cout << "Invalid selection. Please try again." << endl;
            getUserSelection();
        }
    }
    int checkExitCondition() override
    {
        return option == AdministratorOption::ADMINISTRATOR_EXIT;
    }
    void executeOption() override
    {
        commands[option]->execute();
    }
};

class MainInterface : public Interface
{
    private:
    Role role;
    public:
    MainInterface()
    {
        ;
    }
    protected:
    void showWelcomeMessage() override
    {
        printDelimiter();
        cout << "Welcome to the Course Registration System!" << endl;
    }
    void showNavigationMenu() override 
    {
        printDelimiter();
        cout << "Select a role:" << endl;
        cout << "1. Student" << endl;
        cout << "2. Administrator" << endl;
        cout << "3. Exit" << endl;
    }
    void getUserSelection() override 
    {
        printDelimiter();
        int option;
        cout << "Enter your selection: ";
        cin >> option;
        if(option == STUDENT || option == ADMINISTRATOR || option == EXIT)
        {
            role = static_cast<Role>(option);
        }
        else
        {
            cout << "Invalid selection. Please try again." << endl;
            getUserSelection();
        }
    }
    int checkExitCondition() override 
    {
        return role == EXIT;
    }
    void executeOption() override
    {
        if(role == STUDENT)
        {
            StudentInterface studentInterface;
            studentInterface.runInterface();
        }
        else if(role == ADMINISTRATOR)
        {
            AdministratorInterface administratorInterface;
            administratorInterface.runInterface();
        }
    }
    // Main Interface should exit application
    virtual void performExit() override
    {
        printDelimiter();
        cout << "Exiting the Course Registration System." << endl;
        printDelimiter();
        exit(0);
    }
};

