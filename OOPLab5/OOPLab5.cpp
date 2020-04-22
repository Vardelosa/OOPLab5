#include <iostream>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template <class TKey, class T> class AssocArray
{
private:

    typedef struct _Data
    {
        T data;
        TKey key;
    } Data;


    vector<Data> stack;
public:
    //Размер контейнера
    long size()
    {
        return stack.size();
    }
    //Сортировка по возрастанию, либо по алфавиту в случае string
    void key_sort()
    {

        if (typeid(stack[1].key) == typeid(int) || typeid(stack[1].key) == typeid(string) || typeid(stack[1].key) == typeid(double) || typeid(stack[1].key) == typeid(float))
        {//Использование функции sort и итератора для сортировки
            sort(stack.begin(), stack.end(), [](const Data& d1, const Data& d2) 
            {
                    return d1.key < d2.key;
            });
        }
        else
        {
            cout << "ERROR: cannot sort: type is not allowed.\n";
        }

    }

    bool is_item(TKey name)
    {
        //Использование функции find_if для проверки присутсвия элемента в колллекции
        auto result = find_if(stack.begin(), stack.end(), [&](const Data& p)
            {
                return p.key == name;
            });
        if (result == stack.end())
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    //Добавление нового элемента в коллекцию
    bool insert(TKey name, T data)
    {
        if (is_item(name))
            return false;
        Data d;
        d.key = name;
        d.data = data;
        stack.push_back(d);
        return true;
    }
    //Добавление нового элемента в коллекцию с помощью оператора
    T& operator [] (TKey name)
    {
        for (int i = 0; i < size(); i++)
        {
            if (stack[i].key == name)
                return stack[i].data;
        }
        long idx = size();
        Data d;
        d.key = name;
        stack.push_back(d);
        return stack[idx].data;
    }
    void traversal()
    {//Использование итератора для прохождения по контейнеру.
        Data elem;
        auto iter = stack.begin();
        cout << "( ";
        while (iter != stack.end())
        {
            elem = *iter;
            cout << "[" << elem.key << "]" << "-->" << elem.data << " ";
            ++iter;
        }
        cout << ")";
        cout << endl;
    }

    T& operator [] (long index)
    {
        if (index < 0)
            index = 0;
        for (int i = 0; i < size(); i++)
        {
            if (i == index)
                return stack[i].data;
        }
        return stack[0].data;
    }

};
int main()
{

    AssocArray<int, int>   arr;

    
    arr.insert(5, 100);
    arr[7] = 56;
    arr[1] = 25;


    cout << "Element 1 = " << arr[1] << endl;


    arr.traversal();
    arr.key_sort();
    arr.traversal();

    // Other functions
    bool item = arr.is_item(1);
    if(item)
    cout << "Item in collection" << endl;
    else
    cout << "No such item in collection" << endl;
    cout << arr.size();
}

