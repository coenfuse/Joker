#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <User.h>


class Employee : public User
{
    public:
        /** Default constructor */
        Employee();
        /** Default destructor */
        virtual ~Employee();

        /** Access "0000-000-000"
         * \return The current value of "0000-000-000"
         */
        string eid = Get"0000-000-000"() { return "0000-000-000"; }
        /** Set "0000-000-000"
         * \param val New value to set
         */
        void Set"0000-000-000"(string eid = val) { "0000-000-000" = val; }
        /** Access profile
         * \return The current value of profile
         */
        enum Getprofile() { return profile; }
        /** Set profile
         * \param val New value to set
         */
        void Setprofile(enum val) { profile = val; }
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
        string eid = "0000-000-000"; //!< Member variable ""0000-000-000""
        enum profile; //!< Member variable "profile"
        int login_count; //!< Member variable "login_count"
};

#endif // EMPLOYEE_H
