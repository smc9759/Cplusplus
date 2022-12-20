#include <iostream>

class Date {
	int year_;
	int month_;  // 1 ���� 12 ����.
	int day_;    // 1 ���� 31 ����.

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

/*�������� �Ʒ��� ���� Date Ŭ������ ������ �Ϸ��� �մϴ�. 
SetDate �� ���״�� Date �Լ� ���θ� �ʱ�ȭ �ϴ� ���̰� 
AddDay, AddMonth, AddYear �� ��, ��, ���� ���ϴ� ��ŭ ���ϰ� �˴ϴ�. 
�� ���� ������ ���� ���� 2012 �� 2 �� 28 �Ͽ� 3 ���� ���ϸ� 
2012 �� 2 �� 31 ���� �Ǵ� ���� �ƴ϶� 2012 �� 3 �� 2 ���� �ǰ�����? (���̵� : ߾)*/

/*�Ƹ��� ������ ���� C ��� ���¸� ���� �е��̶�� switch ���� ���鼭 �����ϰ� �����Ҵ� �������� ����Ͻ� ���Դϴ�. �̹����� �� �� ����� ����� ���� ���� ���α׷��� �����ϰ� �����ҽ��ϴ�. �ҽ��� ���� ���� �����е鵵 ������ �����ô� �͵� ���� �� �����ϴ�. �ϴ� ������ ������ �����ϴ�.

����(struct Animal) �̶�� ����ü�� �����ؼ� �̸�(char name[30]), ����(int age),ü��(int health), ��θ� ����(int food), ������ ������(int clean) ���� ������.

ó���� ���� ����ü�� ������ �迭(struct Animal* list[30])�� ���� ����ڰ� ������ �߰��� �� ���� �ϳ��� �����Ѵ�.

play ��� �Լ��� ���� ������ ���¸� �����ϰ� show_stat �Լ��� ���� �����ϴ� ������ ���¸� ����Ѵ�.

1 ���� ���� �� ���� ������ ���¸� �����Ѵ�.
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
//		std::cout << "������ �̸� : ";
//		std::cin >> animal->name;  
//		
//		std::cout << "������ ����? ";
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
//		std::cout << "1. ���� �߰��ϱ�" << std::endl;
//		std::cout << "2. ����ֱ�" << std::endl;
//		std::cout << "3. ���� ����" << std::endl;
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
//		case 2: std::cout << "������ ���? : ";
//			std::cin >> play_with;
//
//			if (play_with < animal_num) play(list[play_with]);
//			//playwith = user ���� animal = num = ���� ������, 
//		}
//	}
//
//	return 0;
//}

//������ ������ŭ �Է� �޾Ƽ� ��� ������ �����ϰ� ����ϴ� ���α׷��� �ۼ��Ͻÿ�
//int main() {
//	int arr_size;
//	std::cout << "array size : ";
//	std::cin >> arr_size;
//	int* list = new int[arr_size];
//	for (int i = 0; i < arr_size; i++) {
//		std::cin >> list[i];
//	}//�Է��� �� ũ�⸸ŭ �迭�� �����, �迭�� ������ ���� �Է��� �� �ְ� �Ѵ�
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
//// switch �� �̿��ϱ�
//#include <iostream>
//
//using std::cout;
//using std::endl;
//using std::cin;
//bool istrue = true;
//
//int main() {
//    int user_input;
//    cout << "���� ������ ǥ�����ݴϴ�" << endl;
//    cout << "1. �̸� " << endl;
//    cout << "2. ���� " << endl;
//    cout << "3. ���� " << endl;
//    cout << "4. ���� " << endl;
//    cin >> user_input;
//
//    switch (user_input) {
//    case 1:
//        cout << "Psi ! " << endl;
//        break;
//
//    case 2:
//        cout << "99 ��" << endl;
//        break;
//
//    case 3:
//        cout << "����" << endl;
//        break;
//
//    case 4:
//        istrue = false;
//        break;
//
//    default:
//        cout << "�ñ��Ѱ� ������~" << endl;
//        break;
//    }
//    return 0;
//}
//
//int main() {
//	int lucky_number = 3;
//	std::cout << "�� ��� ���� ���߾� ������~" << std::endl;
//
//	int user_input;
//
//	while (1) {
//		std::cout << "�Է� : ";
//		std::cin >> user_input;
//		if (lucky_number == user_input) {
//			std::cout << "���߼̽��ϴ�~~" << std::endl;
//			break;
//		}
//		else {
//			std::cout << "�ٽ� �����غ�����~" << std::endl;
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
//#include "���.h"
//#include "���2.h"
//
//int main() {
//	
//	smlee::foo();        
//
//	gjhong::foo();
//
//	return 0;
//}
