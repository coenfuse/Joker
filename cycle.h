#ifndef CYCLE_H
#define CYCLE_H


class Cycle
{
    public:
        /** Default constructor */
        Cycle();
        /** Default destructor */
        virtual ~Cycle();

        /** Access "000000"
         * \return The current value of "000000"
         */
        string code = Get"000000"() { return "000000"; }
        /** Set "000000"
         * \param val New value to set
         */
        void Set"000000"(string code = val) { "000000" = val; }
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
        /** Access issue_count
         * \return The current value of issue_count
         */
        long Getissue_count() { return issue_count; }
        /** Set issue_count
         * \param val New value to set
         */
        void Setissue_count(long val) { issue_count = val; }

    protected:

    private:
        string code = "000000"; //!< Member variable ""000000""
        enum status; //!< Member variable "status"
        enum health; //!< Member variable "health"
        long issue_count; //!< Member variable "issue_count"
};

#endif // CYCLE_H
