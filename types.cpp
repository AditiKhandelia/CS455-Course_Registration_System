enum Role
{
    STUDENT = 1,
    ADMINISTRATOR,
    EXIT
};

namespace AdministratorOption
{
    enum AdministratorOption
    {
        ADD_COURSE = 1,
        DISPLAY_COURSES,
        ADMINISTRATOR_EXIT
    };
};

namespace StudentOption
{
    enum StudentOption
    {
        DISPLAY_COURSES = 1,
        REGISTER_COURSE,
        BUILD_SCHEDULE,
        VIEW_SCHEDULE,
        STUDENT_EXIT
    };
};