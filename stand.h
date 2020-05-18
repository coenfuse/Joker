#ifndef STAND_H
#define STAND_H


class Stand
{
    public:
        /** Default constructor */
        Stand();
        /** Default destructor */
        virtual ~Stand();

        /** Access transactions
         * \return The current value of transactions
         */
        long Gettransactions() { return transactions; }
        /** Set transactions
         * \param val New value to set
         */
        void Settransactions(long val) { transactions = val; }
        /** Access sid
         * \return The current value of sid
         */
        string Getsid() { return sid; }
        /** Set sid
         * \param val New value to set
         */
        void Setsid(string val) { sid = val; }
        /** Access location
         * \return The current value of location
         */
        string Getlocation() { return location; }
        /** Set location
         * \param val New value to set
         */
        void Setlocation(string val) { location = val; }
        /** Access capacity
         * \return The current value of capacity
         */
        short Getcapacity() { return capacity; }
        /** Set capacity
         * \param val New value to set
         */
        void Setcapacity(short val) { capacity = val; }

    protected:

    private:
        long transactions; //!< Member variable "transactions"
        string sid; //!< Member variable "sid"
        string location; //!< Member variable "location"
        short capacity; //!< Member variable "capacity"
};

#endif // STAND_H
