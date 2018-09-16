//
//  10814.cpp
//  baek
//
//  Created by Sean on 2017. 9. 7..
//  Copyright © 2017년 Sean. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
struct Person{
    int age;
    string name;
};
bool cmp(const Person &u, const Person &v){
    return u.age < v.age;
}
int main(){
    int n;
    cin >> n;
    vector<Person> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i].age >> a[i].name;
    }
    stable_sort(a.begin(), a.end(), cmp);
    for(int i=0; i<n; i++){
        cout << a[i].age << ' ' << a[i].name << endl;
    }
    return 0;
}
