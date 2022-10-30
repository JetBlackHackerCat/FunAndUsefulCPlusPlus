#include "../../Ch15/Security.cpp"

int main() {

	vector<string> tempPasses = GenerateBrutePasswordList(10);

	for (auto t = tempPasses.begin() ; t != tempPasses.end(); t++)
	{
		cout << *t + "\n";
	}

	return 0;

}