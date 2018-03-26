//bank.cpp --using the Queue interface
//compile with queue.cpp
#include <iostream>
#include <cstdlib>  //for rand() and srand()
#include <ctime>   //for time()
#include "queue.h"

const int MIN_PER_HR = 60;

bool newcustomer(double x);  //is there a new customer?

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;
    using std::ios_base;

    //seting things up
    std::srand(std::time(0));   //random initializing of rand()

    cout << "Case Study: Bank of Heather Autometic Teller\n";
    cout << "Enter maximum size of queue: ";
    int qs;
    cin >> qs;
    Queue line1(qs);
    Queue line2(qs);

    cout << "Enter the number of simulation hours: ";
    int hours;
    cin >> hours;

    long cyclelimit = MIN_PER_HR * hours;

    cout << "Enter the average number of customers per hour: ";
    double perhour;
    cin >> perhour;
    double min_per_cust;   //average time between arriavals
    min_per_cust = MIN_PER_HR / perhour;

    Item temp1,temp2;   //new customer data;
    long turnaways = 0;   //turned away by full queue;
    long customers = 0;   //joined the queue;
    long served1 = 0;      //served during the simulation
    long served2 = 0;
    long sum_line1 = 0;    //cumulative line length
    int wait_time1 = 0;    //time until autoteller is free
    long line_wait1 = 0;   //cumulatiive time in line;
    long sum_line2 = 0;    //cumulative line length
    int wait_time2 = 0;    //time until autoteller is free
    long line_wait2 = 0;   //cumulatiive time in line;

    for(int cycle = 0;cycle < cyclelimit;cycle++)
    {
        if(newcustomer(min_per_cust))  //have newcomer
        {
            if(line1.isfull() && line2.isfull())
                turnaways++;
            else
            {
                customers++;
                temp1.set(cycle);
                if(line1.queuecount() < line2.queuecount())
                    line1.enqueue(temp1);
                else
                    line2.enqueue(temp1);
            }
        }
        if(wait_time1<=0 &&!line1.isempty())
        {
            line1.dequeue(temp1);
            wait_time1 = temp1.ptime();
            line_wait1 += cycle - temp1.when();
            served1++;
        }
        if (wait_time2 <= 0 && !line2.isempty())
        {
            line2.dequeue(temp2);
            wait_time2 = temp2.ptime();
            line_wait2 += cycle - temp2.when();
            served2++;
        }
        if(wait_time1 > 0)
            wait_time1--;
        if (wait_time2 > 0)
            wait_time2--;
        sum_line1 += line1.queuecount();
        sum_line2 += line2.queuecount();
    }
    //reporting result
    if(customers > 0)
    {
        cout << "cusomers accepted : " << customers << endl;
        cout << " customers served: " << served1+served2 << endl;
        cout << "     turnaways: " << turnaways << endl;
        cout << "average queue size: " ;
        cout.precision(2);
        cout.setf(ios_base::fixed,ios_base::floatfield);
        cout << (double) sum_line1/cyclelimit << endl;
        cout << (double)sum_line2 / cyclelimit << endl;
        cout << " average wait time: " 
             << (double) line_wait1 / served1 << " minutes.\n" 
             << (double) line_wait2 / served2 << " minutes.\n";
    }
    else
        cout << "No customers!\n";
    cout << "Done!\n";

    return 0;
}

bool newcustomer(double x)
{
    return (std::rand() * x / RAND_MAX < 1); 
}
