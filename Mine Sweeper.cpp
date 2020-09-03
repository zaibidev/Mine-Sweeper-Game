#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
class board
{
public:
	char box;
	bool mine;
	board()
	{
		box = '*';
		mine = false;
	}
	void display()
	{
		if (mine == true)
		{
			cout << '0';
		}
		else
		cout << box;
	}
};
void map_gen(board ** &map,int row,int col,int mine)  // for generating map
{
	map = new board *[row];
	for (int i = 0; i < row; i++)
	{
		map[i] = new board[col];
	}
	srand(time(0));
	for (int i = 0; i < mine; i++)
	{
		int j, k;
		j = rand()%row;
		k = rand() % col;
		if (map[j][k].mine == false)
		{
			map[j][k].mine = true;
		}
		else
		{
			i--;
		}
	}
}
void map_disp(board ** map, int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			map[i][j].display();
			cout << ' ';
		}
		cout << endl;
	}
	//rc
}
int main()
{
	int row, col, mine, input_row, input_column;
	int choice;
	cout << "Press 1 for Beginner Level." << endl;
	cout << "Press 2 for Intermediate Level." << endl;
	cout << "Press 3 for Advanced Level." << endl;
	cin >> choice;
	switch (choice)
	{
	case 1:
		row = 9; 
		col = 9;
		mine = 10;
		cout << "You choose Beginner Level." << endl;
		break;
	case 2:
		row = 16;
		col = 16;
		mine = 40;
		cout << "You choose Intermediate Level." << endl;
		break;
	case 3:
		row = 24;
		col = 24;
		mine = 99;
		cout << "You choose Advanced Level." << endl;
		break;
	}
	board **map;
	map_gen(map, row, col,mine);
	do
	{
		map_disp(map, row, col);
		cout << "Enter the row and column :" << endl;
		cin >> input_row >> input_column;
		if (map[input_row][input_column].mine == true)
		{
			cout << ".............You loose the game ............." << endl;
			input_row = -1;

		}
		else
		{
			map[input_row][input_column].box = '-';
		}
	} 
	while (input_row != -1 && input_column != -1);


	system("pause");
	return 0;
}