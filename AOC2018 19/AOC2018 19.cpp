#include <iostream>
#include <fstream>
#include <map>
#include <unordered_map>
#include <vector>
#include <string>
#include <math.h>
#include <climits>

using namespace std;

ifstream in("19.txt");

int ip, il;

void addr(vector<int> &rez, int a, int b, int c) {
	rez[c] = rez[a] + rez[b];
}
void addi(vector<int> &rez, int a, int b, int c) {
	rez[c] = rez[a] + b;
}
void mulr(vector<int> &rez, int a, int b, int c) {
	rez[c] = rez[a] * rez[b];
}
void muli(vector<int> &rez, int a, int b, int c) {
	rez[c] = rez[a] * b;
}
void banr(vector<int> &rez, int a, int b, int c) {
	rez[c] = rez[a] & rez[b];
}
void bani(vector<int> &rez, int a, int b, int c) {
	rez[c] = rez[a] & b;
}
void borr(vector<int> &rez, int a, int b, int c) {
	rez[c] = rez[a] | rez[b];
}
void bori(vector<int> &rez, int a, int b, int c) {
	rez[c] = rez[a] | b;
}
void setr(vector<int> &rez, int a, int b, int c) {
	rez[c] = rez[a];
}
void seti(vector<int> &rez, int a, int b, int c) {
	rez[c] = a;
}
void gtir(vector<int> &rez, int a, int b, int c) {
	rez[c] = a > rez[b];
}
void gtri(vector<int> &rez, int a, int b, int c) {
	rez[c] = rez[a] > b;
}
void gtrr(vector<int> &rez, int a, int b, int c) {
	rez[c] = rez[a] > rez[b];
}
void eqir(vector<int> &rez, int a, int b, int c) {
	rez[c] = a == rez[b];
}
void eqri(vector<int> &rez, int a, int b, int c) {
	rez[c] = rez[a] == b;
}
void eqrr(vector<int> &rez, int a, int b, int c) {
	rez[c] = rez[a] == rez[b];
}

struct instruction {
	string inst;
	int a, b, c;

	void do_instr(vector<int> &rez) {
		rez[il] = ip;
		if (this->inst == "addr") addr(rez, this->a, this->b, this->c);
		if (this->inst == "addi") addi(rez, this->a, this->b, this->c);
		if (this->inst == "mulr") mulr(rez, this->a, this->b, this->c);
		if (this->inst == "muli") muli(rez, this->a, this->b, this->c);
		if (this->inst == "banr") banr(rez, this->a, this->b, this->c);
		if (this->inst == "bani") bani(rez, this->a, this->b, this->c);
		if (this->inst == "borr") borr(rez, this->a, this->b, this->c);
		if (this->inst == "bori") bori(rez, this->a, this->b, this->c);
		if (this->inst == "setr") setr(rez, this->a, this->b, this->c);
		if (this->inst == "seti") seti(rez, this->a, this->b, this->c);
		if (this->inst == "gtir") gtir(rez, this->a, this->b, this->c);
		if (this->inst == "gtri") gtri(rez, this->a, this->b, this->c);
		if (this->inst == "gtrr") gtrr(rez, this->a, this->b, this->c);
		if (this->inst == "eqir") eqir(rez, this->a, this->b, this->c);
		if (this->inst == "eqri") eqri(rez, this->a, this->b, this->c);
		if (this->inst == "eqrr") eqrr(rez, this->a, this->b, this->c);


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

	while(ip < v.size()){
		v[ip].do_instr(reg);
		ip++;
	}

	cout << reg[0];

	return 0;
}
