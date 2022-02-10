#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;


void print(vector<int>& a,int arraySize) {
    for(int i = 0; i < arraySize; i++)
        cout << a[i] << " ";
    cout << endl;
}

void RadixSortLSD(vector<int>& arr, int* arraySize)
{
    print(arr,*arraySize);

    int i, buff[*arraySize], maxVal = 0, digitPosition =1 ;
    for(i = 0; i < *arraySize; i++) {
        if(arr[i] > maxVal) maxVal = arr[i];
    }

    while(maxVal/digitPosition > 0) {
        // сбрасует счетчик
        int digitCount[10] = {0};

        // считает позиции ключей сортировки
        for(i = 0; i < *arraySize; i++)
            digitCount[arr[i]/digitPosition%10]++;

        for(int i = 0; i < *arraySize; i++)
            cout << digitCount[i] << " ";
        cout << endl;

        // не знаю как это назвать но алгоритм нужен для того что б расставить по своим местам цифры когда будем переностить в буфер

        for(i = 1; i < 10; i++)
            digitCount[i] += digitCount[i-1];

        for(int i = 0; i < *arraySize; i++)
            cout << digitCount[i] << " ";
        cout << endl;

        // начинает справа кидать в буфер
        for(i = *arraySize - 1; i >= 0; i--)
            buff[--digitCount[arr[i]/digitPosition%10]] = arr[i];

        for(int i = 0; i < *arraySize; i++)
            cout << buff[i] << " ";
        cout << endl;


        // переделывает масив используя значения из буфера
        for(i = 0; i < *arraySize; i++)
            arr[i] = buff[i];

        print(arr,*arraySize);

        // проверяет по некст цифре числу
        digitPosition *= 10;
    }
}


void unique_combination(int l, int sum, int T,vector<int>& buff,vector<int>& arr){
    // найденная комбинация
    if (sum == T) {
        cout << "[";
        for (int i = 0; i < buff.size(); i++)
        {
            if (i != 0)
                cout << " ";
            cout << buff[i];
            if (i != buff.size() - 1)
                cout << ", ";
        }
        cout << "]" << endl;
        return;
    }

    // поиск комбинаций
    for (int i = l; i < arr.size(); i++)
    {

        // если сума будет больше таргета то i++ и заново
        if (sum + arr[i] > T)
            continue;

        // если элемент повторился то i++ и заново
        if (i > l and arr[i] == arr[i - 1])
            continue;

        buff.push_back(arr[i]);

        unique_combination(i + 1, sum + arr[i], T, buff, arr);

        buff.pop_back();
    }
}

void Combination(vector<int> arr, int T)
{
    int size = arr.size();
    // сортировка
    RadixSortLSD(arr, &size);

    // буфер
    vector<int> buff;

    unique_combination(0, 0, T, buff, arr);
}


int main() {
    srand(time(NULL));

    vector<int> arr;
    int x=0;
    while(x < 10){
        int num;
        arr.push_back(rand()%50);
        x++;
    }
    print(arr,arr.size());

    int T;
    cin >> T;
    Combination(arr, T);

    cout << '\n';

}
