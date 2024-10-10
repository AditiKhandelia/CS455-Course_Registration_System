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

#include "course.cpp"

using namespace std;

class Schedule
{
    private:
    vector<Course> courses;
    public:
    void addCourse(Course course, int credits)
    {
        course.appliedCredits = credits;
        courses.push_back(course);
    }
    void displaySchedule()
    {
        printDelimiter();
        cout << "Schedule:" << endl;
        for(int i = 0; i < courses.size(); i++)
        {
            printDelimiter();
            courses[i].displayCourse();
            cout << "Credits: " << courses[i].appliedCredits << endl;
        }
    }
};

class ScheduleBuilder
{
    private:
    static ScheduleBuilder* instance;
    vector<Course> appliedCourses;
    vector<int> appliedCredits;
    Schedule schedule;

    ScheduleBuilder() {}
    public:
    static ScheduleBuilder* getInstance()
    {
        if(instance == nullptr)
        {
            instance = new ScheduleBuilder();
        }
        return instance;
    }
    void registerCourse(int courseID, int credits)
    {
        Course course = CourseStore::getInstance()->getCourse(courseID);
        appliedCourses.push_back(course);
        appliedCredits.push_back(credits);
    }
    void buildSchedule()
    {
        for(int i = 0; i < appliedCourses.size(); i++)
        {
            if(checkValidCourse(i)) schedule.addCourse(appliedCourses[i], appliedCredits[i]);
        }
    }
    bool checkValidCourse(int index)
    {
        Course course = appliedCourses[index];
        int credits = appliedCredits[index];
        int minCredits = course.getMinCredits();
        int maxCredits = course.getMaxCredits();
        return (credits >= minCredits && credits <= maxCredits);
    }
    void viewSchedule()
    {
        schedule.displaySchedule();
    }
};

ScheduleBuilder* ScheduleBuilder::instance = nullptr;