
#include "Header.h"





int main()
{

    List_elem* begin = nullptr;
    List_elem* end = nullptr;

    int key;

    do
    {
        system("cls");
        cout << "=======================================================================" << endl;
        cout << "|                      Welcome to electronic filing                   |"<< endl;
        cout << "|                          Make your choice                           |" << endl;
        cout << "=======================================================================" << endl;
        cout << "Menu:" << endl;
        cout << "1- Add element  ." << endl;
        cout << "2- Print." << endl;
        cout << "3- Default sort." << endl;
        cout << "4- Sort price by ascending." << endl;
        cout << "5- Sort price by descending." << endl;
        cout << "6- Sort counts by ascending." << endl;
        cout << "7- Sort counts by descending." << endl;
        cout << "8- Sort name by ascending." << endl;
        cout << "9- Sort name by descending." << endl;
        cout << "10- Find by Name." << endl;
        cout << "11- Find by publisher ." << endl;
        cout << "12- Find by priviligies." << endl;
        cout << "13- Delete element." << endl;
        cout << "14- Edit element." << endl;
        cout << "15- Save." << endl;
        cout << "16- Download list." << endl;
        cout << "0- Exit." << endl;
        cout << "======================================================================" << endl;

        cout << "Choice:";
        cin >> key;

        switch (key)
        {
            
        case 1:
        {
            system("cls");
            cout << "Choose id" << endl;
            int id;
            cin >> id;
            if (check_id(begin, id))
            {
                cout << "1-Before 2-After" << endl;
                char pos;
                cin >> pos;
                add_elem(begin, end, nullptr, id, pos);
            }
            else
            {
                cout << "Bad id\n";
            }
            _getch();
            break; 
        }

        case 2:
            system("cls");
            output(begin);
            _getch();
            break;

        case 3:
            system("cls");
            defaultSort(begin);
            _getch();
            break;

        case 4:
            system("cls");
            sortPriceASC(begin);
            _getch();
            break;

        case 5:
            system("cls");
            sortPriceDES(begin);
            _getch();
            break;
        case 6:
            system("cls");
            sortCountASC(begin);
            _getch();
            break;

        case 7:
            system("cls");
            sortCountDES(begin);
            _getch();
            break;
        case 8:
            system("cls");
            sortNameASC(begin);
            _getch();
            break;

        case 9:
            system("cls");
            sortNameDES(begin);
            _getch();
            break;

        case 10:
            system("cls");
            showAllByName(begin);
            _getch();
            break;
        case 11:
            system("cls");
            showAllByPublisher(begin);
            _getch();
            break;
        case 12:
            system("cls");
            showAllByPriviliges(begin);
            _getch();
            break;
        case 13:
            system("cls");
            remove(&begin, &end);
            _getch();
            break;

        case 14:
            system("cls");
            update(begin);
            _getch();
            break;
        case 15:
            system("cls");
            save_f(begin);
            _getch();
            break;
            
        case 16:
            system("cls");
            load_f(begin, end);
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


