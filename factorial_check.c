#include<iostream>

using namespace std;

bool factorial_check(int x, int y) {
	bool res = false;
	if(y <= 0) 
		return false;
	if(y < x) 
		return true;
	else {
		int bmap[x+1];
		bmap[0] = 0;
		bmap[1] = 0;
		for(int i = 2; i <= x; i++) {
			bmap[i] = 1;
		}

		int nf = y;


		do {

			bool changed = false;
			for (int i = x; (i > 1 && nf != 1) ; i--)
				if(((nf%i) == 0||i%nf==0) && bmap[i] == 1) {
					cout << "Old value of factor = " << nf << "("<<nf%i<<")("<<i<<")\n";
					if(nf%i == 0)
						nf = nf/i;
					else 
						nf = i/nf;
					changed = true;
					bmap[i] = 0;
					cout << "New value of factor = " << nf << "\n";
				}
			if(nf == 1 || changed == false)
			{
				cout << "Breaking\n";
				break;
			}
		} while(1);
		if(nf == 1)
			res = true;
	}
	return res;
}

int main() {
	
	int x, y;

	cout << "x:";
	cin >> x;
	cout <<"\ny:";
	cin >> y;
	cout << "\n" <<  factorial_check(x,y)<< "\n";
}
