#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;
// Function to find longest common prefix
string commonPrefix(vector<string> v)
{
    if (v.empty())
        return "";
    string prefix = v[0];
    for (int i = 1; i < v.size(); i++)
    {
        string s = v[i];
        int j = 0;
        while (j < prefix.size() && j < s.size() && prefix[j] == s[j])
            j++;
        prefix = prefix.substr(0, j);
    }
    return prefix;
}
int main()
{
    string production;
    cout << "Enter Production (e.g. S->abX|abY|abZ|a): ";
    getline(cin, production);
    // Split LHS and RHS
    int pos = production.find("->");
    string lhs = production.substr(0, pos);
    string rhs = production.substr(pos + 2);
    // Split RHS by '|'
    stringstream ss(rhs);
    vector<string> prods;
    string temp;
    while (getline(ss, temp, '|'))
        prods.push_back(temp);
    string prefix = commonPrefix(prods);
    cout << "\n=== Left Factored Grammar ===\n";
    if (prefix == "" || prefix.size() == 0)
    {
        // No factoring needed
        cout << production << endl;
    }
    else
    {
        string newNT = lhs + "'";
        cout << lhs << " -> " << prefix << newNT << endl;
        cout << newNT << " -> ";
        for (int i = 0; i < prods.size(); i++)
        {
            string beta = prods[i].substr(prefix.size());
            if (beta == "")
                beta = "ε"; // handle empty suffix
            cout << beta;
            if (i != prods.size() - 1)
                cout << " | ";
        }
        cout << endl;
    }
    return 0;
}
