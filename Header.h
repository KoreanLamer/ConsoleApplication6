#pragma once
#ifndef Header_h
#define Header_h
#include <iostream>
#include <conio.h>
#include <locale.h>
#include <stdio.h>
#include <fstream>
using namespace std;


struct Book
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

struct List //Список.
{
    Book book;
    List* next;
};

void output(List* begin);
List* create_elem();
void add_elem(List*& begin, List*& end, List* new_elem = nullptr);
void print_elem(List* tmp);
void defaultSort(List* begin);
void sortPriceASC(List* begin);
void sortPriceDES(List* begin);
void sortCountASC(List* begin);
void sortCountDES(List* begin);
void sortNameASC(List* begin);
void sortNameDES(List* begin);
void showAllByName(List* begin);
void showAllByPublisher(List* begin);
void showAllByPriviliges(List* begin);
void remove(List** begin, List** end);
void update(List* begin);
void save_f(List* begin);
void load_f(List*& begin, List*& end);
List* read_elem(ifstream& fin);

#endif /* Header_h */