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
    int join;
};
int main(){
    int n;
    cin >> n;
    vector<Person> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i].age >> a[i].name;
        a[i].join = i;
    }
    sort(a.begin(), a.end(), [](Person u, Person v) {
        return (u.age < v.age) || (u.age == v.age && u.join < v.join);
    });
    for(auto p : a){
        cout << p.age << ' ' << p.name << endl;
    }
    return 0;
}
