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
void create_list(List** begin, List** end);
void add_elem(List* begin, List* end);
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
void load_f(List** begin, List** end);
void add_f(List** begin, List** end);

int main()
{

    List* begin = NULL;
    List* end = NULL;

    int key;

    do
    {
        system("cls");
        cout << "=======================================================================" << endl;
        cout << "|                      Welcome to electronic filing                   |"<< endl;
        cout << "|                          Make your choice                           |" << endl;
        cout << "=======================================================================" << endl;
        cout << "Menu:" << endl;
        cout << "1- Create List." << endl;
        cout << "2- Add element before/after ." << endl;
        cout << "3- Print." << endl;
        cout << "4- Default sort." << endl;
        cout << "5- Sort price by ascending." << endl;
        cout << "6- Sort price by descending." << endl;
        cout << "7- Sort counts by ascending." << endl;
        cout << "8- Sort counts by descending." << endl;
        cout << "9- Sort name by ascending." << endl;
        cout << "10- Sort name by descending." << endl;
        cout << "11- Find by Name." << endl;
        cout << "12- Find by publisher ." << endl;
        cout << "13- Find by priviligies." << endl;
        cout << "14- Delete element." << endl;
        cout << "15- Edit element." << endl;
        cout << "16- Save." << endl;
        cout << "17- Download list." << endl;
        cout << "0- Exit." << endl;
        cout << "======================================================================" << endl;

        cout << "Choice:";
        cin >> key;

        switch (key)
        {
        case 1:
            system("cls");
            create_list(&begin, &end);
            _getch();
            break;
            
        case 2:
            system("cls");
            add_elem(&begin, &end);
            _getch();
            break;

        case 3:
            system("cls");
            output(begin);
            _getch();
            break;

        case 4:
            system("cls");
            defaultSort(begin);
            _getch();
            break;

        case 5:
            system("cls");
            sortPriceASC(begin);
            _getch();
            break;

        case 6:
            system("cls");
            sortPriceDES(begin);
            _getch();
            break;
        case 7:
            system("cls");
            sortCountASC(begin);
            _getch();
            break;

        case 8:
            system("cls");
            sortCountDES(begin);
            _getch();
            break;
        case 9:
            system("cls");
            sortNameASC(begin);
            _getch();
            break;

        case 10:
            system("cls");
            sortNameDES(begin);
            _getch();
            break;

        case 11:
            system("cls");
            showAllByName(begin);
            _getch();
            break;
        case 12:
            system("cls");
            showAllByPublisher(begin);
            _getch();
            break;
        case 13:
            system("cls");
            showAllByPriviliges(begin);
            _getch();
            break;
        case 14:
            system("cls");
            remove(&begin, &end);
            _getch();
            break;

        case 15:
            system("cls");
            update(begin);
            _getch();
            break;
        case 16:
            system("cls");
            save_f(begin);
            _getch();
            break;
            
        case 17:
            system("cls");
            load_f(&begin, &end);
            _getch();
            break;

        case 0:
            break;

        default:
            cout << "Wrong! Try Again." << endl;
            break;
        }

    } while (key != 0);

    _getch();
    return 0;
}
//создание списка
void create_list(List** begin, List** end)
{
    if (!*begin)
    {
        *end = new List;
        cout << "ID:";
        cin >> (*end)->book.index;
        cout << "Journal Name:";
        cin >> (*end)->book.name;
        cout << "Counts:";
        cin >> (*end)->book.counts;
        cout << "Period :";
        cin >> (*end)->book.period;
        cout << "Time:";
        cin >> (*end)->book.time;
        cout << "Price:";
        cin >> (*end)->book.price;
        cout << "Publisher:";
        cin >> (*end)->book.publisher;
        cout << "Priviliges:";
        cin >> (*end)->book.priviliges;
        (*end)->next = NULL;
        *begin = *end;
        return;
    }
    (*end)->next = new List;
    *end = (*end)->next;
    cout << "ID:";
    cin >> (*end)->book.index;
    cout << "Journal Name:";
    cin >> (*end)->book.name;
    cout << "Counts:";
    cin >> (*end)->book.counts;
    cout << "Period :";
    cin >> (*end)->book.period;
    cout << "Time:";
    cin >> (*end)->book.time;
    cout << "Price:";
    cin >> (*end)->book.price;
    cout << "Publisher:";
    cin >> (*end)->book.publisher;
    cout << "Priviliges:";
    cin >> (*end)->book.priviliges;
    (*end)->next = NULL;
} 
//добавление элементов
void add_elem(List* begin, List* end)
{
    int ch;
    cout << "Choose 1-Before or 2-After" << endl;
    cin >> ch;
    if (ch == 1)
    {
        int id;
        cout << "Before which id should add:";
        cin >> id;

        //TODO:
        ыыы
    }
    else
    {
        int id;
        cout << "After which id should add:";
        cin >> id;

        //TODO:
    }
}
//вывод на экран
void output(List* begin)
{
    if (!begin)
    {
        cout << "List empty." << endl;
    }

    List* print = begin;

    while (print)
    {

        cout << " _____________________________" << endl;
        cout << "|ID:" << print->book.index << endl;
        cout << "|Name:" << print->book.name << endl;
        cout << "|Counts:" << print->book.counts << endl;
        cout << "|Period:" << print->book.period << endl;
        cout << "|Time:" << print->book.time << endl;
        cout << "|Price:" << print->book.price << "$" << endl;
        cout << "|Publisher:" << print->book.publisher << endl;
        cout << "|Priviliges:" << print->book.priviliges << endl;
        cout << "|____________________________" << endl;
        cout << "\n";
        print = print->next;
    }
}
//сохранить список
void save_f(List* begin)
{
    string file_n;
    cout << "Write filename" << endl;
    cin >> file_n;
    ofstream fout(file_n + ".txt");

    if (fout)
    {
        List* tmp = begin;

        while (tmp != NULL)
        {
            fout << tmp->book.index << " ";
            fout << tmp->book.name << " ";
            fout << tmp->book.counts << " ";
            fout << tmp->book.period << " ";
            fout << tmp->book.time << " ";
            fout << tmp->book.price << " ";
            fout << tmp->book.publisher << " ";
            fout << tmp->book.priviliges << " ";

            tmp = tmp->next;
        }

        fout.close();
    }

    else
        cout << "Error saving" << endl;
}
//загрузить список
void load_f(List** begin, List** end)
{
    List* tmp = new List;
    ifstream fin;
    cout << "Choose file:" << endl;
    string file;
    cin >> file;
    fin.open(file + ".txt");
    if (!fin.is_open())
    {
        cout << "File doesn't exist " << endl;
        return;
    }

    while (!fin.eof())
    {
        
        cout << " _____________________________" << endl;
        fin >> tmp->book.index;
        if (fin.eof()) break;
        cout << "|ID:" << tmp->book.index << endl;
        fin >> tmp->book.name;
        cout << "|Name:" << tmp->book.name << endl;
        fin >> tmp->book.counts;
        cout << "|Counts:" << tmp->book.counts << endl;
        fin >> tmp->book.period;
        cout << "|Period:" << tmp->book.period << endl;
        fin >> tmp->book.time;
        cout << "|Time:" << tmp->book.time << endl;
        fin >> tmp->book.price;
        cout << "|Price:" << tmp->book.price << endl;
        fin >> tmp->book.publisher;
        cout << "|Publisher:" << tmp->book.publisher << endl;
        fin >> tmp->book.priviliges;
        cout << "|Priviliges:" << tmp->book.priviliges << endl;
        cout << "|____________________________" << endl;

        add_f(begin, &tmp);
    }


}

void add_f(List** begin, List** end)
{
    if (!*begin)
    {
        (*end)->book.index;
        (*end)->book.name;
        (*end)->book.counts;
        (*end)->book.period;
        (*end)->book.time;
        (*end)->book.price;
        (*end)->book.publisher;
        (*end)->book.priviliges;
        (*end)->next = NULL;
        *begin = *end;
    }

    (*end)->next = new List;
    *end = (*end)->next;
    (*end)->book.index;
    (*end)->book.name;
    (*end)->book.counts;
    (*end)->book.period;
    (*end)->book.time;
    (*end)->book.price;
    (*end)->book.publisher;
    (*end)->book.priviliges;
    (*end)->next = NULL;
}

//поиск по имени
void showAllByName(List* begin)
{
    string Letter;

    cout << "Input Search Name:" << endl;
    cin >> Letter;

    List* ptr = begin;

    while (ptr != NULL)
    {
        if (ptr->book.name == Letter)
        {
            cout << " _____________________________" << endl;
            cout << "|ID:" << ptr->book.index << endl;
            cout << "|Name:" << ptr->book.name << endl;
            cout << "|Counts:" << ptr->book.counts << endl;
            cout << "|Period:" << ptr->book.period << endl;
            cout << "|Time:" << ptr->book.time << endl;
            cout << "|Price:" << ptr->book.price << "$" << endl;
            cout << "|Publisher:" << ptr->book.publisher << endl;
            cout << "|Priviliges:" << ptr->book.priviliges << endl;
            cout << "|____________________________" << endl;
            cout << "\n";
        }

        ptr = ptr->next;
    }
}
//поиск по льготпм
void showAllByPriviliges(List* begin)
{
    string Letter;

    cout << "Input Search Name:" << endl;
    cin >> Letter;

    List* ptr = begin;

    while (ptr != NULL)
    {
        if (ptr->book.priviliges == Letter)
        {
            cout << " _____________________________" << endl;
            cout << "|ID:" << ptr->book.index << endl;
            cout << "|Name:" << ptr->book.name << endl;
            cout << "|Counts:" << ptr->book.counts << endl;
            cout << "|Period:" << ptr->book.period << endl;
            cout << "|Time:" << ptr->book.time << endl;
            cout << "|Price:" << ptr->book.price << "$" << endl;
            cout << "|Publisher:" << ptr->book.publisher << endl;
            cout << "|Priviliges:" << ptr->book.priviliges << endl;
            cout << "|____________________________" << endl;
            cout << "\n";
        }

        ptr = ptr->next;
    }
}
//поиск по издателю
void showAllByPublisher(List* begin)
{
    string Letter;

    cout << "Input Search Name:" << endl;
    cin >> Letter;

    List* ptr = begin;

    while (ptr != NULL)
    {
        if (ptr->book.publisher == Letter)
        {
            cout << " _____________________________" << endl;
            cout << "|ID:" << ptr->book.index << endl;
            cout << "|Name:" << ptr->book.name << endl;
            cout << "|Counts:" << ptr->book.counts << endl;
            cout << "|Period:" << ptr->book.period << endl;
            cout << "|Time:" << ptr->book.time << endl;
            cout << "|Price:" << ptr->book.price << "$" << endl;
            cout << "|Publisher:" << ptr->book.publisher << endl;
            cout << "|Priviliges:" << ptr->book.priviliges << endl;
            cout << "|____________________________" << endl;
            cout << "\n";
        }

        ptr = ptr->next;
    }
}
//стандартный вид списка
void defaultSort(List* begin)
{
    if (!begin)
    {
        cout << "List empty." << endl;

        return;
    }
    List* ptrN = begin;

    while (ptrN->next != NULL)
    {
        List* ptr = begin;

        while (ptr->next != NULL)
        {
            if (ptr->book.index > ptr->next->book.index)
            {
                Book tmp = ptr->book;
                ptr->book = ptr->next->book;
                ptr->next->book = tmp;
            }

            ptr = ptr->next;
        }

        ptrN = ptrN->next;
    }
}
//сортировать цену по возрастанию
void sortPriceASC(List* begin)
{
    if (!begin)
    {
        cout << "List empty." << endl;

        return;
    }
    List* ptrN = begin;

    while (ptrN->next != NULL)
    {
        List* ptr = begin;

        while (ptr->next != NULL)
        {
            if (ptr->book.price < ptr->next->book.price)
            {
                Book tmp = ptr->book;
                ptr->book = ptr->next->book;
                ptr->next->book = tmp;
            }

            ptr = ptr->next;
        }

        ptrN = ptrN->next;
    }
}
//сортировать цену по убыванию
void sortPriceDES(List* begin)
{
    if (!begin)
    {
        cout << "List empty." << endl;

        return;
    }
    List* ptrN = begin;

    while (ptrN->next != NULL)
    {
        List* ptr = begin;

        while (ptr->next != NULL)
        {
            if (ptr->book.price > ptr->next->book.price)
            {
                Book tmp = ptr->book;
                ptr->book = ptr->next->book;
                ptr->next->book = tmp;
            }

            ptr = ptr->next;
        }

        ptrN = ptrN->next;
    }
}
//сортировать тираж по возрастанию
void sortCountASC(List* begin)
{
    if (!begin)
    {
        cout << "List empty." << endl;

        return;
    }
    List* ptrN = begin;

    while (ptrN->next != NULL)
    {
        List* ptr = begin;

        while (ptr->next != NULL)
        {
            if (ptr->book.counts < ptr->next->book.counts)
            {
                Book tmp = ptr->book;
                ptr->book = ptr->next->book;
                ptr->next->book = tmp;
            }

            ptr = ptr->next;
        }

        ptrN = ptrN->next;
    }
}
//сортировать тираж по убыванию
void sortCountDES(List* begin)
{
    if (!begin)
    {
        cout << "List empty." << endl;

        return;
    }
    List* ptrN = begin;

    while (ptrN->next != NULL)
    {
        List* ptr = begin;

        while (ptr->next != NULL)
        {
            if (ptr->book.counts > ptr->next->book.counts)
            {
                Book tmp = ptr->book;
                ptr->book = ptr->next->book;
                ptr->next->book = tmp;
            }

            ptr = ptr->next;
        }

        ptrN = ptrN->next;
    }
}
//сортировать имя по возрастанию
void sortNameASC(List* begin)
{
    if (!begin)
    {
        cout << "List empty." << endl;

        return;
    }
    List* ptrN = begin;

    while (ptrN->next != NULL)
    {
        List* ptr = begin;

        while (ptr->next != NULL)
        {
            if (ptr->book.name < ptr->next->book.name)
            {
                Book tmp = ptr->book;
                ptr->book = ptr->next->book;
                ptr->next->book = tmp;
            }

            ptr = ptr->next;
        }

        ptrN = ptrN->next;
    }
}
//сортировать имя по убыванию
void sortNameDES(List* begin)
{
    if (!begin)
    {
        cout << "List empty." << endl;

        return;
    }
    List* ptrN = begin;

    while (ptrN->next != NULL)
    {
        List* ptr = begin;

        while (ptr->next != NULL)
        {
            if (ptr->book.name > ptr->next->book.name)
            {
                Book tmp = ptr->book;
                ptr->book = ptr->next->book;
                ptr->next->book = tmp;
            }

            ptr = ptr->next;
        }

        ptrN = ptrN->next;
    }
}
//удалить элемент
void remove(List** begin, List** end)
{
    List* ptr = *begin;
    List* previous = *begin;

    int id;

    cout << "Which id you want delete:";
    cin >> id;

    while (ptr != NULL)
    {
        if (ptr->book.index == id)
        {
            if (ptr == *begin)
            {
                *begin = ptr->next;
            }
            if (ptr->next == NULL)
            {
                *end = previous;
            }
            if (begin == NULL)
            {
                end = NULL;
            }

            List* following = ptr->next;
            previous->next = following;
            delete ptr;

            return;
        }

        previous = ptr;
        ptr = ptr->next;
    }
}
//обновить элемент
void update(List* begin)
{
    List* ptr = begin;

    int id;
    cout << "Which id you want update:";
    cin >> id;

    while (ptr != NULL)
    {
        if (ptr->book.index == id)
        {
            cout << "ID:";
            cin >> ptr->book.index;
            cout << "Journal Name:";
            cin >> ptr->book.name;
            cout << "Counts:";
            cin >> ptr->book.counts;
            cout << "Period of subs:";
            cin >> ptr->book.period;
            cout << "Time:";
            cin >> ptr->book.time;
            cout << "Price:";
            cin >> ptr->book.price;
            cout << "Publisher:";
            cin >> ptr->book.publisher;
            cout << "Priviligies:";
            cin >> ptr->book.priviliges;
        }

        ptr = ptr->next;
    }
}

