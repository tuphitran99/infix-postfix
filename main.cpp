/*
   Tu Tran
   Programming II
   Due: July 2, 18
   Infix-Posfix
   Read math formula from file -> Print out infix-postfix
 */

/*if ( st[i]== *("^") ) st[i] = '3';
   else if ( st[i]== *("*") ) st[i] = '2';
   else if ( st[i]== *("/") ) st[i] = '2';
   else if ( st[i]== *("+") ) st[i] = '1';
   else if ( st[i]== *("-") ) st[i] = '1';
   else if ( st[i]== *(")") ) st[i] = '0';
   else if ( st[i]== *(" ") ) continue;*/
 #include <iostream>
 #include <fstream>
 #include <string>
 #include <stack>
using namespace std;

int precedence(char s){
        if ( s == '^' ) return 3;
        else if ( s == '*' ) return 2;
        else if ( s == '/' ) return 2;
        else if ( s == '+' ) return 1;
        else if ( s == '-' ) return 1;
        else if ( s == '(' ) return 0;
        //else if ( s == ' ' ) continue;
}
int priority(char st, char top){
        int a, b;
        a = precedence(st);
        b = precedence(top);

        return b-a;


};

char processData(){
        ifstream file;
        file.open("data.txt");
        string st;

        stack <char> stk;
        char temp;

        while (getline(file, st)) {
                for (int i = 0; i < st.length(); i++) {
                        if ( st[i] == *(" ") ) continue;  //skip blank
                        else{
                                if(isdigit(st[i])) {cout << st[i];}
                                else {
                                        if ( st[i]== *("(") ) {stk.push(st[i]);}
                                        else {
                                                if ( st[i]== *(")") ) {
                                                        while (stk.top()!= '(') {
                                                                temp = stk.pop();
                                                                cout << temp;

                                                        }
                                                        temp = stk.pop();
                                                }
                                                else {
                                                        if (stk.empty()) {stk.push(st[i]);}
                                                        else {
                                                                while (!stk.empty() && priority(st[i], stk.top()) <=0) {
                                                                        temp = stk.pop();
                                                                        cout << temp;

                                                                }
                                                                stk.push(st[i]);
                                                        }
                                                }
                                        }
                                }
                        }
                }
                while(!stk.empty()) {
                        temp = stk.pop();
                        cout << temp;

                }
        }

        file.close();
}




int main(){
        processData();
}
