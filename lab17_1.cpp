//Write your code here
#include<iostream>
#include<string>
#include<fstream>
#include<cctype>
#include<vector>
using namespace std;

string upper(string s){
    string s1;
    for(int i=0;i<s.size();i++){
        s1 += toupper(s[i]);
    }
    return s1;
}

int main(){
    ifstream score("name_score.txt");
    vector<string> name1;
    vector<string> grade;
    vector<int> score1;
    string name;
    char name2[100] ;
    char format[]="%[^:]: %d %d %d";
    int num1,num2,num3;
    int sum;
    string want;
    while(getline(score, name)){
        
        sscanf(name.c_str(),format,name2 ,&num1 , &num2 ,&num3);
        name1.push_back(name2);
        sum = num1 + num2 + num3;
        score1.push_back(sum);
 
    }

    score.close();
    for(int i=0;i<score1.size();i++){
        if(score1[i]>=80) grade.push_back("A");
        else if(score1[i] >= 70 && score1[i]<=79) grade.push_back("B");
        else if(score1[i] >= 60 && score1[i]<=69) grade.push_back("C");
        else if(score1[i] >= 50 && score1[i]<=59) grade.push_back("D");
        else if(score1[i] < 50) grade.push_back("F");
    }
    
    int idx;
    while(1){
        int k=0;
        cout << "Please input your command :";
        getline(cin,want);
        idx = want.find_first_of(" ");
        string want1 = upper(want.substr(0,idx));
        string want2 = upper(want.substr(idx+1,want.size()-1));
        if(want1 == "NAME"){
            cout << "-----------------------------------------------\n";
            if(1){
                for(int i=0;i<name1.size();i++){
                    if(upper(want.substr(idx+1,want.size())) == upper(name1[i])){
                        cout << name1[i] << "'s grade = " << grade[i] <<endl;
                        k++;
                    }
                    
                }
                if(k==0) cout << "Cannot found." <<endl;
            }
            cout << "-----------------------------------------------\n";
                

        }else{
            if(want1 == "GRADE"){
                cout << "-----------------------------------------------\n";
                int c =0;
                if(1){
                    for(int i=0;i<name1.size();i++){
                        if(want2 == upper(grade[i])){
                           c++;
                            cout << name1[i] << "\n";
                        }
                    }
                    if(c==0) cout << "Cannot found." <<endl;
                }
                cout << "-----------------------------------------------\n";  
            }else{
                if(want1 == "EXIT") break;
                else cout << "Invalid command" <<endl;
            }
        }

    }
    return 0;
}