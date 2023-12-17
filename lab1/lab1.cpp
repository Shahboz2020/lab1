#include <iostream>
#include <string>
#include <numeric>
#include <vector>


/*

 C                 ----                C++
 (Defined in header <string.h>) - (Defined in header <cstring>)
 strlen - strlen -  возвращает длину строки

 strcpy - strcpy - копирует содержимое одной строки в другую.

 strcmp - std::strcmp - сравнивает две строки и возвращает результат сравнения.

 strcat - strcat - объединяет две строки путем добавления содержимого одной строки в конец другой.

  someString[index] - в C++ можно получить символ строки по индексу, используя оператор [].

  strcat как сверху - push_back добавляет символ в конец строки.

  замена через размер строки последнего символа на "\0" - pop_back

  Главная разница между строками в C и C++ заключается в том, что в C строки представлены как массивы символов,
  а в C++ есть специальный класс string, который предоставляет удобные методы для работы со строками.
  Строки в C++ могут быть динамическими и иметь переменную длину, в отличие от строк в C, которые имеют фиксированную длину.
  Класс string также обеспечивает автоматическое управление памятью для строк, что делает работу с ними более безопасной и удобной.



  int *ptr = (int*)malloc(sizeof(int)) - int *ptr = new int;
  int *ptrArr = (int*)malloc(sizeof(int)*N) - int *ptrArr = new int[N];
  free(ptr) - delete ptr;
  free(ptrArr) - delete[] ptrArr

  Если вы забудете освободить выделенную память, это может привести к утечкам памяти,
  когда память не будет доступна для последующего использования и будет занимать место в памяти.
  Попытка освободить одну и ту же выделенную память дважды может привести к неопределенному поведению программы.
  C++ не предоставляет прямых средств для освобождения "невыделенной" памяти. Попытка освободить такую
  память также может вызвать ошибку во время выполнения или привести к неопределенным последствиям.
 */


void taskTwo()
{
	int* height = new int;
	int* i = new int;
	int* j = new int;
	int* k = new int;

	std::cout << "Введите нужное количество строк пирамиды: ";
	std::cin >> *height;

	std::cout << '\n';
	for (*i = 0; *i <= *height; ++*i) {

		//выводим нужное кол-во пробелов
		for (*j = 0; *j < *height - *i; ++*j) {
			std::cout << " ";
		}
		//выводим нужное кол-во строк
		for (*k = 0; *k <= *i; ++*k) {
			printf("%d ", hosoyaNumber(i, k));
		}
		std::cout << "\n";
	}
	delete height, i, j, k;
}

int hosoyaNumber(int* n, int* i) {
	//формула с википедии
	return fibNumber(*i + 1) * fibNumber(*n - *i + 1);
}

int fibNumber(int n) {
	if (n == 0) return 0;
	if (n == 1) return 1;
	return fibNumber(n - 1) + fibNumber(n - 2);
}

void taskOneB()
{
	std::string someString;

	const std::string arrSorting{ "()`~!@#$%^&*-+=|\\{}[]:;\"'<>,.?/_…\n" };

	bool isSort = true;

	std::cout << "Введите строку для сортировки." << std::endl;
	std::getline(std::cin, someString);

	std::string filtratedString = "";

	for (auto iter{ someString.begin() }; iter != someString.end(); iter++)
	{
		for (int i = 0; i < arrSorting.size(); i++)
		{
			if (*iter == arrSorting[i])
			{
				isSort = 0;
				break;
			}
		}
		if (isSort)
		{
			filtratedString += *iter;
		}
		isSort = true;

	}

	std::string alphabet = "абвгдеёжзийклмнопрстуфхцчшщъыьэюяАБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯabcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
	std::string endSortString = "";

	for (char c : alphabet)
	{
		for (int j = 0; j < filtratedString.size(); j++)
		{
			if (c == filtratedString[j])
			{
				endSortString += filtratedString[j];
			}
		}
	}
	std::cout << endSortString << std::endl;
}

template<typename T>
T sum_all(T arg) {
	return arg;
}

template<typename T, typename... Args>
T sum_all(T arg, Args... args) {
	return arg + sum_all(args...);
}

template<typename T>
T sum_all(const std::vector<T>& vec) {
	return std::accumulate(vec.begin(), vec.end(), T());
}

void extraTask()
{
	int sum1 = sum_all(1, 2, 3, 4, 5);
	std::cout << "Сумма: " << sum1 << std::endl;

	double sum2 = sum_all(1.5, 2.5, 3.5);
	std::cout << "Сумма: " << sum2 << std::endl;

	std::vector<int> vec = { 1, 2, 3, 4, 5 };
	int sum3 = sum_all(vec);
	std::cout << "Сумма: " << sum3 << std::endl;
}

int main()
{
	system("chcp 1251");
	system("cls");
	setlocale(LC_ALL, "rus");

	std::cout << "Hello! \n";

	taskOneB();

	taskTwo();

	extraTask();
	return 0;
}