#include <iostream>
#include <conio.h>
#include <string>
#include <math.h>
using namespace std;
struct student {
	string fam;
	string name;
	string otch;
	int kurs;
	float bal;
};
struct srav {
	int kurs;
	int bal;
};
void vivod(student* M, int p) {
	for (int i = 0; i < p; i++)
	{
		cout << "\t Студент №" << i + 1 << endl;
		cout << "Фамилия -" << M[i].fam << endl;
		cout << " Имя - " << M[i].name << endl;
		cout << " Отчество - " << M[i].otch << endl;
		cout << " Курс - " << M[i].kurs << endl;
		cout << " Средняя успеваемость - " << M[i].bal << endl;
		
		cout << endl;
	}
}
void vvod(student* M, int p)
{
	string names[5] = { "Дмитрий", "Алексей", "Олег", "Андрей", "Артём" };
	string famil[5] = { "Антипов","Зайцев", "Андреев", "Помаскин","Поствайкин" };
	string otchs[5] = { "Андреевич","Олегович","Егорович","Александрович","Ильич" };
	for (int i = 0; i < p; i++)
	{
		cout << "Cтудент номер " << i + 1 << endl;
		
		M[i].fam = famil[rand()%5];
		cout << "Фамилия - "<< M[i].fam<<"\n";
		
		M[i].name= names[rand() % 5];
		cout << "Имя - " << M[i].name << "\n";
		
		M[i].otch = otchs[rand() % 5];
		cout << "Отчество - " << M[i].otch << "\n";
		
		M[i].kurs = rand() % 4 + 1;
		cout << "Курс - "<< M[i].kurs<< "\n";
		
		M[i].bal = rand() % 3 + 2;
		cout << "Средняя успеваемость - "<< M[i].bal<<'\n';
		cout << "\n";
	}
}

void findBestAndWorstCourse(student * M , int n) {
	int bestCourse = 0;
	float bestAvg = 0.0;
	int worstCourse = 0;
	float worstAvg = 5.0; // Максимальная оценка

	bool sameAvg = true;

	for (int i = 0; i < n; ++i) {
		if (M[i].bal > bestAvg) {
			bestAvg = M[i].bal;
			bestCourse = M[i].kurs;
		}
		if (M[i].bal < worstAvg) {
			worstAvg = M[i].bal;
			worstCourse = M[i].kurs;
		}
		if (M[i].bal != M[0].bal) {
			sameAvg = false;
		}
	}

	if (sameAvg) {
		throw std::runtime_error("Все курсы имеют одинаковую среднюю успеваемость.");
	}

	std::cout << "Курс с наилучшей успеваемостью: " << bestCourse << std::endl;
	std::cout << "Курс с наихудшей успеваемостью: " << worstCourse << std::endl;
}
int main() {
	setlocale(LC_ALL, "Russian");
	int p;
	cout << "Количество студентов ";
	cin >> p;
	student* M = new student[p];
	vvod(M, p);
	vivod(M, p);
	try {
		findBestAndWorstCourse(M, p);
	}
	catch (const std::runtime_error& e) {
		std::cerr << "Ошибка: " << e.what() << std::endl;
	}
	delete[]M;
	M = nullptr;
	system("pause");

}