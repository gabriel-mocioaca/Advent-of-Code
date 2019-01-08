#include <bits/stdc++.h>
using namespace std;

ifstream in("in.txt");

int ip, il;

struct instruction {
	string inst;
	int a, b, c;

	void do_instr(vector<int> &rez) {
		rez[il] = ip;

		if (this->inst == "addr") rez[c] = rez[a] + rez[b];
		if (this->inst == "addi") rez[c] = rez[a] + b;
		if (this->inst == "mulr") rez[c] = rez[a] * rez[b];
		if (this->inst == "muli") rez[c] = rez[a] * b;
		if (this->inst == "banr") rez[c] = rez[a] & rez[b];
		if (this->inst == "bani") rez[c] = rez[a] & b;
		if (this->inst == "borr") rez[c] = rez[a] | rez[b];
		if (this->inst == "bori") rez[c] = rez[a] | b;
		if (this->inst == "setr") rez[c] = rez[a];
		if (this->inst == "seti") rez[c] = a;
		if (this->inst == "gtir") rez[c] = a > rez[b];
		if (this->inst == "gtri") rez[c] = rez[a] > b;
		if (this->inst == "gtrr") rez[c] = rez[a] > rez[b];
		if (this->inst == "eqir") rez[c] = a == rez[b];
		if (this->inst == "eqri") rez[c] = rez[a] == b;
		if (this->inst == "eqrr") rez[c] = rez[a] == rez[b];

		ip = rez[il];

	}
};

int main() {
	vector<int> reg(6, 0);
	vector<instruction> v;
	string trash;
	string inst;
	int a, b, c;
	ip = 0;
	in >> trash;
	in >> il;

	while (!in.eof()) {
		in >> inst;
		in >> a >> b >> c;
		v.push_back({ inst, a, b, c });
	}

	reg[0] = 0;
	set<int> stuff;

	int last;

	while (ip < v.size()) {
		v[ip].do_instr(reg);
		ip++;;
		if (ip == 28) {
			if (stuff.find(reg[1]) != stuff.end())
				break;
			else {
				stuff.insert(reg[1]);
				last = reg[1];
			}
		}
	}

	cout << last;

	return 0;
}
