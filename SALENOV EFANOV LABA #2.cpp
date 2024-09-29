
#define _USE_MATH_DEFINES
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <cmath>
#include <iomanip>
#define stop do{ } while(0)
#include <windows.h>
using namespace std;

int nTwin = 1;			//глобальная переменная
namespace TwinSpace { int nTwin = 2; }	//переменная объявлена в
//пространстве имен - TwinSpace

#define stop do{ } while(0)	

int main(){
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::cout << "Задание 1" << endl;
	

	//**********************************************************
		//Задание 1. Работа с отладчиком. Базовые типы данных. Выполняя программу по шагам, 
		//следите за значениями переменных и интерпретируйте результат (помните, что 
		//количество байт, отводимых под int, системо-зависимо).
		//Обратите внимание на разную интерпретацию отладчиком signed и unsigned целых типов 
		//данных, а также на внутреннее представление отрицательных целых чисел.



	// Выполните фрагмент, приведенный далее. В комментариях отразите,
	// что реально заносится в переменную. Объясните разницу между этим 
	// значением и инициализатором.
	
	double d = 0.1234567890123456789123456789; //0.12345678901234568
	float  f = 0.1234567890123456789123456789; //0.123456791
	std::cout.precision(29);
	std::cout << "d = " << d << endl;
	std::cout << "f = " << f << endl;
	d = 1.; //1.0000000000000000
	d = 0.999999999999999999999999999999999; //1.0000000000000000 

	stop;

	// В комментариях напишите результат, возвращаемый оператором sizeof для
	// переменной типа wchar_t (ее размер)
	wchar_t cw = L'\u0424';
	size_t n = sizeof(cw);
	std::cout << "sizeoff(n) = " << sizeof(n) << endl; //2байта

	stop;


	// **************************************************************
	//Задание 2a. Неявное приведение типов данных.
	//Объясните разницу результата при выполнении (1) и (2):
	//Покажите явно (напишите в коде) преобразования, которые неявно выполняет компилятор
	char cByte = 'A'; cByte = 0x42;
	cByte = 66; cByte = -1;
	unsigned char ucByte = 0x41;
	ucByte = 'B'; ucByte = -1;
	int iInt = 0xffffffff;
	unsigned int uiInt = 0xffffffff;
	float fFloat = 1.f;
	double dDouble = 1.;
	iInt = 1;
	double dDouble1 = static_cast<int>(iInt) / 3;		// (1) целочисленное деление => результат тоже целый
	double dDouble2 = static_cast<double>(iInt) / 3.;	// (2) 3. => 3.0, вещественное число соответственно iInt рассматривается тоже как вещественное
	

	

	short sShort;
	dDouble = (fFloat = (iInt = (sShort = (cByte = (3.3 / 3)))));			// (1)
	


	cByte = (sShort = (iInt = (fFloat = (dDouble = (3.3 / 3)))));			// (2)
	

	

	iInt = 257;
	cByte = static_cast<char>(iInt);
	unsigned char cN1 = 255, cN2 = 2, cSum;
	cSum = cN1 + cN2; 
	int iSum = static_cast<int>(cN1) + static_cast<int>(cN2);  //т.к. результирующее значение типа int(32-битное)

	
	char c1 = 0xff, c2 = 2;
	unsigned char uc1 = 0xff, uc2 = 2;
	int iSum1 = c1 + c2;   //(1) c1 - знаковое число (-1) => -1 + 2 = 1
	int iSum2 = uc1 + uc2; //(2) uc1 - беззнаковое (255) => 255+2 = 257

	stop;

	// ***********************************************************
		//Задание 2b. Явное приведение типов данных.
		//Проинтерпретируйте результат (значения переменной dDouble) в строке (3)
		// Напишите явно преобразования, которые неявно выполняет компилятор
	std::cout << "Задание 2" << endl;
	int nTmp = 100, nn = 3;
	dDouble = 3.3 + static_cast<int>(nTmp) / nn;  // (3) nTmp / nn => целочисленное деление => 33

	//Получите результат без потери точности с помощью оператора явного
	//приведения типа
	double dDouble3 = 3.3 + static_cast<double>(nTmp) / nn; 
	std::cout << "dDouble = " << dDouble << endl;
	std::cout << "dDouble3 = " << dDouble3 << endl;


	stop;


	// Задание 3. 
	

	nTwin = 100; //глобальная
	TwinSpace::nTwin = 300; //пространство имен
	nTwin++; //глобальная
	
	int nTwin; //локальная в main'e
	nTwin = 200;
	::nTwin++;  //глобальная
	{
		int nTwin; //внутри блока
		nTwin = -1;
		::nTwin++; //глобальная
		TwinSpace::nTwin++; //пространство имен
	}

	nTwin--; //локальная в main()


	// *******************************************************
		// Задание 4. С
   	
	for (int i = 0; i < 3; i++)
	{
		static int nStatic1 = 100; //Статическая переменная в данном случае 
		//инициализируется один раз при начале выполнения программы

		int nLocal1 = 100; //Инициализируется каждый раз при выполнении блока
		int nLocal2 = 200; //Инициализируется каждый раз при выполнении блока

		static int nStatic2 = nLocal2++ * 2; //Статическая переменная в данном 
		////случае инициализируется один раз при первом выполнении блока

		nStatic1++;
		nStatic2++;
		nLocal1++;

		
		stop;
	}
	
	for (int i = 0; i < 3; i++)
	{
		static int nStatic1; //инициализированна нулем при запуске приложения
		nStatic1 = 100; //значение 100 переписывает значение переменной на каждой итерации цикла
		int nLocal1 = 100;
		nStatic1++;
		nLocal1++;
		stop;
	}
//
//
//	// *******************************************************
//		// Задание 5.
//
//
	enum eColors
	{
		BLACK,
		BLUE,
		GREEN,
		RED = 5,
		YELLOW,
		WHITE = RED + 4
	};

	eColors   myColors;	//объявление переменной типа eColors 
	myColors = BLACK; //0
	myColors = BLUE; //1
	myColors = GREEN; //2
	myColors = RED; //5
	myColors = YELLOW; //6
	myColors = WHITE; //9
	int nnn = BLACK; //любой целочисленной переменной можно присвоить))

	myColors = BLUE;	
	myColors = static_cast<eColors>(123);
	stop;
//
//
//	// *******************************************************
//		// Задание 6.1 
	int nNumber = 1;
	bool b = (nNumber != 0); std::cout << " правда? = YEEEEES " << b << endl;
	b = (nNumber == 0); std::cout << " правда? = NO( " << b << endl;
	b = (nNumber > 0); std::cout << " правда? = YEEEEES " << b << endl;
	b = (nNumber > 1); std::cout << " правда? = NO( " << b << endl;
	b = 5; std::cout << " правда? = YEEEEES " << b << endl;
	



	int tmp = b + 1;
	std::cout << " tmp ot b " << tmp << endl; 
//
//	
	{
		int year = 1823;
		
		std::cout << "Задание №6.2 " << endl;

//		//Вычислили значение 
		bool isLeapYear = !(year % 400) || ((year % 100) && !(year & 3));
		std::cout << " bool isLeapYear " << isLeapYear << endl;
//		// проверили значение в отладчике
		stop;
	}
//
//	// *******************************************************
//		// Задание 7. Модификатор const и переменные
//
	{
		
			//const int nN; 
			//Константная переменная должна быть инициализирована при объявлении, 
			//либо объявлена как внешняя переменная

			//nN = 1; 
			//Нельзя менять значение переменных объявленных со спецификатором const

	}
//
//
//
//
	{
//		// Сформируйте значение переменной ch с помощью потока ввода
		char ch;
		std::cout << "Задание №8.1" << endl;
		std::cout << "Enter letter a-Z" << endl;
		if (cin >> ch, (ch >= 'a') && (ch <= 'z'))
			ch -= 0x20;
		else if ((ch >= 'A') && (ch <= 'Z'))
			ch += 0x20;


		//... изменили регистр
		std::cout << ch << endl;
		// здесь проверили в отладчике значение или вывели "эхо" на экран
		stop;
	}
//
//
//	
	{
		float x = 1, y = 5;
		std::cout << "Задание №8.2" << endl;

		if (x <= 0)
			y = 0;
		else if (x > 0 && x < 1)
			y = x;
		else
			y = 1;

		std::cout << "y = " << y << std::endl;
	}


	{
		int x = 2, y = 2;
 	    std::cout << "Задание №8.3" << endl;
		char ch;
		std::cout << "Enter 'y' - yes, 'n' - no" << std::endl;
		std::cin >> ch;		//сформировали значение
		switch (ch)
		{
		case 'Y':
		case 'y': y = x;
			break;
		case 'N':
		case 'n': y = x * 2;
			break;
		default:
			std::cout << "Error" << std::endl;
		}
		std::cout << "y = " << y << std::endl;
	}
//
//	// ********************************************************
//		
	{
		std::cout << "Задание №9.1" << endl;
		int low, high, sum;
		std::cout << "Enter low and high bound" << std::endl;
		std::cin >> low >> high;
		//сформировать границы диапазона

		//проверить корректность значений
		if (low <= high)
		{
			// вычислить сумму
			for (int i = low, sum = 0; i <= high; i++) {
				sum += i;
				std::cout << "sum = " << sum << std::endl;
			}

			stop;
		}

		// проверить в отладчике значение
		stop;
	}
	
	{
		std::cout << "Задание №9.2" << endl;
		int x;
		do
		{
			std::cout << "Enter digit >= 10 && even for exit " << std::endl;
			std::cin >> x;
		} while (x < 10);

		std::cout << "x = " << x << std::endl;
	}


	{
		std::cout << "Задание №9.3" << endl;
		int x = 0;
		double sum = 0;

		while (sum <= 1.7)
		{
			std::cout << " + ";
			x++;
			sum += 1. / x;
			std::cout << x << "  ";
		}
		std::cout << "\nsum = " << sum << std::endl;

	}
//
	return 0; //код завершения приложения
}	// Конец функции main()


#include <iostream>
#include <windows.h>
#include <cmath>
#include <string>
using namespace std;
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	double summa, hyuinya;
	cout << "Задание №5 c крышей" << endl;
	int x, y, z, u, d, i;
	string p;
	cout << "Сколько метров покрытия с крышей?" << endl;
	cin >> x;
	cout << "Сколько метров покрытия without крыша?" << endl;
	cin >> y;
	cout << "Сколько метров покрытия sada?" << endl;
	cin >> z;
	cout << "выбери тип материала (1- ахуенный, 2-норм,3-хуйня)" << endl;
	cin >> u;
	cout << "имеются ли базовые услуги?" << endl;
	cin >> p;
	cout << "сколько этажей?" << endl;
	cin >> i;
	summa = (x * 5 + y * 3 + z * 1);
	if (u = 1) {
		summa = summa * 1.15;
	}
	if (u = 2) {
		summa = summa * 1.1;
	}
	if (u = 3) {
		summa = summa * 1.05;

	}
	if (p == "yes") {
		summa = summa + 2.5;
	}
	if (i = 2) {
		summa = summa * 1.1;
	}
	if (i = 3 || 4) {
		summa = summa * 1.15;
	}
	if (i > 4) {
		summa = summa * 1.2;
	}
	cout << "сколько потратил в казике?" << summa << endl;

	return 0;
}