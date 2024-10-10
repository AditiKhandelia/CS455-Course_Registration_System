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

#include "scheduler.cpp"
#include "course.cpp"

extern void printDelimiter();

using namespace std;

class Command
{
    public:
    virtual ~Command(); 
    virtual void execute() = 0;
};

Command::~Command() 
{
    ;
}

class AddCourseCommand : public Command
{
    private:
    string courseName;
    int minCredits;
    int maxCredits;
    int startTime;
    int endTime;
    public:
    void execute() override
    {
        acceptCourseDetails();
        Course course(courseName, minCredits, maxCredits, startTime, endTime);
        CourseStore* store = CourseStore::getInstance();
        store->addCourseIfNoOverlap(course);
    }
    void acceptCourseDetails()
    {
        printDelimiter();
        cout << "Enter the course name: ";
        cin.ignore();
        std::getline(cin, courseName);
        cout << "Enter the minimum credits: ";
        cin >> minCredits;
        cout << "Enter the maximum credits: ";
        cin >> maxCredits;
        cout << "Enter the start time: ";
        startTime = acceptTime();
        cout << "Enter the end time: ";
        endTime = acceptTime();
    }
    int acceptTime()
    {
        int time;
        cin >> time;
        if(time < 0 || time > 23)
        {
            cout << "Invalid time format. Please try again." << endl;
            return acceptTime();
        }
        return time;
    }
    ~AddCourseCommand() override
    {
        ;
    }
};

class DisplayCoursesCommand : public Command
{
    public:
    void execute() override
    {
        CourseStore* store = CourseStore::getInstance();
        store->displayOfferedCourses();
    }
    ~DisplayCoursesCommand() override
    {
        ;
    }
};

class RegisterCourseCommand : public Command
{
    private:
    int courseID;
    int credits;
    public:
    void execute() override
    {
        int courseCount = CourseStore::getInstance()->getCourseCount();
        acceptCourseID(courseCount);
        acceptCredits();
        ScheduleBuilder* scheduler = ScheduleBuilder::getInstance();
        scheduler->registerCourse(courseID, credits);
    }
    void acceptCourseID(int courseCount)
    {
        printDelimiter();
        cout << "Enter the course ID: ";
        cin >> courseID;
        if(courseID < 1 || courseID > courseCount)
        {
            cout << "Invalid course ID. Please try again." << endl;
            acceptCourseID(courseCount);
        }
    }
    void acceptCredits()
    {
        cout << "Enter the credits: ";
        cin >> credits;
    }
    ~RegisterCourseCommand() override
    {
        ;
    }
};

class BuildScheduleCommand : public Command
{
    public:
    void execute() override
    {
        ScheduleBuilder* scheduler = ScheduleBuilder::getInstance();
        scheduler->buildSchedule();
    }
    ~BuildScheduleCommand() override
    {
        ;
    }
};

class ViewScheduleCommand : public Command
{
    public:
    void execute() override
    {
        ScheduleBuilder* scheduler = ScheduleBuilder::getInstance();
        scheduler->viewSchedule();
    }
    ~ViewScheduleCommand() override
    {
        ;
    }
};
