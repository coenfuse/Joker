#ifndef LOCK_H
#define LOCK_H


class Lock
{
    public:
        /** Default constructor */
        Lock();
        /** Default destructor */
        virtual ~Lock();

        /** Access code
         * \return The current value of code
         */
        string Getcode() { return code; }
        /** Set code
         * \param val New value to set
         */
        void Setcode(string val) { code = val; }
        /** Access password
         * \return The current value of password
         */
        int Getpassword() { return password; }
        /** Set password
         * \param val New value to set
         */
        void Setpassword(int val) { password = val; }
        /** Access status
         * \return The current value of status
         */
        enum Getstatus() { return status; }
        /** Set status
         * \param val New value to set
         */
        void Setstatus(enum val) { status = val; }
        /** Access health
         * \return The current value of health
         */
        enum Gethealth() { return health; }
        /** Set health
         * \param val New value to set
         */
        void Sethealth(enum val) { health = val; }

    protected:

    private:
        string code; //!< Member variable "code"
        int password; //!< Member variable "password"
        enum status; //!< Member variable "status"
        enum health; //!< Member variable "health"
};

#endif // LOCK_H
