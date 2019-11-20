#include <iostream>
#include <stack>
#include <queue>
#include <fstream>
#include "Data.h"

using namespace std;

int main() {
    stack <Data> s;
    queue <Data> q;
    priority_queue <Data, vector<Data>, greater<>> pq;

    //Initializes input and output streams
    ifstream in;
    ofstream stack;
    ofstream queue;
    ofstream sort;

    //Opens files
    in.open("videogamesales.csv");
    stack.open("stacked.txt");
    queue.open("queued.txt");
    sort.open("sorted.txt");

    //Checks to see if files have been opened properly
    if (!in.is_open()){
        cout << "Input file not opened correctly" << endl;
        return -1;
    }
    if (!stack.is_open()){
        cout << "Stack file not opened correctly" << endl;
        return -1;
    }
    if (!queue.is_open()){
        cout << "Queue file not opened correctly" << endl;
        return -1;
    }
    if (!sort.is_open()){
        cout << "Sort file not opened correctly" << endl;
        return -1;
    }

    string rank;
    string name;
    string year;
    string globalSales;

    //Reads in first line from dataset which contains the data description
    getline(in, rank, ',');
    getline(in, name, ',');
    getline(in, year, ',');
    getline(in, globalSales);

    stack << rank << " " << name << " " << year << " " << globalSales << endl;
    queue << rank << " " << name << " " << year << " " << globalSales << endl;
    sort << rank << " " << name << " " << year << " " << globalSales << endl;

    cout << "Reading ../videogamesales.csv..." << endl;
    while(!in.eof()){
        getline(in, rank, ',');
        getline(in, name, ',');
        getline(in, year, ',');
        getline(in, globalSales);

        //Creates new data object
        Data videoGame (stod(rank), name, stod(globalSales), stoi(year));

        //Pushes new data object to stack, queue, and priority queue
        s.push(videoGame);
        q.push(videoGame);
        pq.push(videoGame);
    }
    cout << "Writing data in stack inserted at head into stacked.txt" << endl;
    while (!s.empty())
    {
        stack << s.top();
        s.pop();
    }
    cout << "Writing data in queue inserted at tail into queue.txt" << endl;
    while (!q.empty())
    {
        queue << q.front();
        q.pop();
    }
    cout << "Writing data in sorted linked list sorted by year into sort.txt" << endl;
    while (!pq.empty())
    {
        sort << pq.top();
        pq.pop();
    }

    //Close files
    in.close();
    stack.close();
    queue.close();
    sort.close();

    return 0;
}