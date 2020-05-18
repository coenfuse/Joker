#ifndef USER_H
#define USER_H


class User
{
    public:
        /** Default constructor */
        User();
        /** Default destructor */
        virtual ~User();

        /** Access bid
         * \return The current value of bid
         */
        string Getbid() { return bid; }
        /** Set bid
         * \param val New value to set
         */
        void Setbid(string val) { bid = val; }
        /** Access name
         * \return The current value of name
         */
        string Getname() { return name; }
        /** Set name
         * \param val New value to set
         */
        void Setname(string val) { name = val; }
        /** Access address
         * \return The current value of address
         */
        string Getaddress() { return address; }
        /** Set address
         * \param val New value to set
         */
        void Setaddress(string val) { address = val; }
        /** Access phone1
         * \return The current value of phone1
         */
        string Getphone1() { return phone1; }
        /** Set phone1
         * \param val New value to set
         */
        void Setphone1(string val) { phone1 = val; }
        /** Access phone2
         * \return The current value of phone2
         */
        string Getphone2() { return phone2; }
        /** Set phone2
         * \param val New value to set
         */
        void Setphone2(string val) { phone2 = val; }
        /** Access email
         * \return The current value of email
         */
        string Getemail() { return email; }
        /** Set email
         * \param val New value to set
         */
        void Setemail(string val) { email = val; }
        /** Access dept
         * \return The current value of dept
         */
        string Getdept() { return dept; }
        /** Set dept
         * \param val New value to set
         */
        void Setdept(string val) { dept = val; }
        /** Access acc_status
         * \return The current value of acc_status
         */
        enum Getacc_status() { return acc_status; }
        /** Set acc_status
         * \param val New value to set
         */
        void Setacc_status(enum val) { acc_status = val; }
        /** Access issue_status
         * \return The current value of issue_status
         */
        enum Getissue_status() { return issue_status; }
        /** Set issue_status
         * \param val New value to set
         */
        void Setissue_status(enum val) { issue_status = val; }

        enum acc_status; //!< Member variable "acc_status"
        enum issue_status; //!< Member variable "issue_status"

    protected:

    private:
        string bid; //!< Member variable "bid"
        string name; //!< Member variable "name"
        string address; //!< Member variable "address"
        string phone1; //!< Member variable "phone1"
        string phone2; //!< Member variable "phone2"
        string email; //!< Member variable "email"
        string dept; //!< Member variable "dept"
};

#endif // USER_H
