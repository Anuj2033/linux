#include <iostream>
#include <string>
#include <map>
using namespace std;
int main()
{
    map<string, int> statePopulations;
    string city;


    // Populate the map with sample data
    statePopulations["California"] = 39538223;
    statePopulations["Texas"] = 28995881;
    statePopulations["Florida"] = 21477737;
    statePopulations["New York"] = 19453561;
    statePopulations["Pennsylvania"] = 12801989;

    map<string, int>::iterator it;
    for(it = statePopulations.begin(); it != statePopulations.end(); ++it){
        cout<<it->first<<" "<<it->second<<endl;
    }

    cout<<"Enter a city:";
    getline(cin, city);
    if(statePopulations.find(city) == statePopulations.end()){
        cout<<"Not found"<<endl;
    }else{
        cout<<city<<" with population "<<statePopulations.find(city)->second<<endl;
    }

    return 0;
}