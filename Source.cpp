//Day 3 Part 1
//Given a map where '.' represents snow and '#' represents a tree. Starting from the top left, 0,0 , moving 3 positions right and then one position down
//count how many trees you land on.

//For this we need to read in our map into a two dimensional array, this way we can use math to move through the array, the math is the x position plus 1
//and the y position plus 3, then we check that position in the array, if its a '.' we continue but if its '#' we increase our count and then continue, the 
//loop ends when the x position is > 31, or the y position is > 323.

//Part 2
//Using the same map, count the trees you land on using 5 different position pairs, then multiply the results for the answer

//For this since we are using the same array, we can just create a similar method to our solution for part one and make it take two parameters, one for
//the each of the positions.

#include <fstream>
#include <iostream>

char arr[323][31];

void inputToArray()
{
	char c;
	int x = 0;
	int y = 0;
	std::ifstream fin;
	fin.open("puzzle-input.txt", std::ios::in);
	while (!fin.eof())
	{
		fin.get(c);
		if (c == '\n')
		{
			y++;
			x = 0;
		}
		else
		{ 
			if (c == '.')
				arr[y][x] = '.';
			else
				arr[y][x] = '#';
			
			x++;
		}
	}
}

int findAnswerPart1()
{
	int answer = 0;
	int y = 1;
	int x = 3;
	while (y < 323)
	{		
		if (x > 30)
			x = x%31;
		std::cout << "y: " << y << " x: " << x << " char: " << arr[y][x] << '\n';
		if (arr[y][x] == '#')
			answer++;
		y++;
		x += 3;
		
	}
	return answer;
}

int findAnswerPart2(int right, int down)
{
	int answer = 0;
	int y = down;
	int x = right;
	while (y < 323)
	{
		if (x > 30)
			x = x % 31;
		//std::cout << "y: " << y << " x: " << x << " char: " << arr[y][x] << '\n';
		if (arr[y][x] == '#')
			answer++;
		y += down;
		x += right;

	}
	return answer;
}

int main()
{
	inputToArray();


	//for (int i = 0; i < 323; i++)
	//{
	//	std::cout << i << " : ";
	//	for (int j = 0; j < 31; j++)
	//	{
	//		std::cout << arr[i][j];
	//	}
	//	std::cout << '\n';
	//}

	//std::cout << "Done!" << '\n';

	std::cout << "Answer: " << findAnswerPart1() << '\n';

	int slope1 = findAnswerPart2(1, 1);
	int slope2 = findAnswerPart2(3, 1);
	int slope3 = findAnswerPart2(5, 1);
	int slope4 = findAnswerPart2(7, 1);
	int slope5 = findAnswerPart2(1, 2);
	unsigned int answer = slope1*slope2*slope3*slope4*slope5;

	std::cout << slope1 << " * " << slope2 << " * " << slope3 << " * " << slope4 << " * " << slope5 << " = " << answer << '\n';

	return 0;
}