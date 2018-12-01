#include "CPU.h"
#include <string>

using namespace std;

int main()
{
	string time;
	string queue = "";
	string q1 = "";
	string q2 = "";
	string cores = "";

	cout << "Tacts count: ";
	cin >> time;
	cout << "Queue size: ";
	cin >> queue;
	cout << "Task intensity: ";
	cin >> q1;
	cout << "Proc power: ";
	cin >> q2;
	cout << "Cores count: ";
	cin >> cores;

	TCPU p(stoi(queue), stoi(cores));
	auto s = p.Run(stod(q1.c_str()), stod(q2.c_str()), stoi(time));

	cout << "\n";
	cout << "Task count " << s.taskN << endl;
	cout << "Task rejected " << s.taskR << " or " << s.taskRCPU() << "% " << endl;
	cout << "Sleep time " << s.taskSl << " or " << s.taskSlCPU() << "% " << endl;

	system("pause");

	return 0;
}