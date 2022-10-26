
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
#define DZ 2 //Отвечает за выполнение номера домашнего задания (1 - первое, 2 - второе)

//----- Start of Task 1

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
    delete[] arr;
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
    cout << "||All cars' numbers||\n";
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

//------ End of Task 1



//Задание 2. Разработать структуру «Живая сущность»
//(скорость передвижения, тип(птица, скот, человек), цвет,
//характеристика(для птицы — скорость полета, веще -
//ственное число, для скота — парнокопытное, логическая
//переменная, для человека — уровень IQ, целая переменная).

//P.S.Небольшая проблема со вторым задание: при запуске спорадически возникает ситуация с вызовом delete_scalar.cpp
//При заполнении первого элемента массива структур, я не смог её разрешить, поэтому
//Не сетуйте на отпетого безумца

//------ Start of Task 2
struct Creature {
    int speed;
    char* type = new char[9];
    char* color = new char [15];
    struct {
        float speed_fly;
        bool hooves;
        int IQ;
    } Type;
};

//Увеличение размера массива
Creature* UpdateArr(Creature* arr, int& size) {
    size++;
    Creature* newArr = new Creature[size];
    for (int i = 0; i < size - 1; i++) {
        newArr[i] = arr[i];
    }
    delete[] arr;
    return newArr;
}
//Заполнение массива
void FillCreature(Creature* arr, int size) {
    cout << "Enter the speed of creature " << size << " :" << endl;
    cin >> arr[size - 1].speed;
    cin.ignore(256, '\n'); //очиска потока ввода
    cout << "Enter the type of creature " << size << " (bird,human,beasts):" << endl;
    gets_s(arr[size - 1].type, 10);
    cout << "Enter the color of creature " << size << " :" << endl;
    gets_s(arr[size - 1].color, 16);
    //Если сущность птичка
    if (strcmp(arr[size - 1].type, "bird") == 0) {
        cout << "Enter the fly speed of creature " << size << " :" << endl;
        cin >> arr[size - 1].Type.speed_fly;
        arr[size - 1].Type.hooves = false;
        arr[size - 1].Type.IQ = 0;
    }
    //Если сущность скот
    else if (strcmp(arr[size - 1].type, "beasts") == 0) {
        cout << "Enter the type hooves of creature " << size << " (true/false):" << endl;
        cin >> arr[size - 1].Type.hooves;
        arr[size - 1].Type.speed_fly = 0;
        arr[size - 1].Type.IQ = 0;
    }
    //Если сущность человек
    else if (strcmp(arr[size - 1].type, "human") == 0) {
        cout << "Enter the level IQ of creature " << size << " :" << endl;
        cin >> arr[size - 1].Type.IQ;
        arr[size - 1].Type.hooves = false;
        arr[size - 1].Type.speed_fly = 0;
    }
    //Если пользователь ошибся
    else
    {
        system("cls");
        cout << "\tWRONG!!\n";
        Sleep(1500);
        system("cls");
        FillCreature(arr, size);
    }
    cin.ignore(256, '\n'); //Очищаем поток ввода, чтобы не было препоной при выполнении следующих функций
}
//Показ всего массива
void PrintCreature(Creature* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << "||Creature number|| " << i + 1 << " :" << endl;
        cout << "Creature'speed - " << arr[i].speed << endl;
        cout << "Creature's type - " << arr[i].type << endl;
        cout << "Creature's color - " << arr[i].color << endl;
        //Птичка
        if (strcmp(arr[i].type, "bird") == 0) {
            cout << "Fly speed of creature - " << arr[i].Type.speed_fly << endl << endl;
        }
        //Скот
        else if (strcmp(arr[i].type, "beasts") == 0) {
            cout << "Type hooves of creature - " << arr[i].Type.hooves << endl << endl;
        }
        //Человек
        else if (strcmp(arr[i].type, "human") == 0) {
            cout << "Level IQ of creature " << arr[i].Type.IQ << endl << endl;
        }
    }
}
//Поиск по характеристике
void SearchCreatureOnCharacteristic(Creature* arr, int size) {
    char* buff = new char[20]; //Буфер для ввода типа
    float usNb; //Переменная пользователя для птичка
    bool usNbe; //Для скота
    int usNh; //Для человека
    cout << "Enter the searching creature's type\n"; //Не придумал иную реализацию фукнции поиска
    gets_s(buff, 20);
    //Человек
    if (strcmp(buff, "human") == 0) {
        cout << "Enter the searching creature's Characteristic\n";
        cin >> usNh;
        cout << endl;
        for (int i = 0; i < size; i++) {
            if (usNh == arr[i].Type.IQ) {
                cout << "||Creature number|| " << i + 1 << " :" << endl;
                cout << "Creature'speed - " << arr[i].speed << endl;
                cout << "Creature's type - " << arr[i].type << endl;
                cout << "Creature's color - " << arr[i].color << endl;
                cout << "IQ - ";
                SetConsoleTextAttribute(console, 12); //Красный цвет консоли
                cout << arr[size - 1].Type.IQ << endl << endl;
                SetConsoleTextAttribute(console, 15); //Возращаем цвет на белый
            }
        }
    } //Если создание человек
    //Птичка
    else if (strcmp(buff, "bird") == 0) {
        cout << "Enter the searching creature's Characteristic\n";
        cin >> usNb;
        cout << endl;
        for (int i = 0; i < size; i++) {
            if (usNb == arr[i].Type.speed_fly) {
                cout << "||Creature number|| " << i + 1 << " :" << endl;
                cout << "Creature'speed - " << arr[i].speed << endl;
                cout << "Creature's type - " << arr[i].type << endl;
                cout << "Creature's color - " << arr[i].color << endl;
                cout << "Fly speed of creature - ";
                SetConsoleTextAttribute(console, 12); //Красный цвет консоли
                cout << arr[size - 1].Type.speed_fly << endl << endl;
                SetConsoleTextAttribute(console, 15); //Возращаем цвет на белый
            }
        }
    } //Если создание птичка
    //Скот
    else if (strcmp(buff, "beasts") == 0) {
        cout << endl;
        cout << "Enter the searching creature's Characteristic(true/false)\n";
        cin >> usNbe;
        for (int i = 0; i < size; i++) {
            if (usNbe == arr[i].Type.hooves) {
                cout << "||Creature number|| " << i + 1 << " :" << endl;
                cout << "Creature'speed - " << arr[i].speed << endl;
                cout << "Creature's type - " << arr[i].type << endl;
                cout << "Creature's color - " << arr[i].color << endl;
                cout << "Type hooves - ";
                SetConsoleTextAttribute(console, 12); //Красный цвет консоли
                cout << arr[size - 1].Type.hooves << endl << endl;
                SetConsoleTextAttribute(console, 15); //Возращаем цвет на белый
            }
        }
    } //Если создание скот
}
//Редактировать сущность
void RedactCreature(Creature* arr, int size) {
    int creatureNumb;
    cout << "||All creatures' numbers||\n";
    for (int i = 0; i < size; i++) {
        cout << "--| " << i + 1 << endl;
    }
    cout << "Enter the number of the creature being edited:\n";
    cin >> creatureNumb;
    system("cls");
    FillCreature(arr, creatureNumb); //Заполняем заново сущность по размеру creatureNumb, где последний выступает
                                    //В качества индекса замены
}

//----- End of Task 2

#if DZ == 1{
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

        switch (us) {
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
}
#else
int main() {
    SetConsoleTextAttribute(console, 15);
    int size = 0;
    Creature* arr = new Creature[size];
    int us; //Выбор пользователя
    while (true) {
        system("cls");
        cout << "Select the option:\n";
        cout << "1. - Add new creature\n";
        cout << "2. - Print all creatures\n";
        cout << "3. - Redact creature\n";
        cout << "4. - Search creature on Characteristic\n";
        us = _getch();

        switch (us) {
        case 49:
            //Если пользователь ввёл уже 10 машин
            if (size == 10) {
                cout << "\tYou can't add more than 10 creatures\n";
                Sleep(2000);
                break;
            }
            system("cls");
            arr = UpdateArr(arr, size);  
            FillCreature(arr, size);
            break;
        case 50:
            system("cls");
            PrintCreature(arr, size);
            cout << "\n\tPress any key to return\n";
            us = _getch();
            break;
        case 51:
            system("cls");
            RedactCreature(arr, size);
            break;
        case 52:
            system("cls");
            SearchCreatureOnCharacteristic(arr, size);
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
#endif
