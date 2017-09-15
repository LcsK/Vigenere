#include <iostream>
#include "Message.h"

using namespace std;

int main()
{
    while(true){
        string aux, aux1;
        getline(cin, aux);
        cout << aux << endl;
        getline(cin, aux1);
        cout << aux1 << endl;
        Message m;
        m.setDecrypted(aux);
        m.setKey(aux1);
        m.Encrypt();
        cout << m.getEncrypted();
    }
    /*while(true){
    std::string aux;
    getline(cin, aux);
    cout << aux << endl;
    cout << aux.length() << endl << endl;
    Message m;
    cout << m.verifyKey(aux) <<endl <<endl;
    }
    /*Message m;
    cout << m.getEncrypted() << endl;
    cout << m.getDecrypted() << endl;
    cout << m.getKey() << endl;
    m.setDecrypted("nao cript");
    m.setEncrypted("cript");
    m.setKey("chave");
    cout << m.getEncrypted() << endl;
    cout << m.getDecrypted() << endl;
    cout << m.getKey() << endl;*/
    return 0;
}
