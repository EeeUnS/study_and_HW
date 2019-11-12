#include<iostream>
#include<algorithm>

//안정정렬 : 같은값일때 그 값의 순서를 바꾸지않음 
//불안정정렬 : 바꿈


struct date_operator
{
	int year;
	int month;
	int day;
	void print()
	{
		std::cout << year << " " << month << " " << day << std::endl;
	}
	bool operator<(date_operator &back)
	{
		if (this->year == back.year && this->month == back.month)
		{
			return this->day < back.day;
		}
		else if (this->year == back.year)
		{
			return this->month < back.month;
		}
		return this->year < back.year;
	}
};

struct date
{
	int year;
	int month;
	int day;
	void print()
	{
		std::cout << year << " " << month << " " << day << std::endl;
	}

	static bool datesort(date &a, date &b)
	{
		if (a.year == b.year && a.month == b.month)
		{
			return a.day < b.day;
		}
		else if (a.year == b.year)
		{
			return a.month < b.month;
		}
		return a.year < b.year;
	}
};

bool datesort(date &a, date &b)
{
	if (a.year == b.year && a.month == b.month)
	{
		return a.day < b.day;
	}
	else if (a.year == b.year)
	{
		return a.month < b.month;
	}
	return a.year < b.year;
}

struct date_lamda
{
	int year;
	int month;
	int day;
	void print()
	{
		std::cout << year << " " << month << " " << day << std::endl;
	}
	
};

int main()
{
	date array1[6] =
	{
		{2015 , 7 ,18},
		{1992, 5 , 3},
		{2015 , 3, 21 },
		{2004 , 11 , 28},
		{2004 , 11 ,5},
		{1993, 3, 19}
	};
	std::sort(array1, array1 + 6, datesort);

	for (date i : array1)
	{
		i.print();
	}
	std::cout << std::endl << std::endl;


	/*      ------------------------- */
	date array4[6] =
	{
		{2015 , 7 ,18},
		{1992, 5 , 3},
		{2015 , 3, 21 },
		{2004 , 11 , 28},
		{2004 , 11 ,5},
		{1993, 3, 19}
	};
	std::sort(array4, array4 + 6, date::datesort);

	for (date i : array4)
	{
		i.print();
	}
	std::cout << std::endl << std::endl;

	/*      ------------------------- */


	date_operator array2[6] =
	{
		{2015 , 7 ,18},
		{1992, 5 , 3},
		{2015 , 3, 21 },
		{2004 , 11 , 28},
		{2004 , 11 ,5},
		{1993, 3, 19}
	};
	std::sort(array2, array2 + 6);

	for (date_operator i : array2)
	{
		i.print();
	}
	std::cout << std::endl << std::endl;

	/*------------------------- */

	date_lamda array3[6] =
	{
		{2015 , 7 ,18},
		{1992, 5 , 3},
		{2015 , 3, 21 },
		{2004 , 11 , 28},
		{2004 , 11 ,5},
		{1993, 3, 19}
	};
	std::sort(array3, array3 + 6,
	[](date_lamda &a, date_lamda &b) ->bool
	{
		if (a.year == b.year && a.month == b.month)
		{
			return a.day < b.day;
		}
		else if (a.year == b.year)
		{
			return a.month < b.month;
		}
		return a.year < b.year;
	});
	for (date_lamda i : array3)
	{
		i.print();
	}



	return 0;
}
