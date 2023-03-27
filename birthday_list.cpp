#include <iostream>
#include <vector>
using namespace std;

int main() 
{
    vector<vector<string>> birthdayList;
    while (true) 
    {
        cout << "please choose what you want to do:" << endl;
        cout << "1. create bithday list" << endl;
        cout << "2. edit birthday list" << endl;
        cout << "3. search data" << endl;
        cout << "4. monthly bithday list" << endl;
        cout << "5. Nothing(exit)" << endl;
        
        int n;
        cin >> n;
        
        // create 
        if (n == 1) 
        {
            string name, email, dob;
            cout << "please enter your name: ";
            cin >> name;
            cout << "please enter your email: ";
            cin >> email;
            cout << "please enter your date of birth in format(dd/mm/yyyy): ";
            cin >> dob;
            birthdayList.push_back({name, email, dob});
            cout << "data added successfully" << endl;
        } 
        
        // edit
        else if (n == 2) 
        {
            string email, newName, newdob;
            cout << "please enter email id of which you want to edit: ";
            cin >> email;
            
            bool flag = true;
            for (auto &person : birthdayList) 
            {
                if (person[1] == email) 
                {
                    newName = person[0];
                    newdob = person[2];
                    flag = false;
                }
            }
            if (flag) 
            {
                cout << "No data found" << endl;
                continue;
            }
            cout << "please choose what you want to edit: " << endl;   
            cout << "1. Edit name" << endl;
            cout << "2. Edit dob" << endl;
            int t;
            cin >> t;
            if (t == 1) 
            {
                cout << "please write the new name: ";
                cin >> newName;
            } 
            else if (t == 2) 
            {
                cout << "please write the new date in format(dd/mm/yyyy): ";
                cin >> newdob;
            } 
            else 
            {
                cout << "please enter valid number" << endl;
                continue;
            }
            
            for (int i = 0; i < birthdayList.size(); i++) 
            {
                if (birthdayList[i][1] == email) 
                {
                    if (birthdayList[i][0] != newName) 
                    {
                        birthdayList[i][0] = newName;
                    }
                    if (birthdayList[i][2] != newdob) 
                    {
                        birthdayList[i][2] = newdob;
                    }
                    break;
                }
            }
            cout << "edited successfully" << endl;
        }
        else if (n == 3) 
        {
            cout << "On which field you want to search:" << endl;
            cout << "1. Name" << endl;
            cout << "2. Email" << endl;
            cout << "3. DOB" << endl;
            int t;
            cin >> t;
            if (t == 1 || t == 2 || t == 3) 
            {
                cout << "Please enter the search items: ";
                string text;
                cin >> text;
                bool flag = false;
                for (int i = 0; i < birthdayList.size(); i++) 
                {
                    if (birthdayList[i][t-1] == text) 
                    {
                        cout << "Here are the details:" << endl;
                        cout << "Name: " << birthdayList[i][0] << endl;
                        cout << "Email: " << birthdayList[i][1] << endl;
                        cout << "DOB: " << birthdayList[i][2] << endl;
                        flag = true;
                        break;
                    }
                }
                if (!flag) 
                {
                    cout << "No data found" << endl;
                }
            }
            else 
            {
                cout << "Please enter valid number" << endl;
            }
        } 
        else if (n == 4) 
        {
            cout << "Please enter month number: " << endl;
            cout << "01. January" << endl;
            cout << "02. February" << endl;
            cout << "03. March" << endl;
            cout << "04. April" << endl;
            cout << "05. May" << endl;
            cout << "06. June" << endl;
            cout << "07. July" << endl;
            cout << "08. August" << endl;
            cout << "09. September" << endl;
            cout << "10. October" << endl;
            cout << "11. November" << endl;
            cout << "12. December" << endl;

            string t;
            cin >> t;

            bool flag = true;
            for (auto i : birthdayList) 
            {
                if (i[2].substr(3, 2) == t) 
                {
                    if (flag) 
                    {
                        cout << "List of names are: " << endl;
                    }
                    flag = false;
                    cout << i[0] << endl;
                }
            }

            if (flag) 
            {
                cout << "No data found" << endl;
            }
        }
        else if(n==5)
        {
            break;
        }
        else 
        {
            cout<<"Please enter a valid number"<<endl;
        }
    }
    return 0;
}
