#include <iostream>

using namespace std;

void InputTargetArray(int arr[], int size, string arr_name);
int CompareArrays(int arr1[], int arr2[], int size);
void ExtractCommonUnique(int arr1[], int arr2[], int size, int common_arr[], int& common_size);
void BubbleSortAscending(int arr[], int size);
void DisplayCommonArray(int common_arr[], int common_size);

int main()
{
    string _project_logo = "\t\t JPU - Programming 2 (Final - Q2) \a";
    int _elements_count;
    int _first_arr[50], _second_arr[50], _third_arr[50];
    int _same_position_count = 0;
    int _third_size = 0;

    system("clear");
    cout << _project_logo << endl << endl;

    while (true)
    {
        cout << "Please enter array size ( 1 - 50 ) : ";
        cin >> _elements_count;
        
        if (_elements_count >= 1 && _elements_count <= 50) {
            break;
        }
        
        cout << "Size not allowed. Bro, try agin" << endl;
        system("sleep 1");
        system("clear");
        cout << _project_logo << endl << endl;
    }

    system("clear");
    cout << _project_logo << endl << endl;

    cout << "--- Fill First Array ---" << endl;
    InputTargetArray(_first_arr, _elements_count, "First");
    
    cout << endl << "--- Fill Second Array ---" << endl;
    InputTargetArray(_second_arr, _elements_count, "Second");

    cout << "\nGo to sleep ... zzz" << endl;
    system("sleep 1");
    system("clear");

    _same_position_count = CompareArrays(_first_arr, _second_arr, _elements_count);
    ExtractCommonUnique(_first_arr, _second_arr, _elements_count, _third_arr, _third_size);
    BubbleSortAscending(_third_arr, _third_size);

    cout << _project_logo << endl << endl;
    cout << " ## Comparison Results ## " << endl << endl;
    system("sleep .5");

    cout << "Elements equal in the same positions = " << _same_position_count << endl;
    cout << "\a";
    system("sleep .6");

    DisplayCommonArray(_third_arr, _third_size);

    cout << endl << "Exit ......." << endl;
    system("sleep 1");

    return 0;
}


void InputTargetArray(int arr[], int size, string arr_name)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr_name << " Array - Element [" << i + 1 << "] : ";
        cin >> arr[i];
    }
}

int CompareArrays(int arr1[], int arr2[], int size)
{
    int match_count = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr1[i] == arr2[i])
        {
            match_count++;
        }
    }
    return match_count;
}

void ExtractCommonUnique(int arr1[], int arr2[], int size, int common_arr[], int& common_size)
{
    common_size = 0;
    
    for (int i = 0; i < size; i++)
    {
        // البحث عن عنصر من المصفوفة الأولى داخل المصفوفة الثانية
        for (int j = 0; j < size; j++)
        {
            if (arr1[i] == arr2[j])
            {
                // التحقق من أن العنصر لم يُضاف مسبقاً لمنع التكرار
                bool already_exists = false;
                for (int k = 0; k < common_size; k++)
                {
                    if (common_arr[k] == arr1[i])
                    {
                        already_exists = true;
                        break;
                    }
                }
                
                
                if (!already_exists)
                {
                    common_arr[common_size] = arr1[i];
                    common_size++;
                }
                break;
            }
        }
    }
}

void BubbleSortAscending(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}


void DisplayCommonArray(int common_arr[], int common_size)
{
    cout << endl << " ## Third Array (Common & Sorted) ## " << endl << endl;
    if (common_size == 0)
    {
        cout << "No common elements found." << endl;
    }
    else
    {
        for (int i = 0; i < common_size; i++)
        {
            cout << common_arr[i] << "\t";
            cout << "\a";
            system("sleep .18");
        }
        cout << endl;
    }
}
