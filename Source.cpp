
#include <iostream>
using namespace std;

const int MAX_PATH_LENGTH = 100;  // ������������ ����� ����

struct Node {
    int data;
    Node* children;
    int numChildren;

    Node(int value, int numChildren) : data(value), numChildren(numChildren) {
        children = new Node[numChildren];
    }
    Node() : data(0), numChildren(0), children(nullptr) {}

    ~Node() {
        delete[] children;
    }
};

void inputTree(Node& root) {
    cout << "������� �������� ����: ";
    cin >> root.data;

    cout << "������� ���������� ����� � ���� " << root.data << ": ";
    cin >> root.numChildren;

    root.children = new Node[root.numChildren];

    for (int i = 0; i < root.numChildren; ++i) {
        cout << "������� �������� ��� ������� " << i + 1 << " ���� " << root.data << ": ";
        inputTree(root.children[i]);
    }
}

void findLongestPath(const Node& root, int path[], int& maxLength, int currentLength, int currentPath[]) {
    currentPath[currentLength] = root.data;

    if (root.numChildren == 0) {
        if (currentLength > maxLength) {
            maxLength = currentLength;
            // ��������� �������� ������� ���� � ������ path
            for (int i = 0; i <= currentLength; ++i) {
                path[i] = currentPath[i];
            }
        }
        return;
    }

    for (int i = 0; i < root.numChildren; ++i) {
        findLongestPath(root.children[i], path, maxLength, currentLength + 1, currentPath);
    }
    // ������� currentPath ����� ���������� ��������� �����
    currentPath[currentLength] = 0;
}

// ������� ��� ������ ���������� ����
void printPath(const int path[], int length) {
    cout << "����� ������� ���� ��� ���������: ";
    for (int i = 0; i < length; ++i) {
        cout << path[i];
        if (i < length - 1) {
            cout << " -> ";
        }
    }
    cout << endl;
}

int main() {
    setlocale(LC_ALL, "RU");
    Node root(0, 0);

    inputTree(root);
    const int MAX_PATH_LENGTH = 100;
    int path[MAX_PATH_LENGTH];
    int maxLength = 0;
    int currentPath[MAX_PATH_LENGTH];

    findLongestPath(root, path, maxLength, 0, currentPath);

    printPath(path, maxLength);

    return 0;
}

