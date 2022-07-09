#include <iostream>
#include "Kasumi.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");

    u64 data = 0x123456789abcdef0LLU;

    u8 key[16] =
    { 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f };

    Kasumi p;

    cout << "Текст: " << data << endl << endl;
    p.setKey(key);

    p.encryptBlock((u8*)&data);
    cout << "Зашифрованные данные: " << data << endl << endl;


    p.decryptBlock((u8*)&data);
    cout << "Расшифрованные данные: " << data << endl << endl;
	
	return 0;
}
