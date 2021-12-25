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
        cout << "����� ������ - " << articals[i].Number << endl;
        cout << "��� ������ - " << articals[i].Year << endl;
        cout << "������� ������ ������ - " << articals[i].Surname << endl;
        cout << "��� ������ ������ - " << articals[i].Name << endl;
        cout << "�������� ������ - " << articals[i].TitleOfTheArticle << endl << endl;
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
        cout << "������� ����� ������ " + (i + 1) << endl;
        cin >> articals[i].Number;
        while (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "������, ��������� ���� -  ";
            cin >> articals[i].Number;
        }
        cout << "������� ��� ������ " + (i + 1) << endl;
        cin >> articals[i].Year;
        while (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "������, ��������� ���� -  ";
            cin >> articals[i].Year;
        }
        cout << "������� ������� ������ " + (i + 1) << endl;
        cin >> articals[i].Surname;
        while (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "������, ��������� ���� -  ";
            cin >> articals[i].Surname;
        }
        cout << "������� ��� ������ ������ " + (i + 1) << endl;
        cin >> articals[i].Name;
        while (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "������, ��������� ���� -  ";
            cin >> articals[i].Name;
        }
        cout << "������� �������� ������ " + (i + 1) << endl << endl;
        cin >> articals[i].TitleOfTheArticle;
        while (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "������, ��������� ���� -  ";
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
    cout << "������� �������� �������" << endl;
    cin >> nameJournal;
    while (true)
    {
        int menu;
        cout << "�������� �����" << endl;
        cout << "�������� ������, ������� - 1" << endl;
        cout << "����������� ���������� � �������, ������� 2" << endl;
        cout << "����� ������ ��������� ������, ������� 3" << endl << endl;
        cin >> menu;
        while (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "������, ��������� ���� -  ";
            cin >> menu;
        }
        switch (menu)
        {
        case 1:
        {
            int NumArt;
            cout << "������� �����, ��� ������� �������� ������" << endl;
            cin >> NumArt;
            while (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "������, ��������� ���� -  ";
                cin >> NumArt;
            }
            CreateArtical(articals, NumArt, nameJournal);
            ValueArticals++;
            break;
        }
        case 2:
        {
            int n;
            cout << "������� ����� ������, ������� ����� �������" << endl;
            cin >> n;
            while (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "������, ��������� ���� -  ";
                cin >> n;
            }
            Info(articals, n);
            break;
        }
        case 3:
        {
            int av;
            cout << "������ �������" << endl;
            for (int i = 0; i < ValueArticals; i++)
            {
                cout << i+1<< ". - " << articals[i].Surname << articals[i].Name << endl;
            }
            cout << "�������� ������, ������� ����� �� ������" << endl ;
            cin >> av;
            while (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "������, ��������� ���� -  ";
                cin >> av;
            }
            cout << "���������� � ������� ������� ������" << endl << endl;

            cout << "����� ������ - " << articals[av-1].Number << endl;
            cout << "��� ������ - " << articals[av-1].Year << endl;
            cout << "�������� ������ - " << articals[av-1].TitleOfTheArticle << endl << endl;
            break;
        }
        }

    }
}
