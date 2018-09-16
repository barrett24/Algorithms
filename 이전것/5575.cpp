//
//  5575.cpp
//  baek
//
//  Created by Sean on 2018. 2. 25..
//  Copyright © 2018년 Sean. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    for (int i = 0; i < 3; i++) {
        int sh, sm, ss, eh, em, es;
        
        cin >> sh >> sm >> ss >> eh >> em >> es;
        
        if (es - ss < 0) {
            em -= 1, es = 60 + es - ss;
        }
        else {
            es = es - ss;
        }
        if (em - sm < 0) {
            eh -= 1, em = 60 + em - sm;
        }
        else {
            em = em - sm;
        }
        eh = eh - sh;
        cout << eh << " " << em << " " << es << '\n';
    }
    return 0;
}
