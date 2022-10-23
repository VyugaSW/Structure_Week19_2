
#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include <conio.h>

using namespace std;
//Задание 1. Реализовать структуру «Машина» (цвет, модель,
//номер).Номер машины может представлять из себя или
//пятизначный номер или слово до 8 символов.

//P.S. В общем, я соизволили сделать динамическое изменение размера массива
//посредством создание нового, чтобы пользователь мог добавить сколько ему угодно машин,
//но не более 10.

//Основная структура
struct Car {
    char* color = new char[25];
    char* model = new char[25];
    char* number = new char[9];
};

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE); //Цветной текст

//Увелечение размера массива
Car* UpdateArr(Car* arr, int& size) {
    size++;
    Car* newArr = new Car[size];
    for (int i = 0; i < size-1; i++) {
        newArr[i] = arr[i];

    }
    return newArr;
}
//Заполнение массива
void FillCar(Car* arr, int size) {

    cout << "Enter the color of car " << size << " :" << endl;
    gets_s(arr[size-1].color, 25); 
    cout << "Enter the model of car " << size << " :" << endl;
    gets_s(arr[size - 1].model, 25);
    cout << "Enter the nubmer of car " << size << " :" << endl;
    gets_s(arr[size - 1].number, 9);
}
//Печать всех машин
void PrintCars(Car* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << "||Car number|| " << i + 1 << " :" << endl;
        cout << "Car's color - " << arr[i].color << endl;
        cout << "Car's model - " << arr[i].model << endl;
        cout << "Car's number - " << arr[i].number << endl << endl;
    }
}
//Поиск машины по номеру
void SearchCarOnNumber(Car* arr, int size) {
    char* buff = new char[9]; //Буфер для пользователя
    cout << "Enter the searching car's number\n";
    gets_s(buff, 9);
    for (int i = 0; i < size; i++) {
        if (strcmp(buff, arr[i].number) == 0) {
            cout << "||Car number|| " << i + 1 << " :" << endl;
            cout << "Car's color - " << arr[i].color << endl;
            cout << "Car's model - " << arr[i].model << endl;
            cout << "Car's number - ";
            SetConsoleTextAttribute(console, 12); //Красный цвет консоли
            cout << arr[i].number << endl << endl;
            SetConsoleTextAttribute(console, 15); //Возращаем цвет на белый
        }
    }
    delete[] buff; //Ликвидируем праздную память
}
//Редактирование машины по номеру (порядок в списке)
void RedactCar(Car* arr, int size) {
    int carNumb;  
    cout << "||All car's numbers||\n";
    for (int i = 0; i < size; i++) {
        cout << "--| " << i + 1 << endl;
    } 
    cout << "Enter the number of the machine being edited:\n";
    cin >> carNumb;
    cin.ignore(256, '\n'); // очищаем поток ввода
    system("cls");
    FillCar(arr, carNumb); //Заполняем заново машину по размеру carNumb, где последний выступает
                           //В качества индекса
}
int main()
{
    SetConsoleTextAttribute(console, 15);
    int size = 0;
    Car* arr = new Car[size];

    while (true) {
        system("cls");
        int us; //Выбор пользователя
        cout << "Select the option:\n";
        cout << "1 - Add new car\n";
        cout << "2 - Print all cars\n";
        cout << "3 - Redact car\n";
        cout << "4 - Search car on number\n";
        us = _getch();

        switch(us) {
        case 49:
            //Если пользователь ввёл уже 10 машин
            if (size == 10) {
                cout << "\tYou can't add more than 10 cars\n";
                Sleep(2000);
                break;
            }
            system("cls");
            arr = UpdateArr(arr, size);
            FillCar(arr, size);
            break;
        case 50:
            system("cls");
            PrintCars(arr, size);
            cout << "\n\tPress any key to return\n";
            us = _getch();
            break;
        case 51:
            system("cls");
            RedactCar(arr, size);
            break;
        case 52:
            system("cls");
            SearchCarOnNumber(arr, size);
            cout << "\n\tPress any key to return\n";
            us = _getch();
            break;
        default:
            system("cls");
            cout << "\n\n\t\tERROR\n";
            Sleep(1500);
        }
    }










}

