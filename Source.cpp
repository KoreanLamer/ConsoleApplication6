#include "Header.h"


//добавление элементов
void add_elem(List*& begin, List*& end, List* new_elem)
{
    List* elem_to_add = new_elem == nullptr ? create_elem() : new_elem;
    if (!begin)
    {
        begin = elem_to_add;
        end = begin;
        return;
    }
    end->next = elem_to_add;
    end = end->next;
}

List* create_elem()
{
    List* new_element = new List;
    cout << "ID:";
    cin >> (new_element)->book.index;
    cout << "Journal Name:";
    cin >> (new_element)->book.name;
    cout << "Counts:";
    cin >> (new_element)->book.counts;
    cout << "Period :";
    cin >> (new_element)->book.period;
    cout << "Time:";
    cin >> (new_element)->book.time;
    cout << "Price:";
    cin >> (new_element)->book.price;
    cout << "Publisher:";
    cin >> (new_element)->book.publisher;
    cout << "Priviliges:";
    cin >> (new_element)->book.priviliges;
    (new_element)->next = nullptr;
    return new_element;
};
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

        print_elem(print);
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

        while (tmp != nullptr)
        {
            char end_sym = tmp->next == nullptr ? '\0' : '\n';
            fout << tmp->book.index << " ";
            fout << tmp->book.name << " ";
            fout << tmp->book.counts << " ";
            fout << tmp->book.period << " ";
            fout << tmp->book.time << " ";
            fout << tmp->book.price << " ";
            fout << tmp->book.publisher << " ";
            fout << tmp->book.priviliges << end_sym;

            tmp = tmp->next;
        }

        fout.close();
    }

    else
        cout << "Error saving" << endl;
}
//загрузить список

void print_elem(List* tmp)
{
    cout << "_____________________________" << endl;
    cout << "|ID:" << tmp->book.index << endl;
    cout << "|Name:" << tmp->book.name << endl;
    cout << "|Counts:" << tmp->book.counts << endl;
    cout << "|Period:" << tmp->book.period << endl;
    cout << "|Time:" << tmp->book.time << endl;
    cout << "|Price:" << tmp->book.price << endl;
    cout << "|Publisher:" << tmp->book.publisher << endl;
    cout << "|Priviliges:" << tmp->book.priviliges << endl;
    cout << "|____________________________" << endl;
}
void load_f(List*& begin, List*& end)
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
        List* tmp = read_elem(fin);
        print_elem(tmp);
        add_elem(begin, end, tmp);

    }

}

List* read_elem(ifstream& fin)
{
    List* tmp = new List;
    fin >> tmp->book.index;
    fin >> tmp->book.name;
    fin >> tmp->book.counts;
    fin >> tmp->book.period;
    fin >> tmp->book.time;
    fin >> tmp->book.price;
    fin >> tmp->book.publisher;
    fin >> tmp->book.priviliges;
    tmp->next = nullptr;
    return tmp;
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
//поиск по льготам
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
