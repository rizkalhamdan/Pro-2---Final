// Al: 22:54 18.07.2026 -- Last changes

#include <iostream>

using namespace std;

void InputArray(int arr[], int size);
void FindMaxMin(int arr[], int size, int& max_val, int& min_val);
double CalculateAverage(int arr[], int size);
void CreateFilteredArray(int arr[], int size, double avg, int new_arr[], int& new_size);
void DisplayNewArray(int new_arr[], int new_size);

int main()
{
    string _project_logo = "\t\t JPU - Programming 2 (Final) \a";
    int _n;
    int _main_array[100];
    int _result_array[100];
    int _max, _min, _filtered_size;
    double _average = 0;

    system("clear");
    cout << _project_logo << endl << endl;

    while (true)
    {
        cout << "Please enter N ( 5 <= N <= 100 ) : ";
        cin >> _n;
        
        if (_n >= 5 && _n <= 100) {
            break; 
        }
        
        cout << "Not allowed value. Bro, try agin" << endl;
        system("sleep 1");
        system("clear");
        cout << _project_logo << endl << endl;
    }

    system("clear");
    cout << _project_logo << endl << endl;
    
    InputArray(_main_array, _n);

    cout << "\nGo to sleep ... zzz" << endl;
    system("sleep 1");
    system("clear");

    FindMaxMin(_main_array, _n, _max, _min);
    _average = CalculateAverage(_main_array, _n);
    CreateFilteredArray(_main_array, _n, _average, _result_array, _filtered_size);

    cout << _project_logo << endl << endl;
    cout << " ## Processing Results ## " << endl << endl;
    system("sleep .5");
    
    cout << " MAX Value = " << _max << endl;
    cout << "\a"; 
    system("sleep .4");
    
    cout << " MIN Value = " << _min << endl;
    cout << "\a"; 
    system("sleep .4");
    
    cout << " AVG Value = " << _average << endl << endl;
    system("sleep .5");

    
    DisplayNewArray(_result_array, _filtered_size);

    cout << endl << "Exit ......." << endl;
    system("sleep 1");

    return 0;
}



void InputArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "Enter element [" << i + 1 << "] : ";
        cin >> arr[i];
    }
}


void FindMaxMin(int arr[], int size, int& max_val, int& min_val)
{
    max_val = arr[0];
    min_val = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > max_val) max_val = arr[i];
        if (arr[i] < min_val) min_val = arr[i];
    }
}


double CalculateAverage(int arr[], int size)
{
    double sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    return sum / size;
}

void CreateFilteredArray(int arr[], int size, double avg, int new_arr[], int& new_size)
{
    new_size = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > avg)
        {
            new_arr[new_size] = arr[i];
            new_size++;
        }
    }
}


void DisplayNewArray(int new_arr[], int new_size)
{
    if (new_size == 0)
    {
        cout << "No elements greater than the average." << endl;
    }
    else
    {
        cout << " ## New Array (Elements > AVG) ## \n\n";
        for (int i = 0; i < new_size; i++)
        {
            cout << new_arr[i] << "\t";
            cout << "\a"; 
            system("sleep .18");
        }
        cout << "\n\nNumber of elements = " << new_size << endl;
    }
}
