//
//  Proto.cpp
//  baek
//
//  Created by Sean on 2018. 5. 17..
//  Copyright © 2018년 Sean. All rights reserved.
//

/*
 #include <iostream>
 #include <fstream>
 #include <string>
 #include <vector>
 using namespace std;
 
 int main() {
	//∆ƒ¿œ ¿‘∑¬
	ifstream inf("test.cpp");
	string instr;
	vector<string> tokens;
 
	while (!inf.eof()) {
 inf >> instr;
 tokens.push_back(instr);
	}
	inf.close();
 
	int N = tokens.size();
	for (int i = 0; i < N; i++) {
 //string temp = tokens[i];
 if (tokens[i] == "var") {//call-by-reference∑Œ ∫Ø∞Ê
 tokens.erase(tokens.begin() + i);
 string temp = "&";
 tokens[i + 2] = temp + tokens[i + 2];
 }
 if (tokens[i] == "#define") {//define √≥∏Æ
 vector<pair<string, string>> def;
 def.push_back(make_pair(tokens[i + 1], tokens[i + 2]));
 }
	}
 
	//∆ƒ¿œ √‚∑¬
	ofstream outf("test.txt");
	for (int i = 0; i < N; i++) {
 instr = tokens[i]+" ";
 outf << instr;
	}
	outf.close();
 
	return 0;
 }*/
#include "StringTokenizer.hpp"
#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main() {
    //∆ƒ¿œ ¿‘∑¬
    ifstream inf("/Users/sean/Desktop/baek/test.cpp");
    string instr;
    vector<string> tokens;
    
    while (!inf.eof()) {
        //inf >> instr;
        getline(inf, instr);
        //tokenizer(instr, tokens);
        tokens.push_back(instr);
        tokens.push_back("\n");
        if (instr == "\n")
            tokens.push_back("\n");
        if (instr == "\t")
            tokens.push_back("\t");
    }
    inf.close();
    
    int N = (int)tokens.size();
    for (int i = 0; i < N; i++) {
        string var = "var";
        if (tokens[i] == var) {//call-by-reference∑Œ ∫Ø∞Ê
            tokens.erase(tokens.begin() + i);
            string temp = "&";
            tokens[i + 2] = temp + tokens[i + 2];
        }
        if (tokens[i] == "#define") {//define √≥∏Æ
            vector<pair<string, string>> def;
            def.push_back(make_pair(tokens[i + 1], tokens[i + 2]));
        }
    }
    
    //∆ƒ¿œ √‚∑¬
    ofstream outf("/Users/sean/Desktop/test.txt");
    for (int i = 0; i < N; i++) {
        instr = tokens[i];
        if (instr == "\n")
            continue;
        else
            instr = tokens[i] + " ";
        cout << instr<< "토큰";
        outf << instr << "토큰";
    }
    outf.close();
    
    return 0;
}
