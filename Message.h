#ifndef MESSAGE_H
#define MESSAGE_H
#include<string>

using namespace std;

class Message
{
    public:
        Message();
        void Encrypt();
        void Decrypt();
        string getDecrypted();
        void setDecrypted(string decrypted);
        string getEncrypted();
        void setEncrypted(string encrypted);
        string getKey();
        bool setKey(string key);

    private:
        string decrypted;
        string encrypted;
        string key;
        bool verifyKey(string *key);
};

#endif // MESSAGE_H
