#include "Header.h"

void init(List_elem*& begin, List_elem*& end, List_elem* new_elem)
{
    List_elem* elem_to_add = new_elem == nullptr ? create_elem() : new_elem;
    begin = elem_to_add;
    end = begin;
}

void add_begin(List_elem*& begin, List_elem *&end, List_elem* new_elem)
{
    List_elem* elem_to_add = new_elem == nullptr ? create_elem() : new_elem;
    if (!begin)
    {
        init(begin, end, new_elem);
    }
    elem_to_add->next = begin;
    begin = elem_to_add;
    return;
}

void add_end(List_elem*& begin, List_elem*& end, List_elem* new_elem)
{
    List_elem* elem_to_add = new_elem == nullptr ? create_elem() : new_elem;
    if (!begin)
    {
        init(begin, end, new_elem);
    }
    elem_to_add->next = nullptr;
    end->next = elem_to_add;
    end = end->next;
    return;
}
//добавление элементов
void add_elem(List_elem*& begin, List_elem*& end, List_elem* new_elem, int id, char pos)
{
    List_elem* elem_to_add = new_elem == nullptr ? create_elem() : new_elem;
    if (!begin)
    {
        init(begin, end, elem_to_add);
    }
    if (id == 0)
    {
        add_begin(begin, end, elem_to_add);
        return;
    }
    if (id == -1)
    {
        add_end(begin, end, elem_to_add);
        return;
    }
    if (id < 0)
    {
        cout << "BAD ID\n";
        return;
    }

    List_elem* target_elem = begin;
    int target_id = pos == '1' ? id - 1 : pos == '2' ? id : -100;
    if (target_id == -100)
    {
        cout << "Bad pos\n";
        return;
    }
    int curr_id = 0;
    while (target_elem)
    {
        target_elem = target_elem->next;
        ++curr_id;
        if (curr_id == target_id)
            break;
    }
    if (target_elem->next == nullptr)
    {
        add_end(begin, end, elem_to_add);
        return;
    }
    elem_to_add->next = target_elem->next;
    target_elem->next = elem_to_add;
    
}
bool check_id(List_elem* begin, int id)
{
    int curr_id = 0;
    List_elem* ptr = begin;
    if (id < 0)
        return false;
    while (ptr)
    {
        ptr = ptr->next;
        ++curr_id;
        if (curr_id == id && ptr)
            return true;
    }
    return false;
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
    int index = 0;

    while (print)
    {

        print_elem(print,index);
        print = print->next;
        index++;
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

void print_elem(List_elem* tmp, int index)
{
    cout << "_____________________________" << endl;
    cout << "Index: " << index << endl;
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
    int index = 0;
    while (!fin.eof())
    {
        List_elem* tmp = read_elem(fin);
        print_elem(tmp,index);
        add_elem(begin, end, tmp);
        index++;
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
    struct New_List_Elem
    {
        Journal jrnl;
        New_List_Elem* next;
    };
    string Letter;

    cout << "Input Search Name:" << endl;
    cin >> Letter;

    List_elem* ptr = begin;

    while (ptr != nullptr)
    {
        if (ptr->jrnl.publisher == Letter)
        {

            // код для копирования в новый список
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
    List_elem* ptrP = begin;

    while (ptrP->next != nullptr)
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

        ptrP = ptrP->next;
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
    int index = -1;
    while (ptr != nullptr)
    {
        if (ptr->jrnl.index == id)
        {
            print_elem(ptr,index);
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
