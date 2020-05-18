#ifndef STUDENT_H
#define STUDENT_H

#include <User.h>


class Student : public User
{
    public:
        /** Default constructor */
        Student();
        /** Default destructor */
        virtual ~Student();

        /** Access "1234-567-890"
         * \return The current value of "1234-567-890"
         */
        string enr = Get"1234-567-890"() { return "1234-567-890"; }
        /** Set "1234-567-890"
         * \param val New value to set
         */
        void Set"1234-567-890"(string enr = val) { "1234-567-890" = val; }
        /** Access course
         * \return The current value of course
         */
        string Getcourse() { return course; }
        /** Set course
         * \param val New value to set
         */
        void Setcourse(string val) { course = val; }
        /** Access login_count
         * \return The current value of login_count
         */
        int Getlogin_count() { return login_count; }
        /** Set login_count
         * \param val New value to set
         */
        void Setlogin_count(int val) { login_count = val; }

    protected:

    private:
        string enr = "1234-567-890"; //!< Member variable ""1234-567-890""
        string course; //!< Member variable "course"
        int login_count; //!< Member variable "login_count"
};

#endif // STUDENT_H
