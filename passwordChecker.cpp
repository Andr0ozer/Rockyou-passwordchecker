#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

#define ROCKYOUPATH "rockyou.txt"

int main(int argc, char** argv)
{
    ifstream infile, passwordfile;
    vector<string> passwords, found_passwords, rockyou;
    string current_password;

    if(argc != 2)
    {
        cout << "Please provide one file as an argument." << endl;
        return 0;
    }
    
    infile.open(ROCKYOUPATH);
    if (!infile)
    {
        cout << "There was an error opening rockyou.txt!" << endl;
        return 0;
    }

    passwordfile.open(argv[1]);
    if (!passwordfile)
    {
        cout << "There was an error opening rockyou.txt!" << endl;
        return 0;
    }

    cout << "Files opened successfully! Checking passwords against rockyou.txt. Please wait..." << endl << endl <<endl;

    while (getline(infile, current_password))
	{
        rockyou.push_back(current_password);
    }
    while (getline(passwordfile, current_password))
    {
        passwords.push_back(current_password);
    }

    for(int i = 0; i < passwords.size(); i++)
    {
        for (int j = 0; j < rockyou.size(); j++)
        {
            if(passwords[i] == rockyou[j])
            {
                found_passwords.push_back(passwords[i]);
                j = rockyou.size();
            }
        }
    }
    if (found_passwords.size() == 0)
    {
        cout << "Your passwords were not found in rockyou.txt" << endl;
    }
    else
    {
        ofstream file("foundpasswords.txt");
        file << "Your found passwords are:\n";
        for(int i = 0; i < found_passwords.size(); i++)
        {
            file << found_passwords[i] << "\n";
        }
        file.close();
        cout << "Some of your passwords were found in rockyou.txt" << endl << "The found passwords have been stored in foundpasswords.txt" << endl;
    }
    return 0;    
}
