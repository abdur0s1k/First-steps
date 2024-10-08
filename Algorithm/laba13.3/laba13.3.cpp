#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    int rows, cols;
    setlocale(0, "");

    // ���� ���������� �����
    do {
        cout << "������� ���������� �����: ";
        cin >> rows;
        if (rows <= 0) {
            cout << "���������� ����� ������ ���� ������������� ������\n";
        }
    } while (rows <= 0);

    // ���� ���������� ��������
    do {
        cout << "������� ���������� ��������: ";
        cin >> cols;
        if (cols <= 0) {
            cout << "���������� �������� ������ ���� ������������� ������\n";
        }
    } while (cols <= 0);

    // ��������� ������������ ������
    int** arr = new int* [rows];
    for (int i = 0; i < rows; i++) {
        arr[i] = new int[cols];
    }

    if (arr == nullptr) {
        cout << "������ ��������� ������\n";
        return 1;
    }

    // ������������� ��������� ������� ���������������� ����������
    srand(time(0));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = rand() % 9 - 9;
        }
    }

    // ����� ��������� ������� � ���� �������
    cout << "Show massiv:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << arr[i][j];
            if (j != cols - 1) {
                cout << " | ";
            }
        }
        cout << endl;
    }

    // ����� ��������� ������� � �������� �������
    cout << "Show reverse massiv:\n";
    for (int i = rows - 1; i >= 0; i--) {
        for (int j = cols - 1; j >= 0; j--) {
            cout << arr[i][j];
            if (j != 0) {
                cout << " | ";
            }
        }
        cout << endl;
    }

    // ������������ ������������ ������
    for (int i = 0; i < rows; i++) {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}