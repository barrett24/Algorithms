//
//  StringTokenizer.cpp
//  baek
//
//  Created by Sean on 2018. 5. 17..
//  Copyright © 2018년 Sean. All rights reserved.
//
#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class StringTokenizer
{
public:
    static vector<string> getTokens(const string& str, const string& delimiters="\t (),\"")//= " "
    {
        string::size_type lastPos = str.find_first_not_of(delimiters, 0); // 맨 처음 문자가 구분자일 때
        string::size_type pos = str.find_first_of(delimiters, lastPos);     // 구분자 찾기
        vector<string> tokens;
        while (string::npos != pos || string::npos != lastPos)
        {
            tokens.push_back(str.substr(lastPos, pos - lastPos+1)); // 찾은 token을 vector에 저장
            lastPos = str.find_first_not_of(delimiters, pos);// 구분자 다음으로 이동
            pos = str.find_first_of(delimiters, lastPos); // 다음구분자 찾기
        }
        return tokens;
    }
};

int main() {
    ifstream inf("/Users/sean/Desktop/baek/test.cpp");
    ofstream outf("/Users/sean/Desktop/test.txt");
    string instr;
    string def, re_def;
    vector<pair<string,string>> def_s;
    string tab = ";";
    int def_flag = 200;
    int i;
    
    while(getline(inf, instr)){
        vector<string> tokens = StringTokenizer::getTokens(instr);//토큰분리
        int N = (int)tokens.size();
        if(&instr.back() == tab)
            cout << "\t";
        
        for(i=0; i<N; i++){
            if(tokens[i] == "var "){
                tokens.erase(tokens.begin() + i);
                string temp = "&";
                tokens[i + 1] = temp + tokens[i + 1];
            }
            if(tokens[i] == "#include "){
                string temp = tokens[i+1];
                temp.pop_back();
                ifstream inclu("/Users/sean/Desktop/baek/example.h");
                //ifstream inclu(temp);
                tokens.erase(tokens.begin() + i);
                tokens.erase(tokens.begin() + i-1);
                char temp1;
                cout << temp << "의 내용 출력" << endl;
                
                while(inclu.get(temp1)){
                    cout << temp1;
                    outf << temp1;
                }
                inclu.close();
            }
            if(tokens[i] == "#define "){
                def = tokens[i+1];
                def.pop_back();
                re_def = tokens[i+2];
                def_s.push_back(make_pair(def, re_def));
                def_flag = i+1;
            }
            
            if(!def_s.empty()){
                int K = (int)def_s.size();
                for(int k=0; k<K; k++){
                    if(tokens[i].substr(0,def_s[k].first.size()) == def_s[k].first && i>def_flag){
                        string temp = &tokens[i].back();
                        tokens[i].pop_back();
                        tokens[i] = def_s[k].second + temp;
                    }
                }
            }
            cout << tokens[i];
            outf << tokens[i];
        }
        cout << endl; outf << endl;
        tokens.clear();
    }
    inf.close();
    outf.close();
    return 0;
}
