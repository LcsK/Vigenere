#include <iostream>
#include "Message.h"


using namespace std;

int main()
{
    while(true){
        string aux, aux1;
        getline(cin, aux);
        getline(cin, aux1);

        Message m;
        m.setDecrypted(aux);
        m.setKey(aux1);

        m.Encrypt();
        cout << m.getEncrypted();
    }
    return 0;
}
