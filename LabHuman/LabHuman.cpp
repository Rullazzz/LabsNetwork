#include <iostream>
#include <string.h>
#include <locale.h>
#include <cstdlib>
#include <math.h>

using namespace std;

#define PI 3.14159265                                  

class Coordinates {
private:
	/// <summary>
	/// Конечная долгота
	/// </summary>
	double FinalLongtitude;

	/// <summary>
	/// Конечная широта
	/// </summary>
	double FinaLatitude;

	/// <summary>
	/// Текущее положение по долготе
	/// </summary>
	double Longtitude;

	/// <summary>
	/// Текущее положение по широте
	/// </summary>
	double Latitude;

	/// <summary>
	/// Расстояние.
	/// </summary>
	double Dist;
	double d;
	double q;

public:
	Coordinates(double longt, double latit)
	{
		FinalLongtitude = 0 + rand() % (180 + 1);
		FinaLatitude = 0 + rand() % (90 + 1);

		if (longt >= 0 && longt <= 180)
		{
			Longtitude = longt;
		}
		else 
		{
			throw exception("ОШИБКА: Неверно задана долгота");
		}

		if (latit >= 0 && latit <= 90)
		{
			Latitude = latit;
		}
		else 
		{
			throw exception("ОШИБКА: Неверно задана широта");
		}
	}

	void Move()
	{
		FinaLatitude += 0 + rand() % 6;
		FinalLongtitude += 0 + rand() % 6;
	}

	void SetCoordinates(double dolg, double shirot) {
		Longtitude = dolg;
		Latitude = shirot;
	}

	double GetLongtitude() {
		return Longtitude;
	}

	double GetLatitude() {
		return Latitude;
	}

	double GetDist() {
		q = sin(Latitude) * sin(FinaLatitude) + cos(Latitude) * cos(FinaLatitude) * cos(abs(Longtitude - FinalLongtitude));
		d = abs(acos(q));
		Dist = d * 6371;
		return Dist;
	}

	double GetFinalLongtitude()
	{
		return FinalLongtitude;
	}

	double GetFinalLatitude()
	{
		return FinaLatitude;
	}

	void ShowStartCoordinates() {
		cout << "\nНачальная долгота: " << GetLongtitude() << endl;
		cout << "Начальная широта: " << GetLatitude() << endl;
	}

	void ShowFinalCoordinates()
	{
		cout << "\nКонечная долгота: " << GetFinalLongtitude() << endl;
		cout << "Конечная широта: " << GetFinalLatitude() << endl << endl;
	}
};

class Human : public Coordinates {
private:
	string Name;
	string Surname;
	string Patronymiс;
	double Weight;
	double Height;
	int Age;

public:
	/// <summary>
	/// Создать экземпляр класса Human.
	/// </summary>
	/// <param name="surname"> Фамилия </param>
	/// <param name="name"> Имя </param>
	/// <param name="patronymiс"> Отчество </param>
	/// <param name="age"> Возраст </param>
	/// <param name="weight"> Вес </param>
	/// <param name="height">Рост</param>
	/// <param name="longt">Положение по долготе</param>
	/// <param name="latit">Положение по широте</param>
	Human(string surname, string name, string patronymiс, double age, double weight, double height, double longt, double latit) : Coordinates(longt, latit) 
	{
		SetFullName(name, surname, patronymiс);
		SetParameters(age, weight, height);
	}

#pragma region Геттеры
	string GetName()
	{
		return Name;
	}

	string GetSurname()
	{
		return Surname;
	}

	string GetPatronymic()
	{
		return Patronymiс;
	}

	int GetAge()
	{
		return Age;
	}

	double GetWeight()
	{
		return Weight;
	}

	double GetHeight()
	{
		return Height;
	}
#pragma endregion

#pragma region Сеттеры
	void SetFullName(string nm, string sn, string pt)
	{
		Name = nm;
		Surname = sn;
		Patronymiс = pt;
	}

	void SetParameters(int a, double w, double h) {
		Age = a;
		Weight = w;
		Height = h;
	}
#pragma endregion

	/// <summary>
	/// Показать параметры человека.
	/// </summary>
	void ShowParameters() 
	{
		cout << "\nВозраст: " << GetAge() << endl;
		cout << "\nВес: " << GetWeight() << endl;
		cout << "Рост: " << GetHeight() << endl;
	}

	/// <summary>
	/// Показать полное имя человека.
	/// </summary>
	void ShowFullName()
	{
		cout << "Пользователь: " << GetSurname();
		cout << " " << GetName();
		cout << " " << GetPatronymic() << endl;
	}
};

int main() {
	setlocale(LC_ALL, "Russian");

	const int lifeTime = 10;

	Human* human = new Human("Петро", "Иван", "Папичев", 50, 70, 171, 10, 15);
	human->ShowFullName();
	human->ShowParameters();
	human->ShowStartCoordinates();

	for (int i = 0; i < lifeTime; i++)
	{
		human->Move();
		human->ShowFinalCoordinates();
		cout << "Расстояние от начала до этой точки: " << human->GetDist() << " км" << endl;
	}
}