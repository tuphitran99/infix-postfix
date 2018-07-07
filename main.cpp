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
 #include "mystack.cpp"
using namespace std;

int precedence(char s){
        if ( s == '^' ) return 3;
        else if ( s == '*' ) return 2;
        else if ( s == '/' ) return 2;
        else if ( s == '+' ) return 1;
        else if ( s == '-' ) return 1;
        else if ( s == '(' ) return 0;
        else return 0;
};
int priority(char st, char top){
        int a, b;
        a = precedence(st);
        b = precedence(top);

        return b-a;
};

void processData(){
        ifstream file;
        file.open("data.txt");
        string st;


        char temp;
        stack <char> stk(100);
        while (getline(file, st)) {

                for (int i = 0; i < st.length(); i++) {
                        else if ( st[i] == *(" ")) continue;    //skip blank

                        else{

                                if(isdigit(st[i])) {cout << st[i];}
                                else {
                                        if ( st[i]== *("(") ) {stk.push(st[i]);}
                                        else {

                                                if ( st[i]== *(")") ) {
                                                        /*   while (stk.topVal()!= '(') {
                                                                   stk.pop(temp);
                                                                   cout << temp;
                                                                   cout << "LINE: " << __LINE__<<endl;
                                                                   cout << "TOP: " << stk.items() << endl;
                                                           } */
                                                        stk.pop(temp);
                                                }
                                                else {
                                                        if (stk.isEmpty()) {stk.push(st[i]);}
                                                        else {
                                                                while (!stk.isEmpty() && priority(st[i], stk.topVal()) <=0) {
                                                                        stk.pop(temp);
                                                                        cout << temp;
                                                                        //cout << "LINE: " << __LINE__<<endl;

                                                                }
                                                                stk.push(st[i]);
                                                        }
                                                }
                                        }
                                }
                        }
                }

                while(!stk.isEmpty()) {
                        stk.pop(temp);
                        cout << temp;
                        //cout << "LINE: " << __LINE__<<endl;
                }

        }

        file.close();
}




int main(){
        processData();
        return 0;
}
