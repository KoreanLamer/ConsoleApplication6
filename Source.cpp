#include "Header.h"


//добавление элементов
void add_elem(List_elem*& begin, List_elem*& end, List_elem* new_elem)
{
    List_elem* elem_to_add = new_elem == nullptr ? create_elem() : new_elem;
    if (!begin)
    {
        begin = elem_to_add;
        end = begin;
        return;
    }
    end->next = elem_to_add;
    end = end->next;
}

List_elem* create_elem()
{
    List_elem* new_element = new List_elem;
    cout << "ID:";
    cin >> (new_element)->jrnl.index;
    cout << "Journal Name:";
    cin >> (new_element)->jrnl.name;
    cout << "Counts:";
    cin >> (new_element)->jrnl.counts;
    cout << "Period :";
    cin >> (new_element)->jrnl.period;
    cout << "Time:";
    cin >> (new_element)->jrnl.time;
    cout << "Price:";
    cin >> (new_element)->jrnl.price;
    cout << "Publisher:";
    cin >> (new_element)->jrnl.publisher;
    cout << "Priviliges:";
    cin >> (new_element)->jrnl.priviliges;
    (new_element)->next = nullptr;
    return new_element;
};
//вывод на экран
void output(List_elem* begin)
{
    if (!begin)
    {
        cout << "List_elem empty." << endl;
    }

    List_elem* print = begin;

    while (print)
    {

        print_elem(print);
        print = print->next;
    }
}
//сохранить список
void save_f(List_elem* begin)
{
    string file_n;
    cout << "Write filename" << endl;
    cin >> file_n;
    ofstream fout(file_n + ".txt");

    if (fout)
    {
        List_elem* tmp = begin;

        while (tmp != nullptr)
        {
            char end_sym = tmp->next == nullptr ? '\0' : '\n';
            fout << tmp->jrnl.index << " ";
            fout << tmp->jrnl.name << " ";
            fout << tmp->jrnl.counts << " ";
            fout << tmp->jrnl.period << " ";
            fout << tmp->jrnl.time << " ";
            fout << tmp->jrnl.price << " ";
            fout << tmp->jrnl.publisher << " ";
            fout << tmp->jrnl.priviliges << end_sym;

            tmp = tmp->next;
        }

        fout.close();
    }

    else
        cout << "Error saving" << endl;
}
//загрузить список

void print_elem(List_elem* tmp)
{
    cout << "_____________________________" << endl;
    cout << "|ID:" << tmp->jrnl.index << endl;
    cout << "|Name:" << tmp->jrnl.name << endl;
    cout << "|Counts:" << tmp->jrnl.counts << endl;
    cout << "|Period:" << tmp->jrnl.period << endl;
    cout << "|Time:" << tmp->jrnl.time << endl;
    cout << "|Price:" << tmp->jrnl.price << endl;
    cout << "|Publisher:" << tmp->jrnl.publisher << endl;
    cout << "|Priviliges:" << tmp->jrnl.priviliges << endl;
    cout << "|____________________________" << endl;
}
void load_f(List_elem*& begin, List_elem*& end)
{
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
        List_elem* tmp = read_elem(fin);
        print_elem(tmp);
        add_elem(begin, end, tmp);

    }

}

List_elem* read_elem(ifstream& fin)
{
    List_elem* tmp = new List_elem;
    fin >> tmp->jrnl.index;
    fin >> tmp->jrnl.name;
    fin >> tmp->jrnl.counts;
    fin >> tmp->jrnl.period;
    fin >> tmp->jrnl.time;
    fin >> tmp->jrnl.price;
    fin >> tmp->jrnl.publisher;
    fin >> tmp->jrnl.priviliges;
    tmp->next = nullptr;
    return tmp;
}

//поиск по имени
void showAllByName(List_elem* begin)
{
    string Letter;

    cout << "Input Search Name:" << endl;
    cin >> Letter;

    List_elem* ptr = begin;

    while (ptr != nullptr)
    {
        if (ptr->jrnl.name == Letter)
        {
            cout << " _____________________________" << endl;
            cout << "|ID:" << ptr->jrnl.index << endl;
            cout << "|Name:" << ptr->jrnl.name << endl;
            cout << "|Counts:" << ptr->jrnl.counts << endl;
            cout << "|Period:" << ptr->jrnl.period << endl;
            cout << "|Time:" << ptr->jrnl.time << endl;
            cout << "|Price:" << ptr->jrnl.price << "$" << endl;
            cout << "|Publisher:" << ptr->jrnl.publisher << endl;
            cout << "|Priviliges:" << ptr->jrnl.priviliges << endl;
            cout << "|____________________________" << endl;
            cout << "\n";
        }

        ptr = ptr->next;
    }
}
//поиск по льготам
void showAllByPriviliges(List_elem* begin)
{
    string Letter;

    cout << "Input Search Name:" << endl;
    cin >> Letter;

    List_elem* ptr = begin;

    while (ptr != nullptr)
    {
        if (ptr->jrnl.priviliges == Letter)
        {
            cout << " _____________________________" << endl;
            cout << "|ID:" << ptr->jrnl.index << endl;
            cout << "|Name:" << ptr->jrnl.name << endl;
            cout << "|Counts:" << ptr->jrnl.counts << endl;
            cout << "|Period:" << ptr->jrnl.period << endl;
            cout << "|Time:" << ptr->jrnl.time << endl;
            cout << "|Price:" << ptr->jrnl.price << "$" << endl;
            cout << "|Publisher:" << ptr->jrnl.publisher << endl;
            cout << "|Priviliges:" << ptr->jrnl.priviliges << endl;
            cout << "|____________________________" << endl;
            cout << "\n";
        }

        ptr = ptr->next;
    }
}
//поиск по издателю
void showAllByPublisher(List_elem* begin)
{
    string Letter;

    cout << "Input Search Name:" << endl;
    cin >> Letter;

    List_elem* ptr = begin;

    while (ptr != nullptr)
    {
        if (ptr->jrnl.publisher == Letter)
        {
            cout << " _____________________________" << endl;
            cout << "|ID:" << ptr->jrnl.index << endl;
            cout << "|Name:" << ptr->jrnl.name << endl;
            cout << "|Counts:" << ptr->jrnl.counts << endl;
            cout << "|Period:" << ptr->jrnl.period << endl;
            cout << "|Time:" << ptr->jrnl.time << endl;
            cout << "|Price:" << ptr->jrnl.price << "$" << endl;
            cout << "|Publisher:" << ptr->jrnl.publisher << endl;
            cout << "|Priviliges:" << ptr->jrnl.priviliges << endl;
            cout << "|____________________________" << endl;
            cout << "\n";
        }

        ptr = ptr->next;
    }
}
//стандартный вид списка
void defaultSort(List_elem* begin)
{
    if (!begin)
    {
        cout << "List_elem empty." << endl;

        return;
    }
    List_elem* ptrN = begin;

    while (ptrN->next != nullptr)
    {
        List_elem* ptr = begin;

        while (ptr->next != nullptr)
        {
            if (ptr->jrnl.index > ptr->next->jrnl.index)
            {
                Journal tmp = ptr->jrnl;
                ptr->jrnl = ptr->next->jrnl;
                ptr->next->jrnl = tmp;
            }

            ptr = ptr->next;
        }

        ptrN = ptrN->next;
    }
}
//сортировать цену по возрастанию

//TODO Fix sort functions 
// Use ptrN in sort func make 10 journals with different values

void sortPriceASC(List_elem* begin)
{
    if (!begin)
    {
        cout << "List_elem empty." << endl;

        return;
    }
    List_elem* ptrN = begin;

    while (ptrN->next != nullptr)
    {
        List_elem* ptr = begin;

        while (ptr->next != nullptr)
        {
            if (ptr->jrnl.price > ptr->next->jrnl.price)
            {
                Journal tmp = ptr->jrnl;
                ptr->jrnl = ptr->next->jrnl;
                ptr->next->jrnl = tmp;
            }

            ptr = ptr->next;
        }

        ptrN = ptrN->next;
    }
}
//сортировать цену по убыванию
void sortPriceDES(List_elem* begin)
{
    if (!begin)
    {
        cout << "List_elem empty." << endl;

        return;
    }
    List_elem* ptrN = begin;

    while (ptrN->next != nullptr)
    {
        List_elem* ptr = begin;

        while (ptr->next != nullptr)
        {
            if (ptr->jrnl.price < ptr->next->jrnl.price)
            {
                Journal tmp = ptr->jrnl;
                ptr->jrnl = ptr->next->jrnl;
                ptr->next->jrnl = tmp;
            }

            ptr = ptr->next;
        }

        ptrN = ptrN->next;
    }
}
//сортировать тираж по возрастанию
void sortCountASC(List_elem* begin)
{
    if (!begin)
    {
        cout << "List_elem empty." << endl;

        return;
    }
    List_elem* ptrN = begin;

    while (ptrN->next != nullptr)
    {
        List_elem* ptr = begin;

        while (ptr->next != nullptr)
        {
            if (ptr->jrnl.counts > ptr->next->jrnl.counts)
            {
                Journal tmp = ptr->jrnl;
                ptr->jrnl = ptr->next->jrnl;
                ptr->next->jrnl = tmp;
            }

            ptr = ptr->next;
        }

        ptrN = ptrN->next;
    }
}
//сортировать тираж по убыванию
void sortCountDES(List_elem* begin)
{
    if (!begin)
    {
        cout << "List_elem empty." << endl;

        return;
    }
    List_elem* ptrN = begin;

    while (ptrN->next != nullptr)
    {
        List_elem* ptr = begin;

        while (ptr->next != nullptr)
        {
            if (ptr->jrnl.counts < ptr->next->jrnl.counts)
            {
                Journal tmp = ptr->jrnl;
                ptr->jrnl = ptr->next->jrnl;
                ptr->next->jrnl = tmp;
            }

            ptr = ptr->next;
        }

        ptrN = ptrN->next;
    }
}
//сортировать имя по возрастанию
void sortNameASC(List_elem* begin)
{
    if (!begin)
    {
        cout << "List_elem empty." << endl;

        return;
    }
    List_elem* ptrN = begin;

    while (ptrN->next != nullptr)
    {
        List_elem* ptr = begin;

        while (ptr->next != nullptr)
        {
            if (ptr->jrnl.name > ptr->next->jrnl.name)
            {
                Journal tmp = ptr->jrnl;
                ptr->jrnl = ptr->next->jrnl;
                ptr->next->jrnl = tmp;
            }

            ptr = ptr->next;
        }

        ptrN = ptrN->next;
    }
}
//сортировать имя по убыванию
void sortNameDES(List_elem* begin)
{
    if (!begin)
    {
        cout << "List_elem empty." << endl;

        return;
    }
    List_elem* ptrN = begin;

    while (ptrN->next != nullptr)
    {
        List_elem* ptr = begin;

        while (ptr->next != nullptr)
        {
            if (ptr->jrnl.name < ptr->next->jrnl.name)
            {
                Journal tmp = ptr->jrnl;
                ptr->jrnl = ptr->next->jrnl;
                ptr->next->jrnl = tmp;
            }

            ptr = ptr->next;
        }

        ptrN = ptrN->next;
    }
}
//удалить элемент
void remove(List_elem** begin, List_elem** end)
{
    List_elem* ptr = *begin;
    List_elem* previous = *begin;

    int id;

    cout << "Which id you want delete:";
    cin >> id;

    while (ptr != nullptr)
    {
        if (ptr->jrnl.index == id)
        {
            if (ptr == *begin)
            {
                *begin = ptr->next;
            }
            if (ptr->next == nullptr)
            {
                *end = previous;
            }
            if (begin == nullptr)
            {
                end = nullptr;
            }

            List_elem* following = ptr->next;
            previous->next = following;
            delete ptr;

            return;
        }

        previous = ptr;
        ptr = ptr->next;
    }
}
//обновить элемент
void update(List_elem* begin)
{
    List_elem* ptr = begin;

    int id;
    cout << "Which id you want update:";
    cin >> id;

    while (ptr != nullptr)
    {
        if (ptr->jrnl.index == id)
        {
            print_elem(ptr);
            cout << "ID:";
            cin >> ptr->jrnl.index;
            cout << "Journal Name:";
            cin >> ptr->jrnl.name;
            cout << "Counts:";
            cin >> ptr->jrnl.counts;
            cout << "Period of subs:";
            cin >> ptr->jrnl.period;
            cout << "Time:";
            cin >> ptr->jrnl.time;
            cout << "Price:";
            cin >> ptr->jrnl.price;
            cout << "Publisher:";
            cin >> ptr->jrnl.publisher;
            cout << "Priviligies:";
            cin >> ptr->jrnl.priviliges;
        }

        ptr = ptr->next;
    }
}
