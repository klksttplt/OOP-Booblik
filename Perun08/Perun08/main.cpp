#include "Screen.h"
#include <iostream>
using namespace std;

int main()
{
	cout << "--------->Creating screen:" << endl;
	int w1 = 10, h1 = 10;
	char str1[] = "what a beutiful screen";
	Screen screen(w1, h1, str1);
	screen.show();
	cout << "--------->Changing content:" << endl;
	screen.set('!').move(1, 1).set('!').move(2, 2).set('!').move(3, 3).set('!').show();
	
	cout << "--------->First 10 symbols:" << endl;
	for (int i = 0; i <10; i++)
	{
		screen.move(i, 0).showCurrent();
	}
	const NonConstAction menuNonConst[] = { &Screen::home, &Screen::move, &Screen::back, &Screen::clear, &Screen::show };
	const ConstAction constMenu[] = { &Screen::home, &Screen::move, &Screen::back, &Screen::show, &Screen::showCurrent };
	
	cout << "--------->Constant actions:" << endl;
	int w2 = 10, h2 = 10;
	char str2[] = "lisa prosto super";
	const Screen constScreen(w2, h2, str2);
	int k, n;
	char ch;
	constScreen.show();
	do {
		cout << "your action?(0-home:1-move:2-back:3-show:4-showCurrent): ";
		cin >> k;
		while (k < 0 || k > 4)
		{
			cout << "index must be from 0 to 4: ";
			cin >> k;
		}
		cout << "multiplicity? ";
		cin >> n;
		while (n <= 0)
		{
			cout << "index must be greater than 0: ";
			cin >> n;
		}
		doActionConst(constScreen, constMenu[k], n);
		cout << endl << "Repeat (y/n)?";
		cin >> ch;
	} while (ch == 'y');

	cout << "--------->Non-constant actions:" << endl;

	Screen nonConstScreen(w2, h2, str2);
	nonConstScreen.show();
	do {
		cout << "your action?(0-home, 1-move, 2-back, 3-clear, 4-show): ";
		cin >> k;
		while (k < 0 || k > 4)
		{
			cout << "index must be from 0 to 4: ";
			cin >> k;
		}
		cout << "multiplicity? ";
		cin >> n;
		while (n <= 0)
		{
			cout << "index must be greater than 0: ";
			cin >> n;
		}
			doActionNonConst(nonConstScreen, menuNonConst[k], n);
			cout << endl << "Repeat (y/n)?";
			cin >> ch;
	} while (ch == 'y');
	return 0;
}