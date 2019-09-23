#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main()
{
	vector<vector<string>> days(31);
	vector<int> daysInMonth{ 31,28,31,30,31,30,31,31,30,31,30,31 };
	int Q;
	int next = 0;
	setlocale(LC_ALL, "Russian");
	cout << "Введите количество операций: ";
	cin >> Q;
	vector<vector<string>> commands(Q);
	string command, day, deal;
	for (int i = 0; i < Q; i++) {
		cin >> command;
		if (command == "ADD") {
			cin >> day >> deal;
			commands[i].push_back(command);
			commands[i].push_back(day);
			commands[i].push_back(deal);
		}
		if (command == "DUMP") {
			cin >> day;
			commands[i].push_back(command);
			commands[i].push_back(day);
		}
		if (command == "NEXT") {
			commands[i].push_back(command);
		}
	}
	for (int i = 0; i < Q; i++) {
		if (commands[i][0] == "ADD") {
			days[stoi(commands[i][1])-1].push_back(commands[i][2]);
		}
		if (commands[i][0] == "NEXT") {
			next++;
			if (next == 12) {
				next = 1;
			}
			if (daysInMonth[next] > daysInMonth[next - 1]) {
				for (int j = daysInMonth[next - 1]; j < daysInMonth[next] + 1; j++) {
					vector<string> oneDay;
					days.push_back(oneDay);
				}
			}
			if (daysInMonth[next] < daysInMonth[next - 1]) {
				vector<vector<string>> days1(daysInMonth[next]);
				for (int j = 0; j < days1.size(); j++) {
					days1[j] = days[j];
				}
				for (int j = 0; j < daysInMonth[next - 1] - daysInMonth[next]; j++) {
					if (days[daysInMonth[next] + j].size() != 0) {
						days1[days1.size() - 1].insert(end(days1[days1.size() - 1]), begin(days[daysInMonth[next] + j]), end(days[daysInMonth[next] + j]));
					}
				}
				days = days1;
			}
		}
		if (commands[i][0] == "DUMP") {
			cout << days[stoi(commands[i][1])-1].size() << "  ";
			for (int j = 0; j < days[stoi(commands[i][1])-1].size(); j++) {
				cout << days[stoi(commands[i][1])-1][j] << "  ";
			}
			cout << endl;
		}
	}
	system("pause");
	return 0;
}