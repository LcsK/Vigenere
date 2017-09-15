#include "Message.h"

Message::Message()
{
    this->setDecrypted("");
    this->setEncrypted("");
    this->setKey("");
}

bool Message::verifyKey(string *key)
{
    for (string::iterator it = (*key).begin(); it != (*key).end(); it++)
    {
        if( *it >= 65 && *it <= 90 )
            *it = *it + 32;
        else if( !(*it >= 97 && *it <= 122) && *it != 32 )
            return 0;
    }
    return 1;
}
void Message::Encrypt()
{
    char cAux, a, b;
    bool bAux;
    string encrypted="";
    if(this->getKey() == "" || this->getDecrypted() == "")
        return;
    for (string::iterator dIt = this->getDecrypted().begin(), kIt = this->getKey().begin(); dIt != this->getDecrypted().end(); dIt++)
    {
        bAux = false;
        cAux = *dIt;
        if( cAux >= 65 && cAux <= 90)
        {
            a = 65;
            b = 90;
            bAux = true;
            cAux = *kIt - 32;
        }
        else if( cAux >= 97 && cAux <= 122)
        {
            b = 97;
            b = 122;
            bAux = true;
            cAux = *kIt;
        }
        if (bAux)
        {
            cAux += *dIt - a;
            if(cAux > b)
                cAux -= 26;
            kIt++;
            if(kIt == this->getKey().end())
                kIt = this->getKey().begin();
        }
        this->setEncrypted(this->getEncrypted() + cAux);
    }
}
void Message::Decrypt()
{

}

string Message::getDecrypted()
{
    return this->decrypted;
}
void Message::setDecrypted(string decrypted)
{
    this->decrypted = decrypted;
}
string Message::getEncrypted()
{
    return this->encrypted;
}
void Message::setEncrypted(string encrypted)
{
    this->encrypted = encrypted;
}
string Message::getKey()
{
    return this->key;
}
bool Message::setKey(string key)
{
    if(this->verifyKey(&key))
        this->key = key;
    else
        return 0;
    return 1;
}
