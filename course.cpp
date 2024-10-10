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

using namespace std;

extern void printDelimiter();    
extern string getTime12HourFormat(int time);


class Course
{
    private:
    int courseID;
    string courseName;
    int minCredits;
    int maxCredits;
    int appliedCredits = 0;
    int startTime;
    int endTime;   

    public:
    Course(string courseName, int minCredits, int maxCredits, int startTime, int endTime)
    {
        this->courseName = courseName;
        this->minCredits = minCredits;
        this->maxCredits = maxCredits;
        this->startTime = startTime;
        this->endTime = endTime;
    }
    int getMinCredits()    
    {
        return minCredits;
    }
    int getMaxCredits()
    {
        return maxCredits;
    }
    void displayCourse()
    {
        printDelimiter();
        cout << "Course ID: " << courseID << endl;
        cout << "Course Name: " << courseName << endl;
        displayStartTime(); 
        displayEndTime();
    }
    void displayStartTime()
    {
        cout << "Start Time: " << getTime12HourFormat(startTime) << endl;
    }
    void displayEndTime()
    {
        cout << "End Time: " << getTime12HourFormat(endTime) << endl;
    }
    friend class Schedule;
    friend class CourseStore;
};

class CourseStore
{
    private:
    static CourseStore* instance ;
    vector<Course> courses;
    CourseStore() {} // constructor is private to prevent instantiation
    public:
    static CourseStore* getInstance()
    {
        if(instance == nullptr)
        {
            instance = new CourseStore();
        }
        return instance;
    }
    bool checkOverlap(Course course)
    {
        for(Course c : courses)
        {
            if(!(course.startTime <= c.startTime && course.endTime <= c.startTime) && !(course.startTime >= c.endTime && course.endTime >= c.endTime))
            {
                return true;
            }
        }
        return false;
    }
    bool addCourseIfNoOverlap(Course course)
    {
        if(checkOverlap(course))
        {
            printDelimiter();
            cout << "Course overlaps with existing course. Please try again." << endl;
            return false;
        }
        else
        {
            course.courseID = courses.size() + 1;
            courses.push_back(course);
            return true;
        }
    }
    void displayOfferedCourses()
    {
        for(Course course : courses)
        {
            course.displayCourse();
            cout << "Max Credits : " << course.maxCredits << endl;
            cout << "Min Credits : " << course.minCredits << endl;
        }
    }
    Course getCourse(int courseID)
    {
        return courses[courseID - 1];
    }
};

CourseStore* CourseStore::instance = nullptr;