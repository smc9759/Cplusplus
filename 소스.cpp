#include <iostream>

class Date {
	int year_;
	int month_;  // 1 부터 12 까지.
	int day_;    // 1 부터 31 까지.

public:
	void SetDate(int year, int month, int date) 
	{
		year_ = year;
		month_ = month;
		day_ = date;
	};
	void AddDay(int inc);
	void AddMonth(int inc);
	void AddYear(int inc);

	void ShowDate();
	int MaxDay(int month);

	void AddDay(int inc)
	{
		if ((day_ + inc) > MaxDay(month_))
		{
			month_ += 1;
			day_ += inc - MaxDay(month_);
			if (month_ > 12)
			{
				year_ += 1;
				month_ -= 12;
			}
		}
	}

	int MaxDay(int month)
	{
		if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		{
			return 31;
		}
		else if (month == 4 || month == 6 || month == 9 || month == 11)
		{
			return 30;
		}
		else
		{
			return 28;
		}
	}
};

/*여러분은 아래와 같은 Date 클래스를 디자인 하려고 합니다. 
SetDate 는 말그대로 Date 함수 내부를 초기화 하는 것이고 
AddDay, AddMonth, AddYear 는 일, 월, 년을 원하는 만큼 더하게 됩니다. 
한 가지 주의할 점은 만일 2012 년 2 월 28 일에 3 일을 더하면 
2012 년 2 월 31 일이 되는 것이 아니라 2012 년 3 월 2 일이 되겠지요? (난이도 : 上)*/

/*아마도 예전에 저의 C 언어 강좌를 보신 분들이라면 switch 문을 배우면서 간단하게 만들어보았던 마이펫을 기억하실 것입니다. 이번에는 그 때 기억을 살려서 동물 관리 프로그램을 간단하게 만들어보았습니다. 소스를 보기 전에 여러분들도 간단히 만들어보시는 것도 좋을 것 같습니다. 일단 조건은 다음과 같습니다.

동물(struct Animal) 이라는 구조체를 정의해서 이름(char name[30]), 나이(int age),체력(int health), 배부른 정도(int food), 깨끗한 정도의(int clean) 값을 가진다.

처음에 동물 구조체의 포인터 배열(struct Animal* list[30])을 만들어서 사용자가 동물을 추가할 때 마다 하나씩 생성한다.

play 라는 함수를 만들어서 동물의 상태를 변경하고 show_stat 함수를 만들어서 지정하는 동물의 상태를 출력한다.

1 턴이 지날 때 마다 동물의 상태를 변경한다.
//*/
//
//struct Animal {
//	char name[30];
//	int age;
//	int health;
//	int food;
//	int clean;
//};
//
//namespace Mypet {
//	//void play(char& name, int& age, int& health, int& food, int& clean) {
//	void create_Animal(Animal* animal){
//		std::cout << "동물의 이름 : ";
//		std::cin >> animal->name;  
//		
//		std::cout << "동물의 나이? ";
//		std::cin >> animal->age;
//
//		animal->health = 100;
//		animal->food = 100;
//		animal->clean = 100;
//	}
//	void play(Animal* animal) {
//		animal->health -= 10;
//		animal->food -= 20;
//		animal->clean -= 30;
//	}
//	void One_day_passed(Animal * animal) {
//		animal->health += 30;
//		animal->food -= 30;
//		animal->clean -= 30;
//	}
//	void show_stat(Animal* animal) {
//		std::cout << animal->health << std::endl;
//		std::cout << animal->food << std::endl;
//		std::cout << animal->clean << std::endl;
//	}
//}
//using namespace Mypet;
//int main() {
//	
//	//Animal* list = new Animal[30];
//	Animal* list[10];
//	int animal_num = 0;
//
//	for (;;) {
//		std::cout << "1. 동물 추가하기" << std::endl;
//		std::cout << "2. 놀아주기" << std::endl;
//		std::cout << "3. 상태 보기" << std::endl;
//
//		int input;
//		std::cin >> input;
//
//		switch (input) {
//			int play_with;
//		case 1:
//			list[animal_num] = new Animal;
//			create_Animal(list[animal_num]);
//
//			animal_num++;
//			break;
//		case 2: std::cout << "누구랑 놀게? : ";
//			std::cin >> play_with;
//
//			if (play_with < animal_num) play(list[play_with]);
//			//playwith = user 숫자 animal = num = 동물 마리수, 
//		}
//	}
//
//	return 0;
//}

//임의의 개수만큼 입력 받아서 사원 정보를 저장하고 출력하는 프로그램을 작성하시오
//int main() {
//	int arr_size;
//	std::cout << "array size : ";
//	std::cin >> arr_size;
//	int* list = new int[arr_size];
//	for (int i = 0; i < arr_size; i++) {
//		std::cin >> list[i];
//	}//입력한 수 크기만큼 배열을 만들고, 배열에 저장할 수를 입력할 수 있게 한다
//	for (int i = 0; i < arr_size; i++) {
//		std::cout << i << "th element of list : " << list[i] << std::endl;
//	}
//	delete list;
//	return 0;
//}

//int SWAP(int& a, int& b)
//{
//	int temp;
//	temp = a;
//	a = b;
//	b = temp;
//	return 0;
//}
//
//int main() {
//	int number1 = 10;
//	int number2 = 50;
//	std::cout << number1 << std::endl;
//	std::cout << number2 << std::endl;
//	SWAP(number1, number2);
//	std::cout << number1 << std::endl;
//	std::cout << number2 << std::endl;
//	return 0;
//}

//
//static int a = 3;
//
//int& change() {
//	return a;
//}
//
//int main() {
//	int& number = a;
//	std::cout << number << std::endl;
//
//	return 0;
//}
//
//int function() {
//	int a = 2;
//	return a;
//}
//
//int main() {
//	int b = function();
//	return 0;
//}

//
//int main() {
//	int user_input1, user_input2;
//	std::cin >> user_input1;
//	std::cin >> user_input2;
//
//	std::cout << user_input1 << std::endl;
//	std::cout << user_input2 << std::endl;
//
//	return 0;
//}

//
//int change_val(int* p) {
//	*p = 3;
//
//	return 0;
//}
//int main() {
//	int number = 5;
//
//	std::cout << number << std::endl;
//	change_val(&number);
//	std::cout << number << std::endl;
//
//	int a = 3;
//	int& another_a = a;
//
//	another_a = 5;
//	std::cout << "a : " << a << std:: endl;
//	std::cout << "another_a : " << another_a << std:: endl;
//	
//}
//
//// switch 문 이용하기
//#include <iostream>
//
//using std::cout;
//using std::endl;
//using std::cin;
//bool istrue = true;
//
//int main() {
//    int user_input;
//    cout << "저의 정보를 표시해줍니다" << endl;
//    cout << "1. 이름 " << endl;
//    cout << "2. 나이 " << endl;
//    cout << "3. 성별 " << endl;
//    cout << "4. 종료 " << endl;
//    cin >> user_input;
//
//    switch (user_input) {
//    case 1:
//        cout << "Psi ! " << endl;
//        break;
//
//    case 2:
//        cout << "99 살" << endl;
//        break;
//
//    case 3:
//        cout << "남자" << endl;
//        break;
//
//    case 4:
//        istrue = false;
//        break;
//
//    default:
//        cout << "궁금한게 없군요~" << endl;
//        break;
//    }
//    return 0;
//}
//
//int main() {
//	int lucky_number = 3;
//	std::cout << "내 비밀 수를 맞추어 보세요~" << std::endl;
//
//	int user_input;
//
//	while (1) {
//		std::cout << "입력 : ";
//		std::cin >> user_input;
//		if (lucky_number == user_input) {
//			std::cout << "맞추셨습니다~~" << std::endl;
//			break;
//		}
//		else {
//			std::cout << "다시 생각해보세요~" << std::endl;
//		}
//	}
//	return 0;
//}

//
//int main() {
//    std::cout << "hi" << std::endl
//        << "my name is "
//        << "Psi" << std::endl;
//    return 0;
//
//}
//
//#include "헤더.h"
//#include "헤더2.h"
//
//int main() {
//	
//	smlee::foo();        
//
//	gjhong::foo();
//
//	return 0;
//}
