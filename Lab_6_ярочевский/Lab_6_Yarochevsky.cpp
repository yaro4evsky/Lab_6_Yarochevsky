#include <iostream>
using namespace std;

struct artical {
    char* NameJournal;
    int Number;
    int Year;
    char* Surname;
    char* Name;
    char* TitleOfTheArticle;
    int *ValueArticals = new int();
};

void Info(artical *articals,int n)
{
    for (int i = n - 1; i < n;i++)
    {
        cout << "Номер статьи - " << articals[i].Number << endl;
        cout << "Год статьи - " << articals[i].Year << endl;
        cout << "Фамилия автора статьи - " << articals[i].Surname << endl;
        cout << "Имя автора статьи - " << articals[i].Name << endl;
        cout << "Название статьи - " << articals[i].TitleOfTheArticle << endl << endl;
    }
}

void CreateArtical(artical *articals, int n, char *nameJournal)
{
    for (int i = n - 1; i < n; i++)
    {
        articals[i].NameJournal = new char();
        articals[i].NameJournal = nameJournal;
    }

    for (int i = n - 1; i < n; i++)
    {
        articals[i].Surname = new char();
        articals[i].Name = new char();
        articals[i].TitleOfTheArticle = new char();
        cout << "Введите номер статьи " + (i + 1) << endl;
        cin >> articals[i].Number;
        while (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ошибка, повторите ввод -  ";
            cin >> articals[i].Number;
        }
        cout << "Введите год статьи " + (i + 1) << endl;
        cin >> articals[i].Year;
        while (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ошибка, повторите ввод -  ";
            cin >> articals[i].Year;
        }
        cout << "Введите фамилию статьи " + (i + 1) << endl;
        cin >> articals[i].Surname;
        while (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ошибка, повторите ввод -  ";
            cin >> articals[i].Surname;
        }
        cout << "Введите имя автора статьи " + (i + 1) << endl;
        cin >> articals[i].Name;
        while (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ошибка, повторите ввод -  ";
            cin >> articals[i].Name;
        }
        cout << "Введите название статьи " + (i + 1) << endl << endl;
        cin >> articals[i].TitleOfTheArticle;
        while (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ошибка, повторите ввод -  ";
            cin >> articals[i].TitleOfTheArticle;
        }
    }

}

int main()
{
    setlocale(LC_ALL, "Russian");
    artical* articals = new artical();
    int ValueArticals = 0;
    char* nameJournal = new char();
    cout << "Введите название журнала" << endl;
    cin >> nameJournal;
    while (true)
    {
        int menu;
        cout << "Выберите пункт" << endl;
        cout << "Добавить статью, нажмите - 1" << endl;
        cout << "Распечатать информацию о статьях, нажмите 2" << endl;
        cout << "Найти статьи заданного автора, нажмите 3" << endl << endl;
        cin >> menu;
        while (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ошибка, повторите ввод -  ";
            cin >> menu;
        }
        switch (menu)
        {
        case 1:
        {
            int NumArt;
            cout << "Введите номер, под который добавить статью" << endl;
            cin >> NumArt;
            while (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Ошибка, повторите ввод -  ";
                cin >> NumArt;
            }
            CreateArtical(articals, NumArt, nameJournal);
            ValueArticals++;
            break;
        }
        case 2:
        {
            int n;
            cout << "Введите номер статьи, которую нужно вывести" << endl;
            cin >> n;
            while (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Ошибка, повторите ввод -  ";
                cin >> n;
            }
            Info(articals, n);
            break;
        }
        case 3:
        {
            int av;
            cout << "Список авторов" << endl;
            for (int i = 0; i < ValueArticals; i++)
            {
                cout << i+1<< ". - " << articals[i].Surname << articals[i].Name << endl;
            }
            cout << "Выберите автора, введите номер из списка" << endl ;
            cin >> av;
            while (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Ошибка, повторите ввод -  ";
                cin >> av;
            }
            cout << "Информация о статьях данного автора" << endl << endl;

            cout << "Номер статьи - " << articals[av-1].Number << endl;
            cout << "Год статьи - " << articals[av-1].Year << endl;
            cout << "Название статьи - " << articals[av-1].TitleOfTheArticle << endl << endl;
            break;
        }
        }

    }
}
