#include<iostream>
#include<vector>
#include<fstream>

using namespace std;

//Class Person
class Person
{
private:
    //Attributes of Person
    int birth_year; //birth year
    int death_year; //death year
    string name;    //name

public:
    //Constructor to initialize the attributes of Person
    Person(int birth_year, int death_year, string name)
    {
        this->birth_year = birth_year;
        this->death_year = death_year;
        this->name = name;
    }

    //Getters to get attributes of Person Class
    int getBirthYear() const
    {
        return birth_year;
    }

    int getDeathYear() const
    {
        return death_year;
    }

    string getName() const
    {
        return name;
    }
};

//Class to store record of person
class PersonRecord
{
private:
    //Vector of Person objects
    vector<Person> record;

public:
    //Constructor
    PersonRecord()
    {
        //open file in reading mode
        ifstream in("people.txt");

        //if file opened successfully then read records
        if (in.is_open())
        {
            readRecords();
        }
        //Otherwise exit program
        else
        {
            exit(0);
        }
    }

    //Function to read records from file
    void readRecords()
    {
        //open file people.txt in reading mode
        ifstream in("people.txt");

        //varibales to store data of a person
        int birth_year, death_year;
        string name;

        //read all records from file
        while (in >> birth_year >> death_year >> name)
        {
            //read record and push into vector or Person object
            record.push_back(Person(birth_year, death_year, name));
        }
    }

    //function to display people of specific year
    void displayPeople(int year)
    {
        //Display people alive in that year
        cout << "* People alive in " << year << ":" << endl;
        for (unsigned int i = 0; i < record.size(); i++)
        {
            if (year >= record[i].getBirthYear() && year <= record[i].getDeathYear())
            {
                cout << record[i].getName() << " (" << record[i].getBirthYear() << "-" << record[i].getDeathYear() << ")\n";
            }
        }
    }
};

int main()
{
    //Person record
    PersonRecord record;
    int year;
    
    //get input years from standard input and display people
    while (cin >> year)
    {
        record.displayPeople(year);
    }

    return 0;
}
