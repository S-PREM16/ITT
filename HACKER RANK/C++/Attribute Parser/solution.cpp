#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
using namespace std;
int main()
 {
    int n, q;
    cin >> n >> q;
    cin.ignore(); 
    map<string, string> attributes;
    vector<string> tag_stack;
    for (int i = 0; i < n; i++) 
    {
        string line;
        getline(cin, line);
        if (line.substr(0, 2) == "</") 
        {
            if (!tag_stack.empty()) tag_stack.pop_back();
        } 
        else 
        {
            line = line.substr(1, line.length() - 2);
            stringstream ss(line);
            string tag_name;
            ss >> tag_name;
            if (tag_name.back() == '>') tag_name.pop_back();
            tag_stack.push_back(tag_name);
            string current_path = "";
            for (int j = 0; j < tag_stack.size(); j++) 
            {
                current_path += (j == 0 ? "" : ".") + tag_stack[j];
            }
            string attr_name, eq, attr_value;
            while (ss >> attr_name >> eq >> attr_value)
             {
                if (attr_value.back() == '>') attr_value.pop_back();
                attr_value = attr_value.substr(1, attr_value.length() - 2);
                attributes[current_path + "~" + attr_name] = attr_value;
            }
        }
    }
    for (int i = 0; i < q; i++)
     {
        string query;
        getline(cin, query);
        if (attributes.find(query) != attributes.end())
         {
            cout << attributes[query] << endl;
        } 
        else 
        {
            cout << "Not Found!" << endl;
        }
    }
    return 0;
}
