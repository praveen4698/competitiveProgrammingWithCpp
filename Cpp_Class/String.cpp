#include<iostream>

class String {
    
        char* data;
        unsigned length;

    public:
        String() {
            length = 0;
            data = new char[0];
        }

        String(char c) {
            length = 1;
            data = new char(c);
        }

        String(const char *c){
            if(c) {
                unsigned n = 0;
                while(c[n] != '\0') n++;
                length = n;
                data = new char[n];
                for( unsigned j=0;j<n;j++ ){
                    data[j] = c[j];
                }
            }
            else{
                length = 0;
                data = new char[0];
            }
        }

        String(const String &s) {
            length = s.len();
            data = new char[length];
            for(unsigned j=0;j<length;j++) {
                data[j] = s[j];
            }
        }

        ~String() {
            delete[] data;
        }

        unsigned len() const {
            return length;
        }

        int index(char c) const {
            for( unsigned j=0;j<length;j++) {
                if( data[j] == c)
                    return (int)j;
            }
            return -1;
        }

};