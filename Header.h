#pragma once
#ifndef Header_h
#define Header_h
#include <iostream>
#include <conio.h>
#include <locale.h>
#include <stdio.h>
#include <fstream>
using namespace std;


struct Journal
{
    int index; // Номер в справочнике
    string name; // Название книги
    int counts; // Тираж
    int period; // срок подписки
    int time; // период выхода
    int price; // цена
    string publisher; // издатель
    string priviliges; // льготы
};
//TODO fix structs names
struct List_elem //Список.
{
    Journal jrnl;
    List_elem* next;
};
void init(List_elem*& begin, List_elem*& end, List_elem* new_elem);
void add_begin(List_elem*& begin, List_elem*& end, List_elem* new_elem);
void add_end(List_elem*& begin, List_elem*& end, List_elem* new_elem);
void output(List_elem* begin);
List_elem* create_elem();
void add_elem(List_elem*& begin, List_elem*& end, List_elem* new_elem = nullptr,int id=-1, char pos='0');
bool check_id(List_elem* begin, int id);
void print_elem(List_elem* tmp, int index);
void defaultSort(List_elem* begin);
void sortPriceASC(List_elem* begin);
void sortPriceDES(List_elem* begin);
void sortCountASC(List_elem* begin);
void sortCountDES(List_elem* begin);
void sortNameASC(List_elem* begin);
void sortNameDES(List_elem* begin);
void showAllByName(List_elem* begin);
void showAllByPublisher(List_elem* begin);
void showAllByPriviliges(List_elem* begin);
void remove(List_elem** begin, List_elem** end);
void update(List_elem* begin);
void save_f(List_elem* begin);
void load_f(List_elem*& begin, List_elem*& end);
List_elem* read_elem(ifstream& fin);

#endif /* Header_h */